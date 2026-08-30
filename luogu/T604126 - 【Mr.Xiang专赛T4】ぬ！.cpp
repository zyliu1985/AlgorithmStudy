#include <bits/stdc++.h>
using namespace std;

const int MAXL = 2505;
const long long MOD = 1000000007LL;
using BS = bitset<MAXL>;

int lg2[MAXL + 1];

long long modpow(long long a, long long e) {
    long long res = 1;
    while (e) {
        if (e & 1) res = res * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return res;
}

/* 后缀数组 + rank，使用 LSD 基数排序 */
vector<int> build_sa_rank(const string& s, vector<int>& sa) {
    int n = (int)s.size();
    sa.assign(n, 0);
    vector<int> rk(n), tmp(n);

    int maxc = 256;
    vector<int> cnt(max(maxc, n + 1), 0);

    for (int i = 0; i < n; i++) cnt[(unsigned char)s[i]]++;
    for (int i = 1; i < maxc; i++) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; i--) sa[--cnt[(unsigned char)s[i]]] = i;

    rk[sa[0]] = 0;
    for (int i = 1; i < n; i++)
        rk[sa[i]] = rk[sa[i - 1]] + (s[sa[i]] != s[sa[i - 1]]);

    int classes = rk[sa[n - 1]] + 1;

    for (int k = 1; k < n && classes < n; k <<= 1) {
        // 先按第二关键字排序
        vector<int> cnt2(classes + 1, 0);
        for (int i = 0; i < n; i++) {
            int key = (i + k < n) ? rk[i + k] : -1;
            cnt2[key + 1]++;
        }
        for (int i = 1; i <= classes; i++) cnt2[i] += cnt2[i - 1];

        vector<int> sa2(n);
        for (int i = n - 1; i >= 0; i--) {
            int key = (i + k < n) ? rk[i + k] : -1;
            sa2[--cnt2[key + 1]] = i;
        }

        // 再按第一关键字稳定排序
        cnt.assign(classes, 0);
        for (int idx : sa2) cnt[rk[idx]]++;
        for (int i = 1; i < classes; i++) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--) {
            int idx = sa2[i];
            sa[--cnt[rk[idx]]] = idx;
        }

        tmp[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            int a = sa[i - 1], b = sa[i];
            int a2 = (a + k < n) ? rk[a + k] : -1;
            int b2 = (b + k < n) ? rk[b + k] : -1;
            tmp[b] = tmp[a] + ((rk[a] != rk[b]) || (a2 != b2));
        }
        rk.swap(tmp);
        classes = rk[sa[n - 1]] + 1;
    }

    return rk;
}

vector<int> build_lcp(const string& s, const vector<int>& sa, const vector<int>& rank) {
    int n = (int)s.size();
    vector<int> lcp(max(0, n - 1));
    int h = 0;
    for (int i = 0; i < n; i++) {
        int r = rank[i];
        if (r == n - 1) {
            h = 0;
            continue;
        }
        int j = sa[r + 1];
        while (i + h < n && j + h < n && s[i + h] == s[j + h]) h++;
        lcp[r] = h;
        if (h > 0) h--;
    }
    return lcp;
}

vector<vector<int>> build_sparse(const vector<int>& arr) {
    int m = (int)arr.size();
    if (m == 0) return {};
    int K = lg2[m] + 1;
    vector<vector<int>> st(K, vector<int>(m));
    st[0] = arr;
    for (int k = 1; k < K; k++) {
        int len = 1 << k;
        for (int i = 0; i + len <= m; i++) {
            st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
        }
    }
    return st;
}

int query_lcp(const vector<vector<int>>& st, int a, int b) {
    if (a > b) swap(a, b);
    if (a == b) return MAXL;
    int len = b - a;
    int k = lg2[len];
    return min(st[k][a], st[k][b - (1 << k)]);
}

struct Type2 {
    long long l, r;
    string s;
};

int main() {
	freopen("good1.in", "r", stdin);
	freopen("good1.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    lg2[1] = 0;
    for (int i = 2; i <= MAXL; i++) lg2[i] = lg2[i / 2] + 1;

    long long N;
    int Q;
    cin >> N >> Q;

    vector<pair<long long, char>> fixes;
    vector<Type2> type2;

    for (int q = 0; q < Q; q++) {
        int op;
        cin >> op;
        if (op == 1) {
            long long i;
            char c;
            cin >> i >> c;
            fixes.push_back({i, c});
        } else {
            long long l, r;
            string s;
            cin >> l >> r >> s;
            type2.push_back({l, r, s});
        }
    }

    // 合并 type1，相同位置冲突则无解
    sort(fixes.begin(), fixes.end());
    vector<pair<long long, char>> uniq;
    for (auto &p : fixes) {
        if (!uniq.empty() && uniq.back().first == p.first) {
            if (uniq.back().second != p.second) {
                cout << 0 << '\n';
                return 0;
            }
        } else {
            uniq.push_back(p);
        }
    }
    fixes.swap(uniq);

    long long ans = 1;
    long long covered = 0;        // type2 区间覆盖的总长度
    long long inside_fixed = 0;   // 落在 type2 区间内的不同 type1 位置数

    for (const auto& t : type2) {
        long long l = t.l, r = t.r;
        long long len_ll = r - l + 1;
        covered += len_ll;

        const string& s = t.s;
        int L = (int)s.size();

        if (len_ll > (long long)L || len_ll > MAXL) {
            cout << 0 << '\n';
            return 0;
        }

        int m = (int)len_ll;
        int cnt = L - m + 1; // s 中长度为 m 的子串起点个数

        vector<int> pattern(m, -1);
        bool conflict = false;

        auto it = lower_bound(fixes.begin(), fixes.end(), make_pair(l, (char)0));
        while (it != fixes.end() && it->first <= r) {
            int off = (int)(it->first - l);
            int v = it->second - 'a';
            if (pattern[off] == -1) {
                pattern[off] = v;
                inside_fixed++;
            } else if (pattern[off] != v) {
                conflict = true;
            }
            ++it;
        }

        if (conflict) {
            cout << 0 << '\n';
            return 0;
        }

        // 用 bitset 快速求出满足所有固定字符的起点
        array<BS, 26> posmask;
        for (int i = 0; i < L; i++) posmask[s[i] - 'a'].set(i);

        BS valid;
        for (int i = 0; i < cnt; i++) valid.set(i);

        BS cur;
        cur.set();
        for (int j = 0; j < m; j++) {
            if (pattern[j] != -1) {
                cur &= (posmask[pattern[j]] >> j);
            }
        }
        cur &= valid;

        vector<int> match;
        match.reserve(cnt);
        for (int i = 0; i < cnt; i++) {
            if (cur.test(i)) match.push_back(i);
        }

        if (match.empty()) {
            cout << 0 << '\n';
            return 0;
        }

        int ways = 0;
        if (match.size() == 1) {
            ways = 1;
        } else {
            // 后缀数组 + LCP 对相同子串去重
            vector<int> sa;
            vector<int> rank = build_sa_rank(s, sa);
            vector<int> lcp = build_lcp(s, sa, rank);
            vector<vector<int>> st = build_sparse(lcp);

            sort(match.begin(), match.end(), [&](int a, int b) {
                return rank[a] < rank[b];
            });

            int prev = -1;
            for (int idx : match) {
                if (prev == -1) {
                    ways++;
                } else {
                    int common = query_lcp(st, rank[prev], rank[idx]);
                    if (common < m) ways++;
                }
                prev = idx;
            }
        }

        ans = ans * ways % MOD;
    }

    long long F = (long long)fixes.size();
    long long free_pos = N - covered - (F - inside_fixed);

    if (free_pos < 0) {
        cout << 0 << '\n';
        return 0;
    }

    ans = ans * modpow(26, free_pos) % MOD;
    cout << ans << '\n';

    return 0;
}

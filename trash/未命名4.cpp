#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
const int BASE = 137;

struct Query1 { int pos; char c; };
struct Query2 { int l, r; string s; };

// 解题代码（已去除静态变量，每次调用独立）
ll solve(int N, const vector<Query1>& q1, const vector<Query2>& q2) {
    if (q2.empty()) {
        set<int> fixed_pos;
        map<int, char> fixed_char;
        for (auto& x : q1) {
            if (fixed_char.count(x.pos)) {
                if (fixed_char[x.pos] != x.c) return 0;
            } else {
                fixed_char[x.pos] = x.c;
                fixed_pos.insert(x.pos);
            }
        }
        ll free_pos = N - (ll)fixed_pos.size();
        if (free_pos < 0) return 0;
        ll ans = 1;
        for (int i = 0; i < free_pos; ++i) ans = ans * 26 % MOD;
        return ans;
    }

    vector<pair<int, int>> intervals;
    for (int i = 0; i < (int)q2.size(); ++i)
        intervals.emplace_back(q2[i].l, i);
    sort(intervals.begin(), intervals.end());

    for (int i = 1; i < (int)intervals.size(); ++i) {
        int prev_idx = intervals[i-1].second;
        int cur_idx  = intervals[i].second;
        if (q2[prev_idx].r >= q2[cur_idx].l) return 0;
    }

    vector<vector<pair<int, char>>> cond(q2.size());
    map<int, char> ext_fixed;
    bool ext_conflict = false;

    for (auto& x : q1) {
        int pos = x.pos; char c = x.c;
        int found = -1;
        int lo = 0, hi = (int)intervals.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int idx = intervals[mid].second;
            int l = q2[idx].l, r = q2[idx].r;
            if (pos < l) hi = mid - 1;
            else if (pos > r) lo = mid + 1;
            else { found = idx; break; }
        }
        if (found != -1) {
            cond[found].emplace_back(pos - q2[found].l, c);
        } else {
            if (ext_fixed.count(pos)) {
                if (ext_fixed[pos] != c) ext_conflict = true;
            } else ext_fixed[pos] = c;
        }
    }
    if (ext_conflict) return 0;

    ll covered_len = 0;
    for (auto& x : q2) covered_len += (x.r - x.l + 1);
    ll free_pos = N - covered_len - (ll)ext_fixed.size();
    if (free_pos < 0) return 0;

    auto modpow = [](ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    };
    ll ans = modpow(26, free_pos);

    // 每个区间单独计算时所需的幂表（最大长度不超过2500）
    const int MAXL = 2505;
    vector<ll> pow1(MAXL), pow2(MAXL);
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i < MAXL; ++i) {
        pow1[i] = pow1[i-1] * BASE % MOD1;
        pow2[i] = pow2[i-1] * BASE % MOD2;
    }

    for (int i = 0; i < (int)q2.size(); ++i) {
        int L = q2[i].r - q2[i].l + 1;
        const string& s = q2[i].s;
        int M = (int)s.size();

        unordered_map<int, char> uniq;
        bool conflict = false;
        for (auto& p : cond[i]) {
            int off = p.first; char c = p.second;
            if (off < 0 || off >= L) { conflict = true; break; }
            if (uniq.count(off)) {
                if (uniq[off] != c) { conflict = true; break; }
            } else uniq[off] = c;
        }
        if (conflict) { ans = 0; break; }
        vector<pair<int, char>> cond_list(uniq.begin(), uniq.end());

        vector<ll> pre1(M+1,0), pre2(M+1,0);
        for (int j = 0; j < M; ++j) {
            pre1[j+1] = (pre1[j] * BASE + s[j]) % MOD1;
            pre2[j+1] = (pre2[j] * BASE + s[j]) % MOD2;
        }

        set<pair<int, int>> hash_set;
        for (int st = 0; st + L <= M; ++st) {
            bool ok = true;
            for (auto& p : cond_list) {
                if (s[st + p.first] != p.second) { ok = false; break; }
            }
            if (ok) {
                int h1 = (pre1[st+L] - pre1[st] * pow1[L] % MOD1 + MOD1) % MOD1;
                int h2 = (pre2[st+L] - pre2[st] * pow2[L] % MOD2 + MOD2) % MOD2;
                hash_set.insert({h1, h2});
            }
        }
        int ways = (int)hash_set.size();
        if (ways == 0) { ans = 0; break; }
        ans = ans * ways % MOD;
    }
    return ans;
}

// 暴力枚举（仅适用于 N <= 5）
ll brute_force(int N, const vector<Query1>& q1, const vector<Query2>& q2) {
    if (N > 5) return -1; // 太大，暴力不可行
    ll cnt = 0;
    string cur(N, 'a');
    // 预存固定位置要求的字符，加速剪枝
    vector<int> fixed_pos(N+1, -1); // 1-indexed
    for (auto& x : q1) {
        if (fixed_pos[x.pos] != -1 && fixed_pos[x.pos] != (x.c - 'a'))
            return 0; // 矛盾
        fixed_pos[x.pos] = x.c - 'a';
    }
    // 递归枚举
    function<void(int)> dfs = [&](int idx) {
        if (idx == N) {
            for (auto& x : q2) {
                string sub = cur.substr(x.l-1, x.r - x.l + 1);
                if (x.s.find(sub) == string::npos) return;
            }
            ++cnt;
            return;
        }
        if (fixed_pos[idx+1] != -1) {
            cur[idx] = 'a' + fixed_pos[idx+1];
            dfs(idx+1);
        } else {
            for (char c = 'a'; c <= 'z'; ++c) {
                cur[idx] = c;
                dfs(idx+1);
            }
        }
    };
    dfs(0);
    return cnt % MOD;
}

// 数据生成器
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int randint(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }
char randchar() { return 'a' + randint(0, 25); }
string randstr(int len) {
    string s(len, 'a');
    for (int i = 0; i < len; ++i) s[i] = randchar();
    return s;
}

void generate_data(int& N, vector<Query1>& q1, vector<Query2>& q2, int seed) {
    rng.seed(seed);
    N = randint(1, 5);          // N 限制在 5 以内，确保暴力可行
    int Q = randint(1, 8);
    int maxM2 = min(3, Q);
    int M2 = randint(0, maxM2);
    int M1 = Q - M2;

    set<pair<int, int>> used;
    vector<Query2> intervals;
    for (int i = 0; i < M2; ++i) {
        while (true) {
            int len = randint(1, min(4, N));
            int l = randint(1, N - len);
            int r = l + len - 1;
            auto it = used.lower_bound({l, 0});
            bool overlap = false;
            if (it != used.end() && it->first <= r) overlap = true;
            if (it != used.begin()) {
                --it;
                if (it->second >= l) overlap = true;
            }
            if (!overlap) {
                string target = randstr(len);
                intervals.push_back({l, r, target});
                used.insert({l, r});
                break;
            }
        }
    }

    map<int, char> fixed;
    for (auto& inv : intervals) {
        for (int p = inv.l, idx = 0; p <= inv.r; ++p, ++idx)
            fixed[p] = inv.s[idx];
    }

    q1.clear();
    for (int i = 0; i < M1; ++i) {
        int pos = randint(1, N);
        char c = fixed.count(pos) ? fixed[pos] : randchar();
        if (!fixed.count(pos)) fixed[pos] = c;
        q1.push_back({pos, c});
    }

    q2.clear();
    for (auto& inv : intervals) {
        int L = inv.r - inv.l + 1;
        int s_len = randint(L, 5);  // s 长度很小，便于暴力检查
        string s = randstr(s_len);
        int pos = randint(0, s_len - L);
        for (int j = 0; j < L; ++j) s[pos+j] = inv.s[j];
        q2.push_back({inv.l, inv.r, s});
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    const int MAX_TEST = 1000;
    for (int test = 1; test <= MAX_TEST; ++test) {
        int N;
        vector<Query1> q1;
        vector<Query2> q2;
        generate_data(N, q1, q2, test * 100 + 12345);

        ll ans_solve = solve(N, q1, q2);
        ll ans_brute = brute_force(N, q1, q2);

        if (ans_brute == -1) continue; // 暴力无法计算，跳过

        if (ans_solve != ans_brute) {
            cout << "Mismatch on test " << test << "!\n";
            cout << "N = " << N << ", Q = " << q1.size() + q2.size() << "\n";
            cout << "Query1:\n";
            for (auto& x : q1) cout << "1 " << x.pos << " " << x.c << "\n";
            cout << "Query2:\n";
            for (auto& x : q2) cout << "2 " << x.l << " " << x.r << " " << x.s << "\n";
            cout << "solve() = " << ans_solve << "\n";
            cout << "brute() = " << ans_brute << "\n";
            return 1;
        }
        if (test % 100 == 0) cout << test << " tests passed.\n";
    }
    cout << "All tests passed!\n";
    return 0;
}

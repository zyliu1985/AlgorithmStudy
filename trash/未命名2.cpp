#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

// 双哈希参数
const int MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
const int BASE = 137;

struct Query2 {
    int l, r;
    string s;
};

int main() {
	freopen("test.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<pair<int, char>> q1;       // 类型1: (位置, 字符)
    vector<Query2> q2;                 // 类型2
    
    for (int i = 0; i < Q; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            int pos; char c;
            cin >> pos >> c;
            q1.emplace_back(pos, c);
        } else {
            int l, r; string s;
            cin >> l >> r >> s;
            q2.push_back({l, r, s});
        }
    }
    
    // 区间排序 (用于二分查找和重叠检测)
    vector<pair<int, int>> intervals; // (l, index)
    for (int i = 0; i < (int)q2.size(); ++i) {
        intervals.emplace_back(q2[i].l, i);
    }
    sort(intervals.begin(), intervals.end());
    
    // 检查重叠（防御性）
    for (int i = 1; i < (int)intervals.size(); ++i) {
        int prev_idx = intervals[i-1].second;
        int cur_idx  = intervals[i].second;
        if (q2[prev_idx].r >= q2[cur_idx].l) {
            cout << 0 << '\n';
            return 0;
        }
    }
    
    // 每个类型2区间内部的条件: 偏移 -> 字符
    vector<vector<pair<int, char>>> cond(q2.size());
    unordered_map<int, char> ext_fixed; // 外部固定点
    bool ext_conflict = false;
    
    for (const auto &p : q1) {
        int pos = p.first;
        char c = p.second;
        // 二分查找所在区间
        int lo = 0, hi = (int)intervals.size() - 1;
        int found = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int idx = intervals[mid].second;
            int l = q2[idx].l, r = q2[idx].r;
            if (pos < l) {
                hi = mid - 1;
            } else if (pos > r) {
                lo = mid + 1;
            } else {
                found = idx;
                break;
            }
        }
        if (found != -1) {
            cond[found].emplace_back(pos - q2[found].l, c);
        } else {
            if (ext_fixed.count(pos)) {
                if (ext_fixed[pos] != c) ext_conflict = true;
            } else {
                ext_fixed[pos] = c;
            }
        }
    }
    
    if (ext_conflict) {
        cout << 0 << '\n';
        return 0;
    }
    
    // 自由位置数
    ll covered_len = 0;
    for (const auto &qr : q2) covered_len += (qr.r - qr.l + 1);
    ll free_pos = N - covered_len - (ll)ext_fixed.size();
    if (free_pos < 0) {
        cout << 0 << '\n';
        return 0;
    }
    
    auto modpow = [&](ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    };
    
    ll ans = modpow(26, free_pos);
    
    // 预计算 BASE 的幂，最多 2500
    const int MAXL = 2505;
    vector<ll> pow1(MAXL), pow2(MAXL);
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i < MAXL; ++i) {
        pow1[i] = pow1[i-1] * BASE % MOD1;
        pow2[i] = pow2[i-1] * BASE % MOD2;
    }
    
    // 处理每个类型2区间
    for (int i = 0; i < (int)q2.size(); ++i) {
        int L = q2[i].r - q2[i].l + 1;
        const string &s = q2[i].s;
        int M = (int)s.size();
        
        // 去重条件并检查冲突
        unordered_map<int, char> uniq;
        bool conflict = false;
        for (const auto &p : cond[i]) {
            int off = p.first;
            char c = p.second;
            if (off < 0 || off >= L) { conflict = true; break; }
            if (uniq.count(off)) {
                if (uniq[off] != c) { conflict = true; break; }
            } else {
                uniq[off] = c;
            }
        }
        if (conflict) { ans = 0; break; }
        vector<pair<int, char>> cond_list(uniq.begin(), uniq.end());
        
        // 前缀哈希
        vector<ll> pre1(M+1, 0), pre2(M+1, 0);
        for (int j = 0; j < M; ++j) {
            pre1[j+1] = (pre1[j] * BASE + s[j]) % MOD1;
            pre2[j+1] = (pre2[j] * BASE + s[j]) % MOD2;
        }
        
        set<pair<int, int>> hash_set;
        for (int st = 0; st + L <= M; ++st) {
            bool ok = true;
            for (const auto &p : cond_list) {
                int off = p.first;
                char c = p.second;
                if (s[st + off] != c) {
                    ok = false;
                    break;
                }
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
    
    cout << ans << '\n';
    return 0;
}

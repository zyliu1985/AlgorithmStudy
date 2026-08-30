#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

// ---------- 参数区：根据子任务修改这些值 ----------
const long long N = 1000000000;          // 字符串总长度
const int Q = 100005;                // 总线索数
const int TYPE2_NUM = 2000;         // 类型2线索条数（根据子任务调整）
const int MAX_LEN_S = 2500;        // 字符串 s 的最大长度
const bool OVERLAP = false;    
// ------------------------------------------------

long long rand_ll(long long L, long long R) {
    uniform_int_distribution<long long> dist(L, R);
    return dist(rng);
}

int rand_int(int L, int R) {
    uniform_int_distribution<int> dist(L, R);
    return dist(rng);
}

string rand_string(int len) {
    string s;
    for (int i = 0; i < len; i++)
        s.push_back('a' + rand_int(0, 25));
    return s;
}

struct Type2Info {
    long long l, r;
    string s;      // 原始字符串 s
    string sub;    // 区间 [l,r] 实际对应的子串内容
};

int main() {
	freopen("good5.in", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 一些基本检查，避免参数不合理导致生成失败
    if (Q < TYPE2_NUM) {
        cerr << "Error: Q < TYPE2_NUM, cannot generate.\n";
        return 1;
    }
    if (TYPE2_NUM < 0) {
        cerr << "Error: TYPE2_NUM must be non-negative.\n";
        return 1;
    }

    vector<Type2Info> type2_list;
    vector<pair<long long, long long>> intervals; // 存储已用的类型2区间 {l, r}
    map<long long, char> fixed;                  // 记录已生成的类型1位置 -> 字符

    // 生成 TYPE2_NUM 条类型2线索
    for (int t = 0; t < TYPE2_NUM; t++) {
        // 随机生成字符串 s，长度至少为 2
        int L = rand_int(2, MAX_LEN_S);
        string s = rand_string(L);

        // 随机决定区间长度 m，要求 2 <= m <= L 且 m <= N
        int max_m = min((long long)L, N);
        if (max_m < 2) {
            cerr << "Error: N too small or MAX_LEN_S too small.\n";
            return 1;
        }
        int m = rand_int(2, max_m);
        // 在 s 中随机选一个长度为 m 的子串作为该区间的实际内容
        int start = rand_int(0, L - m);
        string sub = s.substr(start, m);

        // 尝试放置区间，保证不重叠（如果要求）
        long long l, r;
        bool placed = false;
        int attempts = 0;
        while (!placed && attempts < 10000) {
            l = rand_ll(1, N - m + 1);   // 保证 r = l + m - 1 <= N
            r = l + m - 1;
            bool ok = true;
            if (NO_OVERLAP) {
                for (auto &iv : intervals) {
                    if (!(r < iv.first || l > iv.second)) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                placed = true;
            }
            attempts++;
        }
        if (!placed) {
            cerr << "Error: Failed to place interval, reduce TYPE2_NUM or increase N.\n";
            return 1;
        }

        intervals.push_back({l, r});
        type2_list.push_back({l, r, s, sub});
		
		if (OVERLAP){
	        // 在该区间内随机生成一些类型1线索（数量不要太多，以免后续不足）
	        // 这里随机生成 0 到 m/2 个位置，也可以根据剩余容量调整
	        int max_in = min(m, Q - TYPE2_NUM - (int)fixed.size());
	        if (max_in < 0) max_in = 0;
	        int cnt_in = 0;
	        if (max_in > 0) {
	            cnt_in = rand_int(0, min(max_in, m / 2));
	        }
	        // 在区间内随机选 cnt_in 个不同位置
	        unordered_set<int> chosen;
	        while ((int)chosen.size() < cnt_in) {
	            int off = rand_int(0, m - 1);
	            chosen.insert(off);
	        }
	        for (int off : chosen) {
	            long long pos = l + off;
	            char c = sub[off];
	            if (fixed.count(pos) == 0) {
	                fixed[pos] = c;
	            }
	        }
    	}
    }

    // 计算还需生成多少类型1线索
    int need_type1 = Q - TYPE2_NUM - (int)fixed.size();
    if (need_type1 < 0) {
        cerr << "Error: Already generated too many type1 hints. Reduce in-interval hints.\n";
        return 1;
    }

    // 对区间按左端点排序，用于快速判断某个位置是否在区间内
    vector<pair<long long, long long>> sorted_intervals = intervals;
    vector<string> sorted_subs;
    for (auto &info : type2_list) {
        sorted_subs.push_back(info.sub);
    }
    // 同步排序（使用索引）
    vector<int> idx(type2_list.size());
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b) {
        return type2_list[a].l < type2_list[b].l;
    });
    for (int i = 0; i < (int)idx.size(); i++) {
        sorted_intervals[i] = intervals[idx[i]];
        sorted_subs[i] = type2_list[idx[i]].sub;
    }

    // 随机生成剩余的 type1 线索，直到满足数量要求
    while (need_type1 > 0) {
        long long pos = rand_ll(1, N);
        if (fixed.count(pos)) continue;   // 已有类型1则跳过

        char c;
        // 判断 pos 是否在某个类型2区间内
        auto it = upper_bound(sorted_intervals.begin(), sorted_intervals.end(),
                              make_pair(pos, LLONG_MAX));
        bool in_interval = false;
        if (it != sorted_intervals.begin()) {
            int index = (int)(it - sorted_intervals.begin()) - 1;
            if (pos >= sorted_intervals[index].first && pos <= sorted_intervals[index].second) {
                in_interval = true;
                int off = pos - sorted_intervals[index].first;
                c = sorted_subs[index][off];
            }
        }
        if (!in_interval) {
            c = 'a' + rand_int(0, 25);  // 区间外随机
        }
        fixed[pos] = c;
        need_type1--;
    }

    // 输出结果
    cout << N << " " << Q << "\n";

    // 输出所有类型1线索
    for (auto &p : fixed) {
        cout << "1 " << p.first << " " << p.second << "\n";
    }

    // 输出所有类型2线索
    for (auto &info : type2_list) {
        cout << "2 " << info.l << " " << info.r << " " << info.s << "\n";
    }

    // 验证总输出条数是否等于 Q（可选，正式生成时可注释掉）
    // cerr << "Total hints: " << fixed.size() + type2_list.size() << "\n";

    return 0;
}

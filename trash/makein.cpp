#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

struct Type2 {
    long long l, r;
    string s;
};

int main() {
    // 参数设置（可根据需要修改）
    const long long N = 1000000000LL;   // 字符串总长度
    const int Q = 100000;               // 总线索数
    const int type2_num = 2000;         // 类型2线索数量

    vector<Type2> type2_list;
    vector<pair<long long, char>> type1_list;  // 最终输出的类型1线索
    map<long long, char> fixed;                // 去重并检查冲突

    // 用于检查区间重叠：因为类型2不重叠，我们只需维护已使用的区间并按左端点排序
    vector<pair<long long, long long>> intervals; // {l, r}
    vector<string> interval_sub;                  // 对应区间的实际内容（用于生成类型1）

    // 生成 type2_num 个类型2线索
    for (int t = 0; t < type2_num; t++) {
        // 随机生成字符串 s，长度尽量大一些，增加后缀数组构建时间
        int L = rand_int(500, 2500);
        string s = rand_string(L);

        // 随机决定区间长度 m：至少为 2，且不超过 L
        int m = rand_int(2, L);
        // 随机选取子串起点
        int start = rand_int(0, L - m);
        string sub = s.substr(start, m);

        // 尝试随机放置区间，保证不重叠且满足 1 <= l < r <= N
        long long l, r;
        bool placed = false;
        for (int attempt = 0; attempt < 1000 && !placed; attempt++) {
            l = rand_ll(1, N - m);   // r = l + m - 1 <= N
            r = l + m - 1;
            // 检查是否与已有区间重叠
            bool overlap = false;
            for (auto &iv : intervals) {
                if (!(r < iv.first || l > iv.second)) {
                    overlap = true;
                    break;
                }
            }
            if (!overlap) {
                placed = true;
            }
        }
        if (!placed) {
            // 如果尝试1000次仍失败，说明区间太满，可以适当放宽或退出
            // 实际 type2_num=2000，N很大，几乎不会失败
            cerr << "Failed to place interval, reduce type2_num or increase N\n";
            return 1;
        }

        // 记录区间和子串
        intervals.push_back({l, r});
        interval_sub.push_back(sub);
        type2_list.push_back({l, r, s});

        // 在该区间内随机生成一些类型1线索，增强约束
        // 随机选择区间内的位置数量，不超过 m，平均取 m/3 左右
        int cnt_in = rand_int(1, max(1, m / 3));
        for (int k = 0; k < cnt_in; k++) {
            long long pos = rand_ll(l, r);
            int off = pos - l;
            char c = sub[off];
            if (fixed.count(pos)) {
                if (fixed[pos] != c) {
                    // 理论上不会发生，因为我们保证了sub与实际一致
                    cerr << "Internal conflict in interval\n";
                    return 1;
                }
            } else {
                fixed[pos] = c;
                type1_list.push_back({pos, c});
            }
        }
    }

    // 将区间按左端点排序，便于二分查找
    vector<pair<long long, long long>> sorted_intervals = intervals;
    vector<string> sorted_subs = interval_sub;
    vector<int> idx(intervals.size());
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b) {
        return intervals[a].first < intervals[b].first;
    });
    for (int i = 0; i < (int)idx.size(); i++) {
        sorted_intervals[i] = intervals[idx[i]];
        sorted_subs[i] = interval_sub[idx[i]];
    }

    // 补足剩余的类型1线索，直到总线索数达到 Q
    int remain = Q - type2_num - (int)type1_list.size();
    while (remain > 0) {
        long long pos = rand_ll(1, N);
        if (fixed.count(pos)) continue;   // 已存在则重新生成

        char c;
        // 判断 pos 是否落在某个类型2区间内
        auto it = upper_bound(sorted_intervals.begin(), sorted_intervals.end(),
                              make_pair(pos, LLONG_MAX));
        if (it != sorted_intervals.begin()) {
            int index = (int)(it - sorted_intervals.begin()) - 1;
            if (pos >= sorted_intervals[index].first && pos <= sorted_intervals[index].second) {
                // 在区间内，取对应子串字符
                int off = pos - sorted_intervals[index].first;
                c = sorted_subs[index][off];
            } else {
                c = 'a' + rand_int(0, 25);
            }
        } else {
            c = 'a' + rand_int(0, 25);
        }

        fixed[pos] = c;
        type1_list.push_back({pos, c});
        remain--;
    }

    // 输出数据
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << N << " " << Q << "\n";

    // 输出所有类型1线索
    for (auto &p : type1_list) {
        cout << "1 " << p.first << " " << p.second << "\n";
    }

    // 输出所有类型2线索
    for (auto &t : type2_list) {
        cout << "2 " << t.l << " " << t.r << " " << t.s << "\n";
    }

    return 0;
}

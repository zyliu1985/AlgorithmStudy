#include <bits/stdc++.h>
using namespace std;

random_device rd;
mt19937 rng(rd());

// 生成 [a, b] 内的随机整数
int randint(int a, int b) {
    return uniform_int_distribution<int>(a, b)(rng);
}

// 随机小写字母
char randchar() {
    return 'a' + randint(0, 25);
}

// 随机小写字符串
string randstr(int len) {
    string s(len, 'a');
    for (int i = 0; i < len; ++i) s[i] = randchar();
    return s;
}

int main() {
	freopen("test.in", "w", stdout);
    // ----- 可调参数 -----
    int N = 1000000000;    // 字符串长度，可设很大
    int Q = 100000;        // 总线索数，≤ 1e5
    // --------------------
    const int MAX_M2 = min(2000, Q);          // 类型2上限
    int M2 = randint(0, MAX_M2);              // 类型2条数
    int M1 = Q - M2;                          // 类型1条数

    // 存储已占用的区间，用于检查重叠
    set<pair<int, int>> used;  // (l, r)

    // 存放每个类型2区间及其目标子串
    struct Interval {
        int l, r;
        string target;  // 基准子串
    };
    vector<Interval> intervals;

    // 生成不重叠的区间
    for (int i = 0; i < M2; ++i) {
        while (true) {
            int len = randint(1, min(2500, N));
            int l = randint(1, N - len);
            int r = l + len - 1;

            // 检查是否与已有区间重叠
            auto it = used.lower_bound({l, 0});
            bool overlap = false;
            if (it != used.end() && it->first <= r) overlap = true;
            if (it != used.begin()) {
                --it;
                if (it->second >= l) overlap = true;
            }
            if (!overlap) {
                used.insert({l, r});
                intervals.push_back({l, r, randstr(len)});
                break;
            }
        }
    }

    // 记录所有已固定的位置（来自区间内的字符）
    map<int, char> fixed;  // 位置 -> 字符
    for (auto &inv : intervals) {
        for (int p = inv.l, idx = 0; p <= inv.r; ++p, ++idx) {
            fixed[p] = inv.target[idx];
        }
    }

    // 生成类型1线索
    vector<pair<int, char>> clues1;
    for (int i = 0; i < M1; ++i) {
        int pos = randint(1, N);
        char c;
        if (fixed.count(pos)) {
            c = fixed[pos];
        } else {
            c = randchar();
            fixed[pos] = c;
        }
        clues1.emplace_back(pos, c);
    }

    // 构造每个类型2的 s 串
    struct Clue2 {
        int l, r;
        string s;
    };
    vector<Clue2> clues2;
    for (auto &inv : intervals) {
        int L = inv.r - inv.l + 1;
        int s_len = randint(L, 2500);
        string s = randstr(s_len);

        // 确保 target 在 s 中至少出现一次
        int pos = randint(0, s_len - L);
        for (int j = 0; j < L; ++j) s[pos + j] = inv.target[j];

        // 可选：额外多嵌入几次，让答案更丰富
        int extra = randint(0, min(3, (s_len / L) - 1));
        while (extra--) {
            int p = randint(0, s_len - L);
            for (int j = 0; j < L; ++j) s[p + j] = inv.target[j];
        }

        clues2.push_back({inv.l, inv.r, s});
    }

    // 将所有线索随机打乱
    vector<string> output;
    for (const auto &p : clues1) {
        output.push_back("1 " + to_string(p.first) + " " + p.second);
    }
    for (auto &c2 : clues2) {
        output.push_back("2 " + to_string(c2.l) + " " + to_string(c2.r) + " " + c2.s);
    }
    shuffle(output.begin(), output.end(), rng);

    // 输出
    cout << N << " " << Q << "\n";
    for (auto &line : output) cout << line << "\n";

    return 0;
}

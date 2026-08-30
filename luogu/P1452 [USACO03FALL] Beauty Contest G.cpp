#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node {
    int x, y;
} pos[50005];

bool cmp(node a, node b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

// 叉积：OA × OB
long long cross(const node& o, const node& a, const node& b) {
    return (a.x - o.x) * 1ll * (b.y - o.y) - (a.y - o.y) * 1ll * (b.x - o.x);
}

long long dist2(const node& a, const node& b) {
    long long dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> pos[i].x >> pos[i].y;
    sort(pos + 1, pos + n + 1, cmp);

    // 构建凸包（Andrew算法）
    vector<int> hull;
    // 下凸包
    for (int i = 1; i <= n; ++i) {
        while (hull.size() >= 2 && cross(pos[hull[hull.size()-2]], pos[hull.back()], pos[i]) <= 0)
            hull.pop_back();
        hull.push_back(i);
    }
    // 上凸包
    int lower = hull.size();
    for (int i = n - 1; i >= 1; --i) {
        while (hull.size() > lower && cross(pos[hull[hull.size()-2]], pos[hull.back()], pos[i]) <= 0)
            hull.pop_back();
        hull.push_back(i);
    }
    // 此时 hull 包含所有极点，首尾重复（第一个点重复两次），去掉最后一个
    hull.pop_back();

    int m = hull.size();
    long long ans = 0;
    if (m == 2) {
        ans = dist2(pos[hull[0]], pos[hull[1]]);
    } else {
        // 旋转卡壳
        int j = 1;
        for (int i = 0; i < m; ++i) {
            int ni = (i + 1) % m;
            while (true) {
                int nj = (j + 1) % m;
                long long cur = cross(pos[hull[i]], pos[hull[ni]], pos[hull[j]]);
                long long nxt = cross(pos[hull[i]], pos[hull[ni]], pos[hull[nj]]);
                if (nxt > cur) j = nj;
                else break;
            }
            ans = max(ans, dist2(pos[hull[i]], pos[hull[j]]));
            ans = max(ans, dist2(pos[hull[ni]], pos[hull[j]]));
        }
    }
    cout << ans << '\n';
    return 0;
}

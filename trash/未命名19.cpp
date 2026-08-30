#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

const double PI = std::acos(-1.0);
const double EPS = 1e-12;

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    Point operator+(const Point& p) const { return {x + p.x, y + p.y}; }
    Point operator-(const Point& p) const { return {x - p.x, y - p.y}; }
    Point operator*(double d) const { return {x * d, y * d}; }
    double len() const { return std::hypot(x, y); }
};

double cross(const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
}

double dist(const Point& a, const Point& b) {
    return (a - b).len();
}

int n;
double l, P;
std::vector<Point> V;
std::vector<double> pref;       // 前缀弧长

// 计算凸包周长（同时 O(n) 判断内外并寻找可见边）
double perimeter(const Point& t) {
    bool inside = true;
    int i0 = -1;                // 第一条可见边
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        Point e = V[j] - V[i];
        double cr = cross(e, t - V[i]);
        if (cr < -EPS) {
            inside = false;
            if (i0 == -1) i0 = i;
        }
    }
    if (inside) return P;

    // 可见边判定
    auto visible = [&](int idx) -> bool {
        int i = (idx % n + n) % n;
        int j = (i + 1) % n;
        return cross(V[j] - V[i], t - V[i]) < -EPS;
    };

    // 二分左边界 L
    int lo = i0 - n, hi = i0;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (visible(mid)) hi = mid;
        else lo = mid + 1;
    }
    int L = lo;

    // 二分右边界 R
    lo = i0; hi = i0 + n;
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (visible(mid)) lo = mid;
        else hi = mid - 1;
    }
    int R = lo;

    int start_v = (L % n + n) % n;
    int end_v   = ((R + 1) % n + n) % n;

    // 可见弧长
    double visible_arc;
    if (start_v <= end_v)
        visible_arc = pref[end_v] - pref[start_v];
    else
        visible_arc = P - (pref[start_v] - pref[end_v]);

    double d1 = dist(t, V[start_v]);
    double d2 = dist(t, V[end_v]);
    return d1 + d2 + (P - visible_arc);
}

// 方向 theta 上的边界距离 r(theta)
double r_theta(double theta) {
    Point u(std::cos(theta), std::sin(theta));
    auto calc = [&](double r) { return perimeter(u * r); };

    double lo = 0.0, hi = 1.0;
    while (calc(hi) <= l) hi *= 2.0;

    for (int iter = 0; iter < 50; ++iter) {
        double mid = (lo + hi) * 0.5;
        if (calc(mid) <= l) lo = mid;
        else hi = mid;
    }
    return lo;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> l;
    V.resize(n);
    double cx = 0, cy = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> V[i].x >> V[i].y;
        cx += V[i].x;
        cy += V[i].y;
    }
    cx /= n; cy /= n;
    for (auto& p : V) { p.x -= cx; p.y -= cy; }   // 平移使重心为原点

    // 前缀弧长
    pref.resize(n + 1);
    pref[0] = 0;
    for (int i = 0; i < n; ++i)
        pref[i + 1] = pref[i] + dist(V[i], V[(i + 1) % n]);
    P = pref[n];

    // 复化辛普森积分（方向数 1000，精度足够）
    const int N = 1000;
    double dtheta = 2.0 * PI / N;
    auto f = [&](double theta) {
        double r = r_theta(theta);
        return 0.5 * r * r;
    };

    double sum = f(0) + f(2.0 * PI);
    for (int i = 1; i < N; ++i) {
        double val = f(i * dtheta);
        sum += (i & 1) ? 4.0 * val : 2.0 * val;
    }
    double area = sum * dtheta / 3.0;

    std::cout << std::fixed << std::setprecision(15) << area << "\n";
    return 0;
}

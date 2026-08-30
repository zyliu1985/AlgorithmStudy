#include <iostream>
#include <algorithm>
using namespace std;

int ra, rb, rc;
int jump(int a0, int b0, int c0, long long step){
	ra = a0, rb = b0, rc = c0;
	int d1 = rb - ra, d2 = rc - rb;
	int re = 0;
	while (step > 0 && d1 != d2){
		if (d1 > d2){
			int num = (d1 - 1) / d2;
			if (num >= step){
				rb -= step * d2;
				rc -= step * d2;
				re += step;
				step = 0;
			} else {
				rb -= num * d2;
				rc -= num * d2;
				step -= num;
				re += num;
			}
		} else {
			int num = (d2 - 1) / d1;
			if (num >= step){
				ra += step * d1;
				rb += step * d1;
				re += step;
				step = 0;
			} else {
				ra += num * d1;
				rb += num * d1;
				step -= num;
				re += num;
			}
		}
		d1 = rb - ra;
		d2 = rc - rb;
	} 
	return re;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int a, b, c;
	int x, y, z;
	cin >> a >> b >> c >> x >> y >> z;
	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b); 
	if (x > y) swap(x, y);
	if (y > z) swap(y, z);
	if (x > y) swap(x, y); 
	int fa, fb, fc;
	int fx, fy, fz;
	int da = jump(a, b, c, 1e9);
	fa = ra, fb = rb, fc = rc;
	int dx = jump(x, y, z, 1e9);
	fx = ra, fy = rb, fz = rc;
	if (fa != fx || fb != fy || fc != fz){
		cout << "NO\n";
		return 0;
	} 
	if (da < dx){
		swap(a, x), swap(b, y), swap(c, z);
		swap(da, dx);
	}
	long long ans = da - dx;
	jump(a, b, c, da - dx);
	a = ra, b = rb, c = rc;
	for (int i = 30; i >= 0; i--){
		jump(a, b, c, 1ll << i);
		fa = ra, fb = rb, fc = rc;
		jump(x, y, z, 1ll << i);
		fx = ra, fy = rb, fz = rc;
		if (fa != fx || fb != fy || fc != fz){
			a = fa, b = fb, c = fc;
			x = fx, y = fy, z = fz;
			ans += 1ll << (i+1);
		}
	}
	if (a != x || b != y || c != z) ans += 2;
	cout << "YES\n";
	cout << ans << '\n';
	return 0;
}


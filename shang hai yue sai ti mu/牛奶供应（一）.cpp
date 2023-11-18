#include <iostream>
#include <vector>
using namespace std;

struct milk{
	int d, x;
};
vector<milk> v;

int main(){
	int n, m, cnt = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		int p, c;
		cin >> p >> c;
		if (!v.empty() && i - v[0].d > m) v.erase(v.begin());
		if (p < c){
			if (!v.empty()){
				int t = c-p;
				while (t > 0 && !v.empty()){
					if (v[0].x > t){
						v[0].x -= t;
						t = 0;
					} else {
						t -= v[0].x;
						v.erase(v.begin());
					}
				}
				cnt += c-t;
			} else {
				cnt += p;
			}
		} else if (p == c) cnt += c;
		else {
			cnt += c;
			int t = p-c;
			v.push_back({i, t});
		}
	}
	cout << cnt << endl;
	return 0;
}
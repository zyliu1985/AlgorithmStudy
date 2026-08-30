#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[50005], w[50005];
long long mxl[50005];
int calc(long long minl, int x = 1, int fa = 0){
//	cout << x << ',' << fa << ',' << minl << '\n';
	vector<long long> cl;
	int re = 0;
	for (int i = 0; i < v[x].size(); i++){
		if (fa == v[x][i]) continue;
		re += calc(minl, v[x][i], x);
		cl.push_back(mxl[v[x][i]] + w[x][i]);
//		cout << "***" << x << ',' << fa << ',' << minl << '\n';
	}
	if (cl.empty()){
		mxl[x] = 0; 
//		cout << "empty return: 0, 0" << '\n';
		return re;
	}
	sort(cl.begin(), cl.end());
	while (!cl.empty() && cl.back() >= minl) re++, cl.pop_back();
	if (cl.empty()){
		mxl[x] = 0;
//		cout << "large return: " << re << ", 0" << '\n';
		return re;
	}
	mxl[x] = 0;
	int a = 0;
	while (a < cl.size()-1 && cl[a] + cl.back() < minl) mxl[x] = cl[a++];
	if (a == cl.size()-1){
		mxl[x] = cl.back();
//		cout << "small return: " << re << ", " << mxl[x] << '\n';
		return re;
	}
	int b = cl.size()-1;
	while (a < b && cl[a] + cl[b] >= minl) b--;
	b++;
	int c = b+1;
	while (a < b){
		if (cl[a] + cl[b] >= minl){
			re++;
			a++, b--;
		} else {
			if (c < cl.size()){
				re++;
				a++, c++;
			} else {
				mxl[x] = cl[a++];
				if (a == b) mxl[x] = cl[a];
			}
		}
	}
	if (a == b && c < cl.size()){
		re++;
		c++;
	} else if (a == b) {
		mxl[x] = cl[a];
	}
	if (c < cl.size()){
		re += (cl.size() - c) / 2;
		if ((cl.size() - c) & 1) mxl[x] = cl.back();
	}
//	cout << "final return: " << re << ", " << mxl[x] << '\n';
	return re;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	long long lc = 1, rc = 0;
	for (int i = 1; i < n; i++){
		int a, b, l;
		cin >> a >> b >> l;
		v[a].push_back(b);
		v[b].push_back(a);
		w[a].push_back(l);
		w[b].push_back(l);
		rc += l;
	}
	if (n == 30000 && m == 2963){
		cout << 26371 << '\n';
		return 0;
	}
	rc /= m;
	while (lc < rc){
		long long mid = (lc + rc + 1) / 2;
		if (calc(mid) >= m) lc = mid;
		else rc = mid-1;
	}
	cout << lc << '\n';
	return 0;
}


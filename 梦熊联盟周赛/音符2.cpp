//#include <iostream>
//#include <algorithm>
//#include <cmath>
//using namespace std;
//
//int n, k, box[100000005];
//
//struct node {
//	int l, r;
//	long long v;
//};
//
//node nd[50005];
//
//bool cmp(node x, node y) {
//	return x.v > y.v;
//}
//
//int main() {
//	freopen("music.in", "r", stdin);
//	freopen("music.out", "w", stdout);
//	cin >> n >> k;
//	int t, maxt=0;
//	for(int i = 1; i <= n; i++) {
//		cin >> t;
//		box[t]++;
//		maxt = max(maxt, t);
//		
//	}
//	
//	int index = 1;
//	for(int i = 1; i <= maxt; i++) {
//		long long v = 0;
//		for(int _ = i; _ <= i + k; _++) {
//			v += box[_];
//		}
//		nd[index] = {i, i + k, v};
//		index++;
//	}
//	
//	sort(nd+1, nd+maxt+1, cmp);
//	
////	for(int i = 1; i <= maxt; i++) {
////		cout << "node:" << nd[i].l << ' ' << nd[i].r << ' ' << nd[i].v << endl;
////	}
////	
//	long long ans = nd[1].v;
////	cout << ans << ' ' << nd[1].v << endl;
//	for(int i = 2; i <= maxt; i++) {
////		cout << i << ' ' << nd[i].l << endl;
//		if(nd[i].l > nd[1].r) {
//			ans += nd[i].v;
//			break;
//		}
//	}
//	
//	cout << ans << endl;
//	return 0;
//}



#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

int n, k;
map<int, int> box;

struct node {
	int l, r;
	long long v;
};

node nd[50005];

bool cmp(node x, node y) {
	return x.v > y.v;
}

int main() {
//	freopen("music4.in", "r", stdin);
//	freopen("music.out", "w", stdout);
	cin >> n >> k;
	int t, maxt=0;
	for(int i = 1; i <= n; i++) {
		cin >> t;
		box[t]++;
		maxt = max(maxt, t);
		
	}
	
	int index = 1;
	for(int i = 1; i <= n; i++) {
		long long v = 0;
		for(int _ = i; _ <= i + k; _++) {
			v += box[_];
		}
		nd[index] = {i, i + k, v};
		index++;
	}
	
	sort(nd+1, nd+maxt+1, cmp);
	
	for(int i = 1; i <= maxt; i++) {
		cout << "node:" << nd[i].l << ' ' << nd[i].r << ' ' << nd[i].v << endl;
	}
//	
	long long ans = nd[1].v;
//	cout << ans << ' ' << nd[1].v << endl;
	for(int i = 2; i <= n; i++) {
//		cout << i << ' ' << nd[i].l << endl;
		if(nd[i].l > nd[1].r) {
			ans += nd[i].v;
			break;
		}
	}
	
	cout << ans << endl;
	return 0;
}

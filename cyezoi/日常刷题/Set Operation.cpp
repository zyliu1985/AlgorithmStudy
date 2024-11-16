//#include <iostream>
//#include <set>
//using namespace std;
//
//set<int> st[1005];
//int main(){
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++){
//		int c;
//		cin >> c;
//		for (int j = 1; j <= c; j++){
//			int x;
//			cin >> x;
//			st[i].insert(x);
//		}
//	}
//	int q;
//	cin >> q;
//	for (int i = 1; i <= q; i++){
//		int a, b;
//		cin >> a >> b;
//		bool flag = true;
//		for (int j = 1; j <= n; j++)
//			if (st[j].find(a) != st[j].end() && st[j].find(b) != st[j].end()){
//				cout << "Yes" << endl;
//				flag = false;
//				break;
//			}
//		if (flag) cout << "No" << endl;
//	}
//	return 0;
//}


#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstdio>
#include <set>
using namespace std;

set<int> st[10005];
set<int> ans;
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		int c;
		scanf("%d", &c);
		for (int j = 1; j <= c; j++){
			int x;
			scanf("%d", &x);
			st[x].insert(i);
		}
	}
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++){
		int a, b;
		cin >> a >> b;
		ans.clear();
	    set_intersection(st[a].begin(), st[b].end(),
                      st[b].begin(), st[b].end(),
                      inserter(ans, ans.begin()));
        if (!ans.empty()) cout << "Yes" << endl;
        else cout << "No" << endl;
	}
	return 0;
}
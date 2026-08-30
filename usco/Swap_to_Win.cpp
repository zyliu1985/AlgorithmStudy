#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string s[1005];
//struct site{
//	int x, y;
//} to[1005][1005];
struct node{
	int p, a, b, c;
} f[2005];
int cur;
vector<int> box[1005][26];
int k[1005][1005];
//vector<int> findlist[26];
//bool ok[1005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		cur = 0;
//		for (int i = 0; i < 1000; i++) ok[i] = 0;
		int n, m;
		cin >> n >> m;
		string t;
		cin >> t;
		for (int i = 1; i <= n; i++)
			cin >> s[i];
//		for (int i = 1; i <= n; i++)
//			for (int j = 0; j < m; j++)
//				if (i != 1 || s[1][j] != t[j])
//					k[i][j] = box[i][s[j] - 'a'].size(), box[i][s[j] - 'a'].push_back(j);
//		for (int j = 0; j < m; j++){
//			if (s[1][j] != t[j]){
//				for (int i = 1; i <= n; i++)
//					if (!box[i][t[j]].empty()){
//						int orj = box[i][t[j]].back();
//						if (orj != j){
//							f[++cur] = {1, i, orj + 1, j + 1};
//							box[i][s[i][j] - 'a'][k[i][j]] = orj;
//						}
//						if (i != 1){
//							f[++cur] = {2, 1, i, j};
//						}
//					}
//			}
//		} 
		
		
//		for (int i = 0; i < m; i++)
//			if (s[1][i] != t[i]){
//				findlist[t[i] - 'a'].push_back(i);
//			} else {
//				ok[i] = 1;
//			}
//		for (int i = 1; i <= n; i++){
//			for (int j = 0; j < m; j++)
//				to[i][j] = {i, j};
//		}
//		for (int i = 1; i <= n; i++)
//			for (int j = 0; j < m; j++){
//				if (i == 1 && ok[j]) continue;
////				cout << i << ' ' << j << '\n';
//				int ti = to[i][j].x;
//				int tj = to[i][j].y;
//				if (!findlist[s[i][j] - 'a'].empty()){
////					cout << "i,j,ti,tj:" << i << ',' << j << ',' << ti << ',' << tj << '\n';
//					int y = findlist[s[i][j] - 'a'].back();
//					if (y != tj){
//						f[++cur] = {1, ti, tj+1, y+1};
//						swap(to[i][j], to[ti][y]);
//					}
//					if (1 != ti){
//						f[++cur] = {2, ti, 1, y+1};
//						swap(to[i][j], to[1][y]);
//					}
//					findlist[s[i][j] - 'a'].pop_back();
//				}
//			}
		cout << cur << '\n';
		for (int i = 1; i <= cur; i++)
			cout << f[i].p << ' ' << f[i].a << ' ' << f[i].b << ' ' << f[i].c << '\n';
	}
	return 0;
}


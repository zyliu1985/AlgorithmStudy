//#include <iostream>
//#include <cmath>
//#include <queue>
//#include <map>
//using namespace std;
//
//int n, m;
//int a[1005][1005];
//bool vis[1005][1005];
//
//struct node{
//	int x, y;
//};
//queue<node> q;
//map<int, vector<node> > mp;
//
//bool out(int x, int y){
//	return 1 > x || x > n || 1 > y || y > m;
//}
//
//void facs(int val) {
//	for(int i = 1; i <= sqrt(val); i++) {
//		if (val % i != 0) continue;
//		int na = i, nb = val / i;
//		if(na == nb && na <= min(n, m)) {
//			mp[val].push_back({na, nb});	
//		} else {
//			if(na <= n && nb <= m) mp[val].push_back({na, nb});
//			if(na <= m && na <= n) mp[val].push_back({nb, na});
//		}
//	}
//}
//
//bool bfs(){
//	q.push({1, 1});
//	vis[1][1] = true;
//	while (!q.empty()){
//		int x = q.front().x;
//		int y = q.front().y;
//		q.pop();
//		if (x == n && y == m) return true;
//		int val = a[x][y];
//		if (val > n*m) continue;
//		
//		if(!mp.count(val))
//			facs(val);
//		vector<node> v = mp[val];
//		for(int i = 0; i < v.size(); i++) {
//			int na = v[i].x, nb = v[i].y;
//			if (!vis[na][nb]){
//				vis[na][nb] = true;
//				q.push({na, nb});
//			}
//			if(!vis[nb][na]) {
//				vis[nb][na] = true;
//				q.push({nb, na});
//			}
//		}
//	}
//	return false;
//}
//int main(){
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= m; j++) {
//			cin >> a[i][j];
//		}
//			
//	if (bfs()) cout << "yes" << endl;
//	else cout << "no" << endl;
//	return 0;
//}





#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
 
int n, m;
int a[1005][1005];
bool vis[1005][1005], flag[1000005];
struct node{
    int x, y;
};
queue<node> q;
vector<node> v[1000005];
bool in(int x, int y){
    return 1 <= x && x <= n && 1 <= y && y <= m;
}
bool bfs(){
    q.push({1, 1});
    vis[1][1] = true;
    while (!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        if (x == n && y == m) return true;
        int val = a[x][y];
        for (int i = 0; i < v[val].size(); i++){
            vis[v[val][i].x][v[val][i].y] = true;
            q.push({v[val][i].x, v[val][i].y});
        }
    }
    return false;
}
int main(){
    int maxn = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
            flag[a[i][j]] = true;
            maxn = max(maxn, a[i][j]);
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            if (i*j <= maxn && flag[i*j])
                v[i*j].push_back({i, j});
        }
    if (bfs()) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}
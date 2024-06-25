#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define int long long
using namespace std;

priority_queue<int> pq;
int ans[10005];
signed main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
    	int a, b, c;
    	cin >> a >> b >> c;
    	for (int x = 1; x <= m; x++){
    		int ans = a*x*x+b*x+c;
    		pq.push(ans);
    		if (pq.size() > m) pq.pop();
		}
	}
	int len = pq.size();
	for (int i = 0; i < len; i++){
		ans[len-i] = pq.top();
		pq.pop();
	}
	for (int i = 1; i <= len; i++){
		cout << ans[i] << ' ';
	}
    return 0;
}
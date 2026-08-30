#include <iostream>
#include <algorithm>
#include <cmath>
#include <deque> 
using namespace std;

deque<int> q;
int a[200005], d[200005];
void ps(int x){
	while (!q.empty() && q.back() <= x) q.pop_back();
	q.push_back(x);
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n, x;
		cin >> n >> x;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			if (i >= 2) d[i] = d[i-1] + abs(a[i] - a[i-1]);
		}
		int start = d[n];
		for (int l = 1, r = 1; r <= n; r++){
			ps(a[r]);
			
		}
	}
	return 0;
}




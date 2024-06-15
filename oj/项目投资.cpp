#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct node{
	int c, p;
} a[100005];
bool cmp(node a, node b){
	return a.c < b.c;
}
priority_queue<int> q;
int main(){
	int n, m, k;
	cin >> n >> m >> k;
	int cur = 1;
	for (int i = 1; i <= n; i++)
		cin >> a[i].c >> a[i].p;
	sort(a+1, a+n+1, cmp);
	for (int i = 1; i <= k; i++){
		while (cur <= n && a[cur].c <= m){
			q.push(a[cur].p);
			cur++;
		}
		if (q.empty()) break;
		int x = q.top();
		m += x;
		q.pop();
	}
	cout << m << endl;
	return 0;
}
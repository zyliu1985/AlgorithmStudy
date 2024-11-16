#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> bpq;
priority_queue<int, vector<int>, greater<int> > spq;
int a[1000005];
int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int cur = 1;
	for (int i = 1; i <= m; i++){
		int x;
		cin >> x;
		for (; cur <= x; cur++)
			if (!bpq.empty() && bpq.top() >= a[cur]){
				spq.push(bpq.top());
				bpq.pop();
				bpq.push(a[cur]);
			} else spq.push(a[cur]);
		cout << spq.top() << endl;
		bpq.push(spq.top());
		spq.pop();
	}
	return 0;
}
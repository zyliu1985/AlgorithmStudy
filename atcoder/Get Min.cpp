#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int qq;
	cin >> qq;
	while (qq--){
		int op;
		cin >> op;
		if (op == 1){
			int x;
			cin >> x;
			q.push(x);
		} else {
			cout << q.top() << '\n';
			q.pop();
		}
	}
	return 0;
}


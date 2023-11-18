#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<int> q;
stack<int> st;

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int t;
		cin >> t;
		q.push(t);
	}
	for (int i = 1; i <= n; i++){
		st.push(i);
		if (i > q.front()){
			cout << "Invalid" << endl;
			return 0;
		}
		while (!st.empty() && !q.empty() && st.top() == q.front()){
			st.pop();
			q.pop();
		}
	}
	if (st.empty()) cout << "Valid" << endl;
	else cout << "Invalid" << endl;
	return 0;
}
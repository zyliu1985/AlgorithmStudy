#include <iostream>
#include <algorithm>
using namespace std;

string pc[200005], svc;
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n, q;
	cin >> n >> q;
	while (q--){
		int op;
		cin >> op;
		if (op == 1){
			int x;
			cin >> x;
			pc[x] = svc;
		} else if (op == 2){
			int x;
			cin >> x;
			string s;
			cin >> s;
			pc[x] += s;
		} else {
			int x;
			cin >> x;
			svc = pc[x];
		}
	}
	cout << svc << '\n';
	return 0;
}




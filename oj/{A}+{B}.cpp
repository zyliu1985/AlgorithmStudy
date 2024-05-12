#include <iostream>
#include <set>
using namespace std;

set<int> a;
int main(){
	int n, m;
	while (cin >> n){
		cin >> m;
		a.clear();
		for (int i = 1; i <= n+m; i++){
			int x;
			cin >> x;
			a.insert(x);
		}
		for (set<int>::iterator it = a.begin(); it != a.end(); it++)
			cout << *it << ' ';
		cout << endl;
	}
}
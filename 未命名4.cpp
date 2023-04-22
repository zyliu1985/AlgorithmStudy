#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<int> nr, yr;
bool ReadYr(int x){
	queue<int> t;
	while (!yr.empty()){
		if (yr.front() == x){
			yr.pop();
			while (!t.empty()){
				yr.push(t.front());
				t.pop();
			}
			return true;
		}
		t.push(yr.front());
		yr.pop();
	}
	while (!t.empty()){
		yr.push(t.front());
		t.pop();
	}
	return false;
}

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int t;
		cin >> t;
		nr.push(t);
	}
	int x = 1;
	while (nr.front() == x || yr.size() >= 2){
		if (nr.front() != x){
			yr.pop();
			yr.pop();
			yr.push(x);
			x++;
			continue;
		}
		while (nr.front() == x){
			yr.push(nr.front());
			nr.pop();
		}
		x++;
	}
	while ()
	cout << x << endl;
	return 0;
}
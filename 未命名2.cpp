#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<int> nr; // init book
queue<int> yr; // readed book
priority_queue<int> pnr; // not read book

void erase(){
	
}

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int t;
		cin >> t;
		nr.push(t);
		pnr.push(t);
	}
	int x = 1;
	while (nr.size() >= 2 || nr.front() == x || yr.size() >= 2){
		if (nr.front() != x){
			if (yr.size() >= 2){
				yr.pop();
				yr.pop();
				yr.push(x);
				x++;
			} else if (yr.size() == 1 && pnr.size() >= 1){
				int t = pnr.top();
				nr.erase(t);
				pnr.pop();
				yr.pop();
				yr.push(x);
				x++;
			} else if (pnr.size() >= 2){
				int t = pnr.top();
				nr.erase(t);
				pnr.pop();
				t = pnr.top();
				nr.erase(t);
				pnr.pop();
				yr.push(x);
				x++;
			} else {
				break;
			}
			continue;
		}
		while (nr.front() == x){
			yr.push(nr.front());
			int t = nr.front();
			nr.pop();
			pnr.erase(t);
		}
		x++;
	}
	cout << x-1 << endl;
	return 0;
}
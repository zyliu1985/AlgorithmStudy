#include <iostream>
using namespace std;

bool vis[200005];
int main(){
	int n;
	cin >> n;
	int c = n, id = 1;
	while (true){
		id++;
		if (id > n) id = 1;
		while (vis[id]){
			id++;
			if (id > n) id = 1;
		}
		vis[id] = true;
		cout << id << endl;
		c--;
		if (c < 1) break;
		id++;
		if (id > n) id = 1;
		while (vis[id]){
			id++;
			if (id > n) id = 1;
		}
	}
	return 0;
}
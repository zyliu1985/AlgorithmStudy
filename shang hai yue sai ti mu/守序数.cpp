#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

struct node{
	int lc, mc, rc, f, val;
} t[100005];
queue<int> q;
int n;a
string ans;
void bfs(){
	int cnt = 0;
	for (int i = 1; i <= 9; i++) q.push(i);
	while (true){
		int x = q.front();
		q.pop();
		cnt++;
		if (cnt > n){
			while (t[x].f != 0){
				s = 
			}
		}
	}
}
int main(){
	cin >> n;
	bfs();
	return 0;
}
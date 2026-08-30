#include <iostream>
#include <algorithm>
#include <deque> 
using namespace std;

struct node{
	int x, id;
};
deque<node> q, p;
void update_q(int x, int id, int least){
	while (!q.empty() && q.front().id < least) q.pop_front();
	while (!q.empty() && q.back().x <= x) q.pop_back();
	q.push_back({x, id});
}
void update_p(int x, int id, int least){
	while (!p.empty() && p.front().id < least) p.pop_front();
	while (!p.empty() && p.back().x >= x) p.pop_back();
	p.push_back({x, id});
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; i++){
		int x;
		cin >> x;
		update_q(x, i, 1);
		update_p(x, i, 1);
	}
	for (int i = k+1; i <= n; i++){
		cout << q.front().x << ' ' << p.front().x << '\n';
		int x;
		cin >> x;
		update_q(x, i, i - k + 1);
		update_p(x, i, i - k + 1);
	}
	cout << q.front().x << ' ' << p.front().x << '\n';
	return 0;
}




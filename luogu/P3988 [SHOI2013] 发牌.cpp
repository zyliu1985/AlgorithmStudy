#include <iostream>
#include <algorithm>
#define lowbit(x) (x&-x)
using namespace std;

int n, N;
int tr[700005];
void init(){
	for (int i = 1; i <= N; i++)
		tr[i] = lowbit(i);
}
void add(int x, int c){
	for (int i = x; i <= N; i += lowbit(i))
		tr[i] += c;
}
int find(int x){
	int re = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		re += tr[i];
	return re;
}
int select(int x){
	int l = 1, r = N;
	while (l < r){
		int mid = (l + r) / 2;
		if (find(mid) >= x + 1) r = mid;
		else l = mid + 1; 
	}
	return l;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	N = n;
	init();
	int rank = 0;
	while (n > 0){
//		for (int i = 1; i <= N; i++)
//			cout << find(i) << ' ';
//		cout << '\n';
		int a;
		cin >> a;
		rank = (rank + a) % n;
		int target = select(rank);
		add(target, -1);
		cout << target << '\n';
		n--;
	}
	return 0;
}


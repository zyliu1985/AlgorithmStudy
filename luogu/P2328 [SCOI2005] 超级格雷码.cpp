#include <iostream>
#include <algorithm>
using namespace std;

int n, b;
char trf(int x){
	if (0 <= x && x <= 9) return x + '0';
	else return x - 10 + 'A';
}
void solve(int now, string s, bool inv){
	if (now == 0){
		cout << s << '\n';
		return; 
	}
	if (inv){
		for (int i = b-1; i >= 0; i--){
			s[now-1] = trf(i);
			solve(now-1, s, !(i & 1));
		}
	} else {
		for (int i = 0; i < b; i++){
			s[now-1] = trf(i);
			solve(now-1, s, i & 1);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> b;
	string s;
	for (int i = 1; i <= n; i++)	
		s += '0';
	solve(n, s, 0); 
	return 0;
}


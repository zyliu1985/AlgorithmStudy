#include <iostream>
#include <cstring>
using namespace std;

// AABDD, ABCD, CCD, BBB, AD
int da[5] = {2, 1, 0, 0, 1};
int db[5] = {1, 1, 0, 3, 0};
int dc[5] = {0, 1, 2, 0, 0};
int dd[5] = {2, 1, 1, 0, 1};
bool dfs(int a, int b, int c, int d, bool turn){
	bool is_end = true;
	bool re = turn;
	for (int i = 0; i < 5; i++){
		int na = a - da[i];
		int nb = b - db[i];
		int nc = c - dc[i];
		int nd = d - dd[i];
		if (na < 0 || nb < 0 || nc < 0 || nd < 0) continue;
		is_end = false;
		if (turn)
			re &= dfs(na, nb, nc, nd, !turn);
		else
			re |= dfs(na, nb, nc, nd, !turn);
	}
	if (is_end) return turn;
	return re;
}
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (dfs(a, b, c, d, 0)) // turn = 0代表Patrick出牌，1代表Roland出牌
			cout << "Patrick" << endl;
		else
			cout << "Roland" << endl;
	}
	return 0;
}
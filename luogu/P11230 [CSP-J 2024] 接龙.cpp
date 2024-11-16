#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

inline int read(){
	int re = 0, type = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') type = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		re = (re << 1) + (re << 3) + (c - '0');
		c = getchar();
	}
	return re * type;
}
inline void write(int x, char end = '\n'){
	if (x < 0){
		putchar('-');
		write(-x, end);
		return;
	}
	int len = x ? 0 : 1, tx = x;
	while (x > 0){
		x /= 10;
		len++;
	}
	while (len--){
		putchar(tx / pow(10, len) + '0');
		tx %= int(pow(10, len));
	}
	putchar(end);
}
inline void endl(){
	putchar('\n');
}
vector<int> s[100005];
int f[105][200005];
struct node{
	int r, c;
};
void clear(){
	memset(f, -1, sizeof(f));
	f[0][1] = 0;
	for (int i = 1; i <= 1e5; i++)
		s[i].clear();
}
void update(int r, int val, int id){
	if (f[r][val] == -1)
		f[r][val] = id;
	else if (f[r][val] != id)
		f[r][val] = 0;
}
void solve(){
	clear();
//	for (int i = 0; i <= 7; i++){
//		for (int j = 1; j <= 6; j++)
//			write(f[i][j], ' ');
//		endl(); 
//	}
	int n = read(), k = read(), q = read();
	for (int i = 1; i <= n; i++){
		int l = read();
		for (int j = 1; j <= l; j++)
			s[i].push_back(read());
	}
	for (int r = 1; r <= 100; r++){
		for (int i = 1; i <= n; i++){
			int end = 0;
			for (int j = 0; j < s[i].size(); j++){
				if (end){ // ×÷Îª½áÎ² 
					update(r, s[i][j], i);
//					cout << "start:" << j - k + end << ", end:" << j << ", can use:";
//					for (int ii = j - k + end; ii <= j; ii++)
//						write(s[i][ii], ' ');
//					endl();
				}
				if (f[r-1][s[i][j]] != -1 && f[r-1][s[i][j]] != i)
					end = k;
				end = max(end - 1, 0);
			}
		}
	}
	while (q--){
		int qr = read(), qc = read();
		write(f[qr][qc] != -1);
	}
}
int main(){
	int t = read();
	while (t--)
		solve(); 
	return 0;
}
/*
1
3 3 7
5 1 2 3 4 1
3 1 2 5
3 5 1 6
1 2
1 4
2 4
3 4
6 6
1 1
7 7
*/

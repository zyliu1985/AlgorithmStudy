#include <iostream>
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
struct node{
	int p, id;
};
vector<node> box[15][100005];
vector<node> now;
int num[100005];
bool cmp(node x, node y){
	return x.p > y.p;
}
int main(){
	int n = read(), k = read();
	for (int i = 0; i < n; i++){
		int s = read(), p = read(), u = read();
		box[s][u].push_back(node{p, i});
	}
	for (int i = 0; i <= 10; i++)
		for (int j = 1; j <= 100000; j++)
			sort(box[i][j].begin(), box[i][j].end(), cmp);
	for (int i = 10; i >= 0; i--)
	return 0;
}

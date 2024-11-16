#include <iostream>
using namespace std;

long long read(){
	long long re = 0, type = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') type = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		re = re * 10 + (c - '0');
		c = getchar();
	}
	return re * type;
}
int pre[100005], nxt[100005];
bool erase[100005];
int main(){
	cout.tie(0);
	int n = read();
	pre[1] = 0, nxt[1] = n+1;
	for (int i = 2; i <= n; i++){
		int k = read(), p = read();
		if (p == 0){
			pre[i] = pre[k];
			nxt[i] = k;
			nxt[pre[k]] = i;
			pre[k] = i;
		} else{
			pre[i] = k;
			nxt[i] = nxt[k];
			pre[nxt[k]] = i;
			nxt[k] = i;
		}
	}
	int m = read();
	for (int i = 1; i <= m; i++){
		int x = read();
		erase[x] = true;
	}
	int id = nxt[0];
	while (id != n+1){
		if (!erase[id])
			cout << id << ' ';
		id = nxt[id];
	}
	return 0;
}

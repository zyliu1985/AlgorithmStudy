#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
void __write(int x){
	if (x < 0){
  		putchar('-');
		__write(-x);
		return;
	}
	if (x > 9) __write(x / 10);
	putchar(x % 10 + '0');
}
void __write(long long x){
  	if (x < 0){
  		putchar('-');
		__write(-x);
		return;
	}
	if (x > 9) __write(x / 10);
	putchar(x % 10 + '0');
}
int read(){
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-')
			f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		x = (x << 1) + (x << 3) + (c - '0');
		c = getchar();
	}
	return x * f;
}
long long READ(){
	long long x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-')
			f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		x = (x << 1) + (x << 3) + (c - '0');
		c = getchar();
	}
	return x * f;
}
void write(int x, char c = '\n'){
	__write(x);
	putchar(c);
}
void write(long long x, char c = '\n'){
	__write(x);
	putchar(c);
}
void endl(){
	putchar('\n');
}

struct box{
	int a[3];
} b[1005];
int n, rd[1005], dis[1005], ans = 1;
vector<int> v[1005];
queue<int> q;
void tbpx(){
	for (int i = 1; i <= n; i++)
		if (rd[i] == 0){
			dis[i] = 1;
			q.push(i);
		}
	while (!q.empty()){
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++){
			rd[v[x][i]]--;
			dis[v[x][i]] = max(dis[v[x][i]], dis[x] + 1);
			ans = max(ans, dis[v[x][i]]);
			if (rd[v[x][i]] == 0)
				q.push(v[x][i]);
		}
	}
}
int main(){
	freopen("box.in", "r", stdin);
	freopen("box.out", "w", stdout);
	n = read();
	for (int i = 1; i <= n; i++){
		cin >> b[i].a[0] >> b[i].a[1] >> b[i].a[2];
		for (int j = 0; j < 3; j++)
			for (int k = 1; k < 3 - j; k++)
				if (b[i].a[k-1] > b[i].a[k]) swap(b[i].a[k-1], b[i].a[k]);
	}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (b[i].a[0] < b[j].a[0] && b[i].a[1] < b[j].a[1] && b[i].a[2] < b[j].a[2]){
				v[i].push_back(j);
				rd[j]++;
			} else if (b[i].a[0] > b[j].a[0] && b[i].a[1] > b[j].a[1] && b[i].a[2] > b[j].a[2]){
				v[j].push_back(i);
				rd[i]++;
			}
	tbpx();
	write(ans);
	return 0;
}



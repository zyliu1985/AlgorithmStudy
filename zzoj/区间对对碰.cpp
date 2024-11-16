#include <iostream>
#include <stack>
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
int a[100005], ans;
stack<int> st;
void push(int x){
	if (!st.empty() && st.top() >= x){
		ans += st.top() - x;
		while (!st.empty() && st.top() >= x)
			st.pop();
	}
	st.push(x);
}
int main(){
	freopen("refer.in", "r", stdin);
	freopen("refer.out", "w", stdout);
	int n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= n; i++)
		a[i] -= read();
	for (int i = 1; i <= n; i++){
		if (a[i] <= 0 ^ a[i-1] <= 0)
			push(0);
		if (a[i] < 0)
			push(-a[i]);
		else
			push(a[i]);
//		cout << i << endl; 
	}
	if (!st.empty()) ans += st.top(); 
	write(ans);
	return 0;
}

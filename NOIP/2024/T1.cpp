#include <iostream>
#include <cmath>
#include <cstring>
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
	int l, r, num0, num1;
} a1[100005], a2[100005];
int color1[100005], color2[100005];
int n, cnt1, cnt2;
string s1, s2, t1, t2;
void init(){
	cnt1 = cnt2 = 0;
	bool type1, type2;
	type1 = type2 = 0;
	for (int i = 0; i < n; i++){
		if (t1[i] == '1'){
			if (!type1){
				type1 = true;
				a1[++cnt1] = {i, 0, 0, 0};
			}
			color1[i] = cnt1;
			if (s1[i] == '0') a1[cnt1].num0++;
			else a1[cnt1].num1++;
		} else if (type1) {
			type1 = false;
			a1[cnt1].r = i-1;
		}
		
		if (t2[i] == '1'){
			if (!type2){
				type2 = true;
				a2[++cnt2] = {i, 0, 0, 0};
			}
			color2[i] = cnt2;
			if (s2[i] == '0') a2[cnt2].num0++;
			else a2[cnt2].num1++;
		} else if (type2) {
			type2 = false;
			a2[cnt2].r = i-1;
		}
	}
	if (type1) a1[cnt1].r = n-1;
	if (type2) a2[cnt2].r = n-1;
}
void solve(){
	// 处理固定<=>固定，可变<=>固定 
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (t1[i] == '0' && t2[i] == '0'){
			ans += (s1[i] == s2[i]);
		} else if (t1[i] == '1' && t2[i] == '0'){
			if (s2[i] == '0' && a1[color1[i]].num0 > 0){
				ans++;
				a1[color1[i]].num0--;
			} else if (s2[i] == '1' && a1[color1[i]].num1 > 0){
				ans++;
				a1[color1[i]].num1--;
			}
		} else if (t1[i] == '0' && t2[i] == '1'){
			if (s1[i] == '0' && a2[color2[i]].num0 > 0){
				ans++;
				a2[color2[i]].num0--;
			} else if (s1[i] == '1' && a2[color2[i]].num1 > 0){
				ans++;
				a2[color2[i]].num1--;
			}
		}
		
	// 处理可变<=>可变
	for (int i = 0; i < n; i++)
		if (t1[i] == '1' && t2[i] == '1'){
			if (a1[color1[i]].num0 > 0 && a2[color2[i]].num0 > 0){
				a1[color1[i]].num0--;
				a2[color2[i]].num0--;
				ans++;
			} else if (a1[color1[i]].num1 > 0 && a2[color2[i]].num1 > 0){
				a1[color1[i]].num1--;
				a2[color2[i]].num1--;
				ans++;
			}
		} 
	write(ans);
}
int main(){
	int t = read();
	while (t--){
		n = read();
		cin >> s1 >> s2 >> t1 >> t2;
		init();
		solve();
	}
	return 0;
}


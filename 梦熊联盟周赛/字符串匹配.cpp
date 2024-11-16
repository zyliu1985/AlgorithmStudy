#include <iostream>
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
int main(){
	freopen("str.in", "r", stdin);
	freopen("str.out", "w", stdout);
	string s1, s2;
	cin >> s1 >> s2;
	if (s1.size() != s2.size()){
		write(1);
		return 0;
	} else if (s1 == s2){
		write(2);
		return 0;
	}
	for (int i = 0; i < s1.size(); i++){
		if (s1[i] >= 'A' && s1[i] <= 'Z')
			s1[i] = s1[i] - 'A' + 'a';
		if (s2[i] >= 'A' && s2[i] <= 'Z')
			s2[i] = s2[i] - 'A' + 'a';
	}
	if (s1 == s2){
		write(3);
		return 0;
	} else {
		write(4);
		return 0;
	}
	return 9;
}

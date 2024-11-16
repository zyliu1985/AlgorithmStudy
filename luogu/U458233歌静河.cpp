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
int numb;
char now = 'a';
void print(string s){
	for (int i = 0; i < s.size(); i++){
		if (s[i] != '#')
			putchar(s[i]);
		else{
			putchar(now);
			if (numb < 'z' - now)
				now++;
			else{
				numb -= 'z' - now;
				now = 'a';
			}
		}
	}
}
int main(){
	cout.tie(0);
	int n = read(), m = read();
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < b.size(); i++)
		if (b[i] == '#')
			numb++;
	print(a);
	return 0;
}

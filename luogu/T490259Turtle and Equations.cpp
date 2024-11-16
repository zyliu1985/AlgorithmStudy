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
int main(){
	cout.tie(0);
	int a = read();
	int b = read();
	int c = read();
	int d = read();
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++){
			int x1, ans;
			switch(i){
				case 1: x1 = a + b; break;
				case 2: x1 = a - b; break;
				case 3: x1 = a * b; break;
			}
			switch(j){
				case 1: ans = x1 + c; break;
				case 2: ans = x1 - c; break;
				case 3: ans = x1 * c; break;
			}
			if (ans == d){
				cout << "Yes" << endl;
				return 0;
			}
		}
	cout << "No" << endl;
	return 0;
}

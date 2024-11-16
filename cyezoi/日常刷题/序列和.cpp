#include <iostream>
using namespace std;

char c[10];
int n;
int cul(){
	int re = 1;
	for (int i = 2; i <= n; ){
		while (c[i-1] == ' '){
			re = re*10 + i;
			i++;
		}
		char t = c[i-1];
		int b = i;
		i++;
		while (c[i-1] == ' '){
			b = b*10 + i;
			i++;
		}
		if (t == '+') re += b;
		else re -= b;
	}
	return re;
}
void print(){
	for (int i = 1; i <= n; i++)
		if (i != n) cout << i << c[i];
		else cout << i;
	cout << endl;
}
void dfs(int step){
	if (step == n){
		if (cul() == 0) print();
		return;
	}
	c[step] = ' ';
	dfs(step+1);
	c[step] = '+';
	dfs(step+1);
	c[step] = '-';
	dfs(step+1);
}
int main(){
	cin >> n;
	dfs(1);
	return 0;
}
#include <iostream>
using namespace std;

int a[25];
int n;
void print(int len){
	cout << n << '=';
	for (int i = 0; i < len-1; i++) cout << a[i] << '+';
	cout << a[len-1] << endl;
}
void dfs(int sum, int step, int last){
//	cout << sum << ' ' << step << endl;
	if (sum == 0){
		if (step >= 2) print(step);
		return;
	}
	for (int i = last+1; i <= sum; i++){
		a[step] = i;
		dfs(sum-i, step+1, i);
	}
}
int main(){
	cin >> n;
	dfs(n, 0, 0);
	return 0;
}
#include <iostream>
using namespace std;

struct node{
	int cl;
	int c[10];
} t[10];
int dfs(int now){
	int lignt = 1, dark = 1;
	for (int i = 1; i <= t[now].cl; i++)
		lignt *= dfs(t[now].c[i]);
	return lignt + dark;
}
int main(){
	int n;
	cin >> n;
	for (int i = 1; i < n; i++){
		int x;
		cin >> x;
		t[x].c[++t[x].cl] = i;
	}
	cout << dfs(n) - 1 << endl;
	return 0;
}
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int n;
double a[15][15];
void mul_rank(int rk, double c){
	for (int i = 1; i <= n+1; i++)
		a[rk][i] = a[rk][i] * c;
}
void add_rank(int from, int to, double c){
	for (int i = 1; i <= n+1; i++)
		a[to][i] = a[to][i] + a[from][i] * c;
}
void swap_rank(int x, int y){
	for (int i = 1; i <= n+1; i++)
		swap(a[x][i], a[y][i]);
} 
double lst[15];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> lst[i];
	for (int i = 1; i <= n; i++){
		double c = 0;
		for (int j = 1; j <= n; j++){
			double x;
			cin >> x;
			a[i][j] = 2 * x - 2 * lst[j];
			c += x * x - lst[j] * lst[j];
			lst[j] = x; 
		}
		a[i][n+1] = c;
	}
	for (int i = 1; i <= n; i++){
		if (a[i][i] == 0){
			for (int j = i+1; j <= n; j++)
				if (a[j][i] != 0){
					swap_rank(i, j);
					break;
				}
			if (!a[i][i]){
				cout << "No Solution" << '\n';
				return 0;
			}
		}
//		for (int j = n+1; j <= n*2; j++){
//			for (int k = 1; k <= n; k++)
//				cout << a[i][j] << ' ';
//			cout <<'\n';
//		}	
		mul_rank(i, 1.0 / a[i][i]);
		for (int j = i+1; j <= n; j++)
			add_rank(i, j, -a[j][i]);
//		for (int j = n+1; j <= n*2; j++){
//			for (int k = 1; k <= n; k++)
//				cout << a[i][j] << ' ';
//			cout <<'\n';
//		}	
	}
	for (int i = n; i >= 1; i--){
		for (int j = i-1; j >= 1; j--)
			add_rank(i, j, -a[j][i]);
	}
	for (int i = 1; i <= n; i++)
		printf("%.3lf ", a[i][n+1]);
	return 0;
}


#include <iostream>
#include <cstring>
using namespace std;

char a[105][105];
int dy[9] = {0, -1, 0, 1, -1, 1, -1, 0, 1};
int dx[9] = {0, -1, -1, -1, 0, 0, 1, 1, 1};
int cul(int x, int y){
	int sum = 0;
	for (int i = 1; i <= 8; i++){
		//cout << dx[i]+x << ' ' << dy[i]+y << ' ' << a[dx[i]+x][dy[i]+y] << endl;
		if (a[dx[i]+x][dy[i]+y] == '*') sum++;
	}
	return sum;
}

int main(){
	memset(a, '.', sizeof(a));
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}
//	for (int i = 0; i <= n+1; i++){
//		for (int j = 0; j <= m+1; j++){
//			cout << a[i][j] << ' ';
//			if (a[i][j] != '*' && a[i][j] != '.') cout << '!';
//		}
//		cout << endl;
//	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if ((a[i][j] == '*' && (cul(i, j) != 2 && cul(i, j) != 3)) || (a[i][j] == '.' && cul(i, j) == 3)){
				cout << "Other" << endl;
				return 0;
			}
		}
	}
	cout << "Still life" << endl;
	return 0;
}
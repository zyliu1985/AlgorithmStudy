#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 0:正常  1:反向  2:停用 
vector<int> v[10005][6][2];
vector<int> t[10005][6][2];
int ans;
void dfs(int x, int y, int fx, int fy){
	for (int i = 0; i < v[x][y][0].size(); i++)
		if (v[x][y][0] == fx)
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	for (int i = 1; i <= n2; i++){
		v[0][0][1].push_back(i);
		v[i][1][0].push_back(0);
		t[0][0][1].push_back(0);
		t[i][1][0].push_back(0);
	}
	int m1, m2;
	cin >> m1;
	for (int i = 1; i <= m1; i++){
		int a, b;
		cin >> a >> b;
		v[b][1][1].push_back(a);
		v[a][2][0].push_back(b);
		t[b][1][1].push_back(0);
		t[a][2][0].push_back(0);
	}
	for (int i = 1; i <= n1; i++){
		v[i][2][1].push_back(i);
		v[i][3][0].push_back(i);
		t[i][2][1].push_back(0);
		t[i][3][0].push_back(0);
	}
	cin >> m2;
	for (int i = 1; i <= m2; i++){
		int a, b;
		cin >> a >> b;
		v[a][3][1].push_back(b);
		v[b][4][0].push_back(a);
		t[a][3][1].push_back(0);
		t[b][4][0].push_back(0);
	}
	for (int i = 1; i <= n3; i++){
		v[i][4][1].push_back(0);
		v[0][5][0].push_back(i);
		t[i][4][1].push_back(0);
		t[0][5][0].push_back(0);
	}
	dfs(0, 0, -1, -1);
	return 0;
}


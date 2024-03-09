#include <iostream>
#include <cstring>
#include <map>
using namespace std;

map<char, int> mp;
char c[105][105];
int n, x, y;
// 上、下、左、右、左下、右下、双上
int turnx[4][7] = {
	{-1, 1, 0, 0, 1, 1, -2}, 
	{0, 0, -1, 1, -1, 1, 0}, 
	{1, -1, 0, 0, -1, -1, 2},
	{0, 0, 1, -1, 1, -1, 0}
};
int turny[4][7] = {
	{0, 0, -1, 1, -1, 1, 0}, 
	{1, -1, 0, 0, -1, -1, 2}, 
	{0, 0, 1, -1, 1, -1, 0},
	{-1, 1, 0, 0, 1, 1, -2}
};
// I, J, L, O, S, T, Z
bool dict[7][7] = {
	{1, 1, 0, 0, 0, 0, 1}, 
	{1, 0, 1, 0, 0, 0, 1}, 
	{1, 0, 0, 1, 0, 0, 1}, 
	{0, 1, 1, 0, 1, 0, 0}, 
	{0, 1, 0, 1, 1, 0, 0}, 
	{0, 1, 1, 1, 0, 0, 0}, 
	{0, 1, 1, 0, 0, 1, 0}
};
bool in(int a, int b){
	return 1 <= a && a <= x && 1 <= b && b <= y;
}
bool check(int a, int b, char type, int turnnum){
	c[a][b] = '#';
	for (int i = 0; i < 7; i++){
		if (!dict[mp[type]][i]) continue;
		int xd = a + turnx[turnnum][i];
		int yd = b + turny[turnnum][i];
		if (!in(xd, yd) || c[xd][yd] == '#') return false;
		else c[xd][yd] = '#';
	}
	return true;
}
int main(){
	mp['I'] = 0;
	mp['J'] = 1;
	mp['L'] = 2;
	mp['O'] = 3;
	mp['S'] = 4;
	mp['T'] = 5;
	mp['Z'] = 6;
	memset(c, '.', sizeof(c));
	cin >> n >> x >> y;
	for (int i = 1; i <= n; i++){
		string s;
		cin >> s;
		char t = s[0];
		int cur = s.size()-1;
		int a, b;
		cin >> a >> b;
		if (!check(a, b, t, cur)){
			cout << "INVALID " << i << endl;
			return 0;
		}
	}
	for (int i = 1; i <= x; i++){
		for (int j = 1; j <= y; j++)
			cout << c[i][j];
		cout << endl;
	}
	return 0;
}
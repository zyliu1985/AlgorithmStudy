#include <iostream>
using namespace std;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};
int main(){
	string s;
	cin >> s;
	int x, y, f; // f = 0 是右，f = 1是下，f = 2是左，f = 3是上
	x = y = f = 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == 'R') f = (f+1)%4;
		else if (s[i] == 'L') f = (f+3)%4;
		else if (s[i] == 'F'){
			x += dx[f];
			y += dy[f];
		} else {
			x -= dx[f];
			y -= dy[f];
		}
	}
	cout << x << ' ' << y << endl;
	return 0;
}
// 3,248.7701987：阶乘计算中的离谱（再加一点就会爆炸）
#include <iostream>
using namespace std;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};
int main(){
	string s;
	cin >> s;
	int x, y, f; // f = 0 ���ң�f = 1���£�f = 2����f = 3����
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
// 3,248.7701987���׳˼����е����ף��ټ�һ��ͻᱬը��
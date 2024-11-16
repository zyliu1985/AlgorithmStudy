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
	freopen("camp.in", "r", stdin);
	freopen("camp.out", "w", stdout);
	cout.tie(0);
	int x1 = read(), y1 = read();
	int x2 = read(), y2 = read();
	int x3 = read(), y3 = read();
	// Ñ¡Ôñab
	int xmax = max(x1, x2);
	int ymax = max(y1, y2);
	int xmin = min(x1, x2);
	int ymin = min(y1, y2);
	int dx, dy;
	if (xmin <= x3 && x3 <= xmax) 
		dx = 0;
	else
		dx = x3 <= xmin ? xmin - x3 : x3 - xmax;
	
	if (ymin <= y3 && y3 <= ymax) 
		dy = 0;
	else
		dy = y3 <= ymin ? ymin - y3 : y3 - ymax;
	cout << (xmax - xmin) + (ymax - ymin) + 1 + dx + dy; 
	return 0;
}

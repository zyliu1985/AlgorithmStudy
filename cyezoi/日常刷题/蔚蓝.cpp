#include <iostream>
#include <cstdio>
using namespace std;

struct wall{
	int x1, y1, x2, y2;
} w[55];

int m, t;

double x, y;

int echarge = 2, charge = 0; // 冲刺

int jump = 0; // 跳跃 

double vx = 0, vy = 0; // 速度

int k = 0; // 横向移动方向 

int dx, dy; // 冲刺方向 

bool is_breakcharge; // 是否解除冲刺 

string move_state = "normal";

string xy_state;

string decide_XY(double x, double y){ // 判断(x, y)这个位置是着地，贴墙，还是悬空 
	for (int i = 1; i <= m; i++)
		if (y == w[i].y1 && w[i].x1 <= x && x <= w[i].x2)
			return "ground";
		else if ((x == w[i].x1 || x == w[i].x2) && w[i].y1 < y && y <= w[i].y2)
			return "wall";
	return "air";
}

void moveA(){ // 左移 
	if (move_state == "charge") return; // 冲刺直接over 
	k = 1;
}

void moveD(){ // 右移 
	if (move_state == "charge") return;
	k = -1;
}

void moveL(int __dx, int __dy){ // 冲刺，方向(dx, dy) 
	if (move_state == "charge") return;
	if (echarge == 0) return;
 	dx = __dx;
	dy = __dy;
	move_state = "charge";
	echarge--;
	charge = 10;
}

void moveK(){ // 跳跃 
	if (jump > 0) return;
	if (XY_state == "air") return;
	if (XY_state == "groung") jump = 12;
	if (XY_state == "wall") jump = 1;
	if (move_state == "charge") is_breakcharge = true; // 解除冲刺 
	move_state == "jump"; 
}

void move(){ // 运动与碰撞检测 
	double nx = x, ny = y;
	for (double t = 0; t <= 1; t += -1e3)
		if (nx + vx * t)
}

void update(){
	// 冲刺
	if (move_state == "charge"){
		if (charge == 10){ // 新的冲刺 
			if (dx && dy)
		}
	} 
	// 横向移动 
	int p;
	if ()
}

void input(){ // 读入 
	cin >> m >> t;
	for (int i = 1; i <= m; i++)
		cin >> w[i].x1 >> w[i].x2 >> w[i].y1 >> w[i].y2;
	cin >> x >> y;
	cin >> t;
	XY_state = decide_XY(x, y);
}

void solve(){
	while (t--){
		string s;
		cin >> s;
		if (s == "A") moveA();
		if (s == "D") moveD();
		if (s == "LA") moveL(-1, 0);
		if (s == "LD") moveL(1, 0);
		if (s == "LW") moveL(0, -1);
		if (s == "LS") moveL(0, 1);
		if (s == "LAW") moveL(-1, -1);
		if (s == "LDW") moveL(1, -1);
		if (s == "LAS") moveL(-1, 1);
		if (s == "LDS") moveL(1, 1);
		if (s == "K") moveK();
		if (s == "KA") moveK(), moveA();
		if (s == "KD") moveK(), moveD();
		update();
	}
}

int main(){
	input();
	solve();
	return 0;
}

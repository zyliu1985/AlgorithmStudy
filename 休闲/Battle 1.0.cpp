/*
这里是 Battle 1.0 的制作现场 
目前进度：玩家speed系统
		  怪物hp
		  玩家攻击系统 
*/ 

#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#define int long long
#define max(x,y) x>y?x:y
#define min(x,y) x<y?x:y
using namespace std;
typedef BOOL (WINAPI *PROCSETCONSOLEFONT)(HANDLE,DWORD);
PROCSETCONSOLEFONT SetConsoleFont; 

int TIME=50;
void SlowSpeak(string s,int tim=TIME){
	//tim*=1000;
	for(int i=0;i<s.size();++i){
		printf("%c",s[i]);
		Sleep(tim);
	}
}
//黑白蓝绿紫红靛黄灰 
//0 1 2 3 4 5 6 7 8
void color(int a){     //字体颜色 
	if(a==0) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE);
    if(a==1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    if(a==2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
    if(a==3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
    if(a==4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
    if(a==5) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
    if(a==6) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
    if(a==7) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
	if(a==8) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);
}
//黑白蓝绿紫红靛黄灰 
//0 1 2 3 4 5 6 7 8
void Color(int a){     //背景颜色 
	if(a==0) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
	if(a==1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE);
    if(a==2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_GREEN|BACKGROUND_BLUE);
    if(a==3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_GREEN);
    if(a==4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_BLUE);
    if(a==5) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_RED);
    if(a==6) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_BLUE);
    if(a==7) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_GREEN);
	if(a==8) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY);
}
void SetSize(int a){
	HMODULE hKernel32=GetModuleHandle("kernel32");
	SetConsoleFont=(PROCSETCONSOLEFONT)GetProcAddress(hKernel32,"SetConsoleFont");
	SetConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
void FULLScreen(){
	HWND hwnd=GetForegroundWindow();
	ShowWindow(hwnd,SW_MAXIMIZE);
/*	
	LONG_PTR last_style=GetWindowLongPtr(hwnd,GWL_STYLE);
    RECT last_rect;
    GetWindowRect(hwnd,&last_rect);
    LONG l_WinStyle=GetWindowLong(hwnd,GWL_STYLE);
    SetWindowLong(hwnd,GWL_STYLE,(l_WinStyle|WS_POPUP|WS_MAXIMIZE)&~WS_CAPTION&~WS_THICKFRAME&~WS_BORDER);
    SetWindowPos(hwnd,NULL,0,0,GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN),0);
    UpdateWindow(hwnd);
*/
} 
POINT GetPos(){
    POINT pt;
    GetCursorPos(&pt);
    HWND h=GetForegroundWindow();
    ScreenToClient(h,&pt);
    pt.x>>=3;pt.y>>=4;
    return pt;
}
void SetPos(int x,int y){
    COORD pos; pos.X=y*2,pos.Y=x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void Hide(){
	CONSOLE_CURSOR_INFO cursor_info={1,0}; 
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}
bool UP(){return GetAsyncKeyState(VK_UP)&0x8000;}      //上键 
bool DOWN(){return GetAsyncKeyState(VK_DOWN)&0x8000;}      //下键
bool LEFT(){return GetAsyncKeyState(VK_LEFT)&0x8000;}      //左键
bool RIGHT(){return GetAsyncKeyState(VK_RIGHT)&0x8000;}      //右键
bool LBUTTON(){return GetAsyncKeyState(VK_LBUTTON)&0x8000;}     //鼠标左键 
bool RBUTTON(){return GetAsyncKeyState(VK_RBUTTON)&0x8000;}     //鼠标右键 
bool CUST;
void stting(){
	system("cls");
	puts("格式校准：");
	puts("请选择下方尾部对齐的一组字符串：");
	puts("1.■");
	puts("  __");
	puts("2.■");
	puts("  _");
	char c;
	c = getch();
	if (c == '1') CUST = 0;
	else CUST = 1;
	system("cls");
}
const int py = 500;
int seed;
int Exp, hp, mxhp, atk, atr, lv, tp, spd, mxspd;
int skill[6], skllv[6];
int emps[] = {0, 142, 286, 428, 572, 714, 856};
// 1怪（Soldier Ant）30%：空心圆圈怪○：spd：1/1/1/1/2/2   hp：20/50/120/240/500/1200  atk: 20/50/120/240/500/1200  atr：2/2/2/2/2/2   exp：1/1/10/50/150/300                      
// 2怪（Leech）      20%：实心三角怪▲：spd：2/2/2/3/4/5   hp：10/30/70/110/300/750    atk：15/30/80/180/300/800    atr：2/2/2/2/2/2   exp：1/1/15/60/150/300 吸血：50%向下取整
// 3怪（Hornet）     15%：实心菱形怪◆：spd: 1/1/1/1/2/2   hp: 10/30/70/110/300/750    atk: 10/25/80/190/350/900    atr：4/4/5/5/6/8  exp：2/2/25/80/200/400 寻路：走到能攻击到的的最远位置攻击 
// 4怪（Starfish）   15%：实心五角星★：spd：1/1/1/1/2/2   hp：20/50/120/240/500/1200  atk：15/30/80/180/300/800    atr：2/2/2/2/2/2  exp：2/2/25/80/200/400 回血：25%血以下时回撤，每次操作回10%血，回满后或被攻击且血量大于25%继续攻击  
// 5怪（Leafbug）    15%：空心方形怪□：spd：1/1/1/1/1/1   hp：35/75/160/350/670/1400  atk：10/25/80/190/350/900    atr：2/2/2/2/2/2  exp：2/2/20/70/180/350 减伤：收到伤害减少4/10/20/50/100/200点 
// 6怪（Firefly回血） 5%：实心倒三角▼：spd：1/1/1/1/2/2   hp：20/50/120/240/500/1200  hlk: 10/20/60/120/170/500    hlr：2/2/2/3/4/4  exp：5/5/70/100/230/460 寻路：走到距离玩家hlr+1的地方 
int emhp[7][7] = {{0, 0, 0, 0, 0, 0, 0}, 
				  {0,20,50,120,240,500,1200},
				  {0,10,30,70,110,300,750},
				  {0,10,30,70,110,300,750},
				  {0,20,50,120,240,500,1200},
				  {0,35,75,160,350,670,1400},
				  {0,20,50,120,240,500,1200}}; 
string sklst[] = {"（未解锁）", "（空）", "瞬移", "冰封"};
int mp[1005][1005];
int health[1005][1005]; 
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
bool in(int x, int y){
	return -500 <= x && x <= 500 && -500 <= y && y <= 500;
}
void rksp(int x, int y, int num){
	if (num == 0) return;
	mp[x+py][y+py] = 1;
	int d1, d2, d3;
	d1 = rand() % (num + 1);
	if (d1 > 0) d2 = rand() % (d1 + 1);
	else d2 = 0;
	if (num - d1 > 0) d3 = rand() % ((num - d1) + 1);
	else d3 = 0;
	for (int i = 0; i < 4; i++){
		int nx, ny;
		nx = x + dx[i];
		ny = y + dy[i];
		if (in(nx, ny)){
			switch (i){
				case 1:{
					rksp(nx, ny, d2); 
					break;
				}
				case 2:{
					rksp(nx, ny, d1 - d2);
					break;
				}
				case 3:{
					rksp(nx, ny, d3);
					break;
				}
				case 4:{
					rksp(nx, ny, (num - d1) - d3);
					break;
				}
			}
		}
	}
}
void setmp(){
	for (int i = -500; i <= 500; i++)
		for (int j = -500; j <= 500; j++){
			int w = rand() % 1000;
			if (w <= 4) rksp(i, j, rand() % 40 + 10);
		}
}
void printmp(int nx, int ny){
	cout << "按C进入技能合成，按X进入天赋树，按Z进入技能背包，按ESC进入设置\n";
	for (int j = ny - 16; j <= ny + 16; j++){printf("■"); if (CUST) printf(" ");}
	cout << "x: " << nx << "    y: " << ny << "       ";
	puts("");
	for (int i = nx - 15; i <= nx + 15; i++){
		printf("■"); if (CUST) printf(" ");
		for (int j = ny - 15; j <= ny + 15; j++){
			if (!in(i, j)) {printf("■"); if (CUST) printf(" ");}
			else if (i == nx && j == ny){color(5); printf("●"); if (CUST) printf(" "); color(1);}
			else if (mp[i+py][j+py] == 0) printf("  ");
			else if (mp[i+py][j+py] == 1){printf("■"); if (CUST) printf(" ");}
			else if (mp[i+py][j+py] >= 10 && mp[i+py][j+py] <= 99){
				//黑白蓝绿紫红靛黄灰 
				//0 1 2 3 4 5 6 7 8		
				switch (mp[i+py][j+py] / 10){
					case 1:{
						color(1);
						break;
					}
					case 2:{
						color(3);
						break;
					}
					case 3:{
						color(6);
						break;
					}
					case 4:{
						color(4);
						break;
					}
					case 5:{
						color(5);
						break;
					}
					case 6:{
						color(8);
						break;
					}
				}
				// 1怪（Soldier Ant）30%：空心圆圈怪○：spd：1/1/1/1/2/2   hp：20/50/120/240/500/1200  atk: 20/50/120/240/500/1200  atr：2/2/2/2/2/2   exp：1/1/10/50/150/300                      
				// 2怪（Leech）      20%：实心三角怪▲：spd：2/2/2/3/4/5   hp：10/30/70/110/300/750    atk：15/30/80/180/300/800    atr：2/2/2/2/2/2   exp：1/1/15/60/150/300 吸血：50%向下取整
				// 3怪（Hornet）     15%：实心菱形怪◆：spd: 1/1/1/1/2/2   hp: 10/30/70/110/300/750    atk: 10/25/80/190/350/900    atr：4/4/5/5/6/8  exp：2/2/25/80/200/400 寻路：走到能攻击到的的最远位置攻击 
				// 4怪（Starfish）   15%：实心五角星★：spd：1/1/1/1/2/2   hp：20/50/120/240/500/1200  atk：15/30/80/180/300/800    atr：2/2/2/2/2/2  exp：2/2/25/80/200/400 回血：25%血以下时回撤，每次操作回10%血，回满后或被攻击且血量大于25%继续攻击  
				// 5怪（Leafbug）    15%：空心方形怪□：spd：1/1/1/1/1/1   hp：35/75/160/350/670/1400  atk：10/25/80/190/350/900    atr：2/2/2/2/2/2  exp：2/2/20/70/180/350 减伤：收到伤害减少4/10/20/50/100/200点 
				// 6怪（Firefly回血） 5%：实心倒三角▼：spd：1/1/1/1/2/2   hp：20/50/120/240/500/1200  hlk: 10/20/60/120/170/500    hlr：2/2/2/3/4/4  exp：5/5/70/100/230/460 寻路：走到离玩家4距离  
				switch (mp[i+py][j+py] % 10){
					case 1:{
						printf("○");
						break;
					}
					case 2:{
						printf("▲");
						break;
					}
					case 3:{
						printf("◆");
						break;
					}
					case 4:{
						printf("★");
						break;
					}
					case 5:{
						printf("□");
						break;
					}
					case 6:{
						printf("▼");
						break;
					}
				}
				if (CUST) printf(" ");
				color(1);
			}
		} 
		printf("■");if (CUST) printf(" ");
		if (i == nx - 15){
			cout << "当前等级：" << lv << "级     经验:" << Exp << "/" << lv * lv * 20;
		} else if (i == nx - 14){
			cout << "血量：[";
			for (int i = 0; i < 20; i++)
				if (hp > mxhp * 1.0 * i / 20){
					cout << "■";
				} else {
					cout << ' ';
					if (!CUST) cout << ' ';
				}
			cout << "] (" << hp << "/" << mxhp << ")";
		} else if (i == nx - 13){
			cout << "携带技能1：" << sklst[skill[1]]; 
		} else if (i == nx - 12){
			cout << "携带技能2：" << sklst[skill[2]];
		} else if (i == nx - 11){
			cout << "携带技能3：" << sklst[skill[3]];
		} else if (i == nx - 10){
			cout << "携带技能4：" << sklst[skill[4]];
		} else if (i == nx - 9){
			cout << "携带技能5：" << sklst[skill[5]];
		}
		puts("");
	}
	for (int j = ny - 16; j <= ny + 16; j++){cout << "■"; if (CUST) printf(" ");}
	puts("");
}
void spwan(){
	// 1怪（Soldier Ant）30%：空心圆圈怪○：spd：1/1/1/1/2/2   hp：20/50/120/240/500/1200  atk: 20/50/120/240/500/1200  atr：2/2/2/2/2/2   exp：1/1/10/50/150/300                      
	// 2怪（Leech）      20%：实心三角怪▲：spd：2/2/2/3/4/5   hp：10/30/70/110/300/750    atk：15/30/80/180/300/800    atr：2/2/2/2/2/2   exp：1/1/15/60/150/300 吸血：50%向下取整
	// 3怪（Hornet）     15%：实心菱形怪◆：spd: 1/1/1/1/2/2   hp: 10/30/70/110/300/750    atk: 10/25/80/190/350/900    atr：4/4/5/5/6/8  exp：2/2/25/80/200/400 寻路：走到能攻击到的的最远位置攻击 
	// 4怪（Starfish）   15%：实心五角星★：spd：1/1/1/1/2/2   hp：20/50/120/240/500/1200  atk：15/30/80/180/300/800    atr：2/2/2/2/2/2  exp：2/2/25/80/200/400 回血：25%血以下时回撤，每次操作回10%血，回满后或被攻击且血量大于25%继续攻击  
	// 5怪（Leafbug）    15%：空心方形怪□：spd：1/1/1/1/1/1   hp：35/75/160/350/670/1400  atk：10/25/80/190/350/900    atr：2/2/2/2/2/2  exp：2/2/20/70/180/350 减伤：收到伤害减少4/10/20/50/100/200点 
	// 6怪（Firefly回血） 5%：实心倒三角▼：spd：1/1/1/1/2/2   hp：20/50/120/240/500/1200  hlk: 10/20/60/120/170/500    hlr：2/2/2/3/4/4  exp：5/5/70/100/230/460 寻路：走到离玩家4距离  
	for (int i = 1; i <= 50; i++){
		int type = rand() % 100 + 1;
		if (type <= 30) type = 1;
		else if (type <= 50) type = 2;
		else if (type <= 65) type = 3;
		else if (type <= 80) type = 4;
		else if (type <= 95) type = 5;
		else type = 6;
		int emlv = rand() % 100 + 1;
		// 概率：15%/15%/15%/30%/20%/5%
		if (emlv <= 15) emlv = 1;
		else if (emlv <= 30) emlv = 2;
		else if (emlv <= 45) emlv = 3;
		else if (emlv <= 75) emlv = 4;
		else if (emlv <= 95) emlv = 5;
		else emlv = 6;
		int sigma = rand() % 20164 + 1;
		int pspy = 0;
		int now = 1, add = 1;
		while (sigma > 0){
			sigma -= now;
			now += add;
			if (now >= 142) add = -1;
			if (sigma <= 0){
				pspy = (142 - now) * (-add);
				break;
			}
		}
		int emps1 = emps[emlv] + pspy;
		if (emps1 <= 0){
			cout << "ERROR!" << emps1 << ' ' << emlv << ' ' << pspy << '\n';
		}
		int x = rand() % (min(1001 - emps1, (emps1 + 1))) + (max(0, emps1 - 500));
		int fx = rand() % 2 == 0 ? -1 : 1;
		int fy = rand() % 2 == 0 ? -1 : 1;
		int y = emps1 - x;
		while (!in(x*fx, y*fy) || mp[x*fx+py][y*fy+py] != 0){
	    	x = rand() % (min(1001 - emps1, (emps1 + 1))) + (max(0, emps1 - 500));
	    	fx = rand() % 2 == 0 ? -1 : 1;
	    	fy = rand() % 2 == 0 ? -1 : 1;
	    	y = emps1 - x;
		}
		if (y < 0){
			exit(0);
		}
		mp[x*fx+py][y*fy+py] = emlv * 10 + type;
	}
}
void game(){
	int x = 0, y = 0;
	mp[x][y] = 0;
	mxhp = lv * 100;
	hp = mxhp;
	atk = lv * 5;
	atr = 2;
	while (1){
		SetPos(0, 0);
		printmp(x, y);
		char c = getch();
		
		if (c == 'w' && in(x-1, y) && mp[x-1+py][y+py] == 0) x--;
		if (c == 'a' && in(x, y-1) && mp[x+py][y-1+py] == 0) y--;
		if (c == 's' && in(x+1, y) && mp[x+1+py][y+py] == 0) x++;
		if (c == 'd' && in(x, y+1) && mp[x+py][y+1+py] == 0) y++;
		spwan();
	}
}
void READ(){
	stting();
	CUST = 1; 
	lv = tp = 1; 
	Exp = 0;
}
void init(){
	srand(seed);
	READ(); Hide(); FULLScreen(); setmp();
}
signed main(){
	seed = time(0)^random_device()();
	init();
	game(); 
	return 0;
}


/*
1.2.6.7 测试版 by sh_Andy

更新日志：
1.小游戏 密室逃脱 更新中 [2740] 
2.更多地形（扩展地图）更新中 [2000]
*/

/*
1.2.6.3 测试版 by sh_Andy

更新日志：
1.更新了更新日志
2.修复了若干个bug
3.新增了存档功能（在菜单中）
4.优化了部分内容
5.更新了自动全屏 
6.添加了内置小游戏
7.添加了地形草地，沼泽，山脉，优化了森林配色（代码行数破3000啦！！） 
8.添加了校验码，防止有人篡改存档数据 
9.添加了地形矿脉与开发者模式 
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
const int N = 30;
const int H = 10; 
const int W = 50;
const int check_mod = 182382887;
bool FLAG=false,FLAG2=false,WAS=false,CUST=false;
int m[N+5][N+5],v[N+5][N+5],h[H+5][H+5],tv[N+5][N+5],c,g[N+5][N+5],w[N+5][W+5],wx=1,wy=1;
int wood;     //木材 
int rock;     //石子 
int money;     //金币 
int stone;     //石料
int board;     //木板 
int knife;     //小刀 
int spear;     //矛 
int meat;     //肉 
int water;     //水 
int axe;     //斧子
int pickaxe;     //镐子
int saw;     //锯子 
int crop;     //谷物
int vegetable;     //蔬菜 
int vine; // 藤蔓 
int diamond,hejin,jin,yin,tong,ti,gang,mei; 
int qdiamond,qjin,qyin,qtong,qti;
//钻石，玉佩，项链，手镯 
int TIME=50;     //文字输出停顿时间 
bool animal=true,enter=false;
int x=1,y=1,vis[N+5][N+5],wis[N+5][W+5],dx[]{1,0,-1,0},dy[]{0,1,0,-1},shishen=10;

void SAVE();
void READ();
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

void update(int i,int j,int k=2){
	if(k<0) return;
	vis[i][j]=1;
	for(int a=0;a<4;++a){
		int xx=i+dx[a],yy=j+dy[a];
		if(xx<1||yy<1||xx>N||yy>N) continue;
		update(xx,yy,k-1);
	}
}
void update2(int i,int j,int k=2){
	if(k<0) return;
	if(money>=100&&!wis[i][j]) money-=100,wis[i][j]=1;
	for(int a=0;a<4;++a){
		int xx=i+dx[a],yy=j+dy[a];
		if(xx<1||yy<1||xx>N||yy>W) continue;
		update2(xx,yy,k-1);
	}
}
void forest(){
	system("cls");
	int x=1,y=1;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=N;++i) for(int j=1;j<=N;++j){
		int t=rand()%13;
		if(t<7) m[i][j]=1;
		else if(t<10) m[i][j]=2;//m[i][j]='■';
		else if(t<12) m[i][j]=4;
		else m[i][j]=3;//m[i][j]='□';
	}
	update(x,y); m[1][1]=1;
	while(1){
		SetPos(0,0);
		printf("<森林>（按ESC返回）\n  ");
		color(3);
		printf("..");
		color(1);
		printf(" 空地  ");
		color(8);
		printf("■");
		color(1);
		printf("阻挡物（树、石头等）  ");
		color(7);
		printf("□");
		color(1);
		printf("木材  ◎石子\n\n木材：%lld  石子：%lld  木板：%lld  石料：%lld                            \n",wood,rock,board,stone);
		for(int i=1;i<=N;++i){
			for(int j=1;j<=N;++j){
				if(x==i&&y==j){
					color(5);
					cout<<"●"; if(CUST){cout<<' ';}
					color(1);
					continue;
				}
				if(vis[i][j]){
					if(m[i][j]==1) color(3), printf("..");  //空地 
					if(m[i][j]==2) {color(8), printf("■"); if(CUST){cout<<' ';}}  //阻挡物（树、石头等） 
					if(m[i][j]==3) {color(7), printf("□"); if(CUST){cout<<' ';}}  //木材 
					if(m[i][j]==4) {color(1), printf("◎"); if(CUST){cout<<' ';}}  //石子 
				}else printf("  ");
			}
			puts("");
		}
		color(1);
		c=getch();
		if(c==27) break;
		if(c=='s'&&(m[x+1][y]!=2||pickaxe)) x=min(x+1,N);
		if(c=='a'&&(m[x][y-1]!=2||pickaxe)) y=max(y-1,1);
		if(c=='w'&&(m[x-1][y]!=2||pickaxe)) x=max(x-1,1);
		if(c=='d'&&(m[x][y+1]!=2||pickaxe)) y=min(y+1,N);
		update(x,y);
		if(m[x][y]==3){
			if(axe) wood+=2;
			else if(saw) wood+=5; 
			else wood++;
			m[x][y]=1;
		}
		if(m[x][y]==4){
			rock++;
			m[x][y]=1;
		}
		if(m[x][y]==2&&pickaxe){
			stone++,wood++;
			if(axe) wood++;
			if(saw) wood+=3;
			m[x][y]=4;
		}
		int tmp=rand()%50;
		if(animal&&!tmp){
			c=0;
			system("cls");
			SlowSpeak("你的眼前闪过一个黑影，原来是一只动物，是否追逐？\n");
			cout<<"1.是     2.否";
			while(c!=1&&c!=2) c=getch(),c-='0';
			if(c==1){
				if(spear||knife) tmp=rand()%5;
				else tmp=rand()%10;
				if(tmp==1){
					system("cls");
					int num=1+rand()%8;
					SlowSpeak("经过不懈的努力与追逐，你猎取了那只动物，获得 [肉类 x");
					printf("%lld",num); Sleep(TIME); SlowSpeak("]。");
					meat+=num;
				}else{
					system("cls");
					SlowSpeak("很遗憾，动物跑走了...");
				}
				Sleep(1000);
			}else{
				system("cls");
				SlowSpeak("动物跑走了...");
				Sleep(1000);
			}
			system("cls");
		}
	}
	system("cls");
} 
void market(){
	int place=1; 
	while(1){
		system("cls");
		puts("<集市>（按ESC离开）");
		if(place==1){
			printf("木材：%lld  小石子：%lld  木板：%lld  石料：%lld  金币：%lld\n\n",wood,rock,board,stone,money);
			printf("1. 50石子 -> 5金币\n");
			printf("2. 50木材 -> 10金币\n");
			printf("3. 20金币 -> 100木材\n");
			printf("4. 10金币 -> 1石料\n");
			printf("5. 50石子 + 5金币 -> 1石料\n");
			printf("6. 1木材 + 5金币 -> 1木板\n");
			printf("7. 1石料 -> 10金币\n");
			printf("8. 10石料 -> 100金币\n");
			printf("9. 10木材 + 50金币 -> 10木板\n");
			printf("0. 去别处看看...\n");
			c=getch();
			if(c==27) break;
			c-='0';
			if(c==1){
				if(rock>=50){
					system("cls");
					printf("兑换成功！");
					rock-=50,money+=5;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==2){
				if(wood>=50){
					system("cls");
					printf("兑换成功！");
					wood-=50,money+=10;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==3){
				if(money>=20){
					system("cls");
					printf("兑换成功！");
					money-=20,wood+=100;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==4){
				if(money>=10){
					system("cls");
					printf("兑换成功！");
					money-=10,stone++;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==5){
				if(rock>=50&&money>=5){
					system("cls");
					printf("兑换成功！");
					rock-=50,money-=5,stone++;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==6){
				if(wood>0&&money>=5){
					system("cls");
					printf("兑换成功！");
					wood--,money-=5,board++;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==7){
				if(stone>0){
					system("cls");
					printf("兑换成功！");
					stone--,money+=10;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==8){
				if(stone>9){
					system("cls");
					printf("兑换成功！");
					stone-=10,money+=100;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==9){
				if(wood>9&&money>=50){
					system("cls");
					printf("兑换成功！");
					wood-=10,money-=50,board+=10;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==0) place=2;
		}else if(place==2){
			cout<<"肉："<<meat<<"  水："<<water<<"  金币："<<money<<"\n\n";
			cout<<"1. 20金币 -> 1肉\n";
			cout<<"2. 1肉 -> 20金币\n";
			cout<<"3. 200金币 -> 10肉\n";
			cout<<"4. 10肉 -> 200金币\n"; 
			cout<<"5. 100水 -> 5金币\n";
			cout<<"6. 5金币 -> 100水\n";
			cout<<"7. 10000水 -> 500金币\n";
			cout<<"8. 500金币 -> 10000水\n";
			cout<<"0. 去别处看看...\n";
			c=getch();
			if(c==27) break;
			c-='0';
			if(c==1){
				if(money>=20){
					system("cls");
					printf("兑换成功！");
					money-=20,meat++;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==2){
				if(meat>0){
					system("cls");
					printf("兑换成功！");
					meat--,money+=20;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==3){
				if(money>=200){
					system("cls");
					printf("兑换成功！");
					money-=200,meat+=10;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==4){
				if(meat>9){
					system("cls");
					printf("兑换成功！");
					meat-=10,money+=200;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==5){
				if(water>=100){
					system("cls");
					printf("兑换成功！");
					water-=100,money+=5;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==6){
				if(money>=5){
					system("cls");
					printf("兑换成功！");
					money-=5,water+=100;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==7){
				if(water>=10000){
					system("cls");
					printf("兑换成功！");
					water-=10000,money+=500;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==8){
				if(money>=500){
					system("cls");
					printf("兑换成功！");
					money-=500,water+=10000;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==0) place=3;
		}else if(place==3){
			cout<<"小刀："<<knife<<"  长矛："<<spear<<"  斧子："<<axe<<"  镐子："<<pickaxe<<"  锯子"<<saw<<"  金币："<<money<<"\n\n";
			cout<<"1. 30金币 -> 1小刀\n";
			cout<<"2. 35金币 -> 1长矛\n";
			cout<<"3. 35金币 -> 1斧子\n";
			cout<<"4. 70金币 -> 1镐子\n";
			cout<<"5. 70金币 -> 1锯子\n";
			cout<<"0. 去别处看看...\n";
			c=getch();
			if(c==27) break;
			c-='0';
			if(c==1){
				if(money>=30){
					system("cls");
					printf("兑换成功！");
					money-=30,knife++;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==2){
				if(money>=35){
					system("cls");
					printf("兑换成功！");
					money-=35,spear++;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==3){
				if(money>=35){
					system("cls");
					printf("兑换成功！");
					money-=35,axe++;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==4){
				if(money>=70){
					system("cls");
					printf("兑换成功！");
					money-=70,pickaxe++;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==5){
				if(money>=70){
					system("cls");
					printf("兑换成功！");
					money-=70,saw++;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==0) place=4;
		}else if(place==4){
			cout<<"钻石：" << diamond << "  合金："<<hejin<<"  金："<<jin<<"  银："<<yin<<"  钢："<<gang<<"  铜："<<tong<<"  铁："<<ti<<"  煤："<<mei<<"  金币："<<money<<"\n\n";
			cout<<"1. 1500金币 -> 1钻石\n";
			cout<<"2. 1000金币 -> 1合金\n";
			cout<<"3. 500金币 -> 1金\n";
			cout<<"4. 400金币 -> 1银\n";
			cout<<"5. 350金币 -> 1钢\n";
			cout<<"6. 300金币 -> 1铜\n";
			cout<<"7. 250金币 -> 1铁\n";
			cout<<"8. 50金币 -> 1煤\n";
			cout<<"0. 去别处看看...\n";
			c=getch();
			if(c==27) break;
			c-='0';
			if(c==1){
				if(money>=1500){
					system("cls");
					printf("兑换成功！");
					money-=1500,diamond++;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==2){
				if(money>=1000){
					system("cls");
					printf("兑换成功！");
					money-=1000,hejin++;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==3){
				if(money>=500){
					system("cls");
					printf("兑换成功！");
					money-=500,jin++;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==4){
				if(money>=400){
					system("cls");
					printf("兑换成功！");
					money-=400,yin++;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==5){
				if(money>=350){
					system("cls");
					printf("兑换成功！");
					money-=350,gang++;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==6){
				if(money>=300){
					system("cls");
					printf("兑换成功！");
					money-=300,tong++;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==7){
				if(money>=250){
					system("cls");
					printf("兑换成功！");
					money-=250,ti++;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==8){
				if(money>=50){
					system("cls");
					printf("兑换成功！");
					money-=50,mei++;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==0) place=1;
		}
	}
	system("cls");
}
void house(){
	int x=H,y=5,b[15][15],meat1=0,spear1=0,knife1=0,board1=0,stone1=0;
	memset(h,0,sizeof(h)); 
	system("cls");
	for(int i=1;i<=H;++i) for(int j=1;j<=H;++j){
		if(i==H&&(j==5||j==6)) h[i][j]=2;
		else if(i==1||j==1||i==H||j==H) h[i][j]=1;
		else if(j==2&&(i==2||i==3)) h[i][j]=3;
		else if(i==2&&j==3||j==H-1&&i>1&&i<H) h[i][j]=4;
	}
	bool P=false;
	while(1){
		SetPos(0,0);
		cout<<"<村民的家>\n\n";
		for(int i=1;i<=H;++i){
			for(int j=1;j<=H;++j){
				if(i==x&&y==j){
					color(5);
					cout<<"●"; if(CUST){cout<<' ';}
					color(1);
					continue;
				}
				if(h[i][j]==1) {cout<<"■"; if(CUST){cout<<' ';}}
				if(h[i][j]==0) cout<<"..";
				if(h[i][j]==2) cout<<"门";
				if(h[i][j]==3) cout<<"床";
				if(h[i][j]==4) {cout<<"□"; if(CUST){cout<<' ';}} 
			}
			puts("");
		}
		c=getch();
		if(c=='s'&&h[x+1][y]!=1) x++; 
		if(c=='d'&&h[x][y+1]!=1) y++; 
		if(c=='w'&&h[x-1][y]!=1) x--; 
		if(c=='a'&&h[x][y-1]!=1) y--; 
		x=min(x,10),y=min(y,10),x=max(x,2),y=max(y,2);
		if(h[x][y]==2&&(!enter||enter&&c==13)) break;
		if(h[x][y]==4&&(!enter||enter&&c==13)){
			int X=2,Y=2;
			system("cls");
			for(int i=1;i<=10;++i) for(int j=1;j<=10;++j){
				if(i==1||i==10||j==1||j==10){b[i][j]=1; continue;}
				int tmp=rand()%64;
				if(tmp<30) b[i][j]=2;
				else if(tmp<40) b[i][j]=3;
				else if(tmp<50) b[i][j]=4;
				else if(tmp<60) b[i][j]=5;
				else if(tmp<63) b[i][j]=6;
				else b[i][j]=7;
			}
			while(1){
				SetPos(0,0);
				cout<<"<村民的箱子>（按ESC返回，空格拿取）\n\n";
				for(int i=1;i<=10;++i) for(int j=1;j<=10;++j){
					if(X==i&&Y==j){
						color(5);
						cout<<"●"; if(CUST){cout<<' ';};
						color(1);
						continue;
					}
					if(b[i][j]==1) {cout<<"■"; if(CUST){cout<<' ';}}
					if(b[i][j]==2) {cout<<"□"; if(CUST){cout<<' ';}}
					if(b[i][j]==3) cout<<"肉";
					if(b[i][j]==4) cout<<"木";
					if(b[i][j]==5) cout<<"石";
					if(b[i][j]==6) cout<<"刀";
					if(b[i][j]==7) cout<<"矛"; 
					if(j==10) puts("");
				}
				c=getch();
				if(c==27) break;
				if(c=='a') Y--;
				if(c=='d') Y++;
				if(c=='w') X--;
				if(c=='s') X++;
				X=max(X,2),Y=max(Y,2),X=min(X,9),Y=min(Y,9);
				if(c==' '){
					if(b[X][Y]==3) meat1++;
					if(b[X][Y]==4) board1++;
					if(b[X][Y]==5) stone1++;
					if(b[X][Y]==6) knife1++;
					if(b[X][Y]==7) spear1++;
					b[X][Y]=2;
					P=true;
				} 
			}
			system("cls");
		}
		if(h[x][y]==3&&(!enter||enter&&c==13)){
			system("cls");
			while(1){
				SetPos(0,0);
				cout<<"<村民的床>（按ESC起床）\n\n晚安，玛卡巴卡ZZZ...\n（你安详地睡了）";
				c=getch();
				if(c==27) break;
			}
			system("cls");
		}
		bool flag=false;
		int tmp;
		if(P) tmp=rand()%2;
		else tmp=rand()%1000;
		if(tmp==1){
			system("cls");
			for(int i=1;i<=H;++i){
				for(int j=1;j<=H;++j){
					if(i==x&&y==j){
						color(5);
						cout<<"●"; if(CUST){cout<<' ';}
						color(1);
						continue;
					}
					if(i==H&&j==6){
						cout<<"民";
						continue;
					}
					if(h[i][j]==1) {cout<<"■"; if(CUST){cout<<' ';}}
					if(h[i][j]==0) cout<<"..";
					if(h[i][j]==2) cout<<"门";
					if(h[i][j]==3) cout<<"床";
					if(h[i][j]==4) {cout<<"□"; if(CUST){cout<<' ';}}
				}
				puts("");
			}
			Sleep(100);
			while(1){
				SetPos(0,0);
				for(int i=1;i<=H;++i){
					for(int j=1;j<=H;++j){
						if(i==x&&y==j){
							color(5);
							cout<<"●"; if(CUST){cout<<' ';}
							color(1);
							continue;
						}
						if(i+1==H&&j==6){
							cout<<"民";
							continue;
						}
						if(h[i][j]==1) {cout<<"■"; if(CUST){cout<<' ';}}
						if(h[i][j]==0) cout<<"..";
						if(h[i][j]==2) cout<<"门";
						if(h[i][j]==3) cout<<"床";
						if(h[i][j]==4) {cout<<"□"; if(CUST){cout<<' ';}} 
					}
					puts("");
				} 
				cout<<"\n";
				Sleep(100);
				cout<<"[村民]：";
				SlowSpeak("你是谁，为什么在我家里！？！\n");
				cout<<"\n\n1.我是你爹     2.对不起\n\n3.这是我家     4.怎么滴，打我呀";
				c=0;
				while(c<1||c>4) c=getch(),c-='0';
				system("cls");
				for(int i=1;i<=H;++i){
					for(int j=1;j<=H;++j){
						if(i==x&&y==j){
							color(5); 
							cout<<"●"; if(CUST){cout<<' ';}
							color(1);
							continue;
						}
						if(i+1==H&&j==6){
							cout<<"民";
							continue;
						}
						if(h[i][j]==1) {cout<<"■"; if(CUST){cout<<' ';}}
						if(h[i][j]==0) cout<<"..";
						if(h[i][j]==2) cout<<"门";
						if(h[i][j]==3) cout<<"床";
						if(h[i][j]==4) {cout<<"□"; if(CUST){cout<<' ';}} 
					}
					puts("");
				}
				puts("");
				Sleep(500);
				cout<<"[村民]：";
				if(c==1){
					if(rand()%20==0){
						SlowSpeak("什么，原来你是我失散多年的亲爹！爸爸啊，你知道你不在的这些年我是怎么过的吗？！");
						cout<<"\n\n[你]：（不忍直视，缓缓离开）";
						Sleep(250);
					}else SlowSpeak("大 * * ，滚出去！");
				}
				if(c==2) SlowSpeak("那请你出去。");
				if(c==3) SlowSpeak("神经病出去！");
				if(c==4) SlowSpeak("好好好...");
				Sleep(1000);
				system("cls");
				if(c==4){
					Sleep(1000);
					cout<<"[你]：";
					SlowSpeak("别打了！别打了...（提示：部分物资归零，金币 -1000）");
					Sleep(1000);
					system("cls");
					Sleep(1000);
					wood=0,rock=0,money-=1000,stone=0,board=0,meat=0,water=0,crop=0,vegetable=0;
					money=max(money,0);
				}else Sleep(1000);
				flag=true;
				break;
			}
			system("cls");
		}
		if(flag){
			meat1=board1=stone1=knife1=spear1=0;
			break;
		}
	}
	system("cls");
	meat+=meat1;
	board+=board1;
	stone+=stone1;
	knife+=knife1;
	spear+=spear1;
} 
string NAME="达除石";  //大厨师 
bool GAME(){
	int x=1,y=1,score=0,ds=0;
	system("cls");
	for(int i=1;i<=N;++i) for(int j=1;j<=N;++j){
		int t=rand()%13;
		if(t<7) g[i][j]=1;
		else if(t<10) g[i][j]=2;
		else if(t<12) g[i][j]=3;
		else g[i][j]=4;
	}
	g[1][1]=1;
	while(1){
		SetPos(0,0); 
		cout<<"\n\n\n                                                                                        ";
		SetPos(0,0);
		bool A=true;
		cout<<"<食神大赛>（按ESC认输）\n .. 空地  ■障碍物（碰到积分减10）  □食材（碰到积分加5）  ☆菜谱（碰到积分加20）                                    \n\n";
		cout<<"你的得分："<<score<<"  "<<NAME<<"的得分："<<ds<<"\n";
		for(int i=1;i<=H;++i){
			for(int j=1;j<=H;++j){
				if(g[i][j]!=1&&g[i][j]!=2) A=false;
				if(i==x&&y==j){
					color(5);
					cout<<"●"; if(CUST){cout<<' ';}
					color(1);
					continue;
				}
				if(g[i][j]==1) cout<<"..";
				if(g[i][j]==2) {cout<<"■"; if(CUST){cout<<' ';}}
				if(g[i][j]==3) {cout<<"□"; if(CUST){cout<<' ';}}
				if(g[i][j]==4) {cout<<"☆"; if(CUST){cout<<' ';}}
			}
			puts("");
		}
		if(A) return score>=ds;
		c=getch();
		if(c==27) return false;
		if(c=='w') x--;
		if(c=='s') x++;
		if(c=='a') y--;
		if(c=='d') y++;
		x=max(x,1),y=max(y,1),x=min(x,H),y=min(y,H);
		if(g[x][y]==2) score-=10;
		if(g[x][y]==3) score+=5;
		if(g[x][y]==4) score+=20;
		if(g[x][y]!=1) g[x][y]=1;
		int t=rand()%13;
		if(t<5) ;
		else if(t<10) ds+=5;
		else if(t<12) ds-=5;
		else ds+=20;
	}
	system("cls");
}
void attend(){
	system("cls");
	cout<<"<食神大赛>\n\n";
	cout<<"Round 01：\n你 vs "<<NAME<<"\n\n";
	Sleep(1200);
	system("cls");
	while(1){
		if(GAME()){
			system("cls");
			cout<<"你赢了！";
			Sleep(1200);
			system("cls"); 
			break;
		}else{
			system("cls");
			cout<<"很遗憾，你败下阵来...";
			Sleep(1200);
			system("cls");
			return;
		}
	}
	int tmp=rand()%2;
	if(tmp==0) NAME="钱才";  //钱财 
	else NAME="布慧莹";  //不会赢 
	system("cls");
	cout<<"<食神大赛>\n\n";
	cout<<"Round 02：\n你 vs "<<NAME<<"\n\n";
	Sleep(1200);
	system("cls");
	while(1){
		if(GAME()){
			system("cls");
			cout<<"你赢了！";
			Sleep(1200);
			system("cls"); 
			break;
		}else{
			system("cls");
			cout<<"很遗憾，你败下阵来...";
			Sleep(1200);
			system("cls");
			return;
		}
	}
	tmp=rand()%3;
	if(!tmp) NAME="宋仁头";  //送人头 
	else if(tmp==1) NAME="艾昆";  //爱坤 
	else NAME="张迪";  //作者的姓氏（张） + sh_Andy的 dy 
	system("cls");
	cout<<"<食神大赛>\n\n";
	cout<<"Round 03：\n你 vs "<<NAME<<"\n\n";
	Sleep(1200);
	system("cls");
	while(1){
		if(GAME()){
			system("cls");
			cout<<"你赢了！";
			Sleep(1200);
			system("cls"); 
			break;
		}else{
			system("cls");
			cout<<"很遗憾，你败下阵来...";
			Sleep(1200);
			system("cls");
			return;
		}
	}
	system("cls");
	cout<<"恭喜你赢得了第"<<shishen<<"届食神大赛的冠军！\n\n获得 [金币 x1500]";
	money+=1500,shishen++;
	Sleep(2000);
	system("cls");
}
void notattend(){
	system("cls");
	int cnt=clock()-10000+1000;
	while(1){
		SetPos(0,0);
		cout<<"<食神大赛>\n\n观看中（按ESC离开）\n\n";
		if(kbhit()){
			c=getch();
			if(c==27) break;
		}
		if(clock()-cnt>10000){
			money++;
			puts("金币 +1 ");
			Sleep(500);
			cnt=clock();
		}else{
			puts("               ");
		}
	}
	system("cls");
}
void barn(){
	int place=1;
	bool C=false;
	system("cls");
	cout<<"<粮仓>\n\n";
	cout<<"[村民]：";
	SlowSpeak("大家慢慢兑换，不要着急，都可以兑换的。\n        要兑换的去兑换，要去看食神比赛的去看。");
	cout<<"\n\n";
	system("pause");
	system("cls");
	while(1){
		system("cls");
		cout<<"<粮仓>（按ESC离开）\n";
		if(place==1){
			cout<<"谷物："<<crop<<"  蔬菜："<<vegetable<<"  金币："<<money<<"\n\n";
			cout<<"1. 20金币 -> 40谷物\n";
			cout<<"2. 20金币 -> 20蔬菜\n";
			cout<<"3. 20谷物 -> 10金币\n";
			cout<<"4. 20蔬菜 -> 20金币\n";
			cout<<"0. 去别处看看...\n" ;
			c=getch();
			if(c==27) break;
			c-='0';
			if(c==1){
				if(money>=20){
					system("cls");
					printf("兑换成功！");
					money-=20,crop+=40;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==2){
				if(money>=20){
					system("cls");
					printf("兑换成功！");
					money-=20,vegetable+=20;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==3){
				if(crop>=20){
					system("cls");
					printf("兑换成功！");
					crop-=20,money+=10;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==4){
				if(vegetable>=20){
					system("cls");
					printf("兑换成功！");
					vegetable-=20,money+=20;
					Sleep(750);
				}else{
					system("cls");
					printf("兑换物不够...");
					Sleep(750);
				}
			}
			if(c==0){place=2; C=true;}
		}else if(place==2){
			if(C){
				system("cls");
				cout<<"<粮仓>（按ESC离开）\n\n";
				Sleep(100);
				cout<<"[主持人]：";
				SlowSpeak("那么我们一年一度的食神大赛，现在开始！！！");
				puts("\n");
				Sleep(100);
				cout<<"[村民们]：（欢呼）";
				Sleep(1250); 
				system("cls");
				cout<<"<粮仓>（按ESC离开）\n";
			}
			cout<<"\n1. 参与比赛\n";
			cout<<"2. 观看比赛\n";
			cout<<"0. 去别处看看\n";
			c=getch();
			if(c==27) break;
			c-='0';
			if(c==1) attend();
			if(c==2) notattend();  
			if(c==0) place=1;
			C=false;
		}
	}
	system("cls");
}
void dream(){
	system("cls");
	int n=rand()%50+50;
	int k=rand()%5+11;
	int i,a,b;
	cout<<"<梦>\n\n[山崩游戏]\n游戏规则：玩家每次需要输入一个小于等于k的数（计算机随机一个小于等于k的数），\n          当玩家或计算机把n变成0或1，ta就胜利了，\n          当计算机胜利或玩家把n变为负数或玩家违反规则时失败。"<<endl;
	cout<<"n:"<<n<<", k:"<<k<<"\n"; 
	for(i=1;i<=6;++i){
		cout<<"请输入1个小于等于k的正整数: ";
		cin>>a;
		if(a>k){
			cout<<"\n你违反规则了...\n";
			break;
		}
		n-=a;
		cout<<"n:"<<n<<", k:"<<k<<"\n";
		if(n==0||n==1){
			cout<<"\n你赢了!\n";
			break;
		}
		if(n<0){
			cout<<"\n你输了...\n";
			break;
		}
		if(n>k+1) b=rand()%k+1;
		else if(n<=k+1) b=n-1;
		n-=b;
		cout<<"计算机的数字:"<<b<<", n:"<<n<<"\n";
		if(n==0||n==1){
			cout<<endl<<"\n你输了...\n"<<endl;
			break;
		} 
	}
	if(i>6) cout<<endl<<"\n进过6轮战斗,你和计算机握手言和\n"<<endl;
	puts(""); system("pause"); system("cls");
}
void ownhouse(int x1=x,int y1=y){
	memset(h,0,sizeof(h));
	int x=H,y=5,b[15][15];
	for(int i=1;i<=H;++i) for(int j=1;j<=H;++j){
		if(i==H&&(j==5||j==6)) h[i][j]=2;
		else if(i==1||j==1||i==H||j==H) h[i][j]=1;
		else if((j==2||j==3)&&(i==2||i==3)) h[i][j]=3;
		else if(i==2&&j==4||j==H-1&&i>1&&i<H) h[i][j]=4;
		else if((i==5||i==6)&&j==5) h[i][j]=5;
		else if((i==5||i==6)&&j==6) h[i][j]=6;
	}
	system("cls");
	while(1){
		SetPos(0,0);
		cout<<"<房屋>（按h出售）\n\n";
		for(int i=1;i<=H;++i) for(int j=1;j<=H;++j){
			if(i==x&&j==y){
				color(5);
				cout<<"●"; if(CUST){cout<<' ';}
				color(1);
				continue;
			}
			if(h[i][j]==0) cout<<"..";
			if(h[i][j]==1) {cout<<"■"; if(CUST){cout<<' ';}}
			if(h[i][j]==2) cout<<"门";
			if(h[i][j]==3) cout<<"床";
			if(h[i][j]==4) {cout<<"□"; if(CUST){cout<<' ';}} 
			if(h[i][j]==5) cout<<"楼";
			if(h[i][j]==6) cout<<"梯";
			if(j==H) puts("");
		}
		c=getch();
		if(c=='w'&&h[x-1][y]!=1) x--;
		if(c=='a'&&h[x][y-1]!=1) y--;
		if(c=='s'&&h[x+1][y]!=1) x++;
		if(c=='d'&&h[x][y+1]!=1) y++;
		if(c=='h'){
			system("cls");
			int tmp;
			while(1){
				SetPos(0,0);
				cout<<"是否确认出售？(Y/N)\n";
				tmp=getch();
				if(tmp>='A'&&tmp<='Z') tmp=tmp-'A'+'a';
				if(tmp=='y'||tmp=='n') break;
			}
			system("cls");
			if(tmp=='y'){
				cout<<"出售成功，获取[金币 x1670]！";
				money+=1670,v[x1][y1]=4;
				Sleep(1000);
				break;
			}
		}
		x=min(x,H),y=min(y,H),x=max(x,2),y=max(y,2);
		if(h[x][y]==2&&(enter&&c==13||!enter)) break; 
		if(h[x][y]==3&&(!enter||enter&&c==13)){
			system("cls");
			while(1){
				SetPos(0,0);
				cout<<"<床>（按ESC起床，按任意键做梦）\n\n晚安ZZZ...\n（你安详地睡了）";
				c=getch();
				if(c==27) break;
				dream();
			}
			system("cls");
		}
		if(h[x][y]==4&&(enter&&c==13||!enter)){
			int X=2,Y=2;
			system("cls");
			for(int i=1;i<=10;++i) for(int j=1;j<=10;++j){
				if(i==1||i==10||j==1||j==10){b[i][j]=1; continue;}
				int tmp=rand()%64;
				if(tmp<30) b[i][j]=2;
				else if(tmp<40) b[i][j]=3;
				else if(tmp<50) b[i][j]=4;
				else if(tmp<60) b[i][j]=5;
				else if(tmp<63) b[i][j]=6;
				else b[i][j]=7;
			}
			while(1){
				SetPos(0,0);
				cout<<"<箱子>（按ESC返回）\n\n";
				for(int i=1;i<=10;++i) for(int j=1;j<=10;++j){
					if(X==i&&Y==j){
						color(5);
						cout<<"●"; if(CUST){cout<<' ';}
						color(1);
						continue;
					}
					if(b[i][j]==1) {cout<<"■"; if(CUST){cout<<' ';}}
					if(b[i][j]==2) {cout<<"□"; if(CUST){cout<<' ';}}
					if(b[i][j]==3) cout<<"肉";
					if(b[i][j]==4) cout<<"木";
					if(b[i][j]==5) cout<<"石";
					if(b[i][j]==6) cout<<"刀";
					if(b[i][j]==7) cout<<"矛"; 
					if(j==10) puts("");
				}
				c=getch();
				if(c==27) break;
				if(c=='a') Y--;
				if(c=='d') Y++;
				if(c=='w') X--;
				if(c=='s') X++;
				X=max(X,2),Y=max(Y,2),X=min(X,H-1),Y=min(Y,H-1);
			}
			system("cls");
		}
		if((h[x][y]==5||h[x][y]==6)&&(enter&&c==13||!enter)){
			system("cls");
			for(int i=1;i<=10;++i) for(int j=1;j<=10;++j){
				if(i==1||i==10||j==1||j==10){b[i][j]=1; continue;}
				if((i==5||i==6)&&j==5) b[i][j]=3;
				else if((i==5||i==6)&&j==6) b[i][j]=4;
				else b[i][j]=2;
			}
			while(1){
				SetPos(0,0);
				cout<<"<地下室>\n\n";
				for(int i=1;i<=10;++i) for(int j=1;j<=10;++j){
					if(i==x&&j==y){
						color(5);
						cout<<"●"; if(CUST){cout<<' ';}
						color(1);
						continue;
					}
					if(b[i][j]==1) {cout<<"■"; if(CUST){cout<<' ';}}
					if(b[i][j]==2) cout<<"..";
					if(b[i][j]==3) cout<<"楼";
					if(b[i][j]==4) cout<<"梯";
					if(j==10) puts("");
				}
				c=getch();
				if(c=='a') y--;
				if(c=='d') y++;
				if(c=='w') x--;
				if(c=='s') x++;
				x=max(x,2),y=max(y,2),x=min(x,H-1),y=min(y,H-1);
				if(b[x][y]==3||b[x][y]==4) break;
			}
			system("cls");
		}
	}
	system("cls");
}
void farmland(){
	system("cls");
	memset(vis,0,sizeof(vis));
	int x=1,y=1;
	while(1){
		SetPos(0,0);
		cout<<"<农田>（按ESC离开，按空格收割）\n □未成熟的作物  ■成熟的作物\n 金币："<<money<<"\n\n";
		for(int i=1;i<=H;++i){
			for(int j=1;j<=H;++j){
				if(i==x&&y==j){
					color(5);
					cout<<"●"; if(CUST){cout<<' ';}
					color(1);
					continue;
				}
				if(!vis[i][j]) {cout<<"■"; if(CUST){cout<<' ';}}
				else {cout<<"□"; if(CUST){cout<<' ';}}
			}
			puts("");
		}
		c=getch();
		if(c==27) break;
		if(c=='w') x--;
		if(c=='a') y--;
		if(c=='s') x++;
		if(c=='d') y++;
		x=max(x,1),y=max(y,1),x=min(x,H),y=min(y,H);
		if(c==' '){
			if(!vis[x][y]){
				vis[x][y]=1;
				money++;
			}
		} 
	}
	system("cls");
}
void otherbarn(){
	system("cls");
	cout<<"<粮仓>\n\n";
	cout<<"[村民]：";
	SlowSpeak("诶诶，大家慢慢兑换，不要着急，都可以兑换的...");
	cout<<"\n\n";
	system("pause");
	system("cls");
	while(1){
		system("cls");
		cout<<"<粮仓>（按ESC离开）\n";
		cout<<"谷物："<<crop<<"  蔬菜："<<vegetable<<"  金币："<<money<<"\n\n";
		cout<<"1. 20金币 -> 40谷物\n";
		cout<<"2. 20金币 -> 20蔬菜\n";
		cout<<"3. 20谷物 -> 10金币\n";
		cout<<"4. 20蔬菜 -> 20金币\n";
		cout<<"0. 去别处看看...\n" ;
		c=getch();
		if(c==27) break;
		c-='0';
		if(c==1){
			if(money>=20){
				system("cls");
				printf("兑换成功！");
				money-=20,crop+=40;
				Sleep(750);
			}else{
				system("cls");
				printf("兑换物不够...");
				Sleep(750);
			}
		}
		if(c==2){
			if(money>=20){
				system("cls");
				printf("兑换成功！");
				money-=20,vegetable+=20;
				Sleep(750);
			}else{
				system("cls");
				printf("兑换物不够...");
				Sleep(750);
			}
		}
		if(c==3){
			if(crop>=20){
				system("cls");
				printf("兑换成功！");
				crop-=20,money+=10;
				Sleep(750);
			}else{
				system("cls");
				printf("兑换物不够...");
				Sleep(750);
			}
		}
		if(c==4){
			if(vegetable>=20){
				system("cls");
				printf("兑换成功！");
				vegetable-=20,money+=20;
				Sleep(750);
			}else{
				system("cls");
				printf("兑换物不够...");
				Sleep(750);
			}
		}
	}
	system("cls");
}
void swampshop(){
	system("cls");
	while (1){
		system("cls");
		cout<<"<商店>（按ESC离开）\n";
		cout<<"藤蔓："<<vine<<"  金币："<<money<<"\n\n";
		cout<<"1. 5藤蔓 -> 5金币\n";
		char c;
		c = getch();
		if (c == 27) break;
		if (c == '1'){
			if (vine>=5){
				system("cls");
				cout << "兑换成功！";
				vine -= 5;
				money += 5;
				Sleep(750);
			} else {
				system("cls");
				cout << "兑换物不够...";
				Sleep(750);
			}
		}
	}
	system("cls");
}
int goy(int x, int y, int aofy){
	while (m[x - aofy][y] == 1 || x - aofy > N) aofy++;
	return x - aofy;
}
void mountainshop(){
	system("cls");
	while (1){
		system("cls");
		cout<<"<商店>（按ESC离开）\n";
		cout<<"水："<<water<<"  谷物："<< crop << "  蔬菜：" << vegetable << "  肉：" << meat <<"  金币："<<money<<"\n\n";
		cout<<"1. 20金币 -> 10谷物\n";
		cout<<"2. 20金币 -> 5蔬菜\n";
		cout<<"3. 20金币 -> 100水\n";
		cout<<"4. 20谷物 -> 40金币\n";
		cout<<"5. 20蔬菜 -> 80金币\n";
		cout<<"6. 100水 -> 20金币\n";
		cout<<"7. 2000金币 -> 10000水\n";
		cout<<"8. 10000水 -> 2000金币\n"; 
		char c;
		c = getch();
		if (c == 27) break;
		if (c == '1'){
			if (money>=20){
				system("cls");
				cout << "兑换成功！";
				money -= 20;
				crop += 10;
				Sleep(750);
			} else {
				system("cls");
				cout << "兑换物不够...";
				Sleep(750);
			}
		}
		if (c == '2'){
			if (money>=20){
				system("cls");
				cout << "兑换成功！";
				money -= 20;
				vegetable += 5;
				Sleep(750);
			} else {
				system("cls");
				cout << "兑换物不够...";
				Sleep(750);
			}
		}
		if (c == '3'){
			if (money>=20){
				system("cls");
				cout << "兑换成功！";
				money -= 20;
				water += 100;
				Sleep(750);
			} else {
				system("cls");
				cout << "兑换物不够...";
				Sleep(750);
			}
		}
		if (c == '4'){
			if (crop>=20){
				system("cls");
				cout << "兑换成功！";
				crop -= 20;
				money += 40;
				Sleep(750);
			} else {
				system("cls");
				cout << "兑换物不够...";
				Sleep(750);
			}
		}
		if (c == '5'){
			if (vegetable>=20){
				system("cls");
				cout << "兑换成功！";
				vegetable -= 20;
				money += 80;
				Sleep(750);
			} else {
				system("cls");
				cout << "兑换物不够...";
				Sleep(750);
			}
		}
		if (c == '6'){
			if (water>=100){
				system("cls");
				cout << "兑换成功！";
				water -= 100;
				money += 20;
				Sleep(750);
			} else {
				system("cls");
				cout << "兑换物不够...";
				Sleep(750);
			}
		}
		if (c == '7'){
			if (money>=2000){
				system("cls");
				cout << "兑换成功！";
				money -= 2000;
				water += 10000;
				Sleep(750);
			} else {
				system("cls");
				cout << "兑换物不够...";
				Sleep(750);
			}
		}
		if (c == '8'){
			if (water>=10000){
				system("cls");
				cout << "兑换成功！";
				water -= 10000;
				money += 2000;
				Sleep(750);
			} else {
				system("cls");
				cout << "兑换物不够...";
				Sleep(750);
			}
		}
	} 
	system("cls");
}
bool dig(int type){
	if (!type) return 1;
	color(1);
	if (!pickaxe){
		cout << "无法挖取！请先获取镐子。";
		Sleep(750);
		return 0;
	}
	int time = type * 2;
	for (int i = 0; i <= time; i++){
		SetPos(34, 0);
		cout << "挖取";
		switch (type){
			case 1: cout << "岩石"; break; 
			case 2: cout << "煤"; break;
			case 3: cout << "铁矿"; break;
			case 4: cout << "铜矿"; break;
			case 5: cout << "银矿"; break;
			case 6: cout << "金矿"; break;
			case 7: cout << "钻石矿"; break;
		}"中......\n"; 
		cout << "进度：";
		int numb = i * 1.0 / time * 50;
		for (int j = 1; j <= numb; j++)
			cout << "■";
		for (int j = numb+1; j <= 50; j++)
			cout << "□";
		cout << "  " << (int)(i * 1.0 / time * 100) << "%\n";
		cout << "剩余时间：" << time - i << "s  \n"; 
		Sleep(1000);
	}
	SetPos(34, 0);
	cout << "                                                                  \n";
	cout << "                                                                  \n";
	cout << "                                                                  \n";
	SetPos(34, 0);
 	int num = 0;
	cout << "挖取完成！获得 ";
	switch (type){
		case 1: num = rand() % 6 + 10; cout << "[石料 x" << num << "]。"; stone += num; break;
		case 2: num = rand() % 4 + 5; cout << "[煤 x" << num << "]。"; mei += num; break;
		case 3: num = rand() % 4 + 3; cout << "[铁矿石 x" << num << "]。"; qti += num; break;
		case 4: num = rand() % 4 + 3; cout << "[铜矿石 x" << num << "]。"; qtong += num; break;
		case 5: num = rand() % 2 + 2; cout << "[银矿石 x" << num << "]。"; qyin += num; break;
		case 6: num = rand() % 3 + 1; cout << "[金矿石 x" << num << "]。"; qjin += num; break;
		case 7: num = rand() % 2 + 1; cout << "[钻石矿 x" << num << "]。"; qdiamond += num; break;
	} 
	cout << "（按任意键关闭）                                                               ";
	getch(); 
	SetPos(34, 0);
	cout << "                                                                  \n";
	cout << "                                                                  \n";
	cout << "                                                                  \n";
	return 1;
}
void othervillage(){
	system("cls");
	int x=1,y=1;
	for(int i=1;i<=N;++i) for(int j=1;j<=N;++j){
		int x=rand()%200;
		if(x<170) tv[i][j]=1; //.. 空地 
		else if(x<180) tv[i][j]=2; //☆集市 
		else if(x<190) tv[i][j]=4; //■房子 
		else tv[i][j]=3; //△粮仓 
	}
	while(1){
		SetPos(0,0);
		cout<<"<村庄>（按ESC离开）\n .. 空地  ☆集市  ■房子  △粮仓\n\n";
		for(int i=1;i<=N;++i){
			for(int j=1;j<=N;++j){
				if(x==i&&y==j){
					color(5);
					cout<<"●"; if(CUST){cout<<' ';}
					color(1);
					continue;
				}
				if(tv[i][j]==1) cout<<"..";
				if(tv[i][j]==2) {cout<<"☆"; if(CUST){cout<<' ';}}
				if(tv[i][j]==3) {cout<<"△"; if(CUST){cout<<' ';}}
				if(tv[i][j]==4) {cout<<"■"; if(CUST){cout<<' ';}}
			}
			puts("");
		}
		c=getch();
		if(c==27) break; 
		if(c=='s') x++;
		if(c=='a') y--;
		if(c=='w') x--;
		if(c=='d') y++;
		if(x>N||y>N||x<1||y<1){system("cls"); forest();}
		x=max(x,1),y=max(y,1),x=min(x,N),y=min(y,N);
		if(enter&&c==13||!enter){
			if(tv[x][y]==2) market();
			if(tv[x][y]==4) house(); 
			if(tv[x][y]==3) otherbarn();
		}
	}
	system("cls");
} 
void lake(){
	system("cls");
	int x=1,y=1;
	while(1){
		SetPos(0,0);
		cout<<"<水源>（按ESC离开）\n ";
		color(6); 
		cout << "..";
		color(1);
		cout << "水："<<water<<"\n\n";
		for(int i=1;i<=N;++i){
			for(int j=1;j<=N;++j){
				if(i==x&&j==y){
					color(5);
					cout<<"●"; if(CUST){cout<<' ';}
					color(1);
					continue;
				}
				color(6);
				cout<<"..";
				color(1);
			}
			puts("");
		}
		c=getch();
		if(c==27) break;
		if(c=='w') x--;
		if(c=='s') x++;
		if(c=='a') y--;
		if(c=='d') y++;
		x=max(x,1),y=max(y,1),x=min(x,N),y=min(y,N);
		water+=5;
	}
	system("cls");
} 
void lawn(){
	system("cls");
	int x = 1, y = 1;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			if (i == 1 && j == 1){m[i][j] = 0; continue;}
			int tmp = rand() % 20;
			if (tmp < 1) m[i][j] = 2;
			else if (tmp < 4) m[i][j] = 1;
			else m[i][j] = 0;
		}
	}
	while (1){
		SetPos(0,0);
		cout << "<草地>（按ESC离开）\n ";
		color(3);
		cout << "..";
		color(1);
		cout << " 空地  ";
		color(7);
		cout << "::";
		color(1);
		cout << " 稻子  ";
		color(3);
		cout << "□";
		color(1);
		cout << " 蔬菜\n 谷物："<< crop << "  蔬菜：" << vegetable << "\n\n";
		color(1);
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= N; j++){
				if (i == x && j == y){
					color(5), cout << "●"; if(CUST) cout<<' ';
				} else {
					if (m[i][j] == 2) {color(3), cout << "□"; if(CUST){cout<<' ';}}
					else if (m[i][j] == 1) color(7), cout << "::";
					else color(3), m[i][j] = 0, cout << "..";
				}
			}
			puts("");
		}
		color(1); 
		char c = getch();
		if (c == 27) break;
		if (c == 'w') x--;
		if (c == 's') x++;
		if (c == 'a') y--;
		if (c == 'd') y++;
		if (m[x][y] == 2) vegetable += 5;
		else if (m[x][y] == 1) crop += 5;
		m[x][y] = 0;
		x = max(1, x), x = min(N, x), y = max(1, y), y = min(N, y);
	}
	system("cls");
}
void swamp(){
	system("cls");
	int x = 1, y = 1;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			if (i == 1 && j == 1){m[i][j] = 0; continue;}
			int tmp = rand() % 20;
			if (tmp < 1) m[i][j] = 1;
			else m[i][j] = 0;
		}
	}
	while (1){
		SetPos(0, 0);
		cout << "<沼泽>（按ESC离开）\n ";
		color(8);
		cout << "..";
		color(1);
		cout << " 空地  ";
		color(3);
		cout << "::";
		color(1);
		cout << " 藤蔓  △ 商店\n 藤蔓：" << vine << "\n\n";
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= N; j++){
				if (i == x && j == y) {color(5), cout << "●"; if(CUST){cout<<' ';}}
				else if (i == N && j == N) {color(1), cout << "△"; if(CUST){cout<<' ';}}
				else if (m[i][j] == 1) color(3), cout << "::";
				else color(8), cout << "..";
			}
			puts("");
		}
		color(1); 
		char c = getch();
		if (c == 27) break;
		if (c == 'w') x--;
		if (c == 's') x++;
		if (c == 'a') y--;
		if (c == 'd') y++;
		if (m[x][y] == 1) vine++, m[x][y] = 0;
		else if (x == N && y == N) swampshop();
		x = max(1, x), x = min(N, x), y = max(1, y), y = min(N, y);
	}
	system("cls");
}
void mountain(){
	system("cls");
	int x, y = 1, aofy = 0, num = 0;
	int lasth = 0, now = 0, highest = N / 2 + (rand() % 5 - 2);
	for (int i = 1; i <= N; i++){
		int nowh = lasth + (rand() % 3 + now - 1) * (i <= highest ? 1 : -1);
		if (i <= highest && (i % 5 == 1)) now++;
		else if (i % 5 == 1) now--;
		lasth = nowh;
		nowh = max(nowh, 1), nowh = min(nowh, N-1);
		if (i == 1) x = N - nowh;
		for (int j = 1; j < N - nowh + 1; j++)
			m[j][i] = 0;
		for (int j = N - nowh + 1; j <= N; j++)
			m[j][i] = 1;
		if (i == highest) m[N - nowh][i] = 2;
	}
	while (1){
		SetPos(0, 0);
		cout << "<山脉>（按ESC离开，按空格放置/移除藤蔓）\n .. 空气  ";
		color(8);
		cout << "■";
		color(1);
		cout << " 石块  ";
		
		color(3);
		cout << "::";
		color(1);
		cout << " 藤蔓  △ 商店\n 藤蔓：";
		printf("%d", vine);
		cout << "     \n\n";
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= N; j++){
				if (i == x && j == y) {color(5), cout << "●"; if(CUST){cout<<' ';}}
				else if (m[i][j] == 1) {color(8), cout << "■"; if(CUST){cout<<' ';}}
				else if (m[i][j] == 2) {color(1), cout << "△"; if(CUST){cout<<' ';}}
				else if (m[i][j] == 3) color(3), cout << "::";
				else color(1), cout << ".."; 
			}
			puts("");
		}
		color(1);
		if (m[x+1][y] == 1 || m[x][y] == 3 || m[x+1][y] == 3) aofy = 0;
		char c;
		c = getch();
		if (c == 27) break;
		if (c == ' '){
			if (m[x][y] == 3) m[x][y] = 0, vine++, num--;
			else if (vine > 0 && m[x][y] != 2){
				vine--;
				num++;
				m[x][y] = 3;
			}
		}
		if (c == 'a' && m[x][y-1] != 1) y--;
		if (c == 'd' && m[x][y+1] != 1) y++;
		if (c == 'w' && (m[x-1][y] == 3 || m[x][y] == 3)) x--;
		else if (c == 'w' && m[x+1][y] == 1) aofy += 1;  
		if (c == 's'){
			if (m[x+1][y] == 3) x++;
			else{
				x = goy(x, y, aofy);
				aofy -= 2;
			} 
		} else {
			x = goy(x, y, aofy);
			if (m[x+1][y] == 0 && m[x][y] != 3){
				aofy -= 1;
			}
		}
		x = max(1, x), x = min(x, N), y = max(1, y), y = min(y, N); 
		if (m[x][y] == 2) mountainshop();
	}
	vine += num; 
	system("cls");
}
void mine(){
	// 钻石：蓝五角星
	// 金：黄圆形 
	// 银：灰圆形 
	// 铜：白圆形 
	// 铁：白实心方块
	// 煤：灰空心方块 
	system("cls");
	memset(vis, 0, sizeof(vis)); 
	int x = 1, y = 1;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++){
			if (i == 1 && j == 1){
				m[i][j] = 0;
				continue;
			}
			int tmp = rand() % 400;
			if (tmp < 2) m[i][j] = 7;
			else if (tmp < 12) m[i][j] = 6;
			else if (tmp < 32) m[i][j] = 5;
			else if (tmp < 62) m[i][j] = 4;
			else if (tmp < 92) m[i][j] = 3;
			else if (tmp < 132) m[i][j] = 2;
			else m[i][j] = 1;
		}
	while (1){
		update(x, y);
		SetPos(0, 0);
		color(1); 
		cout << "<矿脉>（按ESC离开）\n .. 空地  ";
		color(8);
		cout << "□";
		color(1);
		cout << " 岩石  ";
		color(2);
		cout << "★";
		color(1);
		cout << " 钻石矿  ";
		color(7);
		cout << "●";
		color(1);
		cout << " 金矿  ";
		color(8);
		cout << "●";
		color(1);
		cout << " 银矿  ● 铜矿  ■ 铁矿  ";
		color(8);
		cout << "■";
		color(1);
		cout << " 煤 \n 石料：" << stone << "  钻石矿：" << qdiamond << "  金矿石：" << qjin << "  银矿石：" << qyin << "  铜矿石：" << qtong << "  铁矿石：" << qti << "  煤：" << mei << "\n\n"; 
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= N; j++){
				if (i == x && j == y){
					color(5);
					cout << "●"; if (CUST) cout << ' ';
					continue; 
				}
				if (!vis[i][j]){
					cout << "  ";
				} else {
					switch (m[i][j]){
						case 0: color(1), cout << ".."; break;
						case 1: color(8), cout << "□"; if (CUST) cout << ' '; break;
						case 2: color(8), cout << "■"; if (CUST) cout << ' '; break;
						case 3: color(1), cout << "■"; if (CUST) cout << ' '; break;
						case 4: color(1), cout << "●"; if (CUST) cout << ' '; break;
						case 5: color(8), cout << "●"; if (CUST) cout << ' '; break;
						case 6: color(7), cout << "●"; if (CUST) cout << ' '; break;
						case 7: color(2), cout << "★"; if (CUST) cout << ' '; break;
					}
				}
			}
			puts("");
		}
		c = getch();
		if (c == 'w') x--;
		if (c == 'a') y--;
		if (c == 's') x++;
		if (c == 'd') y++;
		if (c == 27) break;
		x = max(x, 1), x = min(x, N), y = max(y, 1), y = min(y, N);
		SetPos(0, 0);
		color(1); 
		cout << "<矿脉>（按ESC离开）\n .. 空地  ";
		color(8);
		cout << "□";
		color(1);
		cout << " 岩石  ";
		color(2);
		cout << "★";
		color(1);
		cout << " 钻石矿  ";
		color(7);
		cout << "●";
		color(1);
		cout << " 金矿  ";
		color(8);
		cout << "●";
		color(1);
		cout << " 银矿  ● 铜矿  ■ 铁矿  ";
		color(8);
		cout << "■";
		color(1);
		cout << " 煤 \n 石料：" << stone << "  钻石矿：" << qdiamond << "  金矿石：" << qjin << "  银矿石：" << qyin << "  铜矿石：" << qtong << "  铁矿石：" << qti << "  煤：" << mei << "\n\n"; 
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= N; j++){
				if (i == x && j == y){
					color(5);
					cout << "●"; if (CUST) cout << ' ';
					continue; 
				}
				if (!vis[i][j]){
					cout << "  ";
				} else {
					switch (m[i][j]){
						case 0: color(1), cout << ".."; break;
						case 1: color(8), cout << "□"; if (CUST) cout << ' '; break;
						case 2: color(8), cout << "■"; if (CUST) cout << ' '; break;
						case 3: color(1), cout << "■"; if (CUST) cout << ' '; break;
						case 4: color(1), cout << "●"; if (CUST) cout << ' '; break;
						case 5: color(8), cout << "●"; if (CUST) cout << ' '; break;
						case 6: color(7), cout << "●"; if (CUST) cout << ' '; break;
						case 7: color(2), cout << "★"; if (CUST) cout << ' '; break;
					}
				}
			}
			puts("");
		}
		if (dig(m[x][y])) m[x][y] = 0;
		else {
			if (c == 'w') x++;
			if (c == 'a') y++;
			if (c == 's') x--;
			if (c == 'd') y--;
		} 
	}
	system("cls");
} 
void town(){
	// 商店：
	// 房子：
	// 工厂：
	system("cls");
	int x = 1, y = 1;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++){
			if (i == 1 && j == 1) m[i][j] = 0;
			else {
				int tmp = rand() % 100;
				if (tmp < 10) m[i][j] = 3;
				else if (tmp < 25) m[i][j] = 2;
				else if (tmp < 40) m[i][j] = 1;
				else m[i][j] = 0;
			}
		}
	while (1){
		color(1);
		cout << "<城镇>（按ESC离开）\n .. 空地  △商店  □房子  ☆工厂 ";
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= N; j++){
				switch (m[i][j]){
					case 0: cout << ".."; break;
					case 1: cout << "△"; break;
					case 2: cout << "□"; break;
					case 3: cout << "☆"; break;
				}
			}
		}
		c = getch();
		if (c == 'w') x--;
		if (c == 's') x++;
		if (c == 'a') y--;
		if (c == 'd') y++;
//		if (m[x][y] == 1) town_shop();
//		if (m[x][y] == 2) town_house();
//		if (m[x][y] = 3) factory(); 
	}
}
void communication(){
	system("cls");
	if(!FLAG2){
		wis[1][1]=1;
		for(int i=1;i<=N;++i) for(int j=1;j<=W;++j){
			if(i==1&&j==1) continue;
			int tmp=rand()%201;
			if(tmp<60) w[i][j]=3;  //..空地
			else if(tmp<80) w[i][j]=2;  //△村庄 
			else if(tmp<100) w[i][j]=1;  //■森林 
			else if(tmp<120) w[i][j]=4;  //○水源
			else if(tmp<130) w[i][j]=5;  //□草地 
			else if(tmp<145) w[i][j]=6;  //◆沼泽 
			else if(tmp<160) w[i][j]=7;  //▲山脉
			else if(tmp<170) w[i][j]=8;  //☆矿脉
			else if(tmp<180) w[i][j]=9;  //▲城镇 
			else if(tmp<190) w[i][j]=10;  //▽峡谷 
			else if(tmp<194) w[i][j]=11;  //★城市 
			else if(tmp<199) w[i][j]=12;  //▼洞穴
			else if(tmp<200) w[i][j]=13;  //◇废弃之地 
			else w[i][j]=14;  //？ ？？？
		}
		FLAG2=true;
	}
	wx = wy = 1;
	while(1){
		update2(wx,wy);
		SetPos(0,0);
		color(1);
		cout<<"<交通站>（按ESC离开，按Enter进入地图上的某个地点）\n";
		cout<<"金币："<<money<<"（扩展视野需要金币，每扩展一格需要100金币）                                           \n\n";
		cout<<"周边地图：\n";
		color(5);
		cout<<" △初始村庄";
		color(1);
		cout<<"   ..空地  ";
		color(7);
		cout<<"△村庄  ";
		color(3);
		cout<<"■森林  ";
		color(6);
		cout<<"○水源  ";
		color(3);
		cout<<"□草地   ";
		color(6);
		cout<<"◆沼泽 ";
		color(8);
		cout<<" ▲山脉\n";
		color(8);
		cout<<" ☆矿脉";
		color(7);
		cout<<"  ▲城镇";
		color(1);
		cout<<"  ▽峡谷  ";
		color(8);
		cout<<"★城市";
		color(1);
		cout<<"  ▼洞穴  ◇废弃之地  ？未知\n\n"; 
		for(int i=1;i<=N;++i){
			for(int j=1;j<=W;++j){
				if(i==wx&&j==wy){
					color(5);
					cout<<"●"; if(CUST){cout<<' ';}
					color(1);
					continue;
				}
				if(!wis[i][j]){cout<<"  "; continue;}
				if(w[i][j]==0){color(5); cout<<"△"; if(CUST) cout<<' ';} 
				if(w[i][j]==1){color(3); cout<<"■"; if(CUST) cout<<' ';}
				if(w[i][j]==2){color(7); cout<<"△"; if(CUST) cout<<' ';}
				if(w[i][j]==3){cout<<"..";}
				if(w[i][j]==4){color(6); cout<<"○"; if(CUST) cout<<' ';}
				if(w[i][j]==5){color(3); cout<<"□"; if(CUST) cout<<' ';}
				if(w[i][j]==6){color(6); cout<<"◆"; if(CUST) cout<<' ';}
				if(w[i][j]==7){color(8); cout<<"▲"; if(CUST) cout<<' ';}
				if(w[i][j]==8){color(8); cout<<"☆"; if(CUST) cout<<' ';}
				if(w[i][j]==9){color(7); cout<<"▲"; if(CUST) cout<<' ';}
				if(w[i][j]==10){cout<<"▽"; if(CUST) cout<<' ';}
				if(w[i][j]==11){color(8); cout<<"★";if(CUST) cout<<' ';}
				if(w[i][j]==12){cout<<"▼";if(CUST) cout<<' ';}
				if(w[i][j]==13){cout<<"◇";if(CUST) cout<<' ';}
				if(w[i][j]==14){cout<<"？";}
				color(1);
			}
			puts("");
		}
		c=getch();
		if(c==27) break;
		if(c==13){
			if(w[wx][wy]==0) break;
			else if(w[wx][wy]==2) othervillage();
			else if(w[wx][wy]==1) forest();
			else if(w[wx][wy]==4) lake();
			else if (w[wx][wy]==5) lawn();
			else if (w[wx][wy]==6) swamp();
			else if (w[wx][wy]==7) mountain();
			else if (w[wx][wy]==8) mine();
//			else if (w[wx][wy]==9) town();
		}
		if(c=='w'&&wis[wx-1][wy]) wx--;
		if(c=='s'&&wis[wx+1][wy]) wx++;
		if(c=='a'&&wis[wx][wy-1]) wy--;
		if(c=='d'&&wis[wx][wy+1]) wy++;
		wx=max(wx,1),wy=max(wy,1),wx=min(wx,N),wy=min(wy,W);
	}
	system("cls");
}
void build(){
	system("cls");
	while(1){
		cout<<"<建造>（按ESC退出，在某个地方就代表选中了那个地方）\n\n";
		cout<<"1. 住宅（350金币+2铁+2钢+20谷物）\n";
		cout<<"2. 农田（200金币+5蔬菜+10石料）\n";
		cout<<"3. 集市（免费）\n";
		cout<<"4. 粮仓（免费）\n";
		cout<<"5. 交通站（1000金币+10钢+1金+1银+1合金）\n";
		cout<<"0. 拆除当前建筑（住宅可以售出，不建议拆除）\n"; 
		c=getch();
		if(c==27) break;
		c-='0';
		if(c==1){
			system("cls");
			if(v[x][y]==1){
				if(money>=350&&ti>1&&gang>1&&crop>=20){
					printf("建造成功！"); 
					money-=350,ti-=2,gang-=2,crop-=20;
					v[x][y]=5;
				}else printf("资源不足...");
			}else printf("请选择一块空地");
			Sleep(750);
		}
		if(c==2){
			system("cls");
			if(v[x][y]==1){
				if(money>=200&&vegetable>=5&&stone>=10){
					printf("建造成功！"); 
					money-=200,vegetable-=5,stone-=10;
					v[x][y]=6;
				}else printf("资源不足...");
			}else printf("请选择一块空地");
			Sleep(750);
		}
		if(c==3){
			system("cls");
			if(v[x][y]==1){
				printf("建造成功！"); 
				v[x][y]=2;
			}else printf("请选择一块空地");
			Sleep(750);
		}
		if(c==4){
			system("cls");
			if(v[x][y]==1){
				printf("建造成功！"); 
				v[x][y]=3;
			}else printf("请选择一块空地");
			Sleep(750);
		}
		if(c==5){
			system("cls");
			if(v[x][y]==1){
				if(money>=1000&&gang>=10&&jin>0&&yin>0&&hejin>0){
					printf("建造成功！"); 
					money-=1000,gang-=10,jin--,yin--,hejin--;
					v[x][y]=7;
				}else printf("资源不足...");
			}else printf("请选择一块空地");
			Sleep(750);
		}
		if(c==0){
			system("cls");
			if(v[x][y]==1) printf("请选中一个建筑...");
			else if(v[x][y]){
				printf("拆除成功！（拆除不退回建造的资源）");
				v[x][y]=1;
				Sleep(1250); 
			}
			Sleep(750);
		}
		system("cls");
	}
	system("cls"); 
}
void setting(){
	int pos=1;
	system("cls");
	while(1){
		SetPos(0,0);
		cout<<"<设置>（按 [空格] 更改，按 [加号+] 增加，按 [减号-] 减少，按 [ESC] 保存并返回）\n\n";
		if(animal) cout<<"[打猎森林动物] <开启>";
		else cout<<"[打猎森林动物] <关闭>";
		if(pos==1) cout<<" <<<";
		else cout<<"    ";
		puts("");
		if(enter) cout<<"[操作前按Enter确认] <开启>";
		else cout<<"[操作前按Enter确认] <关闭>";
		if(pos==2) cout<<" <<<";
		else cout<<"    ";
		puts("");
		printf("[文字输出停顿时间：%d 毫秒]",TIME*2);
		if(pos==3) cout<<" <<<";
		else cout<<"    ";
		puts(""); 
		c=getch();
		if(c==27) break;
		if(c=='s') pos++;
		if(c=='w') pos--;
		pos=max(pos,1);
		pos=min(pos,3);
		if(c==' '&&pos==1) animal^=1;
		if(c==' '&&pos==2) enter^=1;
		if(c=='+'&&pos==3) TIME+=2;
		if(c=='-'&&pos==3) TIME-=2;
		TIME=max(TIME,1);
	}
	system("cls");
}
void backpack(){
	system("cls");
	while(1){
		SetPos(0,0);
		cout<<"<背包>（按ESC关闭）\n\n";
		if(wood>0) cout<<"木材 x"<<wood<<"\n";
		if(rock>0) cout<<"石子 x"<<rock<<"\n";
		if(board>0) cout<<"木板 x"<<board<<"\n";
		if(stone>0) cout<<"石料 x"<<stone<<"\n";
		if(meat>0) cout<<"肉 x"<<meat<<"\n";
		if(water>0) cout<<"水 x"<<water<<"\n";
		if(knife>0) cout<<"小刀 x"<<knife<<"\n";
		if(spear>0) cout<<"长矛 x"<<spear<<"\n";
		if(axe>0) cout<<"斧子 x"<<axe<<"\n";
		if(pickaxe>0) cout<<"镐子 x"<<pickaxe<<"\n";
		if(saw>0) cout<<"锯子 x"<<saw<<"\n";
		if(crop>0) cout<<"谷物 x"<<crop<<"\n";
		if(vegetable>0) cout<<"蔬菜 x"<<vegetable<<"\n";
		if(hejin>0) cout<<"合金 x"<<hejin<<"\n";
		if(jin>0) cout<<"金 x"<<jin<<"\n";
		if(qjin>0) cout << "金矿石 x" << qjin << "\n";
		if(yin>0) cout<<"银 x"<<yin<<"\n";
		if(qyin>0) cout << "银矿石 x" << qyin << "\n";
		if(tong>0) cout<<"铜 x"<<tong<<"\n";
		if(qtong>0) cout << "铜矿石 x" << qtong << "\n";
		if(ti>0) cout<<"铁 x"<<ti<<"\n";
		if(qti>0) cout<< "铁矿石 x" << qti << "\n";
		if(gang>0) cout<<"钢 x"<<gang<<"\n";
		if(mei>0) cout<<"煤 x"<<mei<<"\n";
		if(diamond>0) cout<<"钻石 x"<<diamond<<"\n";
		if(qdiamond>0) cout << "钻石矿 x" << qdiamond << "\n";
		cout<<"金币 x"<<money<<"\n";
		c=getch();
		if(c==27) break;
	}
	system("cls");
}
string problem[]{
"C++中__int128如何进行输入输出？",
"在C++中数据结构 “线段树” 的作用是什么？",
"以下哪个算法引用了动态规划的思想？",
"如何在Linux系统中新建一个文件夹？",
"防御性编程的原意是什么？",
"g++和gcc是什么？",
"那个链剖分不存在？",
"SCC的英文全称是什么？"
};
string option[][4]{
{"A.使用cin和cout","B.使用格式化输入输出","C.手写输入输出","D.使用getline"},
{"A.求解 [A+B Problem]","B.解决区间查询问题","C.解决排序问题","D.用于枚举"},
{"A.Dijkstra","B.Bellman-Ford","C.Tarjan","D.Hash"},
{"A.mkdir","B.dir","C.rm","D.shutdown"},
{"A.让别人看不懂我的代码","B.防御用户","C.防止程序被恶意攻击","D.多写一些应对可能发生意外情况的代码"},
{"A.C++编译器","B.g++等同于C++而gcc等同于c","C.一种数据类型","D.一种操作系统"},
{"A.重链剖分","B.长链剖分","C.实链剖分","D.虚链剖分"},
{"A.SCCs","B.Super Complex Computer","C.Strongly Connected Components","D.Special Carbohydrate Challenge"}
//A.[略]，B.超位复杂计算机，C.强连通分量，D.特殊碳水化合物挑战赛 
};
char answer[]{
'c',
'b',
'b',
'a',
'd',
'a',
'd',
'c'
};
void ask(){
	system("cls");
	if(WAS){
		cout<<"<答题>\n\n本次机会已用完...";
		Sleep(1000);
		system("cls");
		return;
	}
	cout<<"<答题>\n\n";
	int tmp=rand()%8;
	cout<<problem[tmp]<<"\n\n";
	for(int i=0;i<4;++i) cout<<option[tmp][i]<<"\n";
	c=getch();
	if(c>='A'&&c<='Z') c=c-'A'+'a';
	if(c>='1'&&c<='8') c=c-'1'+'a';
	system("cls");
	if(c==answer[tmp]){
		cout<<"回答正确，获得 [金币 x1500]";
		money+=1500;
	}else cout<<"回答错误...";
	WAS=true; SAVE();
	Sleep(1000);
	system("cls");
}
void VS1(){
	int c,blood=1,ownblood=10000;
	system("cls");
	for(int i=1;;++i){
		SlowSpeak("<你的回合>\n");
		printf("神明的血量：%d\n你的血量：%d\n神明的伤害：1\n你的伤害：100\n\n",blood,ownblood);
		Sleep(200);
		printf("[按任意键发起攻击]\n\n");
		c=getch();
		system("cls");
		if(c=='`'){ 
			SlowSpeak("你解锁了隐藏攻击，按任意键发起\n\n");
			getch(); Sleep(100);
			printf("你打出了 [无限] 点伤害\n\n");
			blood=INT_MIN;
		}else{
			if(i==1) SlowSpeak("你的攻击被隔档了，造成伤害0点",30);
			if(i==2) SlowSpeak("你的攻击再次被隔档了，造成伤害0点",30); 
			if(i==3) SlowSpeak("你的攻击被反弹了造成伤害-100点",30),ownblood-=100;
			if(i==4) SlowSpeak("你的攻击被欧拉了，造成伤害 e^(πi)+1 点",30);
			if(i==5) SlowSpeak("你的攻击被魅惑了，造成伤害-1点",30),ownblood--;
			if(i==6) SlowSpeak("你的攻击在发起前爆炸了，造成伤害-200点",30),ownblood-=200;
			if(i==7) SlowSpeak("你的攻击被狗吃了，造成伤害0点",30);
			if(i==8) SlowSpeak("?尔 ?勺 ?攵（网卡了），造成伤害0点",30);
			if(i==9) SlowSpeak("你的攻击被奇数求和了，由于攻击不是奇数，所以不作数",30);
			if(i==10) SlowSpeak("你对神明造成了100点伤害",30),blood-=100;
			if(i==11) SlowSpeak("你打出了炒鸡无敌世纪第一的暴击，造成了伤害1000000000点",30),blood-=1000000000;
			if(i==12) SlowSpeak("你杀死了神明，但是祂又复活了",30),blood=1;
			if(i==14) SlowSpeak("作业还没写完，暂停一回合",30);
			if(i==13) SlowSpeak("你的攻击变成了公鸡，造成伤害0e999999点",30);
			if(i==15) SlowSpeak("你造成了1点，但是不是伤害",30); 
		}
		Sleep(200);
		if(blood==INT_MIN){
			printf("神明的血量为 [未知错误] \n\n");
			SlowSpeak("霎时间，空间开始扭曲，时间开始消逝，\n不知过了多久，是几亿年，还是一个瞬间，\n");
			SlowSpeak("神明的躯体突然发出了强烈而耀眼的白光，\n又不知过了多久，白光退去，你从床上惊坐起来，\n");
			SlowSpeak("“这一切只是一个一场梦吗？”，你自言自语道...\n\n");
			Sleep(200);
			printf("恭喜你，成功弑神！\n\n");
			system("pause");
			break;
		}else printf("\n\n神明的血量为%d\n你的血量为%d\n\n",blood,ownblood);
		system("pause");
		system("cls");
		SlowSpeak("<神明的回合>\n");
		printf("神明的血量：%d\n你的血量：%d\n神明的伤害：1\n你的伤害：100\n\n",blood,ownblood);
		Sleep(200);
		if(i<=8) SlowSpeak("神明对你造成了1点伤害\n\n",30),ownblood--;
		if(i==9) SlowSpeak("神明触发了超级暴击，对你造成100点伤害\n\n",30),ownblood-=100;
		if(i==10) SlowSpeak("神明对你发动的技能，将你的血量上限修改为5000\n\n",30),ownblood=5000;
		if(i==11) SlowSpeak("神明对你发动了蓝屏攻击，但失败了\n\n",30);
		if(i==12) SlowSpeak("神明使用了复活后充值得到的40米大刀砍了你，造成伤害2000点\n\n",30),ownblood-=2000;
		if(i==13) SlowSpeak("神明对你使用了作业大礼包，使你暂停一回合\n\n",30);
		if(i==14) SlowSpeak("神明召唤了老师，将你的血量限制为1\n\n",30),ownblood=1;
		if(i==15){
			SlowSpeak("神明发动了 熬夜+精神攻击 并看了你一眼，你卒了...\n\n");
			Sleep(200);
			printf("弑神失败...\n\n");
			system("pause");
			break;
		}
		Sleep(200);
		printf("神明的血量为%d\n你的血量为%d\n\n",blood,ownblood);
		system("pause");
		system("cls");
	}
	system("cls");
}
void VS2(){
	int c,blood=1,ownblood=10000;
	system("cls");
	for(int i=1;;++i){
		SlowSpeak("<挑战者的回合>\n");
		printf("你的血量：%d\n挑战者的血量：%d\n你的伤害：1\n挑战者的伤害：100\n\n",blood,ownblood);
		Sleep(200);
		if(rand()*rand()<=0){
			SlowSpeak("挑战者解锁了隐藏攻击\n\n");
			Sleep(1000);
			printf("挑战者打出了 [无限] 点伤害\n\n");
			blood=INT_MIN;
		}else{
			if(i==1) SlowSpeak("挑战者的攻击被你隔档了，造成伤害0点",30);
			if(i==2) SlowSpeak("挑战者的攻击再次被你隔档了，造成伤害0点",30); 
			if(i==3) SlowSpeak("挑战者的攻击被你反弹了造成伤害-100点",30),ownblood-=100;
			if(i==4) SlowSpeak("挑战者的攻击被你欧拉了，造成伤害 e^(πi)+1 点",30);
			if(i==5) SlowSpeak("挑战者的攻击被你魅惑了，造成伤害-1点",30),ownblood--;
			if(i==6) SlowSpeak("挑战者的攻击在发起前爆炸了，造成伤害-200点",30),ownblood-=200;
			if(i==7) SlowSpeak("挑战者的攻击被狗吃了，造成伤害0点",30);
			if(i==8) SlowSpeak("********（挑战者的网卡了），造成伤害0点",30);
			if(i==9) SlowSpeak("挑战者的攻击被你奇数求和了，由于攻击不是奇数，所以不作数",30);
			if(i==10) SlowSpeak("挑战者对你造成了100点伤害",30),blood-=100;
			if(i==11) SlowSpeak("挑战者打出了炒鸡无敌世纪第一的暴击，造成了伤害1000000000点",30),blood-=1000000000;
			if(i==12) SlowSpeak("挑战者杀死了你，但是你施展了大复活术，你复活了",30),blood=1;
			if(i==14) SlowSpeak("挑战者的作业还没写完，暂停一回合",30);
			if(i==13) SlowSpeak("挑战者的攻击变成了公鸡，造成伤害0e999999点",30);
			if(i==15) SlowSpeak("挑战者造成了1点，但是不是伤害（哈哈哈哈哈哈哈哈",30); 
		}
		Sleep(200);
		if(blood==INT_MIN){
			printf("你的血量为 [未知错误] \n\n");
			SlowSpeak("霎时间，你感到意识正在渐渐消散，世界消失了取而代之的是无穷的黑暗\n\n"); 
			printf("弑神者成功斩神...\n\n");
			system("pause");
			break;
		}else printf("\n\n你的血量为%d\n挑战者的血量为%d\n\n",blood,ownblood);
		system("pause");
		system("cls");
		SlowSpeak("<你的回合>\n");
		printf("你的血量：%d\n挑战者的血量：%d\n你的伤害：1\n挑战者的伤害：100\n\n",blood,ownblood);
		printf("[按任意键发起攻击]\n\n");
		c=getch(); system("cls");
		if(i<=8) SlowSpeak("你对挑战者造成了1点伤害\n\n",30),ownblood--;
		if(i==9) SlowSpeak("你触发了超级暴击，对挑战者造成100点伤害\n\n",30),ownblood-=100;
		if(i==10) SlowSpeak("你对挑战者发动的技能，将挑战者的血量上限修改为5000\n\n",30),ownblood=5000;
		if(i==11) SlowSpeak("你试图对挑战者发动了蓝屏攻击，但失败了\n\n",30);
		if(i==12) SlowSpeak("你使用了复活后得到的40米大刀砍了挑战者，造成伤害2000点\n\n",30),ownblood-=2000;
		if(i==13) SlowSpeak("你对挑战者使用了作业大礼包，使挑战者暂停一回合\n\n",30);
		if(i==14) SlowSpeak("你召唤了老师，将挑战者的血量限制为1\n\n",30),ownblood=1;
		if(i==15){
			SlowSpeak("你发动了 熬夜+精神攻击 并看了挑战者一眼，挑战者卒了...\n\n");
			Sleep(200);
			printf("挑战者弑神失败！\n\n");
			system("pause");
			break;
		}
		Sleep(200);
		printf("你的血量为%d\n挑战者的血量为%d\n\n",blood,ownblood);
		system("pause");
		system("cls");
	}
	system("cls");
}
void VS(){
	int pos=1;
	system("cls");
	while(1){
		SetPos(0,0);
		puts("<挑战神明>（按ESC退出）");
		printf("1. [挑战神明]");
		if(pos==1) puts(" <<<");
		else puts("    ");
		printf("2. [成为神明]");
		if(pos==2) puts(" <<<");
		else puts("    ");
		c=getch();
		if(c==27) break;
		if(c=='w') pos--;
		if(c=='s') pos++;
		pos=min(pos,2),pos=max(pos,1);
		if(c==13){
			if(pos==1) VS1();
			if(pos==2) VS2();
		}
	}
	system("cls");
}
void shot(int &p1,int &p2,int x1,int x2,int y1,int y2,int f,int x,int y,int m[][20]){
	while(1){
		if(f==1) x--;
		if(f==2) y++;
		if(f==4) x++;
		if(f==3) y--;
		SetPos(x+4,y-1);
		if(x==x1&&y==y1){
			p1--;
			break;
		}
		if(x==x2&&y==y2){
			p2--;
			break;
		}
		if(x<1||y<1||x>15||y>15||m[x][y]!=1) break;
		color(7),printf("∷");
		Sleep(5);
		SetPos(x+4,y-1);
		color(1),printf("..");
		Sleep(5);
	}
	SetPos(1,1);
}
void shoting_game(){
	long long tim;
	system("cls");
	int p1B=10,p2B=10,p1x=1,p2x=15,p1y=1,p2y=15,p1blood=10,p2blood=10,p1f=4,p2f=1;
	int m[20][20]{
	{0},
	{0,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1},
	{0,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1},
	{0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{0,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,3,3},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,3,1,1},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};
	for(int i=1;i<=15;++i) for(int j=1;j<=15;++j){
		if(m[i][j]!=1||i<=3&&j<=4||i>=12&&j>=11) continue;
		int tmp=rand()%15;
		if(tmp==1) m[i][j]=4;
	}
	while(p1blood>0&&p2blood>0){
		SetPos(0,0);
		printf("<射击游戏>\n\n");
		printf("玩家1血量："); color(5); p1B=max(p1B,p1blood),p2B=max(p2B,p2blood);
		for(int i=1;i<=p1B;++i) if(p1blood>=i) printf("■"); else printf("  ");
		color(1); printf("\n玩家2血量："); color(6);
		for(int i=1;i<=p2B;++i) if(p2blood>=i) printf("■"); else printf("  ");
		puts("\n"); color(1);
		for(int i=1;i<=15;++i){
			for(int j=1;j<=15;++j){
				if(i==p1x&&j==p1y){
					color(5);
					printf("●"); if (CUST) cout << ' ';
					color(1);
					continue;
				}
				if(i==p2x&&j==p2y){
					color(6);
					printf("●"); if (CUST) cout << ' ';
					color(1);
					continue;
				}
				if(m[i][j]==1){printf("..");}
				if(m[i][j]==2){color(5); printf("■"); if (CUST) cout << ' ';}
				if(m[i][j]==3){color(6); printf("■"); if (CUST) cout << ' ';}
				if(m[i][j]==4){printf("■"); if (CUST) cout << ' ';}
				if(m[i][j]==5){color(7); printf("☆"); if (CUST) cout << ' ';}
				color(1); 
			}
			puts("");
		}
		c=getch();
		if(c=='w'&&(m[p1x-1][p1y]==1||m[p1x-1][p1y]==5)) p1x--,p1f=1;
		if(c=='s'&&(m[p1x+1][p1y]==1||m[p1x+1][p1y]==5)) p1x++,p1f=4;
		if(c=='a'&&(m[p1x][p1y-1]==1||m[p1x][p1y-1]==5)) p1y--,p1f=3;
		if(c=='d'&&(m[p1x][p1y+1]==1||m[p1x][p1y+1]==5)) p1y++,p1f=2;
		if(c=='i'&&(m[p2x-1][p2y]==1||m[p2x-1][p2y]==5)) p2x--,p2f=1;
		if(c=='k'&&(m[p2x+1][p2y]==1||m[p2x+1][p2y]==5)) p2x++,p2f=4;
		if(c=='j'&&(m[p2x][p2y-1]==1||m[p2x][p2y-1]==5)) p2y--,p2f=3;
		if(c=='l'&&(m[p2x][p2y+1]==1||m[p2x][p2y+1]==5)) p2y++,p2f=2;
		p1x=max(p1x,1),p1x=min(p1x,15);
		p1y=max(p1y,1),p1y=min(p1y,15);
		p2x=max(p2x,1),p2x=min(p2x,15);
		p2y=max(p2y,1),p2y=min(p2y,15);
		if(c=='x') shot(p1blood,p2blood,-1,p2x,-1,p2y,p1f,p1x,p1y,m);
		if(c=='m') shot(p1blood,p2blood,p1x,-1,p1y,-1,p2f,p2x,p2y,m);
		if(m[p1x][p1y]==5){
			p1blood+=5;
			m[p1x][p1y]=1;
			tim=clock();
		}
		if(m[p2x][p2y]==5){
			p2blood+=5;
			m[p2x][p2y]=1;
			tim=clock();
		}
		if(m[8][8]==1){
			if(clock()-tim>=5000){
				m[8][8]=5,tim=clock();
				SetPos(0,0);
				printf("<射击游戏>\n\n");
				printf("玩家1血量："); color(5); p1B=max(p1B,p1blood),p2B=max(p2B,p2blood);
				for(int i=1;i<=p1B;++i) if(p1blood>=i) printf("■"); else printf("  ");
				color(1); printf("\n玩家2血量："); color(6);
				for(int i=1;i<=p2B;++i) if(p2blood>=i) printf("■"); else printf("  ");
				puts("\n"); color(1);
				for(int i=1;i<=15;++i){
					for(int j=1;j<=15;++j){
						if(i==p1x&&j==p1y){
							color(5);
							printf("●"); if (CUST) cout << ' ';
							color(1);
							continue;
						}
						if(i==p2x&&j==p2y){
							color(6);
							printf("●"); if (CUST) cout << ' ';
							color(1);
							continue;
						}
						if(m[i][j]==1){printf("..");}
						if(m[i][j]==2){color(5); printf("■"); if (CUST) cout << ' ';}
						if(m[i][j]==3){color(6); printf("■"); if (CUST) cout << ' ';}
						if(m[i][j]==4){printf("■"); if (CUST) cout << ' ';}
						if(m[i][j]==5){color(7); printf("☆"); if (CUST) cout << ' ';}
						color(1); 
					}
					puts("");
				}
			}
		}else tim=clock();
	}
	Sleep(850),color(1);
	system("cls");
	puts("<射击游戏>\n");
	if(p1blood>0){
		color(5),SlowSpeak("[玩家1]");
		color(7),SlowSpeak("获胜！\n"),color(1);
		SlowSpeak("剩余血量："); printf("%d",p1blood);
	}
	if(p2blood>0){
		color(6),SlowSpeak("[玩家2]");
		color(7),SlowSpeak("获胜！\n"),color(1);
		SlowSpeak("剩余血量："); printf("%d",p2blood);
	}
	puts("\n");
	system("pause");
	color(1);
	system("cls");
} 
void shoting_Game(){
	system("cls");
	int pos=1;
	while(1){
		SetPos(0,0);
		puts("<射击游戏>（按ESC退出）");
		printf("1. [开始游戏]");
		if(pos==1) puts(" <<<");
		else puts("    ");
		printf("2. [规则讲解]");
		if(pos==2) puts(" <<<");
		else puts("    ");
		c=getch();
		if(c==27) break;
		if(c=='w') pos--;
		if(c=='s') pos++;
		if(c==13){
			if(pos==1) shoting_game();
			if(pos==2){
				system("cls");
				printf("<规则讲解>\n\n");
				SlowSpeak("1. 本游戏是双人对战，分为玩家1（红",30),color(5);
				printf("●"); Sleep(30); color(1);
				SlowSpeak("）和玩家2（蓝",30),color(6);
				printf("●"); Sleep(30); color(1);
				SlowSpeak("）两个角色\n",30);
				getch();
				SlowSpeak("2. 玩家1按WASD移动，按x射击，玩家2按IJKL移动，按m射击\n",30);
				getch();
				SlowSpeak("3. 当角色（玩家）向上移动时，默认将准星调为向上，向下、向左、向右同理\n",30);
				getch();
				SlowSpeak("4. 地图中有障碍物■，子弹不可穿透障碍物\n",30);
				getch();
				SlowSpeak("5. 角色（玩家）有 10 点初始血量，被子弹击中减 1 点血量，血量归零则对方胜利\n",30);
				getch();
				SlowSpeak("6. 地图中央每过 5.0 秒会刷新一颗复活星，拾取（吃掉）后加 5 点血\n\n",30);
				system("pause");
				system("cls");
			}
		}
		pos=max(pos,1),pos=min(pos,2);
	}
	system("cls");
}
void mishitaotuo1(){
	system("cls");
	int thing[35],found[35]; 
	memset(thing,0,sizeof(thing));
	memset(found,0,sizeof(found));
	SlowSpeak("已载入 [第1章：小黑屋]（按ESC终止并强行退出）");
	if(getch()==27) return;
	system("cls");
	SlowSpeak("老旧的钨丝灯悬挂发出微弱的亮光，地板上渗透出一丝丝血迹。\n");
	SlowSpeak("你缓缓地坐起身子，忘记了自己是怎么来到这里。\n");
	SlowSpeak("你起身环顾四周，发现自己身处一间狭小的木屋内。");
	if(getch()==27) return;
	while(1){
		system("cls");
		puts("<储物间>");
		puts("1. 搜寻附近");
		if(found[0]) puts("2. 捡起钥匙");
		if(found[1]) puts("3. 前往铁门");
		c=getch();
		if(c==27) return;
		if(c=='1'){
			system("cls");
			if(!found[1]){
				SlowSpeak("你发现墙角屹立着一扇铁门");
				found[1]=1;
			}else if(!found[0]){
				SlowSpeak("你发现一把有钥匙散落在地上");
				found[0]=1;
			}else{
				if(rand()&1) SlowSpeak("你环顾房间，暂时没有发现");
				else SlowSpeak("你将一切都尽收眼底，却没有任何新发现");
			}
			if(getch()==27) return;
		}
		if(c=='2'&&found[0]){
			system("cls");
			if(!thing[0]) SlowSpeak("你俯身捡起了钥匙");
			else SlowSpeak("你已经捡过了"); 
			thing[0]=1;
			if(getch()==27) return;
		}
		if(c=='3'&&found[1]){
			system("cls");
			if(thing[0]){
				SlowSpeak("你将插入钥匙插入铁门，缓缓推开门，\n");
				break;
			}else SlowSpeak("缺少钥匙...");
			if(getch()==27) return;
		} 
	}
	SlowSpeak("映入眼帘的是一个破旧不堪的套房客房。");
	if(getch()==27) return;
	memset(found,0,sizeof(found));
	memset(thing,0,sizeof(thing));
	while(1){
		system("cls");
		puts("<客房>");
		puts("1. 搜寻附近");
		puts("2. 返回储物间");
		if(found[0]) puts("3. 前往窗台");
		if(found[1]) puts("4. 前往壁炉");
		if(found[2]) puts("5. 前往木柜");
		if(found[3]) puts("6. 查看梯子");
		if(found[4]) puts("7. 查看灯罩");
		if(found[5]){
			if(found[5]==1) puts("8. 前往壁画");
			else puts("8. 前往电闸");
		}	
		if(found[6]) puts("9. 前往大床");
		if(found[7]) puts("a. 前往电视机");
		if(found[8]) puts("b. 前往箱子");
		if(found[9]){
			if(found[9]==1) puts("c. 前往铁门");
			else puts("c. 前往走廊");
		}
		c=getch();
		if(c>='A'&&c<='Z') c=c-'A'+'a';
		if(c==27) return; 
		if(thing[6]&&c!='7'&&c!='8'){
			system("cls");
			SlowSpeak("房间里伸手不见五指，请打开电闸...");
			if(getch()==27) return;
			continue;
		}
		if(c=='1'){
			system("cls");
			if(rand()%5==0){
				int t=rand()%2;
				if(t==0) SlowSpeak("你环顾房间，暂时没有发现");
				if(t==1) SlowSpeak("似乎目前没有找到新事物");
				if(getch()==27) return;
				continue; 
			}
			if(found[0]&&found[1]&&found[2]&&found[3]&&found[4]&&found[5]&&found[6]&&found[7]&&found[8]&&found[9]){
				int t=rand()%4;
				if(t==0) SlowSpeak("你环顾房间，暂时没有发现");
				if(t==1) SlowSpeak("似乎目前没有找到新事物");
				if(t==2) SlowSpeak("你翻遍了每一个角落，找不到一丝的新线索");
				if(t==3) SlowSpeak("你将一切都尽收眼底，却没有任何新发现");
				if(getch()==27) return;
				continue;
			}
			while(1){
				bool flag=false;
				int t=rand()%10; 
				if(t==0&&!found[0]) found[0]=1,SlowSpeak("你发现了墙中央存在一个窗台");
				if(t==1&&!found[1]) flag=true,found[1]=1,SlowSpeak("只见一个壁炉靠在墙上");
				if(t==2&&!found[2]) flag=true,found[2]=1,SlowSpeak("你注意到了一个木质柜子——你可没有“老眼昏花”");
				if(t==3&&found[9]&&!found[3]) flag=true,found[3]=1,SlowSpeak("一把梯子靠在门后");
				if(t==4&&found[3]&&!found[4]) flag=true,found[4]=1,SlowSpeak("头顶的灯光闪了闪，你敏锐地注意到灯罩的问题");
				if(t==5&&!found[5]) flag=true,found[5]=1,SlowSpeak("墙上还挂着一副壁画");
				if(t==6&&!found[6]) flag=true,found[6]=1,SlowSpeak("一张大床坐落于房间中央——你又不是瞎子");
				if(t==7&&!found[7]) flag=true,found[7]=1,SlowSpeak("电视机发出了滋滋噪音");
				if(t==8&&!found[8]) flag=true,found[8]=1,SlowSpeak("你发现一个箱子置于墙角");
				if(t==9&&!found[9]) flag=true,found[9]=1,SlowSpeak("你看见又一扇铁门屹立着");
				if(flag) break;
			}
			if(getch()==27) return;
		}
		if(c=='2'){
			system("cls");
			if(thing[0]==0) thing[0]=1,SlowSpeak("你返回了储物间，又发现了一根断棍子");
			else SlowSpeak("你返回了储物间，那里空空如也");
			if(getch()==27) return;
		}
		if(found[0]&&c=='3'){
			system("cls");
			if(/*需要走廊互动*/0&&0){
				//没拿过 
			}else if(0&&0) SlowSpeak("破损的窗户后面什么也没有");//拿过
			else SlowSpeak("窗户后面似乎有什么东西，需要尖锐的东西来打破...");
			if(getch()==27) return;
		}
		if(found[1]&&c=='4'){
			system("cls");
			if(thing[1]==0) thing[1]=1,SlowSpeak("你在壁炉里发现了一些干柴");
			else SlowSpeak("壁炉里面只有一些积灰...");
			if(getch()==27) return;
		}
		if(found[2]&&c=='5'){
			system("cls");
			if(thing[5]&&thing[2]==0&&thing[3]==0){
				SlowSpeak("只见木柜中陈列着一些药品与一个打火机");
				thing[2]=thing[3]=1;
			}else if(thing[5]&&(thing[2]||thing[3])) SlowSpeak("木柜中什么也不剩");
			else SlowSpeak("木柜上锁了，需要一把钥匙...");
			if(getch()==27) return;
		}
		if(found[3]&&c=='6'){
			system("cls");
			if(thing[4]==0) thing[4]=1,SlowSpeak("你得到了梯子");
			else SlowSpeak("门后没有东西，除了蜘蛛网...");
			if(getch()==27) return;
		}
		if(found[4]&&c=='7'){
			system("cls");
			if(thing[4]&&thing[6]&&thing[5]==0){
				thing[5]=1;
				SlowSpeak("你安全地拆开灯罩，一把钥匙掉入了你的口袋中");
			}else if(thing[4]&&thing[6]&&thing[5]) SlowSpeak("灯罩里只有一个点灯泡在发光发热...");
			else if(thing[4]&&!thing[6]) SlowSpeak("一阵酥酥麻麻的触感传来，原来是触电了，你掉下梯子，两眼一黑。\n不过没关系，醒来后可以再来试几次。");
			else SlowSpeak("灯罩太高了...");
			if(getch()==27) return;
		}
		if(found[5]&&c=='8'){
			system("cls"); 
			if(found[5]==1){
				SlowSpeak("你缓缓移开壁画，发现了藏匿其后的电闸");
				found[5]=2;
				if(getch()==27) return;
				continue;
			}
			if(thing[6]==0){
				thing[6]=1;
				SlowSpeak("你关闭电闸");
			}else{
				thing[6]=0;
				SlowSpeak("你打开电闸");
			}
			if(getch()==27) return;
		}
		if(found[6]&&c=='9'){
			system("cls");
			if(thing[7]==0) thing[7]=1,SlowSpeak("翻入床底，你获得了一根撬棍");
			else SlowSpeak("床底空无一物...");
			if(getch()==28) return;
		}
		if(found[7]&&c=='a'){
			system("cls");
			if(found[5]==2&&thing[8]==0) thing[8]=1,SlowSpeak("电视机上浮现出一串数字：749A03（请记下【密码】，其不会重复出现）");
			else if(found[5]==2&&thing[8]) SlowSpeak("电视机上还是熟悉的雪花屏...");
			else{
				SlowSpeak("电视机上只有一片雪花...");
				if(found[5]==1) SlowSpeak("（提示：前往壁画）");
			}
			if(getch()==28) return;
		}
		if(found[8]&&c=='b'){
			system("cls");
			SlowSpeak("请输入密码 (6) ：");
			string password; cin>>password;
			if(password=="749A03"){
				color(3);
				SlowSpeak("密码正确！");
			}else{
				color(5);
				SlowSpeak("密码错误...");
				color(1);
				if(getch()==27) return;
				continue;
			}
			color(1);
			if(getch()==28) return;
			system("cls");
			if(thing[9]==0) thing[9]=1,SlowSpeak("你获得了一张电子卡");
			else SlowSpeak("箱子里空空如也...");
			if(getch()==28) return;
		}
		if(found[9]&&c=='c'){
			system("cls");
			if(thing[9]==1){
				SlowSpeak("滴，门开了\n");
				SlowSpeak("映入眼帘的是一个老式走廊\n");
				SlowSpeak("“...线索怎么越来越多啊！”你头疼道");
				found[9]=2;
				
				//走廊内容 
				
			}else SlowSpeak("你用力推门，门却纹丝不动...");
			if(getch()==28) return;
		}
	}
	system("cls");
}
void escape_Game(){
	int pos=1;
	system("cls");
	while(1){
		SetPos(0,0);
		puts("<密室逃脱>（按ESC退出）");
		printf("1. [第1章：小黑屋]");
		if(pos==1) puts(" <<<");
		else puts("    ");
		c=getch();
		if(c==27) break;
		if(c=='w') pos--;
		if(c=='s') pos++;
		if(c==13){
			system("cls");
			if(pos==1) mishitaotuo1(); 
			system("cls");
		}
		pos=max(pos,1),pos=min(pos,1);
	}
	system("cls");
}
void Games(){
	int pos=1;
	system("cls");
	SetPos(0,0);
	puts("<游戏列表>（按ESC退出）");
	printf("1. [挑战神明]");
	if(pos==1) puts(" <<<");
	else puts("    ");
	printf("2. [肘击游戏]");
	if(pos==2) puts(" <<<");
	else puts("    ");
	printf("3. [密室逃脱]");
	if(pos==3) puts(" <<<");
	else puts("    ");
	Sleep(100);
	while(1){
		SetPos(0,0);
		puts("<游戏列表>（按ESC退出）");
		printf("1. [挑战神明]");
		if(pos==1) puts(" <<<");
		else puts("    ");
		printf("2. [射击游戏]");
		if(pos==2) puts(" <<<");
		else puts("    ");
		printf("3. [密室逃脱]");
		if(pos==3) puts(" <<<");
		else puts("    ");
		c=getch();
		if(c==27) break;
		if(c=='w') pos--;
		if(c=='s') pos++;
		if(c==13){
			if(pos==1) VS();
			if(pos==2) shoting_Game();
			if(pos==3) escape_Game();
		}
		pos=max(pos,1),pos=min(pos,3);
	}
	system("cls");
}
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
string password = "mxjcyf";
void coder_mode(){
	system("cls");
	printf("开发者模式已开启！");
	Sleep(750);
	wood = rock = money = stone = board = knife = spear = meat = water = axe = 999999999;
	pickaxe = saw = crop = vegetable = vine = hejin = jin = yin = tong = ti = gang = 999999999;
	mei = diamond = 999999999;
	qdiamond = qjin = qyin = qtong = qti = 999999999;
}
void menu(){
	int pos=1, cur=0;
	system("cls");
	while(1){
		SetPos(0,0);
		printf("<菜单>（按ESC关闭，按Enter打开选项）\n\n");
		printf("1. [设置]");
		if(pos==1) printf(" <<<\n");
		else printf("    \n");
		printf("2. [背包]");
		if(pos==2) printf(" <<<\n");
		else printf("    \n");
		printf("3. [答题]");
		if(pos==3) printf(" <<<\n");
		else printf("    \n");
		printf("4. [小游戏]");
		if(pos==4) printf(" <<<\n");
		else printf("    \n");
		printf("5. [存档]");
		if(pos==5) printf(" <<<\n");
		else printf("    \n");
		printf("6. [作者信息]");
		if(pos==6) printf(" <<<\n");
		else printf("    \n");
		printf("7. [格式校准]");
		if (pos == 7) printf(" <<<\n");
		else printf("    \n"); 
		printf("8. [退出]");
		if(pos==8) printf(" <<<\n");
		else printf("    \n");
		c=getch();
		if(c==27) break;
		else if(c=='s') pos++, cur = 0;
		else if(c=='w') pos--, cur = 0;
		else if(c==13){
			if(pos==1) setting();
			else if(pos==2) backpack(); 
			else if(pos==3) ask();
			else if(pos==4) Games();
			else if(pos==5){
				system("cls");
				puts("存档成功！\n");
				SAVE();
				system("pause");
				system("cls");
			}else if(pos==6) system("start https://www.luogu.com.cn/user/1247485");
			else if (pos==7){
				stting();
			}else if(pos==8){
				SAVE();
				HWND hwnd=FindWindowA(NULL,"游戏");
				if(hwnd!=NULL) SendMessage(hwnd,WM_CLOSE,0,0);
			}
		} else if (c == password[cur]){
			cur++;
		} else {
			cur = 0;
		}
		pos=max(pos,1),pos=min(pos,8);
		if (cur == password.size()) coder_mode();
	}
	system("cls");
}
void village(){
	system("cls");
	if(!FLAG){
		for(int i=1;i<=N;++i) for(int j=1;j<=N;++j){
			int x=rand()%200;
			if(x<170) v[i][j]=1; //.. 空地 
			else if(x<180) v[i][j]=2; //☆集市 
			else if(x<190) v[i][j]=4; //■房子 
			else v[i][j]=3; //△粮仓 
		}
		FLAG=true;
	}
	while(1){
		SetPos(0,0); Hide();
		cout<<"<村庄>\n .. 空地  ☆集市  ■房子  △粮仓  □你的房子（住宅）  ◎你的农田（农田）  ‖交通站\n 按空格建造，按ESC打开菜单栏\n\n";
		for(int i=1;i<=N;++i){
			for(int j=1;j<=N;++j){
				if(x==i&&y==j){
					color(5);
					cout<<"●"; if (CUST) cout << ' ';
					color(1);
					continue;
				}
				if(v[i][j]==1) cout<<"..";
				if(v[i][j]==2) {cout<<"☆"; if (CUST) cout << ' ';}
				if(v[i][j]==3) {cout<<"△"; if (CUST) cout << ' ';}
				if(v[i][j]==4) {cout<<"■"; if (CUST) cout << ' ';}
				if(v[i][j]==5) {cout<<"□"; if (CUST) cout << ' ';}
				if(v[i][j]==6) {cout<<"◎"; if (CUST) cout << ' ';}
				if(v[i][j]==7) {cout<<"‖"; if (CUST) cout << ' ';}
			}
			puts("");
		}
		c=getch();
		if(c==27) menu(); 
		if(c=='s') x++;
		if(c=='a') y--;
		if(c=='w') x--;
		if(c=='d') y++;
		if(x>N||y>N||x<1||y<1){system("cls"); forest();}
		x=max(x,1),y=max(y,1),x=min(x,N),y=min(y,N);
		if(c==' ') build();
		else if(enter&&c==13||!enter){
			if(v[x][y]==2) market();
			if(v[x][y]==4) house(); 
			if(v[x][y]==3) barn();
			if(v[x][y]==5) ownhouse();
			if(v[x][y]==6) farmland();
			if(v[x][y]==7) communication();
		}
	}
	system("cls");
} 
void beginning(){
	puts("1.2.6.7 测试版 by sh_Andy");
	Sleep(3000);
	if(FLAG) return;
	stting();
	system("cls"); 
	puts("■■■■■□■■■■■□■■■■■□■□□■");
	puts("□□□□■□□□□□■□□□□□■□■□□■");
	puts("□□□□■□□□□□■□□□□□■□■□□■");
	puts("□□□□■□□□□□■□□□□□■□■□□■");
	puts("□□□□■□□□□□■□□□□□■□■□□■");
	puts("■■■■■□■■■■■□■■■■■□■■■■");
	puts("■□□□□□■□□□□□■□□□□□□□□■");
	puts("■□□□□□■□□□□□■□□□□□□□□■");
	puts("■□□□□□■□□□□□■□□□□□□□□■");
	puts("■□□□□□■□□□□□■□□□□□□□□■");
	puts("■□□□□□■□□□□□■□□□□□□□□■");
	puts("■■■■■□■■■■■□■■■■■□□□□■");
	SlowSpeak("2224，你和朋友打算一起去曾经的人类星球探险。\n");
	Sleep(1000);
	system("cls");
	puts("□□□□□□□□■■■■■■□□□□□□□□");
	puts("□□□□□□□■□□□□□□■□□□□□□□");
	puts("□□□□□□■□□□□□□□□■□□□□□□");
	puts("□□□□□■□□□□□□□□□□■□□□□□");
	puts("□■■■■■■■■■■■■■■■■■■■■□");
	puts("□■■□□□□□□□□□□□□□□□□■■□");
	puts("□■■■■■■■■■■■■■■■■■■■■□");
	puts("□□□□□□■□□□□□□□□■□□□□□□");
	puts("□□□□□□□■■□□□□■■□□□□□□□");
	puts("□□□□□□□□□■■■■□□□□□□□□□");
	puts("□□□□□□□□□□□□□□□□□□□□□□");
	puts("□□□□□□□□□□□□□□□□□□□□□□");
	SlowSpeak("你们踏上了前往一颗名为 EARTH 的行星的路上。\n");
	Sleep(1000);
	system("cls");
	SlowSpeak("突然，你们感到头晕目眩，飞船似乎陷入了空间乱流中，你两眼一黑，晕了过去。");
	Sleep(1000);
	system("cls");
	SlowSpeak("醒来后，你发现自己身处森林之中，四处张望，你发现了一个村庄，并走入其中。");
	Sleep(1000);
	system("cls");
}
long long check;
int num;
void upd(long long add){
	check = (check + ((add * ++num) % check_mod * 71) % check_mod) % check_mod;
}
void READ(){
	ifstream in("游戏存档.data");
	check = 0; num = 0;
	in>>wood>>rock>>money>>stone>>board>>knife>>spear>>meat>>water>>axe;
	upd(wood); upd(rock); upd(money); upd(stone); upd(board); upd(knife);
	in>>pickaxe>>saw>>crop>>vegetable>>vine>>hejin>>jin>>yin>>tong>>ti>>gang;
	upd(spear); upd(meat); upd(water); upd(axe); upd(pickaxe); upd(saw); upd(crop);
	upd(vegetable); upd(vine); upd(hejin); upd(jin); upd(yin); upd(tong); upd(ti); upd(gang);
	in>>mei>>diamond;
	upd(mei); upd(diamond);
	in>>qdiamond>>qjin>>qyin>>qtong>>qti;
	upd(qdiamond); upd(qjin); upd(qyin); upd(qtong); upd(qti);
	in>>FLAG>>FLAG2>>animal>>enter>>shishen;
	upd(FLAG); upd(FLAG2); upd(animal); upd(enter); upd(shishen);
	for(int i=1;i<=N;++i) for(int j=1;j<=N;++j) in>>v[i][j], upd(v[i][j]);
	for(int i=1;i<=N;++i) for(int j=1;j<=W;++j) in>>w[i][j]>>wis[i][j], upd(w[i][j]), upd(wis[i][j]);
	in>>WAS>>TIME>>CUST;
	upd(WAS); upd(TIME); upd(CUST);
	long long now_check;
	in>>now_check;
	if (check != now_check){ // 肆意篡改存档数据者，斩！ 
		wood = rock = money = stone = board = knife = spear = meat = water = axe = 0;
		pickaxe = saw = crop = vegetable = vine = hejin = jin = yin = tong = ti = gang = 0;
		mei = diamond = 0;
		qdiamond = qjin = qyin = qtong = qti = 0;
		FLAG = FLAG2 = animal = enter = shishen = 0;
		for(int i=1;i<=N;++i) for(int j=1;j<=N;++j) v[i][j] = 0;
		for(int i=1;i<=N;++i) for(int j=1;j<=W;++j) w[i][j] = wis[i][j] = 0;
		WAS = 0, TIME = 0, CUST = 0; 
	} 
	if(TIME==0) TIME=50;
	if(shishen==0) shishen=10;
	if(animal=0) animal=1;
	in.close();
}
void SAVE(){
	ofstream out("游戏存档.data");
	check = 0, num = 0;
	upd(wood); upd(rock); upd(money); upd(stone); upd(board); upd(knife);
	out<<wood<<" "<<rock<<" "<<money<<" "<<stone<<" "<<board<<" "<<knife<<" ";
	upd(spear); upd(meat); upd(water); upd(axe); upd(pickaxe); upd(saw); upd(crop);
	out<<spear<<" "<<meat<<" "<<water<<" "<<axe<<" "<<pickaxe<<" "<<saw<<" "<<crop<<" ";
	upd(vegetable); upd(vine); upd(hejin); upd(jin); upd(yin); upd(tong); upd(ti); upd(gang);
	out<<" "<<vegetable<<" "<<vine<<" "<<hejin<<" "<<jin<<" "<<yin<<" "<<tong<<" "<<ti<<" "<<gang<<" ";
	upd(mei); upd(diamond);
	out<<" "<<mei<<" "<<diamond<<" ";
	upd(qdiamond); upd(qjin); upd(qyin); upd(qtong); upd(qti);
	out<<" "<<qdiamond<<" "<<qjin<<" "<<qyin<<" "<<qtong<<" "<<qti<<" "; 
	upd(FLAG); upd(FLAG2); upd(animal); upd(enter); upd(shishen);
	out<<FLAG<<" "<<FLAG2<<" "<<animal<<" "<<enter<<" "<<shishen<<" ";
	for(int i=1;i<=N;++i) for(int j=1;j<=N;++j) out<<v[i][j]<<" ", upd(v[i][j]);
	for(int i=1;i<=N;++i) for(int j=1;j<=W;++j) out<<w[i][j]<<" "<<wis[i][j]<<" ", upd(w[i][j]), upd(wis[i][j]);
	upd(WAS); upd(TIME); upd(CUST);
	out<<WAS<<" "<<TIME<<" "<<CUST<<" "; 
	out<<check;
	out.close();
	
}  
void init(){
	srand(time(0)^random_device()());
	system("color 0F"); SetConsoleTitle("游戏");
	READ(); Hide(); beginning(); FULLScreen(); Hide();
}
signed main(){
	init();
	village(); 
	return 0;
}

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <conio.h>
using namespace std;

void clear(){
	system("cls");
}

struct farm{
	int p, level, num;
} f[505][505];
string map[505][505];
int peo[505][505], jb[505][505], food[505][505], gb[505][505], wood[505][505]/*, hero[505][505]*/;
//int level_to_p = {0, 350, 500, 750, 900, 1000, 1080, 1200};
string n[65];
int kj[65], money[65];

void tb_file(string name){
	string filename = "d:\\Codes\\AlgorithmStudy\\you_xi\\"+name+".txt";
	ofstream file(filename.c_str());
//	ofstream file(filename.c_str());
	file << "name:";
	for (int i = 1; i <= 60; i++){
		file << n[i].c_str() << ' ';
	}
	file << endl;
	file << "kj:";
	for (int i = 1; i <= 60; i++){
		file << kj[i].c_str() << ' ';
	}
	file << endl;
	file << "money:";
	for (int i = 1; i <= 60; i++){
		file << money[i].c_str() << ' ';
	}
	file << endl;
	file << "map:" << endl;
	for (int i = 1; i <= 500; i++){
		for (int j = 1; j <= 500; j++){
			if (map[i][j] == "") file << "0 ";
			else file << map[i][j].c_str() << ' ';
		}
		file << endl;
	}
	file << "peo:" << endl;
	for (int i = 1; i <= 500; i++){
		for (int j = 1; j <= 500; j++){
			file << peo[i][j].c_str() << ' ';
		}
		file << endl;
	}
	file << "food:" << endl;
	for (int i = 1; i <= 500; i++){
		for (int j = 1; j <= 500; j++){
			file << food[i][j].c_str() << ' ';
		}
		file << endl;
	}
	file << "jb:" << endl;
//	for (int)
}

namespace n_dl{
	bool chong(int x){
		for (int i = 1; i < x; i++){
			if (n[i] == n[x]) return true;
		}
		return false;
	}
	void set_map(int x, int y, string name){
		clear();
		cout << "初始化地图中......" << endl;
		srand(time(0));
		int lr = rand();
		for (int i = 1; i <= 59; i++){
			for (int j = 1; j <= 4; j++){
				char B_or_S;
				srand(time(0)+lr);
				lr = rand();
				if (lr % 2 == 0) B_or_S = 'B';
				else B_or_S = 'S';
				srand(time(0)+lr);
				lr = rand();
				if (B_or_S == 'B')
					n[i] += char(65 + lr % 26);
				else 
					n[i] += char(97 + lr % 26);
			}
			if (chong(i)) i--;
		}
		n[60] = name;
		srand(time(0)+lr);
		for (int i = 1; i <= 60; i++){
			lr = rand();
			int sx = lr;
			srand(time(0)+lr);
			lr = rand();
			int sy = lr;
			srand(time(0)+lr);
			if (map[sx][sy] == "" && map[sx][sy+1] == "" && map[sx][sy-1] == "" && map[sx+1][sy] == "" && map[sx-1][sy] == ""){
				map[sx][sy] = n[i]+"☆";
				lr = rand();
				jb[sx][sy] = lr % 101 + 600;
				srand(time(0)+lr);
				lr = rand();
				peo[sx][sy] = lr % 101 + 1100;
				srand(time(0)+lr);
				lr = rand();
				wood[sx][sy] = lr % 201 + 400;
				srand(time(0)+lr);
				
				map[sx][sy+1] = n[i];
				lr = rand();
				jb[sx][sy+1] = lr % 101 + 400;
				srand(time(0)+lr);
				lr = rand();
				peo[sx][sy+1] = lr % 101 + 900;
				srand(time(0)+lr);
				lr = rand();
				wood[sx][sy+1] = lr % 201 + 300;
				srand(time(0)+lr);
				
				map[sx][sy-1] = n[i];
				lr = rand();
				jb[sx][sy-1] = lr % 101 + 400;
				srand(time(0)+lr);
				lr = rand();
				peo[sx][sy-1] = lr % 101 + 900;
				srand(time(0)+lr);
				lr = rand();
				wood[sx][sy-1] = lr % 201 + 300;
				srand(time(0)+lr);
				
				map[sx+1][sy] = n[i];
				lr = rand();
				jb[sx+1][sy] = lr % 101 + 400;
				srand(time(0)+lr);
				lr = rand();
				peo[sx+1][sy] = lr % 101 + 900;
				srand(time(0)+lr);
				lr = rand();
				wood[sx+1][sy] = lr % 201 + 300;
				srand(time(0)+lr);
				
				map[sx-1][sy] = n[i];
				lr = rand();
				jb[sx-1][sy] = lr % 101 + 400;
				srand(time(0)+lr);
				lr = rand();
				peo[sx-1][sy] = lr % 101 + 900;
				srand(time(0)+lr);
				lr = rand();
				wood[sx-1][sy] = lr % 201 + 300;
				srand(time(0)+lr);
			}
			lr = rand();
			kj[i] = lr % 101 + 400;
			srand(time(0)+lr);
			money[i] = lr % 501 + 1250;
		}
	}
	string jie_shao(){
		cout << "欢迎来到领地游戏，你可以操控自己的阵营干许多事，下面为游戏规则：（按任意键出示）" << endl;
		getch();
		while (true){
			bool flag = true;
			cout << "1、你有自己的基地，基地有初始兵力与血量。" << endl;
			getch();
			cout << "2、你可以通过兵力占领城池，并不一定兵力大的获胜。" << endl;
			getch();
			cout << "3、你有资源，资源有：金钱、木材、*********（未解锁）。" << endl;
			getch();
			cout << "（暂未解锁，按任意键继续）" << endl;
			getch();
			clear();
			cout << "可按Enter继续，Esc重新阅读规则。" << endl;
			while (true){
				int t = getch();
				if (t == 13) break;
				else if (t == 27) {
					flag = false;
					break;
				}
				else {
					cout << "输入有误，请重新输入！" << endl;
					continue;
				}
			}
			if (flag) break;
		}
		clear();
		string name = "";
		while (true){
			clear();
			cout << "请给你的账号命个名：（不可含空格）";
			cin >> name;
			cout << "确定叫“" << name << "”吗？（确定打Y，不确定打N）" << endl;
			char t = getch();
			if (t == 'Y' || t == 'y') break;
			else if (t == 'N' || t == 'n') continue;
			else {
				cout << "输入错误，创建账号失败，请重新创建。" << endl;
				continue;
			}
		}
		string filename = "d:\\Codes\\AlgorithmStudy\\you_xi\\"+name+".txt";
		ofstream file(filename.c_str());
		file.close();
		clear();
		cout << "创建账号成功！正在初始化中......" << endl;
		return name;
	}
	void set_zh(string name){
		srand(time(0));
		int sx = rand() % 50000 + 1;
		int r = rand();
		srand(time(0));
		int sy = rand() % 50000 + 1;
//		ofstream file(name.c_str());
//		cout << "位置：" << sx << ',' << sy << endl;
		set_map(sx, sy, name);
	}
	void start(){
		string zhname = jie_shao();
		set_zh(zhname);
	}
}
namespace dl{
	
}
namespace game{
	void g_main(){
		
		return;
	}
}

int main(){
	while (true){
		cout << "请问您有账号吗？（有账号打Y，没账号打N）" << endl;
		char t = getch();
		if (t == 'Y')
			dl::start();
		else if (t == 'N')
			n_dl::start();
		else{
			cout << "输入有误，请重新输入！" << endl;
			continue;
		}
		game::g_main();
	}
	
	return 0;
}
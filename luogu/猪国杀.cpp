#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void setup(); // 初始化 

bool isend(); // 结束判断 

void get_card(int player); // 摸牌 

int make_target(int player, char type); // 选择目标 

void reward_and_punish(int killer, int dier); // 奖赏机制 

int find(int player, char type); // 寻找卡牌 

void cardK(int from, int to, int pos); // 杀：K

// 闪：D（无需特别添加函数处理） 

void cardP(int from, int pos); // 桃：P

void cardJ(int from, int to, int pos, bool isworking); // 无懈可击：J 

void cardF(int from, int to, int pos); // 决斗：F

void cardN(int from, int pos); // 南猪入侵：N

void cardW(int from, int pos); // 万箭齐发：W

void cardZ(int pos); // 猪哥连弩：Z 

void game(); // 游戏 

void print(); // 输出 

int main(){
	setup();
	game();
	print();
	return 0;
}


// 实现： 
 
// 变量定义
int n, m, numz, numf;
int hp[15]; // 血量
int set[15]; // 角色（0主猪，1忠猪，-1反猪）
int player_set[15]; // 跳忠/反状态（0未跳，1跳忠，-1跳反，-2类反） 
bool havepiggg[15]; // 是否有猪哥连弩（piggg是我自己编的词汇，代表猪哥连弩） 
vector<char> card[15], CARD; // 卡牌和卡牌堆

// 函数定义
void setup(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		hp[i] = 4;
		string s;
		cin >> s;
		if (s == 'MP') set[i] = 0, numz++;
		if (s == 'ZP') set[i] = 1, numz++;
		if (s == 'FP') set[i] = -1, numf++;
		for (int j = 1; j <= 4; j++){
			char c;
			cin >> c;
			card[i].push_back(c);
		}
	}
	for (int i = 1; i <= m; i++){
		char c;
		cin >> c;
		CARD.push_back(c);
	}
} 

bool isend(){
	return numz != 0 && numf != 0;
}

void get_card(int player){
	card[player].push_back(CARD[0]);
	if (CARD.size() >= 2)
		CARD.erase(CARD.begin());
	
	card[player].push_back(CARD[0]);
	if (CARD.size() >= 2)
		CARD.erase(CARD.begin());
}

int make_target(int player, char type){
	if (type == 'K'){
		// 寻找左边
		int lft = (player + n - 2) % n + 1;
		while (hp[lft] > 0)
			lft = (lft + n - 2) % n + 1;
		
		// 寻找右边
		int rgt = player % n + 1;
		while (hp[rgt] > 0)
			rgt = rgt % n + 1;
		
		// 根据身份决策
		switch (set[player]){
			case 0:
				if (player_set[rgt] < 0)
					return rgt;
				else if (player_set[lft] < 0)
					return lft;
				else
					return -1;
			case 1:
				if (player_set[rgt] == -1)
					return rgt;
				else if (player_set[lft] == -1)
					return lft;
				else
					return -1;
			case -1:
				if (set[rgt] == 0)
					return rgt;
				else if (set[lft] == 0)
					return lft;
				else if (player_set[rgt] == 1)
					return rgt;
				else if (player_set[lft] == 1)
					return lft;
				else
					return -1;
		} 
	}
}

void game(){
	int player = 1;
	while (!isend()){
		get_card(player);
		int numK = 0;
		for (int i = 0; i < v[player].size(); i++)
			switch (v[player][i]){ // 出牌 
				case 'K':
					if (havepiggg[player] || numK < 1){
						numK++;
						int target = make_target(player, 'K');
						if (target != -1)
							cardK(player, target, i);
						i--;
					}
					break;
				case 'P':
					if (hp[player] < 4){
						cardP(player, i);
						i--;
					}
					break;
				case 'F':
					int target = make_target(player, 'F');
					if (target != -1){
						cardF(player, target, i);
						i--;
					}
					break;
				case 'N': cardN(player, i); i--; break;
				case 'W': cardW(player, i); i--; break;
				case 'Z': cardZ(player, i); i = 0; break;
			}
		player = player % n + 1;
	}
}

void print(){
	if (numz == 0)
		cout << "FP" << endl;
	else
		cout << "MP" << endl;
	for (int i = 1; i <= n; i++)
		if (hp[i] < 1) cout << "DEAD" << endl;
		else{
			for (int j = 0; j < card[i].size(); j++)
				cout << card[i][j] << ' ';
			cout << endl;
		}
}

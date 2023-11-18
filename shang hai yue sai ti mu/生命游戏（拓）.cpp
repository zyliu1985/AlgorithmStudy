#include <iostream>
#include <windows.h>
#include <cstring>
#include <string.h>
#include <cstdlib>
#include <ctime>
using namespace std;

const string live = " ¡ö";
const string die = "  "; // ËÀÍö×´Ì¬
bool board[55][55], new_board[55][55];
int random(int lr){
	srand(time(0));
	return (lr + rand()) % 30000;
}
void r_board(){
	int r, lr = 0;
	for (int i = 1; i <= 50; i++){
		for (int j = 1; j <= 50; j++){
			r = random(lr);
			lr = r;
			board[i][j] = r % 2;
		}
	}
}
void game(){
	for (int t = 0; t <= 100; t++){
		cout << "Ê±¿Ì£º" << t << endl;
		for (int i = 1; i <= 50; i++){
			for (int j = 1; j <= 50; j++){
				if (board[i][j]) cout << live;
				else cout << die;
			}
			cout << endl;
		}
		
	}
}

int main(){
	r_board();
	game();
	return 0;
}

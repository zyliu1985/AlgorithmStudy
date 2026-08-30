#include <iostream>
#include <windows.h>
using namespace std;

int main(){
	while (1){
		system("玩具装箱数据.exe");
		system("玩具装箱.exe");
		system("玩具装箱对拍.exe");
		if (system("fc out.out force.out")){
			cout << "WA\n";
			return 0;
		} else {
			cout << "AC\n";
		}
	}
	return 0;
}




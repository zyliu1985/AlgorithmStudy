#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

void clear(){
	system("cls");
}

int main(){
	int t = time(0);
	while (true){
		clear();
		cout << time(0) - t << endl;
	}
	return 0;
}
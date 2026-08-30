#include <iostream>
#include <random>
#include <time.h>
using namespace std;

int main(){
	srand(time(0));
	cout << rand() % 13 + 1 << ' ' << rand() % 13 + 1 << '\n';
	cout << rand() % 13 + 1 << ' ' << rand() % 13 + 1 << '\n';
	cout << rand() % 13 + 1 << ' ' << rand() % 13 + 1 << '\n';
	cout << rand() % 13 + 1 << ' ' << rand() % 13 + 1 << '\n';
	cout << rand() % 13 + 1 << ' ' << rand() % 13 + 1 << '\n';
	cout << rand() % 13 + 1 << ' ' << rand() % 13 + 1 << '\n';
	return 0;
}



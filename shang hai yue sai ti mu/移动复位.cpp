#include <iostream>
#include <cmath>
using namespace std;

int main(){
	string s;
	cin >> s;
	int x = 0, y = 0;
	for (int i = 0; i < s.size(); i++){
		switch (s[i]){
			case 'R': x++; break;
			case 'L': x--; break;
			case 'U': y++; break;
			case 'D': y--; break;
		}
	}
	cout << abs(x)+abs(y) << endl;
	return 0;
}
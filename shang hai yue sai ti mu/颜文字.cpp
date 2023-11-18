#include <iostream>
using namespace std;

int main(){
	string s;
	int cnt = 0;
	while (cin >> s){
		if (s == ":-)") cnt++;
		if (s == ":-(") cnt--;
	}
	cout << cnt << endl;
	return 0;
}
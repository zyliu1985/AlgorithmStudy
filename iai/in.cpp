#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

int main(){
	freopen("in.in", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	srand(11451419);
	int num = 0;
	for (int i = 1; i <= 1e6; i++){
		int now = rand() % 50;
		if (now >= 26 && now <= 35){
			cout << '(', num++;
		} else if (now > 35){
			if (num > 0) cout << ')', num--;
		} else {
			cout << char('a' + now);
		}
	}
	while (num > 0) cout << ')', num--;
	return 0;
}


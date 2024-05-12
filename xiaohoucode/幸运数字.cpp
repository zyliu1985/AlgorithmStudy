#include <iostream>
//#include <unordered_set>
#include <set>
#include <string>
using namespace std;

//unordered_set<string> ans;
set<string> ans;
int cnt = 0;

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	int ans = 0;
	for (int x = 0; x <= 999; x++){
		int a, b, c;
		a = x / 100;
		b = x / 10 % 10;
		c = x % 10;
		int type = 1;
		bool flag = false;
		for (int i = 0; i < n; i++)
			if (type == 1 && s[i] - '0' == a) type++;
			else if (type == 2 && s[i] - '0' == b) type++;
			else if (type == 3 && s[i] - '0' == c){
				ans++;
				break;
			}
	}
	cout << ans <<endl;
	return 0;
}
#include <iostream>
#include <map>
using namespace std;

map<string, int> mp;
long long read(){
	long long re = 0, type = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') type = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		re = re * 10 + (c - '0');
		c = getchar();
	}
	return re * type;
}
int main(){
	cin.tie(0);
	cout.tie(0);
	int n = read();
	string first_name;
	int first_x = 0;
	for (int i = 1; i <= n; i++){
		string s;
		cin >> s;
		mp[s]++;
		if (first_x < mp[s] || (first_x == mp[s] && s < first_name)){
			first_x = mp[s];
			first_name = s;
		}
		cout << first_name << '\n';
	}
	return 0;
}

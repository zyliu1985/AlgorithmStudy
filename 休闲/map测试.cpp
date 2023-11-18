#include <iostream>
#include <map>
using namespace std;
map<string, int> mp;

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		string s;
		int x;
		cin >> s >> x;
		mp[s] += x;
	}
	for (auto kv : mp){
		cout << kv.first << ' ' << kv.second << endl;
	}
	return 0;
}
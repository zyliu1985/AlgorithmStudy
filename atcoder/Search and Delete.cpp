#include <iostream>
#include <algorithm>
#include <map> 
using namespace std;

map<int, int> mp;
int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		mp[x]++;
	}
	for (int j = 1; j <= m; j++){
		int x;
		cin >> x;
		if (mp[x] > 0) mp[x]--;
	}
	for (auto kv : mp){
		for (int i = 1; i <= kv.second; i++)
			cout << kv.first << ' ';
	}
	return 0;
}

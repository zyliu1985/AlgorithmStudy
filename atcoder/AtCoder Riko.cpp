#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<int, int> mp;
bool check(int l){
	for (auto kv : mp){
		if (((l ^ 1) & 1) && kv.first == l / 2 && (kv.second & 1))
			return false;
		if (kv.second != mp[l - kv.first] && kv.first != l)
			return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, maxa = 0, mina = 1e9;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		maxa = max(maxa, x);
		mina = min(mina, x);
		mp[x]++;
	}
	if (check(maxa)){
		cout << maxa << ' ';
	}
	if (check(maxa + mina)){
		cout << maxa + mina << '\n'; 
	}
	return 0;
}


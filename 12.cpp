#include <iostream>
#include <map>
using namespace std;

map<int,int> mp;
int main(){
	mp[5] = 4;
	for (auto kv : mp){
		cout << kv.first << endl;
	}
	return 0;
}
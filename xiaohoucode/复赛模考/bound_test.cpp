#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int num;
vector<int> v;
bool cmp(int x, int y){
	return x > y;
}

bool cmp2(int x, int y){
	return x < y;
}
int main(){
	for(int i = 100; i >= 1; i--) {
		v.push_back(i);
		v.push_back(i);
	}
	
	cin >> num;
	
	int curr = int(upper_bound(v.begin(), v.end(), num, cmp2) - v.begin());
	cout << curr << endl;
	curr = int(lower_bound(v.begin(), v.end(), num, cmp2) - v.begin());
	cout << curr;
	return 0;
}
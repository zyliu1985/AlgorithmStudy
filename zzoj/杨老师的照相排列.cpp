#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int n[6];
struct node{
	int num, a, b, c, d, e;
	friend bool operator < (const node x, const node y){
		if (x.num != y.num) return x.num < y.num;
		else if (x.a != y.a) return x.a < y.a;
		else if (x.b != y.b) return x.b < y.b;
		else if (x.c != y.c) return x.c < y.c;
		else if (x.d != y.d) return x.d < y.d;
		else return x.e < y.e;
	}
};
map<node, long long> mp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int k;
	cin >> k;
	while (k != 0){
		int k;
		cin >> k;
		for (int i = 1; i <= k; i++){
			cin >> n[i];
			
		}
	}
	return 0;
}


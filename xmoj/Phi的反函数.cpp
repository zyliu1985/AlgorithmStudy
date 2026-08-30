#include <iostream>
#include <algorithm>
using namespace std;

int n, p[32005], d[32005], cur;
bool np[32005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 2; i*i <= n; i++){
		if (!np[i]) p[++cur] = i, d[i] = cur; 
	}
	return 0;
}


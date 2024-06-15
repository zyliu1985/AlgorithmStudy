#include <iostream>
#include <cstring>
using namespace std;

long long s[50005];
int mini[7];
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		s[i] = s[i-1] + x;
	}
	mini[0] = 0;
	mini[1] = -1;
	mini[2] = -1;
	mini[3] = -1;
	mini[4] = -1;
	mini[5] = -1;
	mini[6] = -1;
	int ans = 0;
	for (int i = 1; i <= n; i++){
		if (mini[s[i] % 7] == -1) mini[s[i] % 7] = i;
		ans = max(ans, i - mini[s[i] % 7]);
	}
	cout << ans << endl;
	return 0;
}
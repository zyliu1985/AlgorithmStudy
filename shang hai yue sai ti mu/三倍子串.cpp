#include <iostream>
using namespace std;

long s[1000005];
long cnt[3];
int main(){
	string n;
	cin >> n;
	for (int i = 0; i < n.size(); i++) s[i+1] = (s[i] + int(n[i]-'0')) % 3;
	for (int i = 1; i <= n.size(); i++){
		cnt[s[i]]++;
	}
//	cout << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << endl;
	long long ans = 0;
	// 00Åä¶Ô
	ans += cnt[0];
	ans += cnt[0] * (cnt[0]-1) / 2;
	// 11Åä¶Ô
	ans += cnt[1] * (cnt[1]-1) / 2;
	// 22Åä¶Ô
	ans += cnt[2] * (cnt[2]-1) / 2;
	cout << ans << endl;
	return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;

int dp[1000005];
int main(){
//	freopen("alter.in","r",stdin);
//    freopen("alter.out","w",stdout);
    string s;
    cin >> s;
    int ans = 1;
    dp[0] = 1;
    for (int i = 1; i < s.size(); i++){
    	if (s[i] != s[i-1])
    		dp[i] = dp[i-1] + 1;
    	else
    		dp[i] = 1;
    	ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}

#include <iostream>
#include <cstring>
using namespace std;
int N,a[3005],M,b[105];
int main(){
	cin >> N;
	for(int i = 1;i <= N;i++)
		cin >> a[i];
	cin >> M;
	for(int i = 1;i <= M;i++)
		cin >> b[i];
	if(M == 0){
		int dp[3005][2] = {0};
		for(int i = 1;i <= N;i++){
			dp[i][1] = dp[i - 1][0] + a[i];
			dp[i][0] = max(dp[i - 1][0],dp[i - 1][1]);
		}
		cout << max(dp[N][0],dp[N][1]);
	}
	else if(M == 1){
		int dp[3005][2] = {0},maxn = 0;
		for(int j = 1;j <= N + 1;j++){
			memset(dp,0,sizeof dp);
			int k = a[j];
			for(int i = N;i >= j;i--){
				a[i + 1] = a[i];
			}
			a[j] = b[1];
			for(int i = 1;i <= N + 1;i++){
				dp[i][1] = dp[i - 1][0] + a[i];
				dp[i][0] = max(dp[i - 1][0],dp[i - 1][1]);
			}
			maxn = max(maxn,max(dp[N + 1][0],dp[N + 1][1]));
			for(int i = j + 1;i <= N + 1;i++){
				a[i - 1] = a[i];
			}
			a[j] = k;
		}
		cout << maxn;
	}
	return 0;
}

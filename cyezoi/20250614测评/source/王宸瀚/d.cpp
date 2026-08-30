#include <bits/stdc++.h>
using namespace std;
int g,p;
int a[100009],cnt[100009];
const long long INF = 1e9;

int main (){
	cin >> g >> p;
	for (int i = 1;i <= p;i++){
		cin >> a[i];
		for (int j = 1;j <= a[i];j++){
			cnt[j]++;
		}
	}
	int ans = 0;
	long long k = INF;
	for (int i = 1;i <= p;i++){
		k = INF;
		for (int j = 1;j <= a[i];j++){
			if (k == INF){
				if(cnt[j] < INF){
					k = j;
				}
			}else{
				if (cnt[j] < cnt[k]){
					k = j;
				}
			}	
		}
		if (k == INF){
			cout << ans << endl;
			return 0;
		}
		cnt[k] = INF;
		ans++;
	}
	cout << ans << endl;
	return 0;
}

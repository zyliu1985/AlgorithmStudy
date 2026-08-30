#include<bits/stdc++.h>
using namespace std;

	int n,a[5010];
	
	int fdcz(int l,int i){
		int r = l + i - 1,sum = 0;
		for (int j = 0;j <= (r - l) / 2;j++){
			sum += abs(a[l + j] - a[r - j]);
		}
		return sum;
	}
	
int main(){
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i]; 
	}
	for (int i = 1;i <= n;i++){
		int mn = fdcz(1,i);
		for (int l = 2;l <= n - i + 1;l++){
			if (fdcz(l,i) < mn){
				mn = fdcz(l,i);
			}
		}
		cout << mn << " ";
	}
	return 0;
}


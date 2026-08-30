#include <iostream>
#include <cmath>
using namespace std;
int n,h[5005],ans;
int calc(int l,int r){
	int k = 0;
	for(int i = 1;i <= (r - l + 1) / 2;i++){
		k += abs(h[r - i + 1] - h[i + l - 1]);
	}
	return k;
}
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> h[i];
	for(int i = 1;i <= n;i++){
		int minn = 0x7f7f7f7f;
		for(int j = i;j <= n;j++){
			minn = min(minn,calc(j - i + 1,j));
		}
		cout << minn << " ";
	}
	return 0;
}

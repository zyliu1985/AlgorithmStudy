#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
int a[5005];
int main() {
	cin>>n;
	for(int i=0; i<n; i++)cin>>a[i];
	for(int i=1; i<=n; i++) {
		if(i==1) {
			cout<<0<<" ";
			continue;
		} else {
			int min_=100000;
			for(int j=0; j+i<=n; j++) {
				cnt=0;
				int left=j;
				int right=left+i-1;
				while(left<right) {
					cnt+=abs(a[left]-a[right]);
					left++;
					right--;
				}
				min_=min(cnt,min_);
			}
			cout<<min_<<" ";
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+3;
int cnt[maxn];
vector<int> nums;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			char c;
			cin>>c;
			if(c=='Y')cnt[j]++;
		}
	}
	int big=-1;
	for(int i=1;i<=5;i++){
		if(cnt[i]>big){
			nums.clear();
			nums.push_back(i);
			big=cnt[i];
		}else if(cnt[i]==big){
			nums.push_back(i);
		}
	}
	for(int i=0;i<nums.size()-1;i++)cout<<nums[i]<<",";
	cout<<nums[nums.size()-1];
	return 0;
}
/*
5
YY..Y
.YY.Y
.Y.Y.
.YY.Y
Y...Y
*/

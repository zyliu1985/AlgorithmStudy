#include<bits/stdc++.h>
using namespace std;
int g,p,a[100005];
set<int> cnt;
//int f(int x){
//	int ans=-1,mid,l=0,r=cnt.size()-1;
//	while(l<=r){
//		mid=(l+r)>>1;
//		if(cnt[mid]>x) r=mid-1;
//		else ans=cnt[mid],l=mid+1;
//	}
//	return ans;
//} 
int main(){
	cin>>g>>p;
	for(int i=1;i<=g;++i) cnt.insert(i);
	for(int i=1;i<=p;++i) cin>>a[i];
	for(int i=1;i<=p;++i){
		auto t=cnt.upper_bound(a[i]);
		if(cnt.empty()||t==cnt.begin()){
			cout<<i-1;
			return 0;
		}
		--t;
		cnt.erase(t); 
	}
	cout<<p;
	return 0;
}

//#include<bits/stdc++.h>
//using namespace std;
//int g,p,a[100005],flag[100005];
//bool judge;
//int main(){
//	cin>>g>>p;
//	for(int i=1;i<=p;++i) cin>>a[i];
//	for(int i=1;i<=p;++i){
//		judge=true;
//		for(int j=a[i];j>0;--j){
//			if(!flag[j]){
//				flag[j]=1;
//				judge=false;
//				break;
//			}
//		}
//		if(judge){
//			cout<<i-1;
//			return 0;
//		}
//	}
//	cout<<p;
//	return 0;
//}

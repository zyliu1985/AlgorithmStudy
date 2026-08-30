#include<cstdio>
#include<vector>
#include<algorithm>
typedef long long ll;
int main(){
	ll n;
	scanf("%lld",&n);
	std::vector<ll>day(5);
	for(ll i=0;i<n;i++){
		getchar();
		for(ll j=0;j<5;j++){
			if(getchar()=='Y'){
				day[j]++;
			}
		}
	}
	std::vector<ll>ans;
	ll maxn=*std::max_element(day.begin(),day.end());
	for(ll i=0;i<5;i++){
		if(day[i]==maxn){
			ans.push_back(i+1);
		}
	}
	for(ll i=0;i<ans.size();i++){
		printf("%lld",ans[i]);
		if(i!=ans.size()-1){
			printf(",");
		}
	}
	return 0;
}
//ʱ�䣺O(n) �ռ䣺O(1) 

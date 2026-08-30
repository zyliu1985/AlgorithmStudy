#include<cstdio>
#include<vector>
typedef long long ll;
int main(){
	ll g,p;
	scanf("%lld%lld",&g,&p);
	std::vector<ll>maxg(p+1);
	std::vector<bool>isgd(g+1,false);
	for(ll i=1;i<=p;i++){
		scanf("%lld",&maxg[i]);
	}
	ll ans=0;
	for(ll i=1;i<=p;i++){
		ll j=maxg[i];
		for(;isgd[j]&&j>0;j--);
		if(j){
			isgd[j]=true;
			ans++;
		}
		else{
			printf("%lld",ans);
			return 0;
		}
	}
	printf("%lld",ans);
	return 0;
}
//ʱ�䣺O(pg) �ռ䣺O(p+g) 

#include<iostream>
#include<algorithm>
using namespace std;

int a[10],b[10],num_backup[10];

int main(){
	int n,nbk=0;
	cin>>n;
	char p[10];
	char y = 'Y';
	for(int i=1;i<=n;i++){
		cin>>p;
		for(int j=0;j<=4;j++){
			if(p[j]==y){
				a[j]+=1;
				b[j]+=1;
				//cout<<"Code: "<<p[j]<<" "<<a[j]<<" "<<b[j]<<" "<<j<<endl;
			}
		}
	}
	sort(a,a+5);
	//cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<endl;
	int maxn = a[4];
	//cout<<maxn<<endl;
	for(int i=0;i<=4;i++){
		if(maxn==b[i]){
			nbk+=1;
			num_backup[nbk]=i;
			//cout<<"back: "<<num_backup[nbk]<<" "<<nbk<<endl;
		}
	}
	for(int i=1;i<=nbk;i++){
		if(i==nbk){
			cout<<num_backup[i]+1;
		} else {
			cout<<num_backup[i]+1<<",";
		}
	}
	return 0;
}

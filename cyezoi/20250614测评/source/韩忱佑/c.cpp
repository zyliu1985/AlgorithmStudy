#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int jdz(int a,int b){
	return max(a-b,b-a);
}

int main(){
	int n;
	cin>>n;
	int h[n+5],backup[n+5];
	for(int i=1;i<=n;i++){
		cin>>h[i];
	}
	for(int p=1;p<=n;p++){ //Note: p means the **length** of the cutted area,
	//that is r-l+1 in the question.
	int All_F[n-p+5];
		for(int l=1;l<=n-p+1;l++){ //Note: l means the **beginning** of this area.
			int fdcz=0,r=l+p-1;
			for(int i=0;i<=(r-l)/2;i++){
				fdcz+=jdz(h[l+i],h[r-i]);
			}
			All_F[l]=fdcz;
		}
		sort(All_F+1,All_F+n-p+1+1);
		cout<<All_F[1]<<" ";	
	}
}

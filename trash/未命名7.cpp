#include<bits/stdc++.h>
using namespace std;
#define int long long
int hol(int a,int b,int c){
    if(a==b) return (int)(floor(sqrt(a/4/c)));
    return (int)(floor((a*sqrt(b*c)-b*sqrt(a*c))/(a-b)/c));
}

signed main(){
    int T;
    cin>>T;
    while(T--){
        int a,b,c;
        cin>>a>>b>>c;
        int ax=a;
        int H=hol(a,b,c);
        while(H) a-=H*c,b-=H*c,H=hol(a,b,c);
        cout<<(ax-a)/c<<endl;
    }
    return 0;
}

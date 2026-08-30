#include <iostream>
#include <algorithm>
using namespace std;

struct node{
	int a, id;
} v[500005];
int newid[500005];
bool cmp(node x, node y){
	return x.a < y.a;
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> v[i].a;
		v[i].id = i;
	}
	sort(v+1, v+n+1, cmp);
	
	return 0;
}




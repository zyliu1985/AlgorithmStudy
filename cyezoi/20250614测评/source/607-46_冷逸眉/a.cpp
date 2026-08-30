#include <iostream>
#include <algorithm>
using namespace std;
int n;
struct nod{
	int id,cnt;
};
nod a[6];
bool cmp(nod a,nod b){
	return a.cnt > b.cnt;
}
int main(){
	cin >> n;
	a[1].id = 1;
	a[2].id = 2;
	a[3].id = 3;
	a[4].id = 4;
	a[5].id = 5;
	for(int i = 1;i <= n;i++){
		char a1,a2,a3,a4,a5;
		cin >> a1 >> a2 >> a3 >> a4 >> a5;
		if(a1 == 'Y') a[1].cnt++;
		if(a2 == 'Y') a[2].cnt++;
		if(a3 == 'Y') a[3].cnt++;
		if(a4 == 'Y') a[4].cnt++;
		if(a5 == 'Y') a[5].cnt++;
	}
	sort(a + 1,a + 6,cmp);
	cout << a[1].id;
	for(int i = 2;i <= 5;i++){
		if(a[i].cnt == a[1].cnt) cout << "," << a[i].id;
	}
	return 0;
}

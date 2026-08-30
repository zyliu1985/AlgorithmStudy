#include <iostream>
#include <algorithm>
using namespace std;

int a[105];
bool ans[105];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n; 
	int unk = 0, maxid = 0, lst = n;
	bool flag = false;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (a[i] != -1) lst -= a[i];
		if (a[i] == -1) unk++;
		else if (a[i] > a[maxid]){
			maxid = i;
			flag = false;
		} else if (a[i] == a[maxid]) flag = true;
	}
	if (!flag){
		if (unk == 0 || a[maxid] > (lst + unk - 1) / unk) ans[maxid] = true;
	}
	if (lst > a[maxid])
		for (int i = 1; i <= n; i++)
			if (a[i] == -1) ans[i] = true;
	for (int i = 1; i <= n; i++)
		if (ans[i]) cout << i << ' ';
	cout << '\n'; 
	return 0;
}


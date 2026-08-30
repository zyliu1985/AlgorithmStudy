#include<bits/stdc++.h>
using namespace std;

	int g,p,a[100010],num = 0;
	bool b[100010];
	
int main(){
	cin >> g >> p;
	for (int i = 1;i <= p;i++){
		cin >> a[i]; 
		b[i] = 0;
	}
	for (int i = 1;i <= p;i++){
		if (b[a[i]] == 0){
			num++;
			b[a[i]] = 1;
		}
		else{
			bool x = 0;
			for (int j = a[i] - 1;j >= 1;j--){
				if (b[j] == 0){
					num++;
					b[j] = 1;
					x = 1;
					break;
				}
			}
			if (x == 0){
				cout << num;
				return 0;
			}
		}
	}
	cout << num;
	return 0;
}


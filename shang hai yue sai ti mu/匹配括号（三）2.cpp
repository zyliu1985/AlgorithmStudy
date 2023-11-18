//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int a[105];
//int n;
//int maxi;
//void print(){
//	int left = 0;
//	for (int i = 1; i <= n*2; i++){
//		if (a[i] == 0) left++;
//		else{
//			left--;
//			if (left < 0) return;
//		}
//	}
//	for (int i = 1; i <= n*2; i++){
//		if (a[i] == 0) cout << '(';
//		else cout << ')';
//	}
//	cout << endl;
//	maxi++;
//}
//int main(){
//	cin >> n;
//	for (int i = 1; i <= n; i++){
//		a[i] = 0;
//	}
//	for (int i = n+1; i <= n*2; i++){
//		a[i] = 1;
//	}
//	do{
//		print();
//	}while(next_permutation(a+1, a+n*2+1) && maxi < 1000);
//	return 0;
//}

#include <iostream>
using namespace std;

int n, a[105], maxi;
bool check(int x){
	int left = 0;
	for (int i = 1; i <= x; i++){
		if (a[i] == 0) left++;
		else{
			left--;
			if (left < 0) return false;
		}
	}
	return true;
}
void dfs(int step, int le){
	if (le < 0 || !check(step-1) || maxi >= 1000) return;
	else if (step > n*2){
		for (int i = 1; i <= n*2; i++){
			if (a[i] == 0) cout << '(';
			else cout << ')';
		}
		cout << endl;
		maxi++;
		return;
	} else {
		a[step] = 0;
		dfs(step+1, le-1);
		a[step] = 1;
		dfs(step+1, le);
	}
}
int main(){
	cin >> n;
	dfs(1, n);
	return 0;
}
#include <iostream>
using namespace std;

long long ans[3005], sum[2005], jw[2005];
void Big_mul(int x){
	for (int i = 1; i <= sum[0]; i++){
		sum[i] *= x;
		sum[i] += jw[i];
		jw[i+1] += sum[i]/10;
		if (i == sum[0] && jw[i+1] > 0) sum[0]++;
		sum[i] %= 10;
	}
}
void Big_add(){
	for (int i = 1; i <= max(ans[0], sum[0]); i++){
		ans[i] += sum[i];
		ans[i] += jw[i];
		jw[i+1] += ans[i]/10;
		ans[i] %= 10;
	}
	if (jw[ans[0]+1] > 0){
		ans[0]++;
		ans[ans[0]] += jw[ans[0]];
	}
}
void Big_print(){
	for (int i = ans[0]; i >= 1; i--) cout << ans[i];
}
int main(){
	int n;
	cin >> n;
	ans[0] = 1;
	sum[0] = 1;
	sum[1] = 1;
	for (int i = 1; i <= n; i++){
		Big_mul(i);
		Big_add();
	}
	Big_print();
	return 0;
}
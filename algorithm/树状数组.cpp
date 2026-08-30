#include <iostream>
#define lowbit(x) (x&-x) 
using namespace std;

int n, a[1000005], tr[1000005];
int s[1000005];
void build(){
	for (int i = 1; i <= n; i++)
		s[i] = s[i-1] + a[i];
	for (int i = 1; i <= n; i++)
		tr[i] = s[i] - s[i - lowbit(i)]; 
}
void change(int x, int val){
	for (int i = x; i <= n; i += lowbit(i))
		tr[i] += val;
}
int quary(int l, int r){
	int suml = 0, sumr = 0;
	for (int i = l-1; i > 0; i -= lowbit(i))
		suml += tr[i];
	for (int i = r; i > 0; i -= lowbit(i))
		sumr += tr[i];
	return sumr - suml;
}
int main(){
	return 0;
}



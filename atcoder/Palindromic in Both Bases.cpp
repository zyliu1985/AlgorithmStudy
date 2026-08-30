#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int a;
long long n, ans;
int t[100], cur;
bool check(long long x){
	cur = 0;
	while (x > 0){
		t[cur++] = x % a;
		x /= a;
	}
	cur--;
	for (int i = 0; i <= cur / 2; i++)
		if (t[i] != t[cur - i]) return false;
	return true; 
}
long long build(int half, int len){
	long long re = half;
	if (len & 1) half /= 10;
	len /= 2;
	while (len--){
		re = re * 10 + half % 10;
		half /= 10;
	}
	return re;
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> n;
    long long tn = n;
    int len = 0;
    while (tn > 0){
    	len++;
    	tn /= 10;
	}
	for (int ln = 1; ln <= len; ln++){
		int hfln = (ln + 1) / 2;
		for (int hf = pow(10, hfln - 1); hf <= pow(10, hfln) - 1; hf++){
			if (build(hf, ln) > n) break;
			if (check(build(hf, ln))) ans += build(hf, ln); 
		}
	}
	cout << ans << '\n';
	return 0;
}




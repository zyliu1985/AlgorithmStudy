#include <iostream>
#include <algorithm>
using namespace std;


int gcd(int x, int y){
	if (x % y == 0) return y;
	return gcd(y, x % y);
}
struct node{
	long long p, q;
	friend node operator + (const node x, const node y){
		long long newq = x.q * y.q / gcd(x.q, y.q);
//		cout << newq;
		long long newp = x.p * (newq / x.q) + y.p * (newq / y.q); 
//		cout << newp;
		int gd = gcd(newq, newp);
//		cout << gd;
		return node{newp / gd, newq / gd};
	}
	friend bool operator > (const node x, const node y){
		long long newq = x.q * y.q / gcd(x.q, y.q);
		return x.p * (newq / x.q) > y.p * (newq / y.q);
	}
	friend bool operator == (const node x, const node y){
		return x.p == y.p && x.q == y.q;
	}
} v1[10005], v2[10005];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n1, n2;
		cin >> n1 >> n2;
		for (int i = 1; i <= n1; i++){
			int p, q;
			cin >> p >> q;
			v1[i] = {p, q};
		}
		for (int i = 1; i <= n2; i++){
			int p, q;
			cin >> p >> q;
			v2[i] = {p, q};
		}
		node sum1, sum2;
		sum1.p = sum2.p = 0;
		sum1.q = sum2.q = 1;
		int ans = 1;
		for (int i = 1, j = 1; ; ){
//			cout << sum1.p << ' ' << sum1.q << '\n';
//			cout << sum2.p << ' ' << sum2.q << "\n\n";
			if (sum1 > sum2){
				if (j == n2) break;
				sum2 = sum2 + v2[j++];
				if (sum1 == sum2){
					ans++;
				}
			} else {
				if (i == n1) break;
				sum1 = sum1 + v1[i++];
//				cout << "dkasjdas" << '\n';
				if (sum1 == sum2){
					ans++;
				}
			}
		}
		cout << ans << '\n'; 
	}
	return 0;
}




#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int a[100005];


//计算数的阶乘
long long jiecheng(long long n) {
	long long rv = 1;
	for(long long i = 1; i<=n; i++) {
		rv*=i;
	}
	return rv;
}


// 根据符合范围的数计算组合情况
long long com(long long x) {
	if(x < 3) return 0;
	if(x == 3) return 1;
	return jiecheng(x)/(6 * jiecheng(x-3));
}

int main() {
	long long n, X;
	cin >> n >> X;
	
	long long ans = 0;
	for(long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	// solution1
//	for(int i = 1; i <= n-2; i++) {
//		for(int j = i+1; j <= n-1; j++) {
//			for(int k = j+1; k <= n; k++) {
//				if(abs(a[i] - a[j]) <= X && abs(a[i] - a[k]) <= X && abs(a[k] - a[j]) <= X) {
//					ans++;
//					cout<<a[i] << ',' <<a[j] <<','<<a[k]<<endl;
//				}
//			}
//		}
//	}

	// solution2
//	sort(a+1, a+n+1);
//	
//	for(int i = 1; i <= n-2; i++) {
//		for(int j = i+1; j <= n-1; j++) {
//			if(a[j] - a[i] <= X) {
//				for(int k = j+1; k <= n; k++) {
//					if(a[k] - a[i] <= X) {
//						ans++;
//						cout<<a[i] << ',' <<a[j] <<','<<a[k]<<endl;
//					} else {
//						break;
//					}
//				}
//			} else {
//				break;
//			}
//		}
//	}
//	cout << ans << endl;
	
	// solution3
	ans = 0;
	sort(a+1, a+n+1);
//	for(int i = 1; i <= n; i++) {
//		cout<<a[i] << ",";
//	}
//	cout<<endl;
	
	
	long long lastCount = 1;
	for(long long i = 1; i <= n-2; i++) {
		int count = 1;
		for(long long j = i+1; j<=n; j++) {
			if(a[j] - a[i] <= X) {
				count++;
			} else {
				break;
			}
		}
		
		if(count > lastCount) {
			ans += (com(count) - com(lastCount));
		}
		
		lastCount = count - 1;
//		cout << "count=" << count << ",ans=" << ans << endl;
	}
	
	cout << ans;
	return 0;
}
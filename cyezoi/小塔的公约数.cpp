#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int box[500005];

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		memset(box, 0, sizeof(box));
		int n;
		long long ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++){
			int x;
			cin >> x;
			box[x]++; 
		}
		for (int i = 1; i <= n; i++){
			long long sum = 0;
			for (int j = 1; j * j <= i; j++)
				if (i % j == 0){
					sum += box[i - j];
					if (j * j != i) sum += box[i - i / j];
				}
			ans += sum * box[i];
//			cout << i << ':' << sum << '\n'; 
		}
		cout << ans << '\n';
	}
	return 0;
}




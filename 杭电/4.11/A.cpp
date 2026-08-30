#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		int s;
		long long a, b, c;
		cin >> s >> a >> b >> c;
		long long ans = 1e9;
		for (int i = 0; i <= 1; i++)
			for (int j = 0; j <= 1; j++)
				for (int k = 0; k <= 1; k++){
					long long now = (i * a) + (j * b) + (k * c);
					if (now > s) continue;
					ans = min(ans, s - now);
				}
		cout << ans << '\n';
	}
	return 0;
}




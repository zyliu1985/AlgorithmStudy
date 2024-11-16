#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

map<long long, long long> mp;
long long s[1005];
int main() {
    freopen("solve.in","r",stdin);
    freopen("solve.out","w",stdout);
    int a, b, c, d, n;
	long long p;
    cin >> a >> b >> c >> d >> p >> n;
    for (int i = 1; i <= n; i++)
    	cin >> s[i];
    for (int i = 1; i <= n; i++)
    	for (int j = 1; j <= n; j++)
    		mp[p - s[i] * c - s[j] * d]++;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    	for (int j = 1; j <= n; j++)
    		ans += mp[s[i] * a + s[j] * b];
    cout << ans << endl;
    return 0;
}

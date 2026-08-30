#include <iostream>
#include <algorithm>
using namespace std;
 
const int mod = 19930726;
int len[2000005], box[2000005];
int qpow(long long x, int up){
    if (up == 0) return 1;
    if (up & 1) return qpow(x * x % mod, up / 2) * x % mod;
    else return qpow(x * x % mod, up / 2);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    long long k;
    cin >> n >> k;
    string s = " #";
    for (int i = 1; i <= n; i++){
        char c;
        cin >> c;
        s += c;
        s += '#';
    }
    n = s.size();
    int pos, mx;
    pos = mx = 1;
    len[1] = 1;
    for (int i = 2; i <= n; i++){
        if (i < mx) len[i] = min(len[pos * 2 - i], mx - i + 1);
        else len[i] = 1;
        while (s[i - len[i]] == s[i + len[i]])
            len[i]++;
        if (i + len[i] - 1 > mx) pos = i, mx = i + len[i] - 1;
    }
    for (int i = 1; i <= n; i++)
        if (s[i] != '#') len[i] = (len[i] * 2 - 1) / 2, box[len[i]]++;
    for (int i = n; i >= 1; i--)
        box[i] += box[i + 2];
    long long ans = 1;
    for (int i = n; i >= 1 && k > 0; i--){
        if (k >= box[i]) ans = (ans * qpow(i, box[i])) % mod, k -= box[i];
        else ans = (ans * qpow(i, k)) % mod, k = 0;
    }
    if (k > 0) cout << "-1" << '\n';
    else cout << ans << '\n';
    return 0;
}

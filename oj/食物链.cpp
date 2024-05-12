#include <iostream>
using namespace std;
 
int f[150005], high[150005];
int get(int x){
    if (f[x] == 0) return x;
    return f[x] = get(f[x]);
}
void merge(int x, int y){
    int zx = get(x);
    int zy = get(y);
    if (zx != zy){
        if (high[zx] < high[zy]) f[zx] = zy;
        else{
            f[zy] = zx;
            if (high[zx] == high[zy]) high[zx]++;
        }
    }
}
int main(){
    int n, k, ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) high[i] = 1;
    for (int i = 1; i <= k; i++){
        int c, a, b;
        cin >> c >> a >> b;
        if (a > n || b > n){
            ans++;
            continue;
        }
        if (c == 1){
            if (get(a+n) == get(b) || get(b+n) == get(a) || get(a+2*n) == get(b) || get(a) == get(b+2*n) || get(a+n) == get(b+2*n) || get(a+2*n) == get(b+n)){
                ans++;
                continue;
            }
            merge(a, b);
            merge(a+n, b+n);
            merge(a+2*n, b+2*n); 
        } else {
            if (get(a) == get(b) || get(b+n) == get(a) || get(a+2*n) == get(b) || get(a+n) == get(b+n) || get(a+2*n) == get(b+2*n) || get(a+n) == get(b+2*n)){
                ans++;
                continue;
            }
            merge(a+n, b);
            merge(b+2*n, a);
            merge(b+n, a+2*n);
        }
    }
    cout << ans << endl;
    return 0;
}
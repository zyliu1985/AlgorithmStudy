#include <iostream>
#include <algorithm>
using namespace std;

int S[100005], n;

int main(){
	freopen("set.in", "r", stdin);
	freopen("set.out", "w", stdout);
	int q;
	cin >> q;
	char f;
	int x;
	int i = 1;
	for(int _ = 1; _ <= q; _++) {
		cin >> f >> x;
		if(f == '+') {
			// lowerbound插入进去，保证升序 
			int cnt = lower_bound(S+1, S+n+1, x) - S;
			for (int i = n; i >= cnt; i--)
				S[i+1] = S[i];
			n++;
			S[cnt] = x;
		} else {
			int t = 1;
			while(true) {
				int d = t * x;
				// 用lowerbound计算将d插入S中的index；
				// 用upperbound计算将d插入S中的index；
				int l_index = lower_bound(S+1, S+n+1, d) - S;
				int u_index = upper_bound(S+1, S+n+1, d) - S;
				if(l_index == u_index) {
					cout << d << endl; 
					break;
				} else {
					//说明插入的元素已经存在了
					t++; 
				}
			}
		}
	}
	
	return 0;
}

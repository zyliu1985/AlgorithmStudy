#include <iostream>
#include <algorithm>
using namespace std;

long long f[50005];
int c[50005];
long long s[50005], l;
struct node{
	int id, st;
};
struct mystack{
	node val[50005];
	int _top;
	mystack(){
		_top = 0;
	}
	void clear(){
		_top = 0;
	}
	void push(node x){
		val[++_top] = x;
	}
	void pop(){
		_top--;
	}
	int size(){
		return _top;
	}
	node top(){
		return val[_top];
	}
} st;
bool cmp(node x, node y){
	return x.st < y.st;
}
int getfrom(int x){
	int cur = upper_bound(st.val + 1, st.val + st.size() + 1, node{0, x}, cmp) - st.val - 1;
//	cout << "x:" << x << ", cur:" << cur << '\n';
	return st.val[cur].id;
}
long long calc(int a, int b){
	long long x = b - a - 1 + s[b] - s[a];
	return f[a] + (x - l) * (x - l);
}
int main(){
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n >> l;
	for (int i = 1; i <= n; i++)
		cin >> c[i], s[i] = s[i-1] + c[i];
	f[0] = 0;
	st.push({0, 1});
	for (int i = 1; i <= n; i++){
		cout << i << ":\n"
		;f[i] = calc(getfrom(i), i);
		cout << f[i] << '\n';
		for (int j = 1; j <= n; j++)
			cout << getfrom(j) << ' ';
		cout << '\n';
		int ll = i + 1, rr = n;
		while (ll < rr){
			int mid = (ll + rr) / 2;
			cout << ll << ' ' << rr << ':' << mid << ',' << calc(getfrom(mid), mid) << ',' << calc(i, mid) << '\n'; 
			if (calc(getfrom(mid), mid) < calc(i, mid)) ll = mid + 1;
			else rr = mid;
		}
		while (st.top().st >= ll) st.pop();
		st.push({i, ll});
	}
	cout << f[n] << '\n';
	return 0;
}




#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int h[300005];
struct node{
	long long k, b;
};
stack<node> st;
bool cmp(int x, int y){
	return x > y;
}
struct oiia{
	int val, id;
	long long ans;
} v[300005];
bool cmp1(oiia x, oiia y){
	return x.val > y.val;
}
bool cmp2(oiia x, oiia y){
	return x.id < y.id;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	for (int i = 1; i <= m; i++)
		cin >> v[i].val, v[i].id = i;
	sort(h+1, h+n+1, cmp);
	sort(v+1, v+m+1, cmp1);
	for (int i = 1; i <= n; i++){
		node now = node{i, i * 1ll * h[i]};
		node lst1, lst2;
		while (st.size() > 1){
			lst1 = st.top();
			st.pop();
			lst2 = st.top();
			if ((lst1.b - lst2.b) * (now.k - lst1.k) > (now.b - lst1.b) * (lst1.k - lst2.k)){
				st.push(lst1);
				break;
			}
		}
		st.push(now);
	}
	for (int i = 1; i <= m; i++){
		int x = v[i].val;
		node lst1, lst2;
		while (st.size() > 1){
			lst1 = st.top();
			st.pop();
			lst2 = st.top();
			if (x * 1ll * lst1.k + lst1.b > x * 1ll * lst2.k + lst2.b){
				st.push(lst1);
				break;
			} 
		}
		lst1 = st.top();
		v[i].ans = x * 1ll * lst1.k + lst1.b;
	}
	sort(v+1, v+m+1, cmp2);
	for (int i = 1; i <= m; i++)
		cout << v[i].ans << '\n';
	cout << '\n';
	return 0;
}


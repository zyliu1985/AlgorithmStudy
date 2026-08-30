#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring> 
#define lowbit(x) (x&-x)
using namespace std;

struct node{
	int h, v, id;
	bool type;
} a[50005], t[50005];
bool cmph1(node x, node y){
	if (x.h != y.h) return x.h > y.h;
	return x.type < y.type;
}
bool cmph2(node x, node y){
	if (x.h != y.h) return x.h < y.h;
	return x.type < y.type;
}
bool cmpv(node x, node y){
	return x.v > y.v;
}
int n, cur;
int dp1[50005], dp2[50005];
double sum1[50005], sum2[50005];
int tr[50005];
double trsum[50005];
void cmax(int x, int c, double s){
	for (int i = x; i <= n; i += lowbit(i)){
		if (c > tr[i]){
			tr[i] = c;
			trsum[i] = s;
		} else if (c == tr[i]) trsum[i] += s;
	}
}
pair<int, double> query(int x){
	int re = 0;
	double sm = 0;
	for (int i = x; i >= 1; i -= lowbit(i)){
		if (tr[i] > re){
			re = tr[i];
			sm = trsum[i];
		} else if (tr[i] == re) sm += trsum[i];
	}
	return make_pair(re, sm); 
}
void clear(int x){
	for (int i = x; i <= n; i += lowbit(i))
		tr[i] = 0, trsum[i] = 0;
}


void solve1(int l, int r){
	if (l == r) return;
	int mid = (l + r) / 2;
	solve1(l, mid);
//	cout << "-------------\n"; 
	cur = 0;
	for (int i = l; i <= r; i++)
		if (i <= mid) t[++cur] = {a[i].h, a[i].v, i, 0};
		else t[++cur] = {a[i].h, a[i].v, i, 1};
	sort(t+1, t+cur+1, cmpv);
	int id = 0, lst = 0;
	for (int i = 1; i <= cur; i++){
		if (t[i].v == lst){
			lst = t[i].v;
			t[i].v = t[i-1].v;
		} else {
			lst = t[i].v;
			t[i].v = ++id;
		}
	}
	sort(t+1, t+cur+1, cmph1);
	
	for (int i = 1; i <= cur; i++){
		if (t[i].type){
			pair<int, double> ans = query(t[i].v);
			if (ans.first > dp1[t[i].id]){
				dp1[t[i].id] = ans.first;
				sum1[t[i].id] = ans.second;
			} else if (ans.first == dp1[t[i].id]){
				sum1[t[i].id] += ans.second;
			}
		} else {
			cmax(t[i].v, dp1[t[i].id] + 1, sum1[t[i].id]);
		}
	}
	for (int i = 1; i <= cur; i++)
		if (!t[i].type) clear(t[i].v);
	solve1(mid+1, r);
}
void solve2(int l, int r){
	if (l == r) return;
	int mid = (l + r) / 2;
	solve2(mid+1, r);
	cur = 0;
	for (int i = l; i <= r; i++)
		if (i <= mid) t[++cur] = {a[i].h, a[i].v, i, 1};
		else t[++cur] = {a[i].h, a[i].v, i, 0};
	sort(t+1, t+cur+1, cmpv);
	int id = 0, lst = -1;
	for (int i = cur; i >= 1; i--){
		if (t[i].v == lst){
			lst = t[i].v;
			t[i].v = t[i+1].v;
		} else {
			lst = t[i].v;
			t[i].v = ++id;
		}
	}
	sort(t+1, t+cur+1, cmph2);
	
	for (int i = 1; i <= cur; i++){
		if (t[i].type){
			pair<int, double> ans = query(t[i].v);
			if (ans.first > dp2[t[i].id]){
				dp2[t[i].id] = ans.first;
				sum2[t[i].id] = ans.second;
			} else if (ans.first == dp2[t[i].id]){
				sum2[t[i].id] += ans.second;
			}
		} else {
			cmax(t[i].v, dp2[t[i].id] + 1, sum2[t[i].id]);
		}
	}
	for (int i = 1; i <= cur; i++)
		if (!t[i].type) clear(t[i].v);
	solve2(l, mid);
}
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].h >> a[i].v;
	sum1[0] = sum2[n+1] = 1;
	a[0].h = a[0].v = 1e9;
	a[n+1].h = a[n+1].v = 0;
	solve1(0, n);
	solve2(1, n+1);
//	for (int i = 1; i <= n; i++)
//		cout << dp1[i] << ' ';
//	cout << '\n';
//	for (int i = 1; i <= n; i++)
//		cout << dp2[i] << ' ';
//	cout << '\n';
//	for (int i = 1; i <= n; i++)
//		cout << sum1[i] << ' ';
//	cout << '\n'; 
//	for (int i = 1; i <= n; i++)
//		cout << sum2[i] << ' ';
//	cout << '\n'; 
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, dp1[i] + dp2[i] - 1);
	cout << ans << '\n';
	double finalsum = 0;
	for (int i = 1; i <= n; i++)
		if (dp1[i] == ans) finalsum += sum1[i];
	for (int i = 1; i <= n; i++){
		if (dp1[i] + dp2[i] - 1 == ans) printf("%.6lf ", sum1[i] * sum2[i] / finalsum);
		else printf("0.000000 ");
	}
	return 0;
}


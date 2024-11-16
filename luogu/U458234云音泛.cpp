#include <iostream>
#include <algorithm>
using namespace std;

int a[200005];
long long s1[400005], s2[400005]; // 记录每个节点时，有且仅有1和2朵凋零玫瑰的时间长度 
struct node{
	int x, type; // type为1是种下的时间点，type为-1是凋零的时间点 
} b[400005]; // 记录每一个节点 
long long read(){ // 快读 
	long long re = 0, type = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') type = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		re = re * 10 + (c - '0');
		c = getchar();
	}
	return re * type;
}
bool cmp(node x, node y){
	return x.x < y.x;
}
int main(){
	cout.tie(0);
	int n = read(), m = read();
	for (int i = 1; i <= n; i++){
		a[i] = read();
		b[i] = node{a[i], 1};
		b[i+n] = node{a[i] + m, -1}; // 注意这里，在T+m-1时也是开放的，到T+m才凋零，所以这边是T+m 
	}
	sort(b+1, b+2*n+1, cmp);
	int sum = 0, last_ans = 0; // last_ans：记录在不移动时的答案 
	for (int i = 1; i <= 2 * n; i++){
		// 前缀和 
		s1[i] = s1[i-1];
		s2[i] = s2[i-1];
		sum += b[i].type;
		if (sum == 1){
			s1[i] += b[i+1].x - b[i].x;
			last_ans += b[i+1].x - b[i].x; 
		} else if (sum == 2)
			s2[i] += b[i+1].x - b[i].x;
	}
	long long ans = last_ans;
	for (int i = 1; i <= n; i++){
		// 只有在开放到结尾的这段时间内才会对答案有影响 
		int firstpos = lower_bound(b+1, b+2*n+1, node{a[i], 0}, cmp) - b; // 开放点 
		int lastpos = upper_bound(b+1, b+2*n+1, node{a[i] + m - 1, 0}, cmp) - b - 1; // 结束点，需要注意，这里并不是T+m，因为T+m时已经凋零了，不会被影响 
		ans = max(ans, last_ans - (s1[lastpos] - s1[firstpos - 1]) + (s2[lastpos] - s2[firstpos - 1]) + m); // 原答案减去1->0可能性，加上2->1可能性，再加m 
	}
	cout << ans << endl;
	return 0;
}

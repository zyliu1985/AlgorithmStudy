#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int mod = 998244353;
long long n, m, a[100005]; // a代表原序列
vector<int> v[100005], fv[100005]; // v为函数调用关系图，fv为v的反图
queue<int> q;
long long mul[100005], cnt[100005], pos[100005], add[100005], rd[100005], frd[100005], type[100005];
// mul代表每一个点的乘法数
// cnt代表每一个点调用的次数
// pos代表每一个加法的位置
// add代表每一个加法的值
// rd代表正图的入度
// frd代表反图的入度
// type代表每一个函数的类型
void set_mul(){ // 计算每一个点的乘法数
	// 使用反图进行计算
	for (int i = 0; i <= m; i++)
		if (frd[i] == 0)
			q.push(i);
	while (!q.empty()){
		int x = q.front();
		q.pop();
		for (int i = 0; i < fv[x].size(); i++){
			frd[fv[x][i]]--;
			mul[fv[x][i]] *= mul[x]; // 累乘进行计算
			mul[fv[x][i]] %= mod;
			if (frd[fv[x][i]] == 0)
				q.push(fv[x][i]);
		}
	}
}
void set_cnt(){ // 计算每一个点调用的次数
	for (int i = 0; i <= m; i++)
		if (rd[i] == 0)
			q.push(i);
	while (!q.empty()){
		int x = q.front();
		long long n_mul = 1; // 当前点的乘法系数（注意，并不是mul[x]，因为后面的乘法虽然会影响到前面的，但前面的不会影响到后面的）
		q.pop();
		for (int i = v[x].size()-1; i >= 0; i--){ // 注意这边要倒序循环，因为后面的乘法会影响到前面的，而前面的不会影响到后面的，所以从后面开始累乘
			rd[v[x][i]]--;
			cnt[v[x][i]] += cnt[x] * n_mul; // 需要乘上乘法系数
			cnt[v[x][i]] %= mod;
			n_mul *= mul[v[x][i]]; // 乘法系数的更新与mul数组的更新类似，只不过它是用的正图（因为是后调用的更新它而不是它更新后调用的）
			n_mul %= mod;
			if (rd[v[x][i]] == 0)
				q.push(v[x][i]);
		}
	}
}
int main(){
	// 读入
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> m;
	for (int i = 1; i <= m; i++){
		cin >> type[i];
		mul[i] = 1; // 记得赋初值！！
		if (type[i] == 1)
			cin >> pos[i] >> add[i];
		else if (type[i] == 2)
			cin >> mul[i];
		else{
			int c;
			cin >> c;
			for (int j = 1; j <= c; j++){
				int x;
				cin >> x;
				v[i].push_back(x);
				rd[x]++;
				fv[x].push_back(i);
				frd[i]++;
			}
		}
	}
	int q;
	cin >> q;
	// 将0看做调用了所有要调用的节点
	cnt[0] = 1;
	mul[0] = 1;
	for (int i = 1; i <= q; i++){
		int x;
		cin >> x;
		v[0].push_back(x);
		rd[x]++;
		fv[x].push_back(0);
		frd[0]++;
	}
	set_mul();
	set_cnt();
	for (int i = 1; i <= n; i++){
		a[i] *= mul[0]; // 乘上整个图的乘法数
		a[i] %= mod;
	}
	for (int i = 1; i <= m; i++)
		if (type[i] == 1){
			a[pos[i]] += add[i] * cnt[i]; // 记录每一个加法所带来的价值
			a[pos[i]] %= mod;
		}
	// 输出
	for (int i = 1; i <= n; i++)
		cout << a[i] << ' ';
	cout << endl;
	return 0;
}
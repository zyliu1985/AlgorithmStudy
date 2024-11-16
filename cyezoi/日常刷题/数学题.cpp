#include <iostream>
#include <map>
using namespace std;

map<long long, bool> m;
long long box[100005], a[100005];

int jishu, oushu;

// 计算阶乘
long long jc(long long n) {
	if(n == 1) return 1;
	if(box[n] != 0) return box[n];
	box[n] = n * jc(n-1);
	return box[n];
}

// 计算组合结果, 从n个数字里选择2个数的组合数
long long c(int n) {
	if(n < 2) return 0;
	return n*(n-1)/2;
}

int main(){
	box[1] = 1;
	int n;
	cin >> n;
	long long x, cnt = 0;
	for(int i = 1; i <= n; i++){
		cin >> x;
		if (!m[x]) a[++cnt] = x;
		m[x] = true; 
	}
	
//	map<long long, bool>::iterator it;
//	for(it=m.begin(); it != m.end(); ++it) {
//		if(it->first % 2 == 0) oushu++;
//		else jishu++;
//	}
	for (int i = 1; i <= cnt; i++)
		if (a[i] % 2 == 0) oushu++;
		else jishu++;
	cout << c(jishu) + c(oushu) << endl;
//	cout << c(100000) << endl;
	return 0;
}
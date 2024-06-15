#include <iostream>
#include <cstring>
using namespace std;

int sl[400005], sr[400005], ansl[400005], ansr[400005], a[400005];
struct tric{
	int tre[12000005][2], cur;
	bool ed[12000005];
	void set_up(){
		cur = 0;
		memset(tre, 0, sizeof(tre));
		memset(ed, false, sizeof(ed));
	}
	void insert(int x){
		int now = 0;
		for (int i = 30; i >= 0; i--){
			int t = (x >> i) & 1;
			if (!tre[now][t]) tre[now][t] = ++cur;
			now = tre[now][t];
		}
		ed[now] = true;
	}
	int maxXOR(int x){
		int now = 0, re = 0;
		for (int i = 30; i >= 0; i--){
			int t = (x >> i) & 1;
			if (tre[now][!t]) re = re << 1 | 1, now = tre[now][!t];
			else re <<= 1, now = tre[now][t];
		}
		return re;
	}
} dtr;
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++){
		sl[i] = sl[i-1] ^ a[i];
		sr[n-i+1] = sr[n-i+2] ^ a[n-i+1];
	}
	/*
	后续代码原理：
		a[l]^a[l+1]^...^a[r]
	   =(a[1]^a[2]^...a[r]) ^ (a[1]^a[2]^...^a[l-1])
	   =s[r] ^ s[l-1]
	那么是如何推算出这个公式的呢
	我们知道：
		异或具有交换律：x^y=y^x
		异或也具有结合律：(x^y)^z=x^(y^z)
		而且还具有以下性质：
			x^y^y=x
	所以第二行可以展开为：
		(a[1]^a[2]^...a[r]) ^ (a[1]^a[2]^...^a[l-1])
	   =(a[1]^a[2]^...a[l-1]) ^ (a[l]^a[l+1]^...^a[r]) ^ (a[1]^a[2]^...^a[l-1])
	   =(a[l]^a[l+1]^...^a[r]) ^ (a[1]^a[2]^...a[l-1]) ^ (a[1]^a[2]^...^a[l-1])
	   =a[l]^a[l+1]^...^a[r]
	故左边=右边
	（最后一行等于第二行傻子都能证明）
	*/
	// l1~r1计算ans
	dtr.insert(0); // 无异或入tree
	for (int i = 1; i <= n; i++){
		ansl[i] = max(ansl[i-1], dtr.maxXOR(sl[i])); // 先计最大值，在入tree
		dtr.insert(sl[i]);
	}
	dtr.set_up(); // 重置
	// l2~r2计算ans
	dtr.insert(0); // 无异或入tree
	for (int i = n; i >= 1; i--){
		ansr[i] = max(ansr[i+1], dtr.maxXOR(sr[i])); // 先计最大值，在入tree
		dtr.insert(sr[i]);
	}
	// 求最终答案
	int lastans = -1;
	for (int i = 1; i < n; i++) // 枚举分割点：因为两块区域不可以重叠
		lastans = max(lastans, ansl[i] + ansr[i+1]);
	cout << lastans << endl;
	return 0;
}
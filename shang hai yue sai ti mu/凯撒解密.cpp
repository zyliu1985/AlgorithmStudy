#include <iostream>
using namespace std;

string a[505]; // a存储的是可能为t加密文的单词
int b[26]; // b存储的是答案
int main(){
	string t, s, ans;
	// t为题目要求，s是扫描的辅助变量，ans是t通过不同秘钥加密后的结果
	int sum = 0, cnt = 0;
	cin >> t;
	while (cin >> s){
		if (s.size() == t.size()) a[++cnt] = s; 
		// 扫描句子
	}
	for (int i = 1; i <= 25; i++){ // i为秘钥
		// 加密
		ans = t;
		for (int j = 0; j < t.size(); j++){
			ans[j] = char((int(ans[j]-'a'+i) % 26) + 'a');
		}
		// 查找
		for (int j = 1; j <= cnt; j++){
			if (a[j] == ans){
				b[++sum] = i; // 存储答案
				break; // 避免重复查找
			}
		}
	}
	if (sum == 0){
		cout << "Error" << endl;
		return 0;
	}
	cout << sum << endl;
	for (int i = 1; i <= sum; i++) cout << b[i] << ' ';
	return 0;
}
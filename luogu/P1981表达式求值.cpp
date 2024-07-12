#include <iostream>
#include <stack>
using namespace std;

const int mod = 10000;
stack<int> ist;
stack<char> cst;
string s;
int num;
int __read(int start){
	num = 0;
	int now = start;
	while (s[now] >= '0' && s[now] <= '9')
		num = (num * 10 + s[now++] - '0') % mod;
	return now-1;
}
int main(){
	cin >> s;
	int len = s.size();
	s = ' ' + s;
	for (int cur = 1; cur <= len; cur++)
		if (s[cur] >= '0' && s[cur] <= '9'){
			cur = __read(cur);
			ist.push(num);
		} else if (s[cur] == '+'){
			cst.push('+');
		} else {
			cur = __read(cur+1);
			int x = ist.top();
			ist.pop();
			ist.push((num * x) % mod);
		}
	while (!cst.empty()){
		cst.pop();
		int x = ist.top();
		ist.pop();
		int y = ist.top();
		ist.pop();
		ist.push((x + y) % mod);
	}
	cout << ist.top() << endl;
	return 0;
}
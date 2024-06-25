#include <iostream>
#include <cmath>
#include <stack>
#include <map>
using namespace std;

stack<int> a;
stack<char> b;
map<char, int> mp;
void out(){
	char c = b.top();
	b.pop();
	int x, y, ans;
	y = a.top();
	a.pop();
	x = a.top();
	a.pop();
	switch(c){
		case '+': ans = x+y; break;
		case '-': ans = x-y; break;
		case '*': ans = x*y; break;
		case '/': ans = x/y; break;
		case '^': ans = pow(x, y); break;
	}
//	cout << x << c << y << '=' << ans << endl;
	a.push(ans);
}
signed main(){
	mp['+'] = 1;
	mp['-'] = 1;
	mp['*'] = 2;
	mp['/'] = 2;
	mp['^'] = 3;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		if (s[i] >= '0' && s[i] <= '9'){
			int num = 0;
			while (i < s.size() && s[i] >= '0' && s[i] <= '9'){
				num = num*10 + int(s[i]-'0');
				i++;
			}
			i--;
			a.push(num);
		} else {
			if (s[i] == '('){
				b.push(s[i]);
				continue;
			} else if (s[i] == ')'){
				while (b.top() != '(')
					out();
				b.pop();
				continue;
			}
			while (!b.empty() && mp[s[i]] <= mp[b.top()])
				out();
			b.push(s[i]);
		}
	}
	while (!b.empty())
		out();
	cout << a.top() << endl;
	return 0;
}
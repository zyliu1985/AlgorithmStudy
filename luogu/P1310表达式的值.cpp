#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

const int mod = 10007;
int n, f[4000005][2];
stack<char> cst;
struct node{
	int f0, f1;
};
stack<node> fst;
char s[4000005];
char t[4000005];
int curs, curt = 0;
void post(){
	for (int i = 1; i <= n; i++)
		if ((s[i] == '+' || s[i] == '*' || s[i] == ')') && s[i-1] != ')')
			t[++curt] = '_', t[++curt] = s[i];
		else 
			t[++curt] = s[i];
	if (s[n] != ')')
		t[++curt] = '_';
	curs = 0;
	for (int i = 1; i <= curt; i++)
		s[++curs] = t[i];
	curt = 0;
	for (int i = 1; i <= curs; i++)
		if (s[i] == '_') t[++curt] = '_';
		else if (s[i] == '+'){
			while (!cst.empty() && cst.top() != '('){
				t[++curt] = cst.top();
				cst.pop();
			}
			cst.push(s[i]);
		} else if (s[i] == '*'){
			while (!cst.empty() && cst.top() == '*'){
				t[++curt] = cst.top();
				cst.pop();
			}
			cst.push(s[i]);
		} else if (s[i] == '('){
			cst.push(s[i]);
		} else {
			int rignt = 1;
			while (!cst.empty() && cst.top() != '('){
				t[++curt] = cst.top();
				cst.pop();
			}
			cst.pop();
		}
	while (!cst.empty()){
		t[++curt] = cst.top();
		cst.pop();
	}
	curs = 0;
	for (int i = 1; i <= curt; i++)
		s[++curs] = t[i];
}
int main(){
	cin >> n;
	if (n == 0){
		cout << 1 << endl;
		return 0; 
	}
	getchar();
	curs = n;
	for (int i = 1; i <= n; i++)
		s[i] = getchar();
	post();
	for (int i = 1; i <= curs; i++)
		if (s[i] == '_')
			fst.push(node{1, 1});
		else if (s[i] == '+'){
			node x = fst.top();
			fst.pop();
			node y = fst.top();
			fst.pop();
			fst.push({(x.f0 * y.f0) % mod, (x.f1 * y.f1 + x.f1 * y.f0 + x.f0 * y.f1) % mod});
		} else {
			node x = fst.top();
			fst.pop();
			node y = fst.top();
			fst.pop();
			fst.push({(x.f0 * y.f0 + x.f1 * y.f0 + x.f0 * y.f1) % mod, (x.f1 * y.f1) % mod});
		}
	cout << fst.top().f0 << endl;
	return 0;
}
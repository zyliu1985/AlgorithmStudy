#include <iostream>
#include <stack>
#include <vector>
#include <string.h>
using namespace std;

struct node{
	int val, fa, lch, rch;
} tre[1000005];
struct dp_node{
	int dp_or, dp_and, dp_val;
} dp[1000005];
struct st_node{
	int id, val;
};
int root;
stack<char> cst;
stack<st_node> tst;
int num;
char s[1000005];
char t[1000005];
int curs, curt;
void solve(int x){
	if (tre[x].val != 0 && tre[x].val != 1){
		solve(tre[x].lch);
		dp[x].dp_or += dp[tre[x].lch].dp_or;
		dp[x].dp_and += dp[tre[x].lch].dp_and;
		if (dp[tre[x].lch].dp_val && tre[x].val == -1){
			dp[x].dp_val = 1;
			dp[x].dp_or++;
			return;
		} else if (!dp[tre[x].lch].dp_val && tre[x].val == -2){
			dp[x].dp_val = 0;
			dp[x].dp_and++;
			return;
		} else {
			solve(tre[x].rch);
			dp[x].dp_or += dp[tre[x].rch].dp_or;
			dp[x].dp_and += dp[tre[x].rch].dp_and;
			dp[x].dp_val = dp[tre[x].rch].dp_val;
		}
	} else  dp[x].dp_val = tre[x].val;
}
void post(){
	for (int i = 1; i <= curs; i++)
		if (s[i] == '0' || s[i] == '1') t[++curt] = s[i];
		else if (s[i] == '|'){
			while (!cst.empty() && cst.top() != '('){
				t[++curt] = cst.top();
				cst.pop();
			}
			cst.push(s[i]);
		} else if (s[i] == '&'){
			while (!cst.empty() && cst.top() == '&'){
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
void tree(){
	for (int i = 1; i <= curs; i++)
		if (s[i] == '0' || s[i] == '1'){
			num++;
			tst.push({num, s[i]-'0'});
			tre[num].val = s[i]-'0';
		} else if (s[i] == '|'){ // 或为-1
			st_node x = tst.top();
			tst.pop();
			st_node y = tst.top();
			tst.pop();
			num++;
			tre[x.id].fa = num;
			tre[y.id].fa = num;
			tre[num].rch = x.id;
			tre[num].lch = y.id;
			tre[num].val = -1;
			tst.push({num, -1});
		} else { // 与为-2
			st_node x = tst.top();
			tst.pop();
			st_node y = tst.top();
			tst.pop();
			num++;
			tre[x.id].fa = num;
			tre[y.id].fa = num;
			tre[num].rch = x.id;
			tre[num].lch = y.id;
			tre[num].val = -2;
			tst.push({num, -2});
		}
}
int main(){
	cin >> s+1;
	curs = strlen(s+1);
	post(); // 中缀转后缀
	tree(); // 后缀转表达式树
	for (int i = 1; i <= num; i++)
		if (tre[i].fa == 0){
			root = i;
			break;
		}
	solve(root); // 用递归来运行dp
	cout << dp[root].dp_val << endl << dp[root].dp_and << ' ' << dp[root].dp_or << endl;
	return 0;
}
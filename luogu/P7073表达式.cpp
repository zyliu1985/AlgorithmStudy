#include <iostream>
#include <stack>
#include <vector>
#include <string.h>
using namespace std;

struct node{
	int val, fa, lch, rch, real_val;
} tre[1000005];
struct st_node{
	int id, val, real_val;
};
stack<st_node> tst;
int num, tot, root;
char s[1000005];
bool a[100005];
int curs, curt, mp[100005], important[100005]; 
int __read(int start){
	tot = 0;
	int now = start;
	while (s[now] >= '0' && s[now] <= '9')
		tot = tot * 10 + s[now++] - '0';
	return now;
}
bool solve(int x){
	int now = mp[x];
	bool re = !a[x];	
	while (now != root){	
		if (tre[tre[now].fa].val == -1){ 
			if (tre[tre[now].fa].lch == now) re = re | tre[tre[tre[now].fa].rch].real_val;
			else re = re | tre[tre[tre[now].fa].lch].real_val;							
		} else if (tre[tre[now].fa].val == -2){
			if (tre[tre[now].fa].lch == now) re = re & tre[tre[tre[now].fa].rch].real_val;
			else re = re & tre[tre[tre[now].fa].lch].real_val;
		} else {
			re = !re;		
		}
		now = tre[now].fa;							
	}	
	return re;		
}
void you_hua(int x){
	important[x] = true;
	if (tre[x].val == 0 || tre[x].val == 1) return;
	if (tre[x].val == -1){
		if (tre[tre[x].lch].real_val && tre[tre[x].rch].real_val) return;
		else if (tre[tre[x].lch].real_val) you_hua(tre[x].lch);
		else if (tre[tre[x].rch].real_val) you_hua(tre[x].rch);
		else you_hua(tre[x].lch), you_hua(tre[x].rch);
	} else if (tre[x].val == -2){
		if (!tre[tre[x].lch].real_val && !tre[tre[x].rch].real_val) return;
		else if (!tre[tre[x].lch].real_val) you_hua(tre[x].lch);
		else if (!tre[tre[x].rch].real_val) you_hua(tre[x].rch);
		else you_hua(tre[x].lch), you_hua(tre[x].rch);
	} else
		you_hua(tre[x].lch);
}
void tree(){
	for (int i = 1; i <= curs; i++)
		if (s[i] == 'x'){
			i = __read(i+1);
			num++;
			tre[num].val = a[tot];
			tre[num].real_val = a[tot];
			mp[tot] = num;			
			tst.push({num, a[tot], a[tot]});
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
			tre[num].real_val = x.real_val | y.real_val;
			tst.push({num, -1, x.real_val | y.real_val});
		} else if (s[i] == '&'){ // 与为-2
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
			tre[num].real_val = x.real_val & y.real_val;
			tst.push({num, -2, x.real_val & y.real_val});
		} else if (s[i] == '!'){ // 非为-3
			st_node x = tst.top();
			tst.pop();
			num++;
			tre[x.id].fa = num;
			tre[num].lch = x.id;
			tre[num].val = -3;
			tre[num].real_val = !x.real_val;
			tst.push({num, -3, !x.real_val});
		}
}
int main(){
	int c = getchar();
	while (c != '\n'){
		s[++curs] = c;
		c = getchar();
	}
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	tree();
	for (int i = 1; i <= num; i++)
		if (tre[i].fa == 0){
			root = i;
			break;
		}
	you_hua(root);							
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++){
		int x;
		cin >> x;
		if (important[mp[x]])
			cout << solve(x) << endl;
		else 
			cout << tre[root].real_val << endl;
	}
	return 0;
}
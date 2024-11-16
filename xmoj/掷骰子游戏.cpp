#include <iostream>
#include <vector>
using namespace std;

int n, s, e, ans;
int box[10];
struct node{
	int w, r;
};
vector<node> v[25];
bool check(){
	for (int i = 1; i <= e; i++){
		bool flag = true;
		for (int j = 0; j < v[i].size(); j++)
			if (box[v[i][j].r] < v[i][j].w){
				flag = false;
				break;
			}
		if (flag) return true;
	}
	return false;
}
void dfs(int x){
	if (x > n){
		ans += check();
		return;
	}
	for (int i = 1; i <= s; i++){
		box[i]++;
		dfs(x+1);
		box[i]--;
	}
}
int main(){
	cin >> n >> s >> e;
	getchar();
	for (int i = 1; i <= e; i++){
		char a = getchar(), t = getchar(), c = getchar();
		v[i].push_back({a - '0', c - '0'});
		char op = getchar();
		if (op == '+') i--;
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}

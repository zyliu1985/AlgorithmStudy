#include <iostream>
using namespace std;

int cnt[10];
int type[10], ans;
bool check(){
	for (int i = 0; i <= 9; i++)
		if (type[i] == 1 && !cnt[i])
			return false;
		else if (type[i] == -1 && cnt[i])
			return false;
	return true;
}
void dfs(int x){
	if (x > 4){
		ans += check();
		return;
	}
	for (int i = 0; i <= 9; i++){
		cnt[i]++;
		dfs(x+1);
		cnt[i]--;
	}
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		switch (s[i]){
			case 'o':{
				type[i] = 1;
				break;
			}
			case 'x':{
				type[i] = -1;
				break;
			}
		}
	dfs(1);
	cout << ans << endl;
	return 0;
}

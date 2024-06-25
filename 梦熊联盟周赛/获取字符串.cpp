#include <iostream>
#include <cstring>
using namespace std;


int n, m;
bool ans;
bool flag[155];
char a[200005];
string s1, s2, s3;
void dfs(int x, int last){
	if (ans) return;
	if (x >= m){
		for (int i = 0; i < m; i++){
			if (a[i] > s2[i]){
				ans = true;
				return;
			} else if (a[i] < s2[i]) return;
			if (i == m - 1){
				ans = true;
				return;
			}
		}
	}
	for (int i = last; i < s3.size(); i++){
		a[x] = s3[i];
		dfs(x+1, i+1);
	}
}
int main(){
	int t;
	cin >> t;
	while (t--){
		memset(flag, false, sizeof(flag));
		ans = false;
		cin >> n >> m >> s1 >> s2;
		s3 = "";
		for (int i = 0; i < m; i++)
			flag[s2[i]] = true;
		for (int i = 0; i < n; i++)
			if (flag[s1[i]]) s3 += s1[i];
		if (s3.size() < s2.size()){
			cout << "No" << endl;
			continue;
		}
		dfs(0, 0);
		if (ans) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
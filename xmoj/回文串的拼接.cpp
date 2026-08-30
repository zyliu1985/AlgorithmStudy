#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std;

vector<int> v[5005];
int sum[5005];
void init(string s){
	for (int i = 0; i < s.size(); i++){
		int l, r;
		l = r = i;
		while (s[l] == s[r] && l >= 0 && r < s.size()){
			v[l].push_back(r);
			if (r == s.size()-1) sum[l]++;
			l--, r++;
		}
		l = i, r = i+1;
		while (s[l] == s[r] && l >= 0 && r < s.size()){
			v[l].push_back(r);
			if (r == s.size()-1) sum[l]++;
			l--, r++;
		}
	}
	for (int i = s.size()-1; i >= 0; i--)
		sum[i] += sum[i+1];
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("par.in", "r", stdin);
    freopen("par.out", "w", stdout);
	string s;
	cin >> s;
	init(s); 
//	for (int i = 0; i < s.size(); i++){
//		for (int j = 0; j < v[i].size(); j++)
//			cout << '(' << i << ", " << v[i][j] << "), ";
//		cout << '\n';
//	}
//	for (int i = 0; i < s.size(); i++)
//		cout << sum[i] << ' ';
//	cout << '\n';
	long long ans = 0;
	for (int i = 0; i < v[0].size(); i++)
		for (int j = 0; j < v[v[0][i] + 1].size(); j++){
//			cout << "(0, " << v[0][i] << ") => (" << v[0][i] + 1 << ", " << v[v[0][i] + 1][j] << ")  add:" << sum[v[v[0][i] + 1][j] + 2] << '\n';
			ans += sum[v[v[0][i] + 1][j] + 2];
		}
	cout << ans << '\n';
	return 0;
}




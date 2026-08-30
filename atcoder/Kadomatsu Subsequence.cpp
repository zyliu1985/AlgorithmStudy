#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

map<int, vector<int> > mp3, mp7;
struct node{
	int x, num;
};
vector<node> v5;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		if (x % 3 == 0) mp3[x / 3].push_back(i);
		if (x % 5 == 0) v5.push_back({i, x / 5});
		if (x % 7 == 0) mp7[x / 7].push_back(i);
	}
	long long ans = 0;
	for (int i = 0; i < v5.size(); i++){
		if (mp3[v5[i].num].size() > 0 && mp7[v5[i].num].size() > 0){
			int t3 = mp3[v5[i].num].size() - (lower_bound(mp3[v5[i].num].begin(), mp3[v5[i].num].end(), v5[i].x) - mp3[v5[i].num].begin());
			int t7 = mp7[v5[i].num].size() - (lower_bound(mp7[v5[i].num].begin(), mp7[v5[i].num].end(), v5[i].x) - mp7[v5[i].num].begin());
			ans += t3 * 1ll * t7;
			t3 = upper_bound(mp3[v5[i].num].begin(), mp3[v5[i].num].end(), v5[i].x) - mp3[v5[i].num].begin();
			t7 = upper_bound(mp7[v5[i].num].begin(), mp7[v5[i].num].end(), v5[i].x) - mp7[v5[i].num].begin();
			ans += t3 * 1ll * t7;
		}
	}
	cout << ans << '\n';
	return 0;
}


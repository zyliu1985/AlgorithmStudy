#include <iostream>
#include <vector>
#define int long long
using namespace std;

int boxa[100005], boxc[100005];
vector<int> b[100005];
signed main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		boxa[x]++;
	}
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		b[x].push_back(i);
	}
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		boxc[x]++;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		int sum = 0;
		if (boxa[i] > 0)
			for (int j = 0; j < b[i].size(); j++)
				sum += boxc[b[i][j]];
		ans += sum * boxa[i];
	}
	cout << ans << endl;
}
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct node{
	int a, b;
};
vector<node> v[4005];
int box[4005], ans[500005];
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
    	int x;
        cin >> x;
        box[x]++;
    }
    for (int i = 2; i <= 4000; i++)
    	for (int j = 1; j <= i/2; j++){
    		int k = i - j;
    		v[j + k].push_back({j, k});
		}
	for (int i = 2; i <= 4000; i++){
		int sum = 0;
		for (int j = 0; j < v[i].size(); j++)
			sum += min(box[v[i][j].a], box[v[i][j].b]) / (1 + (v[i][j].a == v[i][j].b));
		ans[sum]++;
//		if (sum > 0) cout << sum << ' ' << i << endl;
	}
	for (int i = 500000; i >= 1; i--)
		if (ans[i] > 0){
			cout << i << ' ' << ans[i] << endl;
			return 0;
		}
    return 0;
}
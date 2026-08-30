#include <iostream>
#include <algorithm>
using namespace std;

const int d = 1e5 + 5;
bool target[200010];
int spot[100005], num[5][100005];
void update(int x){
	for (int i = 0; i < 5; i++)
		num[i][x] += num[i][x-1];
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t, c;
	cin >> t >> c;
	for (int i = 1; i <= t; i++){
		int x;
		cin >> x;
		target[x + d] = true;
	}
	string s;
	cin >> s;
	for (int i = 1; i <= c; i++){
		if (s[i-1] == 'L'){
			spot[i] = spot[i-1] - 1;
			update(i); 
		} else if (s[i-1] == 'R'){
			spot[i] = spot[i-1] + 1;
			now++；
			update(i); 
		} else {
			spot[i] = spot[i-1]; 
			for (int j = 0; j < 5; j++)
				num[j][i] += target[spot[i] + j - 2 + d];
			update(i);
		}
	}
	int ans = num[2][c];
	for (int i = 1; i <= c; i++){
		// 改成L
		if (s[i-1] == 'F'){
			ans = max(ans, num[2][i-1] + num[1][c] - num[1][i] - target[spot[i] + d]);
		} else if (s[i-1] == 'R'){
			ans = max(ans, num[2][i-1] + num[0][c] - num[0][i]);
		}
		// 改成R
		 
	}
	return 0;
}




#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int N, M;
	string S, T;
	cin >> N >> M;
	cin >> S >> T;
	int res = 1e9;
	for(int i = 0; i < N - M + 1; i++) {
		int ts= 0;
		for(int j = 0; j < M; j++) {
			ts += (S[i + j] - T[j] + 10) % 10;
		}
		res = min(res, ts);
	} 
	
	cout << res << endl;
	return 0;
}


#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n, r;
		cin >> n >> r;
		for (int i = 1; i <= 10; i++){
			if (n * i % 10 == 0 || n * i % 10 == r){
				cout << i << '\n';
				break;
			}
		}
	}
	return 0;
}




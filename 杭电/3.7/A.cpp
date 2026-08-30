#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
    	int n;
    	string s;
    	cin >> n >> s;
    	bool flag = true;
    	for (int i = 1; i <= n; i++){
    		string t;
    		cin >> t;
    		if (t == s){
    			cout << i << '\n';
    			flag = false;
			}
		}
		if (flag) cout << -1 <<'\n'; 
	}
	return 0;
}



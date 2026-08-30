#include <iostream>
#include <algorithm>
using namespace std;

string s;
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	long long sum = 0;
	cin >> n;
	while (n--){
		char c;
		long long l;
		cin >> c >> l;
		sum += l;
		if (sum > 100){
			cout << "Too Long\n";
			return 0; 
		}
		while (l--) s += c;
	}
	cout << s << '\n';
	return 0;
}




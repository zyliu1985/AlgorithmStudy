#include <iostream>
#include <algorithm>
using namespace std;

string mnc(string s){
	int n = s.size();
	s = ' ' + s;
	int i = 1, j = 2, k = 0;
	while (i + k <= n && j + k <= n){
		if (s[i + k] == s[j + k]) k++;
		else{
			int t = s[i + k] - s[j + k];
			if (t > 0) i += k + 1;
			else j += k + 1;
			if (i == j) j++;
			k = 0;
		}
	}
	string re;
	for (int l = 0; l < n; l++){
		re += s[(min(i, j) + l - 1) % n + 1];
	}
	return re;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	string a, b;
	cin >> a >> b;
	string aa = mnc(a);
	string ab = mnc(b);
	if (aa == ab){
		cout << "Yes\n" << aa << '\n';
	} else {
		cout << "No\n";
	}
	return 0;
}


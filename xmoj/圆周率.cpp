#include <iostream>
using namespace std;

int pai_digit_num[10] = {20104, 20063, 19892, 20011, 19874, 20199, 19898, 20163, 19956, 19841};
int digit_num[10];
int main(){
	freopen("pai.in", "r", stdin);
	freopen("pai.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		digit_num[s[i] - '0']++;
	int ans1, ans2;
	for (int i = 0; i <= 9; i++)
		if (pai_digit_num[i] < digit_num[i])
			ans1 = i;
		else if (pai_digit_num[i] > digit_num[i])
			ans2 = i;
	cout << ans1 << ' ' << ans2 << endl; 
	return 0;
}

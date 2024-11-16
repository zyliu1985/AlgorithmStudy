#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

string x;
int f[100005];
int ans = 1e9;
int cul(string s){
	bool flag = true;
	char last = s[0];
	for (int i = 1; i < s.size(); i++)
		if (s[i] != last){
			flag = false;
			break;
		}
	if (flag) return 1;
	flag = true;
	for (int i = 1; i < s.size(); i++)
		if (s[i] - last != i){
			flag = false;
			break;
		}
	if (flag) return 2;
	flag = true;
	for (int i = 1; i < s.size(); i++)
		if (last - s[i] != i){
			flag = false;
			break;
		}
	if (flag) return 2;
	flag = true;
	for (int i = 2; i < s.size(); i++)
		if (s[i] != s[i % 2]){
			flag = false;
			break;
		}
	if (flag) return 4;
	flag = true;
	int d = s[1] - s[0];
	for (int i = 2; i < s.size(); i++)
		if (last + d * i != s[i]){
			flag = false;
			break;
		}
	if (flag) return 5;
	return 10; 
}
int main(){
//    freopen("round.in","r",stdin);
//    freopen("round.out","w",stdout);
    cin >> x;
    x = ' ' + x;
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    f[3] = f[0] + cul(x.substr(1, 3));
    f[4] = f[0] + cul(x.substr(1, 4));
    f[5] = f[0] + cul(x.substr(1, 5));
    for (int i = 6; i <= x.size(); i++)
    	f[i] = min(f[i-3] + cul(x.substr(i-2, 3)), min(f[i-4] + cul(x.substr(i-3, 4)), min(f[i-5] + cul(x.substr(i-4, 5)), f[i-6] + cul(x.substr(i-5, 6)))));
	cout << f[x.size() - 1] << endl;
    return 0;
}

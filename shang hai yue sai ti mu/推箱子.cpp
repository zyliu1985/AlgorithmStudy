#include <iostream>
#include <cmath>
using namespace std;

int a[1000005];
int main(){
	int t, n;
	string s;
	cin >> t;
	for (int _ = 1; _ <= t; _++){
		cin >> n;
		cin >> s;
		int cnt = 0;
		for (int i = 0; i < s.size(); i++) // ��¼ÿ�����ӵ�λ��
			if (s[i] == '@') a[++cnt] = i;
		for (int i = 1; i <= cnt; i++) // λ��ƫ�Ƴ����ֵ
			a[i] -= i;
		int mid = cnt/2+1; // ��λ����ż��ƫ�ң����׼��
		int ans = 0;
		for (int i = 1; i <= cnt; i++){
			ans += abs(a[i] - a[mid]);
		}
		cout << ans << endl;
	}
	return 0;
}
#include <iostream>
using namespace std;

int box[10005], a[100005]; // box��ʾÿ�ֿ�ζ������
int cnt, ans = 1e9; // cnt��ʾ���е�������
int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int l = 1, r = 0; // ��������
	while (r < n){
		if (cnt == m) ans = min(ans, r - l + 1);
		r++;
		if (box[a[r]] == 0) cnt++;
		box[a[r]]++;
		while (box[a[l]] > 1) box[a[l]]--, l++;
//		cout << '[' << l << ',' << r << ']' << ':';
//		for (int i = 1; i <= m; i++) cout << box[i] << ' ';
//		cout << endl;
	}
	if (ans == 1e9) cout << "no answer" << endl;
	cout << ans << endl;
	return 0;
}
#include <iostream>
using namespace std;

int main(){
	int n, n5, n10; // 20Ԫֽ���޷�����
	n5 = n10 = 0;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++){
		int c;
		cin >> c;
		if (c == 5){
			// ��������
			n5++;
			ans++;
		} else if (c == 10){
			// ֻ����5Ԫ����
			if (n5 > 0){
				n5--;
				n10++;
				ans++;
			}
		} else {
			// ����5Ԫ+5Ԫ+5Ԫ��Ҳ����10Ԫ+5Ԫ��������10Ԫ
			if (n5 > 0 && n10 > 0){
				n10--;
				n5--;
				ans++;
			} else if (n5 > 2){
				n5 -= 3;
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
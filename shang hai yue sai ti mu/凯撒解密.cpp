#include <iostream>
using namespace std;

string a[505]; // a�洢���ǿ���Ϊt�����ĵĵ���
int b[26]; // b�洢���Ǵ�
int main(){
	string t, s, ans;
	// tΪ��ĿҪ��s��ɨ��ĸ���������ans��tͨ����ͬ��Կ���ܺ�Ľ��
	int sum = 0, cnt = 0;
	cin >> t;
	while (cin >> s){
		if (s.size() == t.size()) a[++cnt] = s; 
		// ɨ�����
	}
	for (int i = 1; i <= 25; i++){ // iΪ��Կ
		// ����
		ans = t;
		for (int j = 0; j < t.size(); j++){
			ans[j] = char((int(ans[j]-'a'+i) % 26) + 'a');
		}
		// ����
		for (int j = 1; j <= cnt; j++){
			if (a[j] == ans){
				b[++sum] = i; // �洢��
				break; // �����ظ�����
			}
		}
	}
	if (sum == 0){
		cout << "Error" << endl;
		return 0;
	}
	cout << sum << endl;
	for (int i = 1; i <= sum; i++) cout << b[i] << ' ';
	return 0;
}
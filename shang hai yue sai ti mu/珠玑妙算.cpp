#include <iostream>
using namespace std;

int main(){
	string a, b;
	int cnt1 = 0, cnt2 = 0;
	cin >> a >> b;
	for (int i = 0; i < 4; i++){
		if (a[i] == b[i]){
			cnt1++;
			continue;
		}
		for (int j = 0; j < 4; j++){
			if (a[i] == b[j]){
				cnt2++;
				break;
			}
		}
	}
	cout << cnt1 << endl << cnt2 << endl;
	return 0;
}
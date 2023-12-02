#include <iostream>
using namespace std;

int box[500005], a[500005];
int main(){
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++){
		cnt++;
		if (a[i] != a[i+1]){
			box[cnt]++;
			cnt = 0;
		}
	}
	for (int i = n; i >= 1; i--){
		if (box[i] > 0){
			cout << i << ' ' << box[i] << endl;
			return 0;
		}
	}
	return 0;
}
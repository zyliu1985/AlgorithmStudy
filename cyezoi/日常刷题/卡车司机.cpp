#include <iostream>
using namespace std;

int f[7005];
bool ld[7005];
int main(){
	ld[0] = true;
	ld[990] = true;
	ld[1010] = true;
	ld[1970] = true;
	ld[2030] = true;
	ld[2940] = true;
	ld[3060] = true;
	ld[3930] = true;
	ld[4060] = true;
	ld[4970] = true;
	ld[5030] = true;
	ld[5990] = true;
	ld[6010] = true;
	ld[7000] = true;
	int a, b, x;
	cin >> a >> b >> x;
	for (int i = 1; i <= x; i++){
		int x;
		cin >> x;
		ld[x] = true;
	}
	f[0] = 1;
	for (int i = 1; i <= 7000; i++)
		for (int j = max(0, i - b); j <= max(0, i - a); j++)
			if (ld[j]) f[i] += f[j];
	cout << f[7000] << endl;
	return 0;
}
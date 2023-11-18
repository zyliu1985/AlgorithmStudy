#include <iostream>
using namespace std;

int A[10] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};
int main(){
	string n;
	int sum = 0;
	cin >> n;
	for (int i = 0; i < 4; i++){
		int x = n[i]-'0';
		sum += A[x];
	}
	cout << sum << endl;
	return 0;
}
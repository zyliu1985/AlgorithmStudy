#include <iostream>
#include <algorithm>
using namespace std;

int N = 200005; 
int A[200005];
int B[200005]; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int bIndex = 0;
	int k = 0; 
	for(int i = 1; i <= n; i++) {
		cin >> A[i];
		bIndex++;
		A[bIndex] = A[i];
		if(A[bIndex - 1] == A[i]) {
			B[bIndex] = B[bIndex-1] + 1;
			if(B[bIndex] == 4) {
				bIndex -= 4;
				k++;
			}
		} else {
			B[bIndex] = 1;
		}
	}
	cout << bIndex << endl;
	return 0;
}


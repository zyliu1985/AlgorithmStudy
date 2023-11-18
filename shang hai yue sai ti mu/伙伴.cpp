#include <iostream>
using namespace std;

int out[1000005];
int Left[1000005], Right[1000005];

int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		cin >> out[i];
	}
	for (int i = 1; i <= n; i++){
		if (i == 1) Left[i] = -1;
		else Left[i] = i-1;
		if (i == n) Right[i] = -1;
		else Right[i] = i+1;
	}
	for (int i = 1; i <= m; i++){
		if (Left[out[i]] == -1) cout << "* ";
		else cout << Left[out[i]] << ' ';
		if (Right[out[i]] == -1) cout << '*' << endl;
		else cout << Right[out[i]] << endl;
		if (out[i] != 1) Right[Left[out[i]]] = Right[out[i]];
		if (out[i] != n) Left[Right[out[i]]] = Left[out[i]];
	}
	return 0;
}
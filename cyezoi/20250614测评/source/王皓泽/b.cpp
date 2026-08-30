#include<bits/stdc++.h>
using namespace std;
int l;
bool tapes0[400010];
bool tapes1[400010];
int main() {
	cin >> l;
	for(int i = 1; i <= l; i++) {
		int tmp;
		cin >> tmp;
		tapes0[i] = (bool)tmp;
	}
	for(int i = 1; i <= l; i++) {
		int tmp;
		cin >> tmp;
		tapes1[i] = (bool)tmp;
	}
	int cnt = 0;
	for(int i = 1; i <= l; i++) {
		if(tapes0[i]){
			if(tapes0[i - 1]) {
				cnt++;
			} else {
				cnt += 3;
			}
		}
	}
	for(int i = 1; i <= l; i++) {
		if(tapes1[i]){
			if(tapes1[i - 1]) {
				cnt++;
			} else {
				cnt += 3;
			}
			if(tapes0[i] && i % 2 == 1) {
				cnt -= 2;
			}
		}
	}
	cout << cnt;
	return 0;
}
/*
5
1 0 1 0 1
0 0 0 0 0


7
0 0 1 1 0 1 0
0 0 1 0 1 0 0
*/

#include <iostream>
#include <algorithm>
using namespace std;

int l[1000005][5];

int main(){
	int len, n, t = 0, out = 0;
	cin >> n >> len;
	for (int i = 1; i <= n; i++){
		int w, f;
		cin >> w >> f;
		l[w][f]++;
	}
	//cout << "end" << endl;
	while (out != n){
		t++;
		for (int i = 0; i <= len; i++){
			if (i > 0) l[i-1][2] += l[i][0];
			if (i < len) l[i+1][3] += l[i][1];
		}
		for (int i = 0; i <= len; i++){
			l[i][0] = l[i][2];
			l[i][1] = l[i][3];
			l[i][2] = 0;
			l[i][3] = 0;
			if (l[i][0] + l[i][1] > 1){
				swap(l[i][0], l[i][1]);
			}
		}
		out += l[0][0] + l[0][1] + l[len][0] + l[len][1];
		l[0][0] = 0;
		l[0][1] = 0;
		l[len][0] = 0;
		l[len][1] = 0;
	}
	cout << t << endl;
	return 0;
}
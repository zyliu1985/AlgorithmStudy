#include <iostream>
#include <vector>
using namespace std;

struct thing{
	int h, v;
	string name;
} th[105];
struct dpstr{
	int h, v;
	vector<string> ve;
} dpa[105][105];

void dp(int maxh, int n){
	for (int i = 1; i <= n; i++){
		string s = th[i].name;
		for (int j = 1; j <= maxh; j++){
			//cout << "xxx" << endl;
			int t, t2;
			if (th[i].h <= j){
				t = th[i].v + dpa[i-1][j-th[i].h].v;
				t2 = th[i].h + dpa[i-1][j-th[i].h].h;
			} else {
				t = 0;
				t2 = 0;
			}
			if (t > dpa[i-1][j].v){
				dpa[i][j].v = t;
				dpa[i][j].h = t2;
				dpa[i][j].ve.push_back(s);
				if (j-th[i].h <= 0){
					cout << th[i].v << ',' << th[i].h;
					cout << s << "  ";
					continue;
				}
				for (int k = 0; k < dpa[i-1][j-th[i].h].ve.size(); k++){
					dpa[i][j].ve.push_back(dpa[i-1][j-th[i].h].ve[k]);
				}
			} else {
				dpa[i][j] = dpa[i-1][j];
			}
			cout << dpa[i][j].v << ',' << dpa[i][j].h;
			for (int k = 0; k < dpa[i][j].ve.size(); k++){
				cout << dpa[i][j].ve[k];
			}
			cout << "  ";
		}
		cout << endl;
	}
	return;
}

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> th[i].h >> th[i].v >> th[i].name;
	}
	int maxh;
	cin >> maxh;
	dp(maxh, n);
	cout << dpa[n][maxh].v << ' ' << dpa[n][maxh].h << endl;
	for (int i = 0; i < dpa[n][maxh].ve.size(); i++){
		cout << dpa[n][maxh].ve[i] << ' ';
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
vector<int> lf[30];
vector<int> nc[30];
int lfn[30], ncn[30], res[30];
bool visl[30], visn[30];
struct hdp{
	int x1, y1, x2, y2;
} h[30];
struct number{
	int x, y;
} num[30];
stack<int> st;
bool is_in(hdp x, number y){
	return x.x1 <= y.x && y.x <= x.x2 && x.y1 <= y.y && y.y <= x.y2;
}
void tbpx(){
	for (int i = 1; i <= n; i++)
		if (lfn[i] == 1){
			res[i] = lf[i][0];
			st.push(i);
		}
	for (int i = 1; i <= n; i++)
		if (ncn[i] == 1){
			res[nc[i][0]] = i;
			st.push(i+n);
		}
	while (!st.empty()){
		int x = st.top();
		st.pop();
		if (x <= n){
			visl[x] = true;
			int y;
			for (int i = 0; i < lf[x].size(); i++)
				if (!visn[lf[x][i]]){
					y = lf[x][i];
					break;
				}
			visn[y] = true;
			for (int i = 0; i < nc[y].size(); i++)
				if (!visl[nc[y][i]]){
					lfn[nc[y][i]]--;
					if (lfn[nc[y][i]] == 1){
						int z = nc[y][i];
						for (int j = 0; j < lf[z].size(); j++)
							if (!visn[lf[z][j]]){
								res[z] = lf[z][j];
								break;
							}
						st.push(nc[y][i]);
					}
				}
		} else {
			x -= n;
			visn[x] = true;
			int y;
			for (int i = 0; i < nc[x].size(); i++)
				if (!visl[nc[x][i]]){
					y = nc[x][i];
					break;
				}
//			cout << x << ' ' << res[x] << ' ' << visn[x] << endl;
			visl[y] = true;
			for (int i = 0; i < lf[y].size(); i++)
				if (!visn[lf[y][i]]){
//					cout << lf[y][i] << endl;
					ncn[lf[y][i]]--;
					if (ncn[lf[y][i]] == 1){
						int z = lf[y][i];
						for (int j = 0; j < nc[z].size(); j++)
							if (!visl[nc[z][j]]){
								res[nc[z][j]] = z;
								break;
							}
//						cout << '*' << endl;
						st.push(lf[y][i]+n);
					}
				}
		}
	}
	for (int i = 1; i <= n; i++)
		if (!visl[i] || !visn[i]){
			cout << "None" << endl;
			return;
		}
	for (int i = 1; i <= n; i++)
		cout << char(i-1+'A') << res[i] << endl;
}
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> h[i].x1 >> h[i].x2 >> h[i].y1 >> h[i].y2;
	for (int i = 1; i <= n; i++){
		cin >> num[i].x >> num[i].y;
		for (int j = 1; j <= n; j++)
			if (is_in(h[j], num[i])){
				lf[j].push_back(i);
				lfn[j]++;
				nc[i].push_back(j);
				ncn[i]++;
			}
	}
	tbpx();
	return 0;
}
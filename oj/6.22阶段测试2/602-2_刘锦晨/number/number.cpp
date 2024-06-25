#include <iostream>
#include <cstdio>
using namespace std;

int a[105][105];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++){
		for (int x = 1; x <= 5; x++){
			for (int j = 1; j <= m; j++){
				if (a[i][j] == 0){
					switch(x){
						case 1: cout << "### "; break;
						case 2: cout << "# # "; break;
						case 3: cout << "# # "; break;
						case 4: cout << "# # "; break;
						case 5: cout << "### "; break;
					}
				} else if (a[i][j] == 1){
					switch(x){
						case 1: cout << "  # "; break;
						case 2: cout << "  # "; break;
						case 3: cout << "  # "; break;
						case 4: cout << "  # "; break;
						case 5: cout << "  # "; break;
					}
				} else {
					switch(x){
						case 1: cout << "### "; break;
						case 2: cout << "  # "; break;
						case 3: cout << "### "; break;
						case 4: cout << "#   "; break;
						case 5: cout << "### "; break;
					}
				}
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}

#include <iostream>
using namespace std;

int main(){
	string a, b;
	cin >> a >> b;
	int cura = 0;
	for (int curb = 0; curb < b.size(); curb++)
		if (b[curb] == a[cura]){
			cura++;
			if (cura == a.size()){
				cout << "Yes" << endl;
				return 0;
			}
		}
	cout << "No" << endl;
	return 0;
}
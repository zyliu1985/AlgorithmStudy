#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> nr; // init book
int yr; // readed book

int main(){
	int n;
	cin >> n;
	int bef = 0;
	for (int i = 1; i <= n; i++){
		int t;
		cin >> t;
		if (bef == t){
			yr++;
		} else {
			nr.push_back(t);
			bef = t;
		}
	}
	int x = 1;
	while ((!nr.empty() && nr[0] == x) || yr+nr.size() >= 2){
		//cout << "nrs=" << nr.size() << ",nr[0]=" << nr[0] << ",yr=" << yr << ",x=" << x << endl;  
		if (nr.empty() || nr[0] != x){
			if (yr >= 2){
				yr--;
				x++;
			} else if (yr == 1 && nr.size() >= 1){
				nr.pop_back();
				x++;
			} else if (nr.size() >= 2){
				nr.pop_back();
				nr.pop_back();
				yr++;
				x++;
			} else {
				x++;
				break;
			}
			continue;
		}
		while (nr[0] == x && !nr.empty()){
			//cout << "===================" << nr[0] << endl;
			yr++;
			nr.erase(nr.begin());
		}
		x++;
	}
	cout << x-1 << endl;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
struct Day{
	int ppl, ind;
};
bool cmp(Day& a, Day& b) {
	return a.ppl != b.ppl ? a.ppl > b.ppl : a.ind < b.ind;
}
Day days[5];
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < 5; i++) {
		days[i].ind = i + 1;
	}
	for(int i = 0; i < n; i++) {
		char c;
		for(int d = 0; d < 5; d++) {
			cin >> c;
			if(c == 'Y') {
				days[d].ppl++;
			}
		}
	}
	vector<int> maxIndexs;
	sort(days, days + 5, cmp);
	maxIndexs.push_back(days[0].ind);
	for(int i = 1; i < 5; i++) {
		if(days[i].ppl == days[0].ppl) {
			maxIndexs.push_back(days[i].ind);
		} else {
			break;
		}
	}
	cout << maxIndexs[0];
	for(int i = 1; i < maxIndexs.size(); i++) {
		cout << ',' << maxIndexs[i];
	}
	return 0;
}

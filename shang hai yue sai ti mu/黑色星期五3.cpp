#include <iostream>
using namespace std;

int day[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int sd[13];
int F = 13;

bool isRunnian(int year) {
	if(year % 400 == 0) {
		return true;
	} else if(year % 100 != 0 && year % 4 == 0) {
		return true;
	} else {
		return false;
	}
}

int main() {
	int y, w;
	cin >> y >> w;
	
	bool run = isRunnian(y);
	for(int i = 0; i <= 12; i++) {
		for(int j = 0; j<=i; j++) {
			sd[i] += day[j];
		}
		if(run && i >= 2) {
			sd[i] += 1;
		}
	}
	
	
	bool hasResult = false;
	for(int i = 1; i <= 12; i++) {
		int wi = wi = (w + (sd[i-1] + F) % 7) % 7;
		
		cout << "i = " << i << ", wi = " << wi << endl;
		if(wi == 5) {
			hasResult = true;
			cout << i << endl;
		}
	}
	
	if(!hasResult) {
		cout << "None" << endl;
	}
	
	return 0;
}
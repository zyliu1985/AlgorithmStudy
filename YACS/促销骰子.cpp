#include<iostream>
#include<sstream>
using namespace std;

int main() {
	string line;
	getline(cin, line);
	
	int count = 0;
	
	stringstream ss;
	ss << line;
	int num;
	while (ss >> num) {
//		cout << "读取到的数字是：" << num << endl;
		if(num == 6) {
			count ++;
		}
	}

	
	
	if(count == 0) {
		cout << 0;
	} else if(count == 1) {
		cout << 10;
	} else if(count == 2) {
		cout << 100;
	} else if(count == 3) {
		cout << 1000;
	}
	return 0;
}
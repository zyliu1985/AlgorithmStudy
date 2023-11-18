#include <iostream>
using namespace std;


int main(){
	string a, b;
	cin >> a >> b;
	string rv = "";
	string rvf = "";
	
	int lenA = a.length();
	int lenB = b.length();
	int len = max(a.length(), b.length());
//	cout << "len=" << lenA << ' ' << lenB << ' ' << len << endl;
	int c = 0;
	for(int i = 0; i < len; i++) {
		string ca, cb;
		if(len == lenA) {
			ca = a[i];
		} else {
			if(len > lenA && len > lenA + i) {
				ca = "0";
				c++;
			} else {
				ca = a[i - c];
			}
		}
		
		if(len == lenB) {
			cb = b[i];
		} else {
			if(len > lenB && len > lenB + i) {
				cb = "0";
				c++;
			} else {
				cb = b[i - c];
			}
		}
		
//		cout << " aa " << ca << ' ' << cb << ' ' << i << endl;
		if(ca == cb) {
			rv += "0";
		} else {
			rv += "1";
		}
	}
	
//	cout << "rv=" << rv << endl;
	bool flag = false;
	for(int k = 0; k < rv.length(); k++) {
		if(!flag && rv[k] == '1') {
			flag = true;
		}
		
		if(flag) {
			rvf += rv[k];
		}
	}

	cout << rvf << endl;	
}
#include<iostream>
using namespace std;


int main() {
  int n;
  cin >> n;
//  if(n % 2 == 0) {
//  	cout << "even" << endl;
//  } else {
//  	cout << "odd" << endl;
//  }

	if(n & 1) {
		cout << "odd" << endl;
	} else {
		cout << "even" << endl;
	}
  return 0;
}
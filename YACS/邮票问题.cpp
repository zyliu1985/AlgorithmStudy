#include<iostream>
using namespace std;

int a[4] = {20, 10, 5, 1};

int main() {
  int n;
  cin >> n;
  int count = 0;
  for(int i = 0; i < 4; i++) {
  	if(n>=a[i]) {
      count += n/a[i];
      n = n % a[i];
    }
  }
  
  cout << count << endl;
  return 0;
}
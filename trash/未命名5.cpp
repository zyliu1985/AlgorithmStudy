#include <iostream>
#include <algorithm>
using namespace std;

bool isprime(int x){
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0) return false;
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int ans = 1;
	for (int i = 2; i <= ; i++)
		if (isprime(i)) ans *= i;
	
	return 0;
}


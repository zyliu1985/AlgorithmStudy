//#include <iostream>
//#include <cmath>
//using namespace std;
//
//bool check(int x){
//	if (x == 1) return false;
//	for (int i = 2; i <= sqrt(x); i++){
//		if (x % i == 0) return false;
//	}
//	return true;
//}
//int main(){
//	int n;
//	cin >> n;
//	int t = 2;
//	while (n > 1){
//		if (n % t != 0 || !check(t)){
//			t++;
//			continue;
//		}
//		n /= t;
//		cout << t << ' ';
//	}
//	return 0;
//}



#include <iostream>
#include <cmath>
using namespace std;

bool check(long long x){
	if (x == 1) return false;
	for (long long i = 2; i <= sqrt(x); i++){
		if (x % i == 0) return false;
	}
	return true;
}
int main(){
	int cnt = 0;
	for (int i = 1; i <= 100000; i++)
		if (i ^ 1 && i != 5 && check(10000000000 + i)){
			cout << 10000000000 + i << endl;
			cnt++;
			if (cnt == 4) return 0;
		}
	return 0;
}
#include <iostream>
using namespace std;

const int mod = 998244353;
int q_mi(long long di, long long up){
	if (up == 0) return 1;
	if (up & 1) return (q_mi(di * di % mod, up / 2) * di) % mod;
	else return q_mi(di * di % mod, up / 2) % mod;
}
int main(){
	
	return 0;
}
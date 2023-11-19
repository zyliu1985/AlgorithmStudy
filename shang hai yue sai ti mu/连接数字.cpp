//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//string a[100005];
//int step = 0;
//bool cmp(string x, string y){
//	return x[step] > y[step];
//}
//int fun(int l, int r){
//	sort(a+l, a+r, cmp);
//	step++;
//	for (int i = 1; i <= n; i++){
//		
//	}
//	step--;
//}
//int main(){
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++){
//		cin >> a[i];
//	}
//	
//}
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

long long a[100005];
bool cmp(long long x, long long y){
	return x > y;
}
//int main(){
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++){
//		cin >> a[i];
//	}
//	sort(a+1, a+n+1, cmp);
//	for (int i = 1; i <= n; i++) cout << a[i];
//	return 0;
//}

stack<long long> s[100005];

stack split(long long x) {
	stack<long long> rv;
	while (x != 0) {
		rv.push(x%10);
		x = x / 10;
	}
	return rv;
}

long long b[100005];

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		s[i] = split(a[i]);
		b[i] = s[i].pop();
	}
	
	sort(b+1, b+n+1, cmp);
	//取出每个数字的第一个数字
	for (int i = 1; i <= n; i++){
		b
	}
	
	return 0;
}
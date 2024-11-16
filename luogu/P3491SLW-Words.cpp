#include <iostream>
#include <stack>
using namespace std;

stack<int> st;
long long read(){
	long long re = 0, type = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') type = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		re = re * 10 + (c - '0');
		c = getchar();
	}
	return re * type;
}
bool check(){
	int x = st.top();
	st.pop();
	int y = st.top();
	st.pop();
	st.push(y);
	st.push(x);
	return x + 1 == y;
}
int main(){
	cout.tie(0);
	int t = read();
	while (t--){
		int n = read();
		for (int i = 1; i <= n; i++){
			int x = read();
			st.push(x);
			while (st.size() > 1 && check()){
				int to = st.top();
				st.pop();
				st.pop();
				st.push(to+2);
			}
		}
		if (st.size() == 1)
			cout << "TAK\n";
		else
			cout << "NIE\n";
	}
	return 0;
}

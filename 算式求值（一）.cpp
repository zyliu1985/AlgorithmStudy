#include <iostream>
#include <stack>
using namespace std;

stack<int> a;
stack<char> b;
string s;
int pushNum(int x){
	int num = 0;
	while (s[x] >= '0' && s[x] <= '9'){
		num = num*10 + int(s[x]-'0');
		x++;
	}
	a.push(num);
	return x;
}
void popSt(){
	int x, y;
	y = a.top();
	a.pop();
	x = a.top();
	a.pop();
	char ch;
	ch = b.top();
	b.pop();
	if (ch == '+') a.push(x+y);
	else a.push(x-y);
}
int main(){
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		if (a.size() >= 2 && !b.empty()) popSt();
		if (s[i] >= '0' && s[i] <= '9') i = pushNum(i)-1;
		else b.push(s[i]);
	}
	popSt();
	cout << a.top() << endl;
	return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;

int fun(char x){
	switch (x){
		case 'A': return 4;
		case 'B': return 3;
		case 'C': return 2;
		case 'D': return 1;
	}
}
int main(){
	string s;
	cin >> s;
	int n = 0;
	double sum = 0;
	for (int i = 0; i < s.size(); i++){
		n++;
		if (s[i+1] == '+' || s[i+1] == '-'){
			i++;
			if (s[i] == '+') sum += fun(s[i-1]) + 0.3;
			else sum += fun(s[i-1]) - 0.3;
		} else {
			sum += fun(s[i]);
		}
	}
	printf("%.2f", sum/n);
	return 0;
}
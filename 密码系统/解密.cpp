#include <iostream>
#define key 5
using namespace std;

string s;
int numSize, l2numSize = 0;
bool TFx;

int uncom(int mi){
	int ans = 0;
	int subn = key;
	if (s[numSize+1] == '%' || s[l2numSize+1] == '%'){
		subn++;
	}
	int t = 1;
	while (mi > 0){
		int a = mi % 10 + 10;
		a -= subn;
		a %= 10;
		if (TFx && mi < 10){
			a--;
		}
		ans += a * t;
		t *= 10;
		mi /= 10;
	}
	l2numSize = numSize;
	return ans;
}

int findNum(int x){
	int ans = 0;
	bool flag = false;
	while ((s[x] >= '0' && s[x] <= '9') || s[x] == '-' || s[x] == 'x'){
		if (s[x] == '-'){
			flag = true;
		} else if (s[x] == 'x'){
			TFx = true;
		} else {
			ans += s[x] - '0';
			ans *= 10;
		}
		
		if (x == int(s.size()) - 1){
			break;
		}
		x++;
	}
	ans /= 10;
	numSize = x-1;
	int ansUncom = uncom(ans);
	if (flag){
		ansUncom -= 2 * ansUncom;
	}
	return ansUncom;
}

int main(){
	getline(cin, s);
	for (int i = 0; i < s.size(); i++){
		if ((!(s[i] >= '0' && s[i] <= '9')) && s[i] != '-' && s[i] != '%' && s[i] != '*' && s[i] != 'x'){
			cout << "Wrong!" << endl;
			return 0;
		}
	}
	for (int i = 0; i < s.size(); i++){
		TFx = false;
		int n;
		if ((s[i] >= '0' && s[i] <= '9') || s[i] == '-'){
			n = findNum(i);
			cout << char(n);
			i = numSize;
			if (numSize+1 >= int(s.size()) - 1){
				return 0;
			}
		} else if (s[i] == '%'){
			cout << ' ';
		}
	}
	return 0;
}
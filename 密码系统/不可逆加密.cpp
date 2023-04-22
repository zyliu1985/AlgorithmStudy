#include <iostream>
#include <vector> 
using namespace std;

string password;
string ascpassword;
vector<int> v;
vector<int> clearv;

void s2asc(){
	for (int i = 0; i < password.size(); i++){
		int x = int(password[i]);
		string num;
		while (x > 0){
			num = char(x % 10 + '0') + num;
			x /= 10;
		}
		ascpassword += num;
	}
}

void fullV(int x){
	for (int i = 0; i < ascpassword.size(); i++){
		int t = 0;
		int num = 0;
		while (t < x && i+t < ascpassword.size()){
			num += int(ascpassword[i+t] - '0');
			num *= 10;
			t++;
		}
		num /= 10;
		v.push_back(num);
	}
}

void renewV(){
	for (int i = 0; i < v.size(); i++){
		v[i] = (i+1) * 998 % 1007;
	}
}

//void fullAscpswd(){
//	for (int i = 0; i < v.size(); i++){
//		ascpassword += v[i];
//	}
//}

int main(){
	cin >> password;
	s2asc();
	fullV(3);
	renewV();
	v = clearv;
	fullV(2);
	
	return 0;
}

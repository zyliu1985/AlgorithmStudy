#include <iostream>
using namespace std;

int S[1005];
int mod(int m){
	int last = 0;
	for (int i = S[0]; i >= 1; i--){
		last = (last*10+S[i]) % m;
	}
	return last;
}
int main(){
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		S[s.size()-i] = int(s[i]-'0');
	}
	S[0] = s.size();
	for (int i = 1; i <= S[0]; i++){
		if (S[i] != 0 && mod(S[i]) != 0){
			cout << "not clever" << endl;
			return 0;
		}
	}
	cout << "clever" << endl;
	return 0;
}
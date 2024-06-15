#include <iostream>
using namespace std;
typedef unsigned long long ull;
const ull __p = 1e9+7;
 
ull hash1[1000005];
ull p[1000005];
string s;
int len;
void set_hash(string s, ull* __hash){
    __hash[0] = 0;
    for (int i = 0; i < s.size(); i++){
        __hash[i+1] = __hash[i] * __p + s[i];
    }
}
ull hash_substr(int l, int r, ull* __hash){
    return __hash[r] - __hash[l-1] * p[r-l+1];
}
int main(){
    p[0] = 1;
    for (int i = 1; i <= 1000000; i++)
        p[i] = p[i-1] * __p;
    cin >> len >> s;
    if (len % 2 == 0){
    	cout << "NOT POSSIBLE" << endl;
    	return 0;
    }
    set_hash(s, hash1);
    for (int i = 1; i <= len; i++)
    	cout << hash1[i] << ' ';
    cout << endl;
    string ans = "!";
    for (int i = 0; i < len; i++){
    	int left = hash_substr(1, i, hash1);
    	int right = hash_substr(i+2, len, hash1);
    	int real_left, real_right;
    	if (i == len / 2 + 1 && left == right){ // left, right 均可用
    		if (ans == "!") ans = s.substr(0, len / 2);
    		else{
    			cout << "NOT UNIQUE" << endl;
    			return 0;
			}
		} else if (i < len / 2 + 1){ // right 可用
			real_right = hash_substr(len-len/2, len, hash1);
			if (left * p[len/2-i] + (right - real_right) / p[len/2] == real_right){
				if (ans == "!") ans = s.substr(0, len / 2);
	    		else{
	    			cout << "NOT UNIQUE" << endl;
	    			return 0;
				}
			}
		} else { // left 可用
			real_left = hash_substr(0, len/2, hash1);
			
			if (left * p[len/2-i] + (right - real_right) / p[len/2] == real_right){
				if (ans == "!") ans = s.substr(0, len / 2);
	    		else{
	    			cout << "NOT UNIQUE" << endl;
	    			return 0;
				}
			}
		}
    	cout << left * p[len-i-1] + right << endl;
	}
    return 0;
}
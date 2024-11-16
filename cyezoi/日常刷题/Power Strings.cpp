#include <iostream>
using namespace std;
typedef unsigned long long ull;
const ull __p = 1e9+7;
 
ull hash1[1000005], hash2[1000005];
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
bool check(int x){
	string t = s.substr(0, x);
	for (int i = x; i < len; i += x){
		set_hash(t, hash2);
		if (hash2[t.size()] != hash_substr(i+1, i+x, hash1))
			return false;
	}
	return true;
}
int main(){
    p[0] = 1;
    for (int i = 1; i <= 1000000; i++)
        p[i] = p[i-1] * __p;
    cin >> s;
    while (s != "."){
    	set_hash(s, hash1);
    	len = s.size();
    	for (int i = 1; i <= len; i++){
    		if (len % i == 0)
    			if (check(i)){
    				cout << len / i << endl;
    				break;
				}
		}
		cin >> s;
	}
    return 0;
}
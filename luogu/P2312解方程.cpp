#include <iostream>
#include <cstring>
using namespace std;

const long long mod1 = 10000000019;
const long long mod2 = 10000000033;
const long long mod3 = 10000000061;
long long _hash[105][4], x, anshash[4];
int ans, anslist[1000005];
bool mina[105];
long long q_pow(long long di, int up, int mod){
	if (up == 0) return 1;
	if (up == 1) return di;
	if (up ^ 1) return (q_pow(di * di % mod, up / 2, mod) * di) % mod;
	else return q_pow(di * di % mod, up / 2, mod);
}
void to_hash(string s, int id){
	int begi = 0;
	if (s[0] == '-') mina[id] = true, begi++;
	int len = s.size();
	long long smul1 = 1, smul2 = 1, smul3 = 1, smul4 = 1;
	for (int i = len - 1; i >= begi; i--){
		_hash[id][1] = (_hash[id][1] + (smul1 * (s[i] - '0')) % mod1) % mod1;
		_hash[id][2] = (_hash[id][2] + (smul2 * (s[i] - '0')) % mod2) % mod2;
		_hash[id][3] = (_hash[id][3] + (smul3 * (s[i] - '0')) % mod3) % mod3;
		smul1 = (smul1 * 10) % mod1;
		smul2 = (smul2 * 10) % mod2;
		smul3 = (smul3 * 10) % mod3;
	}
}
void hash_mul(){
	anshash[1] = (anshash[1] * x) % mod1;
	anshash[2] = (anshash[2] * x) % mod2;
	anshash[3] = (anshash[3] * x) % mod3;
}
void hash_add(int id){
	if (mina[id]){
		anshash[1] = (anshash[1] - _hash[id][1]) % mod1;
		anshash[2] = (anshash[2] - _hash[id][2]) % mod2;
		anshash[3] = (anshash[3] - _hash[id][3]) % mod3;
	} else {
		anshash[1] = (anshash[1] + _hash[id][1]) % mod1;
		anshash[2] = (anshash[2] + _hash[id][2]) % mod2;
		anshash[3] = (anshash[3] + _hash[id][3]) % mod3;
	}
}
int main(){
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++){
		string a;
		cin >> a;
		to_hash(a, i);
	}
	for (int i = 1; i <= m; i++){
		x++;
		memset(anshash, 0, sizeof(anshash));
		// ÇØ¾ÅÉØ¹«Ê½
		for (int j = n; j >= 1; j--){
			hash_add(j);
			hash_mul();
		}
		hash_add(0);
		if (!anshash[1] && !anshash[2] && !anshash[3])
			anslist[++ans] = x;
	}
	cout << ans << endl;
	for (int i = 1; i <= ans; i++)
		cout << anslist[i] << endl;
	return 0;
}
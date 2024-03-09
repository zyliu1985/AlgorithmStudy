#include <iostream>
#include <string.h>
#include <cstring>
//#pragma GCC optimize(2)
using namespace std;

char a[100005], b[100005], l[20], ca[100005], cb[100005];
bool flag[20][20];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b;
	for (char i = 'a'; i <= 'r'; i++)
		for (char j = i; j <= 'r'; j++){
			memset(ca, char(0), sizeof(ca));
			memset(cb, char(0), sizeof(cb));
			int calen, cblen;
			calen = cblen = 0;
			for (int k = 0; k < strlen(a); k++)
				if (a[k] == i || a[k] == j) ca[calen++] = a[k];
			for (int k = 0; k < strlen(b); k++)
				if (b[k] == i || b[k] == j) cb[cblen++] = b[k];
//			cout << ca << ' ' << cb << endl;
			bool bl = true;
			if (calen != cblen) bl = false;
			else{
				for (int k = 0; k < calen; k++)
					if (ca[k] != cb[k]){
						bl = false;
						break;
					}
			}
//			cout << bl << endl;
			flag[i-'a'][j-'a'] = bl;
			flag[j-'a'][i-'a'] = bl;
		}
	int q;		
	cin >> q;
	while (q--){
		bool bl = true;				
		cin >> l;				
		for (int i = 0; i < strlen(l); i++){
			for (int j = i; j < strlen(l); j++)
				if (!flag[l[i]-'a'][l[j]-'a']){
					cout << 'N';
					bl = false;										
					break;									
				}
			if (!bl) break;								
		}								
		if (bl) cout << 'Y';				
	}
	return 0;
}

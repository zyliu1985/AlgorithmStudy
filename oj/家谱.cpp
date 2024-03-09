#include <iostream>
#include <map>;
using namespace std;

map<string, int> mp1;
map<int, string> mp2;
int f[50005];
int find_rt(int x){
	int root = x;
	while (f[root] != 0){
		root = f[root];
	}
	while (f[x] != 0){
		int nxt = f[x];
		f[x] = root;
		x = nxt;
	}
	return root;
}
//void he(int x, int y){
//	int art, brt;
//	art = find_rt(x);
//	brt = find_rt(y);
//	if (art == brt) return;
//	if (size[art] > size[brt]){
//		f[brt] = art;
//		size[art] += size[brt];
//	} else {
//		f[art] = brt;
//		size[brt] += size[art];
//	}
//}
int main(){
	int cnt = 0;
	string fa, s;
	while (s != "$"){
		cin >> s;
		string name = s.substr(1);
		if (!mp1.count(name)){
			mp1[name] = ++cnt;
			mp2[cnt] = name;
		}
		if (s[0] == '#')
			fa = name;
		else if (s[0] == '+')
			f[mp1[name]] = mp1[fa];
		else
			cout << name << ' ' << mp2[find_rt(mp1[name])] << endl;
	}
	return 0;
}
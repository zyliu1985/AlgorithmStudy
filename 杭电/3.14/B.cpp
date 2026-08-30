#include <iostream>
#include <algorithm>
using namespace std;

string tg[10] = {"jia", "yi", "bing", "ding", "wu", "ji", "geng", "xin", "ren", "gui"};
string dz[12] = {"zi", "chou", "yin", "mao", "chen", "si", "wu", "wei", "shen", "you", "xu", "hai"}; 
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		string s;
		cin >> s;
		for (int i = 0; i < 60; i++)
			if (tg[i % 10] + dz[i % 12] == s){
				cout << 1984 + i << '\n';
				break;
			} 
	}
	return 0;
}




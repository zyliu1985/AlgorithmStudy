#include <iostream>
#include <cstring>
#include <map>
using namespace std;

map<string, int> name;
map<int, string> f_name;
map<string, int> da;
string s[105];
int truth[25];
int main(){
	da["Monday."] = 1;
	da["Tuesday."] = 2;
	da["Wednesday."] = 3;
	da["Thursday."] = 4;
	da["Friday."] = 5;
	da["Saturday."] = 6;
	da["Sunday."] = 7;
	int m, n, p;
	cin >> m >> n >> p;
	int cur = 0;
	for (int i = 1; i <= m; i++){
		string t;
		cin >> t;
		name[t] = ++cur;
		f_name[cur] = t;
	}
	getchar();
	for (int i = 1; i <= p; i++)
		getline(cin, s[i]);
	int ans = -1;
	for (int gui = 1; gui <= m; gui++){
		// 枚举犯人
		for (int date = 1; date <= 7; date++){
			// 枚举日期
			memset(truth, -1, sizeof(truth));
			bool flag = false;
			for (int i = 1; i <= p; i++){
				int cnt1;
				for (int c = 0; c < s[i].size(); c++)
					if (s[i][c] == ':'){
						cnt1 = c;
						break;
					}
				string who = s[i].substr(0, cnt1);
				string say = s[i].substr(cnt1+2);
				if (say == "I am guilty.")
					if (gui == name[who]){
						if (truth[name[who]] == 0){flag = true; break;}
						truth[name[who]] = 1;
					} else {
						if (truth[name[who]] == 1){flag = true; break;}
						truth[name[who]] = 0;
					}
				else if (say == "I am not guilty.")
					if (gui == name[who]){
						if (truth[name[who]] == 1){flag = true; break;}
						truth[name[who]] = 0;
					} else {
						if (truth[name[who]] == 0){flag = true; break;}
						truth[name[who]] = 1;
					}
				else if (say.substr(0, 8) == "Today is"){
					string day = say.substr(9);
					if (da[day] == date){
						if (truth[name[who]] == 0){flag = true; break;}
						truth[name[who]] = 1;				
					} else {
						if (truth[name[who]] == 1){flag = true; break;}
						truth[name[who]] = 0;
					}
				} else {
					int cnt2 = -1;
					for (int c = 0; c < say.size(); c++)
						if (say[c] == 'i'){cnt2 = c-1; break;}
					if (cnt2 == -1) continue;
					string who2 = say.substr(0, cnt2);
					string say2 = say.substr(cnt2+1);
					if (name[who2] == 0) continue;
					if (say2 == "is guilty.")
						if (gui == name[who2]){
							if (truth[name[who]] == 0){flag = true; break;}
							truth[name[who]] = 1;
						} else {
							if (truth[name[who]] == 1){flag = true; break;}
							truth[name[who]] = 0;
						}
					if (say2 == "is not guitly.")
						if (gui == name[who2]){
							if (truth[name[who]] == 1){flag = true; break;}
							truth[name[who]] = 0;
						} else {
							if (truth[name[who]] == 0){flag = true; break;}
							truth[name[who]] = 1;
						}
				}
			}
			if (flag) continue;
			int num = 0, wrong = 0;
			for (int i = 1; i <= m; i++)
				if (truth[i] == -1) num++;
				else if (truth[i] == 0) wrong++;
			if (wrong == n || (wrong < n && wrong + num >= n))
			    if (ans == -1) ans = gui;
			    else {
			    	cout << "Cannot Determine" << endl;
			    	return 0;
				}
		}
	}
	if (ans == -1) cout << "Impossible" << endl;
	else cout << f_name[ans] << endl;
	return 0;
}
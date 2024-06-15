#include <iostream>
#include <cstring>
using namespace std;

struct tric{
	int tre[10005][150], cur;
	bool ed[10005];
	void set_up(){
		cur = 0;
		memset(tre, 0, sizeof(tre));
		memset(ed, false, sizeof(ed));
	}
	void insert(string s){
		int now = 0;
		for (int i = 0; i < s.size(); i++){
			int t = s[i];
			if (!tre[now][t]) tre[now][t] = ++cur;
			now = tre[now][t];
		}
		ed[now] = true;
	}
	bool find(string s){
		int now = 0;
		for (int i = 0; i < s.size(); i++){
			int t = s[i];
			if (!tre[now][t]) return false;
			now = tre[now][t];
		}
		return ed[now];
	}
};
int main(){
	
	return 0;
}
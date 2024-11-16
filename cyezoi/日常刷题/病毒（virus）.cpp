#include <iostream>
#include <vector>
#include <stack>
using namespace std;
 
string s[50005];
int rd[30], res[30];
vector<int> v[30];
int n;
bool vis[30], vres[30], flag[30];
stack<int> st;
void tbpx(){
    string ans;
    cin >> ans;
    for (int i = 0; i < ans.size(); i++) flag[ans[i]-'a'] = true;
    for (int i = 0; i < 26; i++)
        if (rd[i] == 0 && flag[i]){
            st.push(i);
            res[i] = 0;
        }
    while (!st.empty()){
        int x = st.top();
//        cout << char(x+'a') << char(res[x]+'a') << endl;
        st.pop();
        if (vis[x]) continue;
        vis[x] = true;
        for (int i = 0; i < v[x].size(); i++){
            rd[v[x][i]]--;
            res[v[x][i]] = max(res[v[x][i]], res[x] + 1);
            if (rd[v[x][i]] == 0) st.push(v[x][i]);
        }
        // ×Öµä²»ÍêÕû
        if (!vres[res[x]]){
            vres[res[x]] = true;
        } else {
            cout << 0 << endl;
            return;
        }
    }
    // ×Öµä´íÎó
    for (int i = 0; i < 26; i++) 
        if (!vis[i] && rd[i]){
            cout << 0 << endl;
            return;
        }
    string xx;
	for (int i = 0; i < ans.size(); i++)
		if (!vis[ans[i]-'a']){
			cout << 0 << endl;
			return;
		} else {
			xx += res[ans[i]-'a']+'a';
		}
	cout << xx << endl;
}
int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 2; i <= n; i++){
        int cur = 0;
        while (cur < s[i].size() && cur < s[i-1].size() && s[i][cur] == s[i-1][cur])
            cur++;
        if (cur == s[i].size() || cur == s[i-1].size()){
            if (s[i].size() < s[i-1].size()){
                cout << 0 << endl;
                return 0;
            }
            continue;
        }
        v[s[i-1][cur]-'a'].push_back(s[i][cur]-'a');
        rd[s[i][cur]-'a']++;
    }
    tbpx();
    return 0;
}
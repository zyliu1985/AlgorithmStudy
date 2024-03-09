#include <iostream>
#include <cstdio>
#include <cmath>
#include <stack>
#include <map>
using namespace std;
 
stack<double> a;
stack<char> b;
map<char, int> mp;
void out(){
    char c = b.top();
    b.pop();
    double x, y, ans;
    y = a.top();
    a.pop();
    x = a.top();
    a.pop();
    switch(c){
        case '+': ans = x+y; break;
        case '-': ans = x-y; break;
        case '*': ans = x*y; break;
        case '/': ans = x/y; break;
    }
//  cout << x << c << y << '=' << ans << endl;
    a.push(ans);
}
signed main(){
    mp['+'] = 1;
    mp['-'] = 1;
    mp['*'] = 2;
    mp['/'] = 2;
    string s;
    while (true){
        getline(cin, s);
        if (s == "0") return 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == ' ') continue;
            if (s[i] >= '0' && s[i] <= '9'){
                int num = 0;
                while (i < s.size() && s[i] >= '0' && s[i] <= '9'){
                    num = num*10 + int(s[i]-'0');
                    i++;
                }
                i--;
                a.push(num);
            } else {
                while (!b.empty() && mp[s[i]] <= mp[b.top()])
                    out();
                b.push(s[i]);
            }
        }
        while (!b.empty())
            out();
        printf("%.2f\n", a.top());
        a.pop();
    }
    return 0;
}
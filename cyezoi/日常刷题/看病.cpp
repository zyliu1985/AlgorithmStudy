#include <iostream>
#include <queue>
#include <stack>
#define int long long
using namespace std;

struct node{
	int val;
	string name;
	friend bool operator < (const node x, const node y){
		return x.val < y.val;
	}
};
priority_queue<node> pq;
signed main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
    	string c;
    	cin >> c;
    	if (c == "pop"){
    		if (pq.empty()) cout << "none" << endl;
    		else{
    			cout << pq.top().name << ' ' << pq.top().val << endl;
    			pq.pop();
			}
		} else {
			node x;
			cin >> x.name >> x.val;
			pq.push(x);
		}
	}
    return 0;
}
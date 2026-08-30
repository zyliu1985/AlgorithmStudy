#include <bits/stdc++.h>
using namespace std;
int f[10];
int n;
queue<int> q;
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		string c;
		cin >> c;
		for (int j = 0; j < 5; j++)
			if (c[j] == 'Y')
				f[j + 1]++;
	}
	int mx = 0;
	for (int i = 1; i <= 5; i++){
		if (f[i] > mx){
//			cout << i << " " << f[i] << endl;
			mx = f[i];
			while (!q.empty())
				q.pop();
			q.push(i);
		}
		else if (f[i] == mx)
			q.push(i);
	}
		
	while (!q.empty()){
		cout << q.front();
		q.pop();
		if (!q.empty())
			cout << ",";
	}
	return 0;
}

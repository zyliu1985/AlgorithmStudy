#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int vis[100005], ans;
vector<int> v[100005];
queue<int> q;
void bfs(){
	vis[1] = true;
	q.push(1); // ��ʼ��
	while (!q.empty()){
		int x = q.front();
		q.pop();
		int sum = 0; // sum��ʾx������δ��Ⱦ���ھ�
		for (int i = 0; i < v[x].size(); i++) // ö��x�������ھӣ�����δ��Ⱦ�Ľڵ�
			if (!vis[v[x][i]]){ // ȥ���Ѹ�Ⱦ�Ľڵ�
				vis[v[x][i]] = true; // ��Ǹ�Ⱦ
				sum++;
				q.push(v[x][i]);
			}
		ans += ceil(log2(sum+1)) + sum; // �����Ⱦ����ʱ��
		// cout << x << ' ' << ans << ' ' << sum << endl;
	}
}
int main(){
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++){
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	bfs();
	cout << ans << endl;
	return 0;
}
#include <iostream>
#include <cmath>
using namespace std;

int q[200005];
//������
bool box[200005];
int c[200005];

//queue<int> q[200005];
bool vis[200005];
bool flag[200005];
int n, m;
int bfs(){
	
}

// ���ز�ֵ�ĺ�
int updateC() {
	int d = 0;
	int mi = 9999999;
	// ������С������Ķ�֮��ľ���
	for (int i = 1; i <= n; i++) {
		if(vis[i]) continue;
//		if(box[q[i] + m]) vis[i]=true;
		int count = 1;
		while(true) {
			if(box[q[i] + m + count]) {
				c[i] = count;
				if(abs(c[i]) <= mi) {
					mi = abs(c[i]);
					d = -1;
				}
				break;
			} else if(box[q[i] + m - count]) {
				c[i] = -count;
				if(abs(c[i]) <= mi) {
					mi = abs(c[i]);
					d = 1;
				}
				break;
			} else {
				count++;
			}
		}
	}
	
//	for (int i = 1; i <= n; i++) {
//		cout << c[i] << ' ';
//	}
//	cout << d << endl;
	return d;
}

int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin>>q[i];
		
	for (int i = 1; i <= m; i++) {
		int p;
		cin >> p;
		// ͳһ�����ƶ�m��������ָ���
		box[p + m] = true;
	}
	
	int ans = 0;
	int sum = updateC();
	while(sum != 0) {
		ans++;
		if(sum < 0) {
			for (int i = 1; i <= n; i++) {
				q[i] += 1;
				if(q[i] == 0) vis[i] = true;
			}
			sum = updateC();
		} else {
			for (int i = 1; i <= n; i++) {
				q[i] -= 1;
				if(q[i] == 0) vis[i] = true;
			}
			sum = updateC();
		}
	}
	
	cout << ans << endl;
	return 0;
}
#include <iostream>
using namespace std;

class myDeque{
	int q[1000000], hed = 1, tal = 0, num = 0;
	public:
	void clear(){
		hed = 1, tal = 0, num = 0;
	}
	void push_back(int x){
		if (num == 1000000){
			cout << "deque is overflow!\n";
			exit(-1);
		}
		if (++tal == 1000000) tal = 0;
		q[tal] = x;
		num++;
	}
	void push_front(int x){
		if (num == 1000000){
			cout << "deque is overflow!\n";
			exit(-1);
		}
		if (--hed < 0) hed = 999999;
		q[hed] = x;
		num++;
	}
	void pop_back(){
		if (num == 0){
			cout << "deque is underflow!\n";
			exit(-1);
		}
		if (tal == 0) tal = 999999;
		else tal--;
		num--;
	}
	void pop_front(){
		if (num == 0){
			cout << "deque is underflow!\n";
			exit(-1);
		}
		if (hed + 1 == 1000000) hed = 0;
		else hed++;
		num--;
	}
	bool empty(){
		return num == 0;
	}
	int size(){
		return num;
	}
	int back(){
		return q[tal];
	}
	int front(){
		return q[hed];
	}
} q;
long long read(){
	long long re = 0, type = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') type = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		re = re * 10 + (c - '0');
		c = getchar();
	}
	return re * type;
}
long long s[200005];
int main(){
	cout.tie(0);
	int n = read();
	for (int i = 1; i <= n; i++){
		int x = read();
		s[i] = s[i+n] = s[i-1] + x;
	}
	for (int i = n+1; i <= 2*n; i++)
		s[i] += s[n];
	long long ans = 0;
	for (int i = 0; i <= 2*n; i++){
		while (!q.empty() && i - q.front() > n)
			q.pop_front();
		while (!q.empty() && s[q.back()] >= s[i])
			q.pop_back();
		q.push_back(i);
		// cout << maxq.size() << ' ' << minq.size() << endl;
		// cout << s[q.front()] <<endl;
		ans = max(ans, s[i] - s[q.front()]);
	}
	cout << ans << endl;
	return 0;
}

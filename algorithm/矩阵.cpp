#include <iostream>
#include <algorithm>
using namespace std;

class sq{
	int n, m;
	long long val[15][15];
	public:
		void input(int a, int b, int** s){
			n = a, m = b;
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= m; j++)
					val[i][j] = s[i][j];
		} 
		sq(int a = 0, int b = 0, int** s = NULL){
			input(a, b, s);
		}
		friend sq operator * (const sq a, const sq b){
			if (a.m != b.n) exit(21);
			sq c;
			for (int i = 1; i <= a.n; i++)
				for (int j = 1; j <= b.m; j++)
					for (int k = 1; k <= a.m; k++)
						c.val[i][j] += a.val[i][k] * b.val[k][j];
			return c;
		}
		void print(){
			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= m; j++)
					cout << val[i][j] << ' ';
				cout << '\n';
			}
		} 
};
int b[15][15];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	sq a = new sq(5, 5, b); 
	return 0;
}


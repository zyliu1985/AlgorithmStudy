#include <iostream>
using namespace std;

namespace Big{
	const int SIZE = 10005;
	struct num{
		int val[SIZE];
		friend bool operator > (const num x, const num y){
			if (x.val[0] != y.val[0]) return x.val[0] > y.val[0];
			for (int i = x.val[0]; i >= 1; i--)
				if (x.val[i] != y.val[i]) return x.val[i] > y.val[i];
			return false;
		}
		friend bool operator < (const num x, const num y){
			if (x.val[0] != y.val[0]) return x.val[0] < y.val[0];
			for (int i = x.val[0]; i >= 1; i--)
				if (x.val[i] != y.val[i]) return x.val[i] < y.val[i];
			return false;
		}
		friend bool operator >= (const num x, const num y){
			if (x.val[0] != y.val[0]) return x.val[0] > y.val[0];
			for (int i = x.val[0]; i >= 1; i--)
				if (x.val[i] != y.val[i]) return x.val[i] > y.val[i];
			return true;
		}
		friend bool operator <= (const num x, const num y){
			if (x.val[0] != y.val[0]) return x.val[0] < y.val[0];
			for (int i = x.val[0]; i >= 1; i--)
				if (x.val[i] != y.val[i]) return x.val[i] < y.val[i];
			return true;
		}
		friend bool operator == (const num x, const num y){
			if (x.val[0] != y.val[0]) return false;
			for (int i = x.val[0]; i >= 1; i--)
				if (x.val[i] != y.val[i]) return false;
			return true;
		}
		friend bool operator != (const num x, const num y){
			if (x.val[0] != y.val[0]) return true;
			for (int i = x.val[0]; i >= 1; i--)
				if (x.val[i] != y.val[i]) return true;
			return false;
		}
		void input(){
			string s;
			cin >> s;
			val[0] = s.size();
			for (int i = 0; i < val[0]; i++)
				val[val[0]-i] = s[i] - '0';
		}
		void output(){
			for (int i = val[0]; i >= 1; i--)
				cout << val[i];
		}
	};
}
int main(){
	Big::num a, b;
	a.input();
	b.input();
	cout << (a != b) << endl;
	return 0;
}
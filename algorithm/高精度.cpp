#include <iostream>
using namespace std;

namespace Big{
	const int SIZE = 10005;
	class num{
		bool __bigger(num x, num y, bool eq){
			if (x.val[0] != y.val[0]) return x.val[0] > y.val[0];
			for (int i = x.val[0]; i >= 1; i--)
				if (x.val[i] != y.val[i]) return x.val[i] > y.val[i];
			return eq;
		}
		bool __minner(num x, num y, bool eq){
			if (x.val[0] != y.val[0]) return x.val[0] < y.val[0];
			for (int i = x.val[0]; i >= 1; i--)
				if (x.val[i] != y.val[i]) return x.val[i] < y.val[i];
			return eq;
		}
		public:
			int val[SIZE];
			bool type;
			void input(){
				string s;
				cin >> s;
				if (s[0] == '-') type = 1;
				val[0] = s.size() - type;
				for (int i = 0; i < val[0]; i++)
					val[val[0]-i] = s[i+type] - '0';
			}
			void string_input(string s){
				if (s[0] == '-') type = 1;
				val[0] = s.size() - type;
				for (int i = 0; i < val[0]; i++)
					val[val[0]-i] = s[i+type] - '0';
			}
			void output(string ed = ""){
				if (val[0] == 0){
					cout << 0 << ed;
					return;
				}
				if (type) cout << '-';
				for (int i = val[0]; i >= 1; i--)
					cout << val[i];
				cout << ed;
			}
			void clear(){
				type = 0;
				for (int i = 1; i <= val[0]; i++)
					val[i] = 0;
				val[0] = 0;
			}
			friend bool operator > (const num x, const num y){
				if (x.type && y.type) return __minner(x, y, 0);
				if (x.type || y.type) return y.type;
				return __bigger(x, y, 0);
			}
			friend bool operator < (const num x, const num y){
				if (x.type && y.type) return __bigger(x, y, 0);
				if (x.type || y.type) return x.type;
				return __minner(x, y, 0);
			}
			friend bool operator >= (const num x, const num y){
				if (x.type && y.type) return __minner(x, y, 1);
				if (x.type || y.type) return y.type;
				return __bigger(x, y, 1);
			}
			friend bool operator <= (const num x, const num y){
				if (x.type && y.type) return __bigger(x, y, 1);
				if (x.type || y.type) return x.type;
				return __minner(x, y, 1);
			}
			friend bool operator == (const num x, const num y){
				if (x.type ^ y.type) return false;
				return eaq(x, y)
			}
			friend bool operator != (const num x, const num y){
				if (x.val[0] != y.val[0]) return true;
				for (int i = x.val[0]; i >= 1; i--)
					if (x.val[i] != y.val[i]) return true;
				return false;
			}
			friend num operator + (const num x, const num y){
				int len = max(x.val[0], y.val[0]);
				num ans;
				ans.val[len+1] = 0;
				ans.val[0] = len;
				for (int i = 1; i <= len; i++){
					if (i > x.val[0])
						ans.val[i] += y.val[i];
					else if (i > y.val[0])
						ans.val[i] += x.val[i];
					else
						ans.val[i] += x.val[i] + y.val[i];
					if (ans.val[i] >= 10){
						ans.val[i] -= 10;
						ans.val[i+1]++;
					}
				}
				if (ans.val[len+1]) ans.val[0]++;
				return ans;
			}
			friend num operator - (const num x, const num y){
				int len = max(x.val[0], y.val[0]);
				num ans;
				ans.val[len+1] = 0;
				ans.val[0] = len;
				for (int i = 1; i <= len; i++){
					if (i > x.val[0])
						ans.val[i] += y.val[i];
					else if (i > y.val[0])
						ans.val[i] += x.val[i];
					else
						ans.val[i] += x.val[i] + y.val[i];
					if (ans.val[i] >= 10){
						ans.val[i] -= 10;
						ans.val[i+1]++;
					}
				}
				if (ans.val[len+1]) ans.val[0]++;
				return ans;
			}
			num& operator = (const num&);
		};
	num& num::operator = (const num& x){
		for (int i = 0; i <= x.val[0]; i++)
			val[i] = x.val[i];
		return *this;
	}
}
int main(){
	Big::num a, b, c;
	a.input();
	a.output("\n");
	return 0;
}
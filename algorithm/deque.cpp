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
};
int main(){
	
	return 0;
}

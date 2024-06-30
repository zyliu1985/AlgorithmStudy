#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

void clear(){
	system("cls");
}
void zjs(){
	int t = time(0);
	int last = -1;
	while (true){
		int x = time(0) - t;
		if (x != last){
			clear();
			int h = x / 3600;
			int m = x % 3600 / 60;
			int s = x % 60;
			cout << "计时：" << h << ':' << m << ':' << s << endl;
			last = x;
		}
	}
}
void djs(int sum){
	int t = time(0);
	int last = -1;
	while (true){
		int x = sum - time(0) + t;
		if (x < 0) break;
		if (x != last){
			clear();
			int h = x / 3600;
			int m = x % 3600 / 60;
			int s = x % 60;
			cout << "倒计时还剩：" << h << ':' << m << ':' << s << endl;
			last = x;
		}
	}
	last = -1;
	t = time(0);
	while (true){
		int x = time(0) - t;
		if (x != last){
			clear();
			int h = x / 3600;
			int m = x % 3600 / 60;
			int s = x % 60; 
			cout << "时间到！" << endl;
			cout << "已超时：" << h << ':' << m << ':' << s << endl;
			last = x;
		}
	}
}
int main(){
	int dh, dm, ds;
	cout << "请输入倒计时时间（小时）：";
	cin >> dh;
	cout << "请输入倒计时时间（分）：";
	cin >> dm;
	cout << "请输入倒计时时间（秒）：";
	cin >> ds;
	int all = dh * 3600 + dm * 60 + ds;
	if (all == 0){
		zjs();
	} else {
		djs(all);
	}
	return 0;
}
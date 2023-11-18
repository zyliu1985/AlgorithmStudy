#include <iostream>
#include <conio.h>
using namespace std;

//int getch()
//{
//    struct termios nts, ots;
//    if (tcgetattr(0, &ots) < 0) return EOF;
//    nts = ots;
//    cfmakeraw(&nts); 
//    if (tcsetattr(0, TCSANOW, &nts) < 0) return EOF;
//    int cr;
//    cr = getchar();
//    if (tcsetattr(0, TCSANOW, &ots) < 0)  return EOF;
//    return cr;
//}

int main(){
	int a;
	while (true){
		a = getche();
		cout << a << endl;
		cout << "¡î" << a << endl;
	}
}
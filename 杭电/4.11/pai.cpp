#include <iostream>
#include <windows.h>
using namespace std;

int main(){
	while (1){
		system("Imakein.exe");
		system("I.exe");
		system("Ipai.exe");
		if (system("fc out.out force.out")){
			cout << "WA\n";
			return 0;
		} else {
			cout << "AC\n";
		}
	}
	return 0;
}




#include "mybmp.h"


using namespace std;

int main(){
	MyBMP f;
    char filename [20] ;
    cout << "Bmp file: " ; // force output
    cin >> filename;
	
	f.OpenBmp(filename);
    
	f.PrintHeader();
    f.PrintInfoHeader();
}


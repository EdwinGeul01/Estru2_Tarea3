#include <limits>
#include <stdio.h>
#include <stdint.h> 
#include <cstring>
#include "mybmp.h"

using namespace std;

void MyBMP::ReadHeader(){
	file_bmp.seekg(0, ios_base::beg);
	file_bmp.read((char *) &reg_header, sizeof(reg_header));
}	

void MyBMP::OpenBmp(const char * filename){
	file_name = (char *)filename;
	file_bmp.open(filename, ifstream::in|ifstream::binary);
	ReadHeader();
}

void BMP_HEADER::UnPack()
{

	file_bmp.seekg(0, ios_base::beg);
	file_bmp.read((char *) this, sizeof(BMP_HEADER));



}

void MyBMP::PrintHeader(){

	

	cout << "********************************************" << endl;
	cout << "Tipo: " << type << endl;
	cout << "Size: " << reg_header.SIZE << endl;
	cout << "Reservado 1: " << reg_header.RESERVED1 << endl;
	cout << "Reservado 2: " << reg_header.RESERVED2 << endl;
	cout << "Offset: " << reg_header.OFFSET << endl;
	cout << "size of " << sizeof(BMP_HEADER) << endl;
	cout << "********************************************" << endl;
	
}


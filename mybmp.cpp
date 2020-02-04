#include <limits>
#include <stdio.h>
#include <stdint.h> 
#include <cstring>
#include "mybmp.h"

using namespace std;

void MyBMP::ReadHeader(){
}	

void MyBMP::OpenBmp(const char * filename){
	file_name = (char *)filename;
	file_bmp.open(filename, ifstream::in|ifstream::binary);
	reg_header.UnPack(file_bmp);
	info_header.UnPack(file_bmp);
}

void BMP_HEADER::UnPack(ifstream &file_bmp)
{
	file_bmp.seekg(0, ios_base::beg);
	file_bmp.read((char *) this, sizeof(BMP_HEADER));

}

void BMP_INFO_HEADER::UnPack(ifstream &file_bmp)
{
	file_bmp.read((char *) this, sizeof(BMP_INFO_HEADER));

}

void MyBMP::PrintHeader(){
	char type[3];

	type[0] = reg_header.typeFile[0];
	type[1] = reg_header.typeFile[1];	

	cout << "*******************HEADER*******************" << endl;
	cout << "Tipo: " << type << endl;
	cout << "Size: " << reg_header.SIZE << endl;
	cout << "Reservado 1: " << reg_header.RESERVED1 << endl;
	cout << "Reservado 2: " << reg_header.RESERVED2 << endl;
	cout << "Offset: " << reg_header.OFFSET << endl;
	cout << "Size of : " << sizeof(BMP_HEADER) << endl;

	cout << "********************************************" << endl << endl;
	
}

void MyBMP::PrintInfoHeader()
{

	cout << "*******************INFO HEADER*******************" << endl;
	cout << "Tamaño de la cabecera del bitmap: " << info_header.Size << endl;
	cout << "Anchura: " << info_header.width << endl;
	cout << "Altura: " << info_header.height << endl;
	cout << "Número de planos: " << info_header.planes << endl;
	cout << "Tamaño de cada punto: " << info_header.bitsxPix << endl;
	cout << "Compresión: " << info_header.Compression << endl;
	cout << "Tamaño de la imagen: " << info_header.SizeImage << endl;
	cout << "Resolución horizontal: " << info_header.bitXPelsPerMeter << endl;
	cout << "Resolución vertical: " << info_header.bitYPelsPerMeter << endl;
	cout << "Tamaño de la tabla de color: " << info_header.ClrUsed << endl;
	cout << "Contador de Colores Importantes: " << info_header.ClrImportant << endl;

	cout << "********************************************" << endl;
	

}
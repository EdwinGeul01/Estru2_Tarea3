#include <iostream>
#include <fstream>
#include <inttypes.h>

using namespace std;

#pragma pack(push, 1)
class BMP_HEADER{
	public :
	
    char type[2];
    uint32_t SIZE;
	uint16_t RESERVED1;
	uint16_t RESERVED2;
    uint32_t OFFSET;



};
#pragma pack(pop)

class MyBMP{
	private:
		private:
		char *file_name;
		ifstream file_bmp;
		BMP_HEADER reg_header;
		void ReadHeader();

	public:
		void OpenBmp(const char * filename);		
		void PrintHeader();
 		void UnPack();

};
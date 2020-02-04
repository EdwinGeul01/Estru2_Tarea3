#include <iostream>
#include <fstream>
#include <inttypes.h>

using namespace std;

#pragma pack(push, 1)
class BMP_HEADER{
	public :
    char typeFile[2];
    uint32_t SIZE;
	uint16_t RESERVED1;
	uint16_t RESERVED2;
    uint32_t OFFSET;

	void UnPack(ifstream &file_bmp);


};

#pragma pack(pop)

#pragma pack(push, 1)

class BMP_INFO_HEADER{
	public :
		 u_int32_t      Size;      
         u_int32_t      width;        
         u_int32_t      height;           
         u_int16_t		planes;        
         u_int16_t		bitsxPix;        
         u_int32_t	    Compression;        
         u_int32_t      SizeImage;       
         u_int32_t      bitXPelsPerMeter; 
         u_int32_t      bitYPelsPerMeter;       
         u_int32_t	    ClrUsed;        
         u_int32_t	    ClrImportant;

	void UnPack(ifstream &file_bmp);


};

#pragma pack(pop)



class MyBMP{
	private:
		private:
		char *file_name;
		ifstream file_bmp;
		BMP_HEADER reg_header;
		BMP_INFO_HEADER info_header;
		void ReadHeader();

	public:
		void OpenBmp(const char * filename);		
		void PrintHeader();
		void PrintInfoHeader();

};
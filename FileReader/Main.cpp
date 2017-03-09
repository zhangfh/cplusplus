#include <iostream>
#include "FileReader.hpp"

#define srs_freepa(pa) \
    if (pa) { \
        delete[] pa; \
        pa = NULL; \
    } \
    (void)0



int main()
{
	
        int ret = 0;
        
        FileReader reader;
        
        // open file reader.
        if ((ret = reader.open("config.txt")) != 0) {
            std::cout<<"open conf file error. ret="<<ret<<std::endl;
            return ret;
        }
        int filesize = (int)reader.filesize();
	char* start;
	start = new char[filesize];
        // read total content from file.
        ssize_t nread = 0;
        if ((ret = reader.read(start, filesize, &nread)) != 0) {
            std::cout<<"read  file read error. expect " << filesize<<" actual "<<nread<< " bytes. ret="<<ret<<std::endl;
            return ret;
        }
        
	srs_freepa(start);	
	return 0;
}

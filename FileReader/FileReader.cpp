
#include <unistd.h>
#include <sys/uio.h>
#include "FileReader.hpp"
#include <iostream>

using namespace std;
FileReader::FileReader()
{
	fd = -1;
}

FileReader::~FileReader()
{
	close();
}

int FileReader::open(std::string p)
{
    int ret = 0;
    
    if (fd > 0) {
        ret = 1041;//ERROR_SYSTEM_FILE_ALREADY_OPENED
	std::cout<<"file "<<path.c_str()<<" already opend, ret= " << ret <<std::endl;
        return ret;
    }
    if ((fd = ::open(p.c_str(), O_RDONLY)) < 0) {
        ret = 1042; //ERROR_SYSTEM_FILE_OPENE;
	std::cout<<"open file "<<p.c_str()<<"ret= " << ret <<std::endl;
        return ret;
    }
    path = p;
    return ret;
}

void FileReader::close()
{
    int ret = 0;
    
    if (fd < 0) {
        return;
    }
    
    if (::close(fd) < 0) {
        ret = 1043; //ERROR_SYSTEM_FILE_CLOSE
	std::cout<<"close file "<<path.c_str()<<"ret= " << ret <<std::endl;
        return;
    }
    fd = -1;
    
    return;
}


bool FileReader::is_open()
{
    return fd > 0;
}

int64_t FileReader::tellg()
{
    return (int64_t)::lseek(fd, 0, SEEK_CUR);
}

void FileReader::skip(int64_t size)
{
    ::lseek(fd, (off_t)size, SEEK_CUR);
}

int64_t FileReader::lseek(int64_t offset)
{
    return (int64_t)::lseek(fd, (off_t)offset, SEEK_SET);
}

int64_t FileReader::filesize()
{
    int64_t cur = tellg();
    int64_t size = (int64_t)::lseek(fd, 0, SEEK_END);
    ::lseek(fd, (off_t)cur, SEEK_SET);
    return size;
}


int FileReader::read(char* buf, size_t count, ssize_t* pnread)
{
    int ret = 0;
    
    ssize_t nread;
    if ((nread = ::read(fd, buf, count)) < 0) {
        ret = 1044;//ERROR_SYSTEM_FILE_READ;
	std::cout<<"read from file "<<path.c_str()<<" failed. ret= " << ret <<std::endl;
        return ret;
    }
    
    if (nread == 0) {
        ret = 1046;//ERROR_SYSTEM_FILE_EOF;
        return ret;
    }
    
    if (pnread != NULL) {
        *pnread = nread;
    }
    
    return ret;
}


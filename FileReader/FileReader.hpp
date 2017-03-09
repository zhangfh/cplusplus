#ifndef FILE_READER_h
#define FILE_READER_h

#include <string>
#include <fcntl.h>

class FileReader{

public:
	FileReader();
	virtual ~FileReader();
public:
	virtual int open(std::string p);
	virtual void close();

public:
	virtual bool is_open();
	virtual int64_t tellg();
	virtual void skip(int64_t size);
	virtual int64_t lseek(int64_t offset);
	virtual int64_t filesize();
public:
    	virtual int read(char* buf, size_t count, ssize_t* pnread);
private:
	int fd;
	std::string path;
};


#endif

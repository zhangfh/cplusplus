#ifndef _VECTOR_CLASS_H
#define _VECTOR_CLASS_H

#include <vector>
#include <string>

class VectorClass {

	public:
		VectorClass();
		~VectorClass();
		void push(std::string);
		void list();
	private:
		std::vector<std::string> stringvectors;
};
#endif

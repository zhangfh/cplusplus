#include "VectorClass.hpp"
#include <iostream>


       VectorClass::VectorClass()
       {
       }

	
       VectorClass::~VectorClass()
       {
		stringvectors.clear();
       }
       void VectorClass::push(std::string element)
       {
		stringvectors.push_back(element);
       }

       void VectorClass::list()
       {
    		std::vector<std::string>::iterator it;
    		for (it = stringvectors.begin(); it != stringvectors.end(); ++it) {
        		std::string newstring = *it;
        		std::cout<<"contents "<< newstring.c_str()<<std::endl;
    		}
       }


#include <iostream>
#include "VectorClass.hpp"

int main()
{
	VectorClass vc;
	vc.push("this is first line");
	vc.push("this is second line");
	vc.list();
	return 0;
}

#include <iostream>
#include <version.h>
#include <BuildNumber.h>

using namespace MyHomework;

	int main()
	{

	  BuildNumber bn(HomeWorkMajorNumber, HomeWorkMinorNumber, HomeWorkBuildNumber, BuildTime);

	  std::cout << "Build Number: " << bn;
	  std::cout << "Hello, OTUS-World!" << std::endl;


	  return 0;
	}



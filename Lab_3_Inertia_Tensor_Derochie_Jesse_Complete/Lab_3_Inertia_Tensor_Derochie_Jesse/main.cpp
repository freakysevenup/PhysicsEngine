#include <cstdio>
#include "Simulator.h"

int main()
{
	Simulator PROGRAM;
	PROGRAM.Run_InertiaTensor_Test();

	std::printf ("Press any Key to exit...");
	std::getchar();
	return 0;
}
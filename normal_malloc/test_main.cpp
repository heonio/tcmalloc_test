#include <iostream>
#include <sstream>
#include <cstdio>
#include <time.h>
#include <stdio.h>
#include <boost/chrono.hpp>

void testMAlloc()
{
	int i = 0;
	const int ARRAY_SIZE = 100000;
	int* ar_pi[ARRAY_SIZE] = {nullptr,};

	std::cout << "[== normal malloc ==]\n";

	boost::chrono::steady_clock::time_point start = boost::chrono::steady_clock::now();

	for (i=0; i<ARRAY_SIZE; ++i)
	{
		ar_pi[i] = new int[0x1000];
		ar_pi[i][0] = 0x124f;
	}

	for (i=0; i<ARRAY_SIZE; ++i)
	{
		delete [] ar_pi[i];
		ar_pi[i] = nullptr;
	}

	boost::chrono::milliseconds millisec = boost::chrono::duration_cast<boost::chrono::milliseconds>(boost::chrono::steady_clock::now() - start);

	std::cout << "elapsed : " << millisec.count() << "ms\n";
}

int main()
{
	testMAlloc();

	std::cout << "Press Enter to Quit\n";
#ifdef _DEBUG
	std::cin.ignore();
#endif
	return 0;
}

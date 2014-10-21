//============================================================================
// Name        : DBBenchmark.cpp
// Author      : Chris
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ExecutionManager.h"
#include <unistd.h>
using namespace std;

int main() {
	char buf[32];
	gethostname(buf,sizeof buf);
	std::cout << buf;
	DBBenchmark::ExecutionManager manager = DBBenchmark::ExecutionManager();
	manager.start();
	system("./update.sh");
	return 0;
}

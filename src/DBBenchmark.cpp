//============================================================================
// Name        : DBBenchmark.cpp
// Author      : Chris
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ExecutionManager.h"
using namespace std;

int main() {
	system("./update.sh");
	DBBenchmark::ExecutionManager manager = DBBenchmark::ExecutionManager();
	manager.start();

	return 0;
}

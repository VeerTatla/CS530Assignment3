#ifndef PARSER__
#define PARSER__

#include <iostream>
#include <fstream>
#include "Grammar.h"

using namespace std;

class Parser {

public:
	void examineFile();
	void runFile();
	

private:
	vector<string> selectValue(vector<string> token);
	vector<string> fileContent;

};

#endif

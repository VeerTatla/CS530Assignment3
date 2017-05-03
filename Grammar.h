#ifndef GRAMMAR__
#define GRAMMAR__

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <string.h>

using namespace std;

class Grammar {

public:
	bool grammarID (string token);
	vector<string> grammarAssg (vector<string> token);
	vector<string> grammarExp (vector<string> token);
	

private:
	static bool grammarChar (char character);
	static bool grammarNumber (char digit);
	static bool grammarOperators (char operators);


};

#endif

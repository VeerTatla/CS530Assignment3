#include "Parser.h"
#define MAX 256

//This section opens the file "in.txt" automatically and reads it. 

void Parser::examineFile() {
	
	string line;
	char *fileName = new char[MAX]();
	
	
	ifstream inputFile("in.txt");
	if (inputFile.is_open()) {
		while (inputFile.good()) {
			getline(inputFile,line);
			fileContent.push_back(line);
		}
		inputFile.close();
		Parser::runFile();
	
	}
}

//This section here opens out.txt and writes the resulting parsing results of in.txt

void Parser::runFile() {

	char *outFile = new char[MAX]();
	strcat(outFile, "out.txt");
	ofstream outfile(outFile);
	FILE *outFileName = fopen(outFile, "wb");
	
	bool pass = true;
	
	
    for(int j = 0; j < fileContent.size(); j++) {
        
        if(!fileContent[j].empty()) {
            
            vector<string> token;
            istringstream f(fileContent[j]);
            string s;
            while (getline(f, s, ' ')) {
                token.push_back(s);
            }
            
            
            vector<string> temp = selectValue(token);
            fprintf(outFileName, "%3d: %-60s  %-20s %-20s \n", j, fileContent[j].c_str(), temp[0].c_str(), temp[1].c_str());
            
            
            if (temp[0].length() > 16) {
                pass = false;
            }
        }
        else{
	        fprintf(outFileName, "%3d: \n", j);
        }
    }
    fprintf(outFileName,"\n File Validation: %s", pass ? "Pass":"Fail");
    printf("Parsing complete! Check file out.txt for results!! \n");
    outfile.close();



}



// This section looks to make sure the appropriate grammar 
//is selected for each instruction.

vector<string> Parser::selectValue(vector<string> token) {
    vector<string> result(2), temp(2);
    stringstream ss;
    Grammar *grammar = new Grammar;
    for (int j = 0; j < token.size(); j++) {
        
        if (token[j] == "=") {
            temp = grammar->grammarAssg(token);
            if (temp[0] == "1"){
                result[0] = "Valid Assignment.";
                result[1] = " ";
                return result;
            }
            result[0] = "Invalid Assignment.";
            result[1] = temp[1];
            return result;
        }
    }
    temp = grammar->grammarExp(token);
    if (temp[0] == "1") {
        result[0] = "Valid Expression.";
        result[1] = " ";
        return result;
    }
    result[0] = "Invalid Expression.";
    result[1] = temp[1];
    return result;
}

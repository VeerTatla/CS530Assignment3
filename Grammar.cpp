#include "Grammar.h"

//Grammar for digit. 

struct charDigit {

	char charDigit;

};

const struct charDigit charDigitTable[] = {

	{ '0' }, { '1' }, { '2' }, { '3' }, { '4' }, 
	{ '5' }, { '6' }, { '7' }, { '8' }, { '9' },
	
};

bool Grammar::grammarNumber (char digit) {

	for(int j = 0; j < 10; j++){
	
		if(charDigitTable[j].charDigit == digit)
			return true;
	
	}
	
	return false;
}

//Grammar for operators.

struct operators {
    char charOperators;
};

const struct operators charOperatorsTable [] = {

    { '+' }, { '-' }, { '*' }, { '/' }, { '%' },
    
};

bool Grammar::grammarOperators (char operators){

	for(int j = 0; j < 5; j++){
	
		if(charOperatorsTable[j].charOperators == operators)
			return true;
	
	}
	
	return false;


}

//Grammar for charcters from a-Z.

struct characters {
    char character_aToZ;
};

const struct characters characterTable [] = {
    { 'a' },   { 'b' },    { 'c' },    { 'd' },
    { 'e' },   { 'f' },    { 'g' },    { 'h' },
    { 'i' },   { 'j' },    { 'k' },    { 'l' },
    { 'm' },   { 'n' },    { 'o' },    { 'p' },
    { 'q' },   { 'r' },    { 's' },    { 't' },
    { 'u' },   { 'v' },    { 'w' },    { 'x' },
    { 'y' },   { 'z' },    { 'A' },    { 'B' },
    { 'C' },   { 'D' },    { 'E' },    { 'F' },
    { 'G' },   { 'H' },    { 'I' },    { 'J' },
    { 'K' },   { 'L' },    { 'M' },    { 'N' },
    { 'O' },   { 'P' },    { 'Q' },    { 'R' },
    { 'S' },   { 'T' },    { 'U' },    { 'V' },
    { 'W' },   { 'X' },    { 'Y' },    { 'Z' },
    { '_' },   { '(' },    { ')' },
};

bool Grammar::grammarChar(char character) {
    for(int j = 0; j < 55; j++) {
        if(characterTable[j].character_aToZ == character)
            return true;
    }
    return false;
}

//Grammar checked for ID.

bool Grammar::grammarID(string token){

	if(grammarChar(token[0])) {
	
		for(int j = 0; j < token.length(); j++) {
		
			if(grammarChar(token[j]))
				continue;
			else if(grammarNumber(token[j]))
				continue;
			else {
				return false;
			}
		
		}
		return true;
	
	}
	return false;
}

// Grammar check for <assignment>

vector<string> Grammar::grammarAssg(vector<string> token) {

	vector<string> result(2);
	stringstream ss;
	Grammar *grammar = new Grammar();
	
	if (grammar->grammarID(token[0])) {
		if (token[1] == "=") {
			if (token[token.size() - 1][0] == ';') {
				vector<string> restOfWord;
				for(int j = 2; j < token.size()-1; j++) {
				
					restOfWord.push_back(token[j]);
				}
				return grammarExp(restOfWord);
			
			}
			result[0] = "0";
			ss << "\"" << token[token.size() - 1] << "\" is missing a semi colon!";
			result[1] = ss.str();
			return result;
		
		}
		result[0] = "0";
        	ss << "\"" << token[1] << "\" is missing an equal sign!";
        	result[1] = ss.str();
        	return result;
	
	}
	 result[0] = "0";
    	 ss << "\"" << token[0] << "\" is not a valid ID!";
   	 result[1] = ss.str();
   	 return result;

}

//Grammar for <expression>.

vector<string> Grammar::grammarExp(vector<string> token){
    vector<string> result(2);
    stringstream ss;
    Grammar *grammar = new Grammar();
    
    if (token[0] != " " && grammar->grammarID(token[0])) {
        
        if (token[1].length() == 1 && grammar->grammarOperators(token[1][0])) {
            
            if (grammar->grammarID(token[token.size()-1])) {
                for (int j = 2; j < token.size()-1; j++) {
                    if (!(grammar->grammarID(token[j]))) {
                        result[0] = "0";
                        ss << "\"" << token[j] << "\" is not a valid ID!";
                        result[1] = ss.str();
                        return result;
                    }
                    j = j + 1;
                    if (!(grammar->grammarOperators(token[j][0]))) {
                        result[0] = "0";
                        ss << "\"" << token[j] << "\" is not a valid Operator!";
                        result[1] = ss.str();
                        return result;
                    }
                }
                result[0] = "1";
                result[1] = " ";
                return result;
            }
            result[0] = "0";
            ss << "\"" << token[token.size()-1] << "\" is not a valid ID!";
            result[1] = ss.str();
            return result;
        }
        result[0] = "0";
        ss << "\"" << token[1] << "\" is not a valid Operator1";
        result[1] = ss.str();
        return result;
    }
    result[0] = "0";
    ss << "\"" << token[0] << "\" is not a valid ID.";
    result[1] = ss.str();
    return result;
}








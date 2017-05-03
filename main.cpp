#include <iostream>
#include "Parser.h"
#include "Grammar.h"

int main(int argc, const char * argv[])
{
    Parser *test = new Parser;
    test -> examineFile();
    return 0;
}

# CS530Assignment3
Veerparatap Tatla masc0847 RedId: 818212298

Grammar: 
<assignment>    ::= ID = <expression> ;
<expression>    ::= <ID> <operators> <ID> {<operators> <ID>}
<ID>    	      ::= <char>|<ID><char>|<ID><digit>
<char>          ::= a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z|A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z
<digit> 	      ::= 0|1|2|3|4|5|6|7|8|9
<operators> 		::= +|-|*|/|%

To run: 
1.) Make sure you have a file named in.txt that you would like to test and have a blank out.txt for results.
2.) On the command line type 'make' to compile it
3.) Run the program by typing './parser'
4.) Open out.txt file to view results.

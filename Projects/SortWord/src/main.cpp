#include "commandparser.h"
#include "wordsorter.h"
#include <iostream>

static const char* help = "\
Sort alphabetically a list of words\n \
SortWord [options] <word_list>\n \
\n \
Options:\n \
-R or -r: recursive order\n \
-U or -u: unique (without duplicate)\
";

int main(int argc, char* argv[])
{
	CommandParser cmdParser(argc, argv);
	try
	{
		cmdParser.parse();

		std::cout << WordSorter(cmdParser.getWords(), cmdParser.isReverse(), cmdParser.isUnique());
	}
	catch (const CommandParserEx& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << help << std::endl;
	}

	return 0;
}

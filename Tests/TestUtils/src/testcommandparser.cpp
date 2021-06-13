// tests for the class CommandParser

#include "commandparser.h"
#include "gtest/gtest.h"

class TestCommandParser : public ::testing::Test {};

TEST_F(TestCommandParser, parse_ok)
{
	// words
	{
		char* argv[] = { "myProg", "one", "two" };
		const int argc = sizeof(argv) / sizeof(argv[0]);
		const CommandParser::Words expectedWords = { "one", "two" };

		CommandParser cmdParser(argc, argv);
		ASSERT_NO_THROW(cmdParser.parse());
		ASSERT_FALSE(cmdParser.isReverse());
		ASSERT_FALSE(cmdParser.isUnique());
		ASSERT_EQ(expectedWords, cmdParser.getWords());
	}

	// Reverse words
	{
		char* argv[] = { "myProg", "-r", "one", "two" };
		const int argc = sizeof(argv) / sizeof(argv[0]);
		const CommandParser::Words expectedWords = { "one", "two" };

		CommandParser cmdParser(argc, argv);
		ASSERT_NO_THROW(cmdParser.parse());
		ASSERT_TRUE(cmdParser.isReverse());
		ASSERT_FALSE(cmdParser.isUnique());
		ASSERT_EQ(expectedWords, cmdParser.getWords());
	}

	// Unique words
	{
		char* argv[] = { "myProg", "-u", "one", "two" };
		const int argc = sizeof(argv) / sizeof(argv[0]);
		const CommandParser::Words expectedWords = { "one", "two" };

		CommandParser cmdParser(argc, argv);
		ASSERT_NO_THROW(cmdParser.parse());
		ASSERT_FALSE(cmdParser.isReverse());
		ASSERT_TRUE(cmdParser.isUnique());
		ASSERT_EQ(expectedWords, cmdParser.getWords());
	}

	// Reverse + unique + words
	{
		char* argv[] = { "myProg", "-u", "-r", "one", "two" };
		const int argc = sizeof(argv) / sizeof(argv[0]);
		const CommandParser::Words expectedWords = { "one", "two" };

		CommandParser cmdParser(argc, argv);
		ASSERT_NO_THROW(cmdParser.parse());
		ASSERT_TRUE(cmdParser.isReverse());
		ASSERT_TRUE(cmdParser.isUnique());
		ASSERT_EQ(expectedWords, cmdParser.getWords());
	}
}
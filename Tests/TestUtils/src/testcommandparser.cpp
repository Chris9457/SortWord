// tests for the class CommandParser

#include "commandparser.h"
#include "gtest/gtest.h"

class TestCommandParser : public ::testing::Test {};

TEST_F(TestCommandParser, parse_words)
{
	char* argv[] = { "myProg", "one", "two" };
	const int argc = sizeof(argv) / sizeof(argv[0]);
	const Words expectedWords = { "one", "two" };

	CommandParser cmdParser(argc, argv);
	ASSERT_NO_THROW(cmdParser.parse());
	ASSERT_FALSE(cmdParser.isReverse());
	ASSERT_FALSE(cmdParser.isUnique());
	ASSERT_EQ(expectedWords, cmdParser.getWords());
}

TEST_F(TestCommandParser, parse_reverse_words)
{
	char* argv[] = { "myProg", "-r", "one", "two" };
	const int argc = sizeof(argv) / sizeof(argv[0]);
	const Words expectedWords = { "one", "two" };

	CommandParser cmdParser(argc, argv);
	ASSERT_NO_THROW(cmdParser.parse());
	ASSERT_TRUE(cmdParser.isReverse());
	ASSERT_FALSE(cmdParser.isUnique());
	ASSERT_EQ(expectedWords, cmdParser.getWords());
}

TEST_F(TestCommandParser, parse_unqiue_words)
{
	char* argv[] = { "myProg", "-u", "one", "two" };
	const int argc = sizeof(argv) / sizeof(argv[0]);
	const Words expectedWords = { "one", "two" };

	CommandParser cmdParser(argc, argv);
	ASSERT_NO_THROW(cmdParser.parse());
	ASSERT_FALSE(cmdParser.isReverse());
	ASSERT_TRUE(cmdParser.isUnique());
	ASSERT_EQ(expectedWords, cmdParser.getWords());
}

TEST_F(TestCommandParser, parse_unqiue_reverse_words)
{	
	// Reverse + unique + words
	{
		char* argv[] = { "myProg", "-r", "-u", "one", "two" };
		const int argc = sizeof(argv) / sizeof(argv[0]);
		const Words expectedWords = { "one", "two" };

		CommandParser cmdParser(argc, argv);
		ASSERT_NO_THROW(cmdParser.parse());
		ASSERT_TRUE(cmdParser.isReverse());
		ASSERT_TRUE(cmdParser.isUnique());
		ASSERT_EQ(expectedWords, cmdParser.getWords());
	}

	// unique + reverse + words
	{
		char* argv[] = { "myProg", "-u", "-r", "one", "two" };
		const int argc = sizeof(argv) / sizeof(argv[0]);
		const Words expectedWords = { "one", "two" };

		CommandParser cmdParser(argc, argv);
		ASSERT_NO_THROW(cmdParser.parse());
		ASSERT_TRUE(cmdParser.isReverse());
		ASSERT_TRUE(cmdParser.isUnique());
		ASSERT_EQ(expectedWords, cmdParser.getWords());
	}
}

TEST_F(TestCommandParser, parse_ko_multiple_flag)
{
	{
		char* argv[] = { "myProg", "-u", "-u", "one", "two" };
		const int argc = sizeof(argv) / sizeof(argv[0]);
		const Words expectedWords = { "one", "two" };

		CommandParser cmdParser(argc, argv);
		ASSERT_THROW(cmdParser.parse(), CommandParserEx);
	}

	{
		char* argv[] = { "myProg", "-r", "-r", "one", "two" };
		const int argc = sizeof(argv) / sizeof(argv[0]);
		const Words expectedWords = { "one", "two" };

		CommandParser cmdParser(argc, argv);
		ASSERT_THROW(cmdParser.parse(), CommandParserEx);
	}
}
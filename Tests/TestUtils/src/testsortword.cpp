// tests for the class WordSorter

#include "wordsorter.h"
#include "gtest/gtest.h"

class TestWordSorter: public ::testing::Test {};

static const Words inWords = { "one", "two", "three", "one" };

TEST_F(TestWordSorter, ctor)
{
	const Words expectedSortedWords = { "one", "one", "three", "two" };
	WordSorter ws(inWords, false, false);

	ASSERT_EQ(expectedSortedWords, ws.getWords());
}

TEST_F(TestWordSorter, ctor_reverse)
{
	const Words expectedSortedWords = { "two", "three", "one", "one" };
	WordSorter ws(inWords, true, false);

	ASSERT_EQ(expectedSortedWords, ws.getWords());
}

TEST_F(TestWordSorter, ctor_unique)
{
	const Words expectedSortedWords = { "one", "three", "two" };
	WordSorter ws(inWords, false, true);

	ASSERT_EQ(expectedSortedWords, ws.getWords());
}

TEST_F(TestWordSorter, ctor_reverse_unique)
{
	const Words expectedSortedWords = { "two", "three", "one" };
	WordSorter ws(inWords, true, true);

	ASSERT_EQ(expectedSortedWords, ws.getWords());
}

TEST_F(TestWordSorter, stream_operator)
{
	const std::string expectedStrSortedWords = "one\none\nthree\ntwo\n";
	std::ostringstream oss;
	oss << WordSorter(inWords, false, false);
	ASSERT_EQ(expectedStrSortedWords, oss.str());
}
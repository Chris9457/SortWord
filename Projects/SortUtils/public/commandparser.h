// Declaration of the class CommandParser

#pragma once

#include <words.h>
#include <stdexcept>
#include <string>
#include <deque>

class CommandParserEx : public std::logic_error
{
public:
	explicit CommandParserEx(const std::string& strErr);
};

class CommandParser
{
public:
	explicit CommandParser(int argc, char* argv[]) noexcept;
	void parse();

	bool isReverse() const noexcept;
	bool isUnique() const noexcept;

	const Words& getWords() const noexcept;

private:
	Words m_words;
	bool m_bReverse = false;
	bool m_bUnique = false;
};
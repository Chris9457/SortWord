// Implementation of the class CommandParser
 
#include "commandparser.h"


// Class CommandParserEx
CommandParserEx::CommandParserEx(const std::string& strErr)
	: std::logic_error(strErr)
{}

// Class CommandParser
CommandParser::CommandParser(int argc, char* argv[]) noexcept
{
	if (argc <= 1)
		return;

	for (int index = 1; index < argc; ++index)
	{
		m_words.push_back(argv[index]);
	}
}

void CommandParser::parse()
{
	static const char strFlagPrefix = '-';
	static const std::string strReverseUpper = "R";
	static const std::string strReverseLower = "r";
	static const std::string strUniqueUpper = "U";
	static const std::string strUniqueLower = "u";

	bool bFlagPresent = true;
	while (bFlagPresent && !m_words.empty())
	{
		const std::string word = m_words.front();
		if (word.empty())
		{
			continue;
		}

		bFlagPresent = word[0] == strFlagPrefix;
		if (bFlagPresent)
		{
			const std::string flag = word.substr(1);
			const bool bReverse = flag == strReverseLower || flag == strReverseUpper;
			const bool bUnique = flag == strUniqueUpper || flag == strUniqueLower;
			if (!bReverse && !bUnique ||
				bReverse && m_bReverse ||
				bUnique && m_bUnique)
				throw CommandParserEx("Bad flags!");

			m_bReverse |= bReverse;
			m_bUnique |= bUnique;
			m_words.pop_front();
		}
	}

	if (m_words.empty())
	{
		throw CommandParserEx("Empty word list!");
	}
}

bool CommandParser::isReverse() const noexcept
{
	return m_bReverse;
}

bool CommandParser::isUnique() const noexcept
{
	return m_bUnique;
}

const Words& CommandParser::getWords() const noexcept
{
	return m_words;
}

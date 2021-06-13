// implementation of the class WordSorter

#include "wordsorter.h"
#include <algorithm>
#include <functional>

WordSorter::WordSorter(const Words& words, const bool bReverse, const bool bUnique) noexcept
	: m_words(words)
{
	if (bReverse)
	{
		std::sort(m_words.begin(), m_words.end(), [](auto const& lhs, auto const& rhs) { return !std::less_equal<std::string>()(lhs, rhs); });
	}
	else
	{
		std::sort(m_words.begin(), m_words.end(), std::less<std::string>());
	}

	if (bUnique)
	{
		m_words.erase(std::unique(m_words.begin(), m_words.end()), m_words.end());
	}
}


const Words& WordSorter::getWords() const noexcept
{
	return m_words;
}


// stream operator
std::ostream& operator <<(std::ostream& stream, const WordSorter& wordSorter)
{
	for (auto&& word : wordSorter.getWords())
	{
		stream << word.c_str() << std::endl;
	}

	return stream;
}

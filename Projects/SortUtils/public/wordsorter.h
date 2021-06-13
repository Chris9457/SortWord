// Declaration of the class WordSorter

#pragma once

#include "words.h"
#include <ostream>

class WordSorter
{
public:
	explicit WordSorter(const Words& words, const bool bReverse, const bool bUnique) noexcept;

	const Words& getWords() const noexcept;
private:
	Words m_words;
};

std::ostream& operator <<(std::ostream& stream, const WordSorter& wordSorter);

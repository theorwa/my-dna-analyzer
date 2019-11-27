#ifndef _Nucleotide_
#define _Nucleotide_

#include <iostream>
#include <map>
#include "NucleotideException.h"

typedef std::map<char, char> tMapPairs;

class Nucleotide{
public:
	Nucleotide(const char);
	bool operator==(const Nucleotide&);
	bool operator!=(const Nucleotide&);
	Nucleotide& operator=(const char);
	const char& getChar() const;
	const char& getPair() const;
	friend std::ostream& operator<< (std::ostream& os, const Nucleotide& nuc);
private:
	char m_char;
	static tMapPairs s_mapPaires;
	static tMapPairs init_map();
};

inline const char& Nucleotide::getChar() const { return m_char; }
inline const char& Nucleotide::getPair() const { return s_mapPaires[m_char]; }

#endif
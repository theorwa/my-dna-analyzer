#include "Nucleotide.h"

tMapPairs Nucleotide::s_mapPaires = init_map();

tMapPairs Nucleotide::init_map(){
	tMapPairs some_map;
	some_map['A'] = 'T';
	some_map['T'] = 'A';
	some_map['C'] = 'G';
	some_map['G'] = 'C';
	return some_map;
}

std::ostream& operator<<(std::ostream& os, const Nucleotide& nuc){
	os.put(nuc.m_char);
	return os;
}

Nucleotide::Nucleotide(const char letter) {
	if ( s_mapPaires.find(letter) == s_mapPaires.end() )
		throw NucleotideException("Nucleotide character not legal!");
	m_char = letter;
}

bool Nucleotide::operator==(const Nucleotide& other){
	if (m_char == other.m_char) return true;
	return false;
}

bool Nucleotide::operator!=(const Nucleotide& other){
	if (m_char != other.m_char) return true;
		return false;
}

Nucleotide& Nucleotide::operator=(const char letter){
	if (s_mapPaires.find(letter) == s_mapPaires.end())
		throw NucleotideException("Nucleotide character not legal!");
	m_char = letter;
	return *this;
}
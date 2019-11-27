#ifndef _DnaSequence_
#define _DnaSequence_

#include <iostream>
#include "Nucleotide.h"
#include <vector>


// typedef size_t NucleotideFunc* (char);

class DnaSequence{
public:
	DnaSequence(const std::string);
	DnaSequence(const char*);
	DnaSequence(const DnaSequence&);
	virtual ~DnaSequence();

	virtual bool operator==(const DnaSequence&);
	virtual bool operator!=(const DnaSequence&);
	virtual DnaSequence& operator=(const DnaSequence&);
	virtual DnaSequence& operator=(const char*);
	virtual DnaSequence& operator=(const std::string&);
	virtual Nucleotide& operator[] (unsigned int index);
	virtual const Nucleotide& operator[] (unsigned int index) const;

	virtual size_t getLength();
	virtual Nucleotide* getSeq() const;
	virtual std::string getDnaString() const;

    virtual const DnaSequence slice(unsigned int start, unsigned int end) const;
    const char* getPaired() const;
    virtual int find(const DnaSequence&) const;
    virtual size_t count(const DnaSequence&) const;
    // virtual std::vector<size_t> findAll(const DnaSequence&) const;
    // virtual std::vector<size_t> findConsensus() const;

	friend std::ostream& operator<< (std::ostream&, const DnaSequence&);
protected:
	Nucleotide* m_seq;
	size_t m_length;
	void setNucleotide(const char* str);
};

inline DnaSequence::~DnaSequence() {}
inline size_t DnaSequence::getLength() { return m_length; }
inline Nucleotide* DnaSequence::getSeq() const { return m_seq; }

#endif
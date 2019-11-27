#ifndef _NucleotideException_
#define _NucleotideException_

#include <exception>

class NucleotideException : public std::exception {
public:
	NucleotideException(const char*);
	const char * getMessage();
private:
	const char *m_msg;
};

inline NucleotideException::NucleotideException(const char *msg) : m_msg(msg) {}
inline const char * NucleotideException::getMessage() { return m_msg; }

#endif
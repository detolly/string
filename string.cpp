#include "string.h"
#include <cstdlib>
#include <cstring>

namespace detolly {
namespace string {
	
/*
inline int strlen(const char* chars) {
	int i = 0;
	while(1) {
		if (chars[i] == '\0')
			return i;
		i++;
	}
}
*/


string::string()
	: m_buffer(nullptr) 
{
	m_buffer = new char[m_bufferSize];
	m_length = 0;
	memset(m_buffer, 0, m_bufferSize);
}

string::string(string& string)
	: m_buffer(nullptr)
{
	m_bufferSize = string.m_bufferSize;
	m_buffer = new char[m_bufferSize];
	memset(m_buffer, 0, m_bufferSize);
	memcpy(m_buffer, string.m_buffer, string.m_length);
	m_length = string.m_length;
}

string::string(const char* chars)
 : m_buffer(nullptr)
{
	createOrExpandBufferFromChars(chars);
}

string::string(char* chars)
	: m_buffer(nullptr)
{
	createOrExpandBufferFromChars(chars);
}

string::~string() {
	delete[] m_buffer;
}

/*
string::operator const char* () {
	return m_buffer;
}
*/

string& string::operator=(const char* chars) {
	int len = strlen(chars);
	m_length = len;
	if (len < m_bufferSize)
	{
		memset(m_buffer, 0, m_bufferSize);
		memcpy(m_buffer, chars, len);
	}
	else {
		expand_buffer(len);
		memcpy(m_buffer, chars, len);
	}
	return *this;
}

string& string::operator=(string& string)
{
	*this = string.chars();
	return *this;
}

string& string::operator+=(const char* chars)
{
	add(chars);
	return *this;
}

string& string::operator+=(string& string)
{
	int newlen = string.m_length + m_length;
	if (newlen < m_bufferSize) {
		memcpy((m_buffer + m_length), string.chars(), string.m_length);
		m_length = newlen;
	}
	else {
		char* temp = new char[m_length];
		memcpy(temp, m_buffer, m_length);
		expand_buffer(newlen);
		memcpy(m_buffer, temp, m_length);
		delete[] temp;
		memcpy((m_buffer + m_length), string.chars(), string.m_length);
		m_length = newlen;
	}
	return *this;
}

string string::operator+(const char* chars)
{
	string ret(this->chars());
	//ret.m_shouldDispose = false;
	ret.add(chars);
	return ret;
}

string string::operator+(string& string)
{
	detolly::string::string ret(chars());
	//ret.m_shouldDispose = false;
	ret += string;
	return ret;
}

void string::createOrExpandBufferFromChars(const char* chars)
{
	int len = strlen(chars);
	if (len < m_bufferSize) {
		m_buffer = new char[m_bufferSize];
		memset(m_buffer, 0, m_bufferSize);
		memcpy(m_buffer, chars, len);
		m_length = len;
	}
	else {
		expand_buffer(len);
		memcpy(m_buffer, chars, len);
		m_length = len;
	}
}

void string::expand_buffer(int len) {
	delete[] m_buffer;
	m_bufferSize = len * 1.25;
	m_buffer = new char[m_bufferSize];
	memset(m_buffer, 0, m_bufferSize);
}

void string::add(const char* chars)
{
	int ext_len = strlen(chars);
	int newlen = m_length + ext_len;
	if (newlen < m_bufferSize) {
		memcpy((m_buffer + m_length), chars, ext_len);
		m_length = newlen;
	} else {
		char* temp = new char[m_length];
		memcpy(temp, m_buffer, m_length);
		expand_buffer(newlen);
		memcpy(m_buffer, temp, m_length);
		delete[] temp;
		memcpy((m_buffer + m_length), chars, ext_len);
		m_length = newlen;
	}
}

unsigned int string::length() const
{
	return m_length;
}

const char* string::chars() const
{
	return m_buffer;
}

}
}
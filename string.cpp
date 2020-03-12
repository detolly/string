#include "string.h"
#include <cstdlib>
#include <cstring>

namespace detolly {
namespace string {
	

inline int strlen(const char* chars) {
	int i = 0;
	while(1) {
		if (chars[i] == '\0')
			return i;
		i++;
	}
}


string::string() {
	this->m_buffer = new char[this->m_bufferSize];
	memset(this->m_buffer, 0, this->m_bufferSize);
}

string::string(string& string) {
	m_bufferSize = string.m_bufferSize;
	m_buffer = string.m_buffer;
	m_length = string.m_length;
}

string::string(const char* chars) {
	this->m_buffer = new char[this->m_bufferSize];
	memset(this->m_buffer, 0, this->m_bufferSize);
	int len = strlen(chars);
	m_length = len;
	if (len < this->m_bufferSize) {
		memcpy(this->m_buffer, chars, len);
	} else {
		expand_buffer(len);
		memcpy(this->m_buffer, chars, len);
	}
}

string::string(char* chars) {
	this->m_buffer = new char[this->m_bufferSize];
	memset(this->m_buffer, 0, this->m_bufferSize);
	int len = strlen(chars);
	m_length = len;
	if (len < this->m_bufferSize) {
		memcpy(this->m_buffer, chars, len);
	}
	else {
		expand_buffer(len);
		memcpy(this->m_buffer, chars, len);
	}
}

string::~string() {
	delete[] m_buffer;
}

void string::expand_buffer(int len) {
	delete[] this->m_buffer;
	this->m_bufferSize = this->m_bufferSize*1.2;
	this->m_buffer = new char[this->m_bufferSize];
	memset(this->m_buffer, 0, this->m_bufferSize);
}

const char* string::chars() {
	return m_buffer;
}

string::operator const char* () {
	return m_buffer;
}

string& string::operator=(const char* chars) {
	int len = strlen(chars);
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

string& string::operator=(string& string) {
	string::operator=(string.chars());
	return *this;
}

string& string::operator+=(const char* chars) {
	this->add(chars);
	return *this;
}

string& string::operator+=(string& string)
{
	int newlen = string.m_length + this->m_length;
	if (newlen < m_bufferSize) {
		memcpy((this->m_buffer + m_length), string.chars(), string.m_length);
		this->m_length = newlen;
	}
	else {
		char* temp = new char[m_length];
		memcpy(temp, this->m_buffer, m_length);
		expand_buffer(newlen);
		memcpy(this->m_buffer, temp, m_length);
		delete[] temp;
		memcpy((this->m_buffer + m_length), string.chars(), string.m_length);
		this->m_length = newlen;
	}
	return *this;
}

string string::operator+(const char* chars) {
	string ret(this->chars());
	ret.add(chars);
	return ret;
}

string string::operator+(string& string) {
	detolly::string::string ret(this->chars());
	ret.operator+=(string);
	return ret;
}

void string::add(const char* chars) {
	int ext_len = strlen(chars);
	int newlen = this->m_length + ext_len;
	if (newlen < m_bufferSize) {
		memcpy((this->m_buffer + this->m_length), chars, ext_len);
		this->m_length = newlen;
	} else {
		char* temp = new char[this->m_length];
		memcpy(temp, this->m_buffer, this->m_length);
		expand_buffer(newlen);
		memcpy(this->m_buffer, temp, this->m_length);
		delete[] temp;
		memcpy((this->m_buffer + this->m_length), chars, ext_len);
		this->m_length = newlen;
	}
}

unsigned int string::length() {
	return m_length;
}

}
}
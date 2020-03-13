#include <cstdio>
#include <iostream>
#include "string.h"
#include <chrono>
#include <string>

template<typename stringtype, typename testtype>
void TestTypes(const char* stringName, const char* testName, stringtype t, testtype test)
{
	test = "AA_b5";
	{
		std::chrono::time_point t1 = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < 10000; i++) {
			t = t + test;
		}
		std::chrono::time_point t2 = std::chrono::high_resolution_clock::now();
		auto time = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
		printf("%s in operator = a + b (%s) : %ll", name, testName, time);
	}
}

int main()
{
	/*
	detolly::string::string a;
	detolly::string::string testTypeA;
	TestTypes("detolly::string::string", "detolly::string::string", a, testTypeA);
	std::string b;
	std::string testTypeB;
	TestTypes("std::string", "std::string", b, testTypeB);
	*/

	using namespace detolly::string;

	string a = "Thomas is a person";
	string b = a.substring(3, 3);
	printf((b + "a\n").chars());

}

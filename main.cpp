#include <cstdio>
#include <iostream>
#include "string.h"
#include "chrono"
#include <string>

using namespace detolly::string;

int Test() {
	{
		string a;
		string b = "bbbb";
		auto t1 = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < 100000; i++) {
			//still spend a lot of time on this particular problem
			a = a + "bbbb";
		}
		auto t2 = std::chrono::high_resolution_clock::now();
		auto time = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
		std::cout << "Time: " << time << std::endl;
	}
	{
		std::string a;
		std::string b = "bbbb";
		auto t1 = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < 100000; i++) {
			a = a + "bbbb";
		}
		auto t2 = std::chrono::high_resolution_clock::now();
		auto time = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
		std::cout << "Time: " << time << std::endl;
	}

	return 0;
}

int main() {
	Test();
}
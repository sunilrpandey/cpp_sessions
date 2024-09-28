#pragma once
#include "friends.h"
//#define ENABLE_LOGGING 1

class DemoFriends
{
public:

	void demoFriends()
	{

		Book book("C++", 300);

		LOG("Demo : Friend function");
		print(book);

		LOG("Demo : Friend class");
		Printer printer;
		printer.print(book);

		LOG("Demo : pageCount member function is friend");
		Scanner scanner;
		scanner.pageCount(book);
	}
};
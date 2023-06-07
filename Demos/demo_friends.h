#pragma once
#include "friends.h"

class DemoFriends
{
public:

	void demoFriends()
	{

		Book book("C++", 300);

		//Friend function
		print(book);

		//Friend class
		Printer printer;
		printer.print(book);
	}
};
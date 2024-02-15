#pragma once
#include "includes.h"

#include "common.h"


void demo_uniqueptr_get_exposes_ptr()
{
	auto upEmp = unique_ptr<Employee>();
	Employee* emp = upEmp.get();
	delete emp;

	//Here underneath employee pointer is deleted therefor below line will crash
	upEmp->getName();

}



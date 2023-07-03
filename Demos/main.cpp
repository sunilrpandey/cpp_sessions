#include "common.h"
#include "demo_employee.h"
#include "file_manger_demo.h"
#include "demo_inheritance.h"
#include "demo_array.h"
#include "demo_kstring.h"
#include "demo_misc.h"
#include "demo_friends.h"
#include "templates_basics.h"
#include "smart_pointer.h"
#include "unique_pointer.h"
#include "demo_custom_smart_pointer.h"



void demoEnum(Color selectedColor)
{
	switch (selectedColor) {
	case RED:
		cout << "The selected color is red." << endl;
		break;
	case GREEN:
		cout << "The selected color is green." << endl;
		break;
	case BLUE:
		cout << "The selected color is blue." << endl;
		break;
	default:
		cout << "Invalid color selection." << endl;
		break;
	}
}




int main()
{
		

	/*
	KStringDemo ksd;
	ksd.demoKSTrings();

	
	ArrayDemo ad;
	ad.demo_arrays();

	InheritanceDemo id;
	id.demo_inheritance();

	EmployeeClassDemo ecd;
	ecd.demo();

	DemoFriends df;
	df.demoFriends();


	FileHandlingDemo fhd;
	fhd.demo_file_func_demo();
	fhd.demo_filehandling_with_class_objects();

	
	
	demo_templates();
	
	demoPointer2ConstAndConstPointer();
	
	demoSmartPointer();	
	demoUniquePointer();
	demoSharedPointer();

	*/
	




	demo_templates();

	
	




	
	return 0;
}

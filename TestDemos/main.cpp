#include "common.h"
#include "demo_employee.h"
#include "file_manger_demo.h"
#include "demo_inheritance.h"
#include "demo_array.h"
#include "demo_kstring.h"
#include "demo_misc.h"
#include "demo_friends.h"
#include "demo_custom_smart_pointer.h"
#include "demo_enums.h"
#include "demo_smart_pointers.h"
#include "demo_initializer_list.h"
#include "demo_auto_few_algo.h"
#include "demo_lambda_func.h"
#include "demo_user_defined_literals.h"
#include "demo_exception_handling.h"
#include "demo_weak_ptr.h"
#include "demo_LValue_RValue.h"
#include "demo_move_semantics.h"
#include "demo_perfect_forwarding.h"
#include "demo_virtual_operatoroverload.h"
#include "demo_bind.h"
//#include "demo_threads.h"
#include "demo_classsize_in_diamond_case.h"
#include "demo_diamond_prob.h"
#include "demo_static_member.h"
//#include "demo_templates.h"
#include "demo_passobjects_lambda_cpp17.h"
#include "demo_perfect_forwarding_multi_args.h"

void demo_uniqueptr_get_exposes_ptr()
{
	auto upEmp = unique_ptr<Employee>();
	Employee* emp = upEmp.get();
	delete emp;

	//Here underneath employee pointer is deleted therefor below line will crash
	upEmp->getName();

}


class TwoDArray {
private:
	std::vector<std::vector<int>> array;
	int rows;
	int cols;

public:
	// Constructor: Initializes the 2D array with given rows and columns.
	TwoDArray(int r, int c) : rows(r), cols(c) {
		array.resize(r, std::vector<int>(c, 0));  // Initialize all elements to 0
	}

	// Overload operator[] to return a reference to a row.
	std::vector<int>& operator[](int i) 
	{
		if (i < 0 || i >= rows) {
			throw std::out_of_range("Row index out of range");
		}
		return array[i];
	}

	// Overload operator[] for const objects (for read-only access)
	const std::vector<int>& operator[](int i) const {
		if (i < 0 || i >= rows) {
			throw std::out_of_range("Row index out of range");
		}
		return array[i];
	}

	// Print the array for debugging purposes
	void print() const {
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				std::cout << array[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
};

int demo2DArrayUsingIndexs() {
	TwoDArray arr(3, 4); // Create a 3x4 two-dimensional array

	// Access and modify elements using the overloaded [] operator
	arr[0][0] = 1;
	arr[0][1] = 2;
	arr[1][0] = 3;
	arr[2][2] = 4;

	// Print the 2D array
	arr.print();

	// Example of out-of-bounds access
	try {
		arr[4][1] = 10;  // Invalid row access, throws exception
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}


void demoStructuralBinding()
{
	struct Point { int x, y; };
	Point p{ 3,4 };
	auto [a, b] = p;
	cout << "a=p.x : " << a << std::endl << "b=p.y : " << b << std::endl;
}
int main()
{
	demo_perfect_forwarding_multi_arg();

	//demoPassThisToMemeberFunc();
	//ns_wkptr::demo();
	/*
	ns_static::demo_static();

	return 0;

	
	demoStructuralBinding();
	return 0;

	ArrayDemo ad;
	ad.demoAutoRangeBasedAccess();
	ad.demo_arrays();
	return 0;

	ns_wkptr::demo_pass_smartptrs_to_func();
	return 0;
	
	ns_classsize::demo_sizeof_derived_class();
	demoBind();
	ns_move_semantics::demo_moveConstructible_moveAssignable();
	return 0;
	
	diamondprob::demo();
	return 0;
	
	//float f{ 4 }; // works 
	// int i{3.4}; // does not compile
	
	
	*/
	//ns_smartptrs::demo();
	//ns_wkptr::demo();
	//ns_misc::demo();
	
	
	// to make console wait for user input to close	
	// return std::cin.get();
	
	/*
	KStringDemo ksd;
	ksd.demoKSTrings();
	
	
	InheritanceDemo id; 
	id.demo_inheritance();

	EmployeeClassDemo ecd;
	ecd.demo();

	DemoFriends df;
	df.demoFriends();


	FileHandlingDemo fhd;
	fhd.demo_file_func_demo();
	fhd.demo_filehandling_with_class_objects();

	
	
	demoEnum(RED);
	
	//Custom Smart Pointer
	demoSmartPointer();	
	demoCustomUniquePointer();
	demoCustomSharedPointer();
		
	demoExceptionHandling();	 
	
	demoIntializerList();
	demoAutoAndFewAlgo();	 	
	demoLambdaFunc();	 
	demoBind();
	demoUserDefinedLiterals(); 
	ns_smartptrs::demo();
	ns_wkptr::demo(); 
	ns_misc::demo();
	ns_move_semantics::demoMoveSemantics() ;
	ns_move_semantics::demoPerfectForwarding();
	ns_move_semantics::demoRValue();
	ns_misc::ns_constexpr::demoConstExpr();
	*/

	//ns_thread::demo(); 
	 
	//demo_oo();



	return 0;  
}    
  
   
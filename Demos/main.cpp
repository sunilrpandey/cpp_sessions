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
#include "demo_static_member.h"
#include "demo_templates.h"


void demo_uniqueptr_get_exposes_ptr()
{
	auto upEmp = unique_ptr<Employee>();
	Employee* emp = upEmp.get();
	delete emp;

	//Here underneath employee pointer is deleted therefor below line will crash
	upEmp->getName();

}



int main()
{
	float f{ 4 }; // works 
	// int i{3.4}; // does not compile
	

	//ns_static::demo_static();
	ns_templates::demo_templates();
	
	//ns_smartptrs::demo();
	//ns_wkptr::demo();
	//ns_misc::demo();
	
	
	// to make console wait for user input to close	
	// return std::cin.get();
	//ns_classsize::demo_sizeof_derived_class();

	/*
	KStringDemo ksd;
	ksd.demoKSTrings();
	+
	
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
	//ns_templates::demo_templates();      
	// ns_variadic_templates::demoRecursionWithVariadicTemplates(); 
	ns_variadic_templates::demoVeriadicTemplateUsingFoldExpression();
	//ns_variadic_templates::demoVeriadicTemplateClass();
	*/

	//ns_thread::demo(); 
	 
	//demo_oo();

	return 0;  
}    
  
   
#include <iostream>
#include <type_traits>
#include "templates_ext.h"
#include "concepts.h"
#include "custom_concepts.h"
#include "requires.h"
#include "combining_concepts.h"

#include "DesignatedInitializers.h"

// in memeber wise init object is already created but in initilizer list members are initialized during object created,
// array has copies of object created
//for(ojb o : o_array) copies


void func_int(int) {
	std::cout << "int param" << std::endl;
}

void func_float(float) {
	std::cout << "float param" << std::endl;
}
template<typename T>
void func(T value) {
	if constexpr (std::is_integral_v<T>)
		func_int(value);
	else if constexpr (std::is_floating_point_v<T>)
		func_float(value);
	else
		static_assert(std::is_integral_v<T> || std::is_floating_point_v<T>, "Only int or float is allowed");
}
void demoConstExprIf() {
	func(10);
	func(10.5);
	//func("xyz");
}

using namespace std;
int main()
{
	//demoAutoFunctionTemplates();
	//demoNamedTemplateParameters();

	//demoTypeTraits();
	//demoConstExprIf();

	//demoBuiltInConcepts();
	//demoCustomConcepts();
	//demoRequires();
	//demoCombiningConcepts();
	// demoConceptAndAuto();

	demoDesignatedInitializers();

	return 0;
}
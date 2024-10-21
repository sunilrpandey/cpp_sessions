#include <iostream>
#include "demo_func_templates.h"
#include "demo_type_traits.h"
#include "template_array.h"
#include "adder.h"

using namespace std;

void demoGenericArray() {
	Array<int> arr;
	cout << arr;	
}

void demoSpecializedClass() {
	Adder<int> adder;
	cout << "Demo - Adder[12,13] : " << adder.execute(12, 13);

	Adder<char*> concater;
	char first[10] = "Hello";
	char second[10] = "C++";
	cout << "\nDemo - Concater[Hello,c++] : " << concater.execute(first, second);

}


int main()
{
	demoSpecializedClass();
	return 0;

	demoGenericArray();
	return 0;
	//ns_templates::demo_templates();
	demoBasicTypeTraits();
	return 0;
	// ns_variadic_templates::demoRecursionWithVariadicTemplates(); 
	// ns_variadic_templates::demoVeriadicTemplateUsingFoldExpression();
	//ns_variadic_templates::demoVeriadicTemplateClass();

	return 0;
}
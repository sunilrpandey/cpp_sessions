#include <iostream>
#include "demo_func_templates.h"
#include "demo_type_traits.h"
#include "template_array.h"

using namespace std;

void demoGenericArray() {
	Array<int> arr;
	cout << arr;	
}

int main()
{
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
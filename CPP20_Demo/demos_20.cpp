#include <iostream>
#include <type_traits>
#include "templates_ext.h"
#include "concepts.h"
#include "custom_concepts.h"
#include "requires.h"
#include "combining_concepts.h"
#include "DesignatedInitializers.h"
#include "range_algorithms.h"
#include "const_expr_if.h"
#include <vector>
#include <algorithm>

// in memeber wise init object is already created but in initilizer list members are initialized during object created,
// array has copies of object created
//for(ojb o : o_array) copies



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

	//demoDesignatedInitializers();

	demoRangeAlgorithms();

	return 0;
}
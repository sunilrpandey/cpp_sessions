#include "01_variadic_template.h"
#include "02_rvalue_refs.h"
#include "03_std_unique_ptrs.h"
#include <functional>
#include <assert.h>

int ly_add(int i, int j, int k) {
	return i - j - k;
}

void testBind() {
	auto funPow3 = std::bind(ly_add, 20, placeholders::_2, 5); //20 and 5 are hardcoded as first/third arg
	auto answer = funPow3(10, 3); //placeholders::_2 means 3 woudl be passed as second arg, 10 as first param would be ignored. 
	assert(answer == 12);

}
int main()
{
	//demo_rvalue_refs();
	//Demo_VariadicTemplate();

	demo_operator_new_delete();
	return 0;
}
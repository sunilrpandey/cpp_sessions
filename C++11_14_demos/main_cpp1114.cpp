#include "01_variadic_template.h"

/*
int& getNum() {
	return 10;
}
const int& or int&& work
*/
int&& getNum() {
	return 10;
}
int main()
{
	int i = getNum();
	Demo_VariadicTemplate();
	return 0;
}
#include <iostream>
using namespace std;
namespace ns_templates
{

	template <int N>
	struct Factorial
	{
		static const int value = N * Factorial<N - 1>::value;
	};

	template <>
	struct Factorial<1>
	{
		static const int value = 1;
	};

	

	/*template<int N>
	int get_factorial()
	{
		if (N == 0)
			return 1;
		else if (N == 1)
			return N;
		else
			return N * get_factorial<N - 1>();
	}*/

	void demo_factorial_using_meta_programming() {
		
		// somehow not working giving C1202 compilation issues on windows/vs2022
		//cout << "Demo : Factorial 5 using Function : " << get_factorial<5>() << endl;
		cout << "Demo : Factorial 5 using class 'int' member : " << Factorial<5>::value << endl;
	}



};

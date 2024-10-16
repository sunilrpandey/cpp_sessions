
#include"common.h"

namespace ns_variadic_templates
{
	template <typename T>
	T sum(T value) {
		return value;
	}

	template <typename T, typename... Args>
	T sum(T first, Args... rest) {
		return first + sum(rest...);
	}

	int demoRecursionWithVariadicTemplates() {
		int total = sum(1, 2, 3.5, 4, 5);
		return 0;
	}

	template <typename... Args>
	void printValues(Args... args) {
		((std::cout << args << " "), ...);
	}


	int demoVeriadicTemplateUsingFoldExpression() {
		printValues(1, 2, 3, "hello", 3.14);
		return 0;
	}

	/*
	template <typename... Args>
	class Tuple {
	public:
		Tuple(Args... args) : values(args...) {}

		void print() {
			(void(std::cout << ... << values) << endl);
		}

	private:
		std::tuple<Args...> values;
	};

	int demoVeriadicTemplateClass() {
		Tuple<int, std::string, double> tuple(1, "hello", 3.14);
		tuple.print();
		return 0;
	}

	*/


};

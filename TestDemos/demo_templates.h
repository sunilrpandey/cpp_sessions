#include "common.h"
#include "templates_basics.h"
#include "template_meta_prog.h"
#include "template_array.h"
#include "template_sized_array.h"

//function written using templates are function template (blueprint )and instance out of it is template function
// if classic function is there it will have followed by specialized template function and then template function

namespace ns_templates {

	void demoFunctionTemplates()
	{
		//Template type deduction 
		cout << Max(5, 10);
		cout << Max(5.5f, 10.5f); // if classic function is available compiler wont generate it for float
		cout << Max(KString("KPIT"), KString("Technologies"));
		//cout << Max(5, 10.0); // Since two types it will  call two template param version.. 
		cout << Max(static_cast<float>(5), 10.5f);

		//cout << Max('a', 'b');



		//cout << Max(2.0, 3.5);

		//cout << "\nFactorial : " << print<5>();
	}
	void demoTemplatesClass()
	{

		{
			SizedArray<int, 15> arr;
			for (int i = 0; i < 5; i++) {
				arr[i] = i + 1;
			}
			arr.print();

			SizedArray<float, 5> flt_arr;
			for (int i = 0; i < 5; i++) {
				flt_arr[i] = (i + 1) / 2.0f;
			}
			flt_arr.print();
			return;
		}

		{
			Array<int> arr(5);
			for (int i = 0; i < 5; i++) {
				arr[i] = i + 1;
			}
			arr.print();

			Array<float> flt_arr(5);
			for (int i = 0; i < 5; i++) {
				flt_arr[i] = (i + 1) / 2.0f;
			}
			flt_arr.print();
			return;
		}

	}
	void demo_templates()
	{
		
		cout << "Demo : Template Functions" << endl;
		demoFunctionTemplates();

		/*
		cout << "Demo : Template Class" << endl;
		demoTemplatesClass();

		cout << "\nDemo : Template MetaProgramming" << endl;
		ns_templates::demo_factorial_using_meta_programming();
		*/
	}
};


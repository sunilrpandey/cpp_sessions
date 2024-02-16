#include "common.h"
#include "templates_basics.h"
#include "template_meta_prog.h"

namespace ns_templates {

	void demoTemplateFunction()
	{
		cout << Max(5, 10);
		cout << Max(5.5f, 10.5f);


		cout << Max(KString("KPIT"), KString("Technologies"));

		cout << Max(5, 10.0);
		cout << Max(static_cast<float>(5), 10.5f);

		//cout << Max('a', 'b');



		cout << Max(2, 3.5);

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
		cout << "\nDemo : Template MetaProgramming" << endl;
		ns_templates::demo_factorial_using_meta_programming();

		cout << "Demo : Template Functions" << endl;
		demoTemplateFunction();

		cout << "Demo : Template Class" << endl;
		demoTemplatesClass();

	}
};


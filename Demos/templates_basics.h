#pragma once
#include "KString.h" 

template <typename T>
T Max(T a, T b)
{
	cout << "\ncalling template function" << endl;
	if (a >= b)
		return a;

	return b;
}

template <typename T>
T Min(T a, T b)
{
	T max = Max(a, b);
	cout << "\ncalling template function -  MIN" << endl;
	if (a == max)
		return b;

	return a;
}

float Max(float a, float b)
{
	cout << "\nClassic function" << endl;

	if (a >= b)
		return a;

	return b;
}


template <>
float Max(float a, float b)
{
	cout << "\ncalling non template function" << endl;

	if (a >= b)
		return a;

	return b;
}

char Max(char a, char b) = delete;

template <typename T, typename S>
T Max(T a, S b)
{
	cout << "\ncalling Max2" << endl;
	if (a >= b)
		return a;

	return b;
}

template <typename T>
class Array
{
public:
	Array(int size) {
		size_ = size;
		data = new T[size_];
		for (int i = 0; i < size_; i++) {
			data[i] = 0;
		}
	}
	Array(const Array& rhs) { // Copy constructor
		size_ = rhs.size_;
		data = new T[size_];
		for (int i = 0; i < size_; i++) {
			data[i] = rhs.data[i];
		}
	}
	void print() {
		cout << endl << "Array Elements : ";
		for (int i = 0; i < size_; i++) {
			cout << data[i] << "  ";
		}
		cout << endl;
	}

	T& operator [] (int index) {
		return data[index];
	}
	~Array() {
		delete[] data;

	}
private:
	T* data;
	int size_;
};

template <typename T, int size>
class SizedArray
{
public:
	SizedArray() {
		size_ = size;
		data = new T[size_];
	}
	SizedArray(const SizedArray& rhs) {
		size_ = rhs.size_;
		data = new T[size_];
		for (int i = 0; i < size_; i++) {
			data[i] = rhs.data[i];
		}
	}
	void print() {
		cout << endl << "Array Elements : ";
		for (int i = 0; i < size_; i++) {
			cout << data[i] << "  ";
		}
		cout << endl;
	}

	T& operator [] (int index) {
		return data[index];
	}
	~SizedArray() {
		delete[] data;

	}
private:
	T* data;
	int size_;
};

//template<int N>
//int print()
//{
//	if (N == 1)
//		return N;
//	else
//		return N * print<N - 1>();	
//}
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
		SizedArray<int,15> arr;
		for (int i = 0; i < 5; i++) {
			arr[i] = i + 1;
		}
		arr.print();

		SizedArray<float,5> flt_arr;
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
	demoTemplateFunction();
	demoTemplatesClass();

}
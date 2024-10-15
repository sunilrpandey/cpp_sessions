#pragma once

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

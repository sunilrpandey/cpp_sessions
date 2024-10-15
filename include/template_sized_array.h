#pragma once
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
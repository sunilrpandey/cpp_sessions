#pragma once

template <typename T>
class Array
{
private:
	static const int DEFAULT_SIZE;
	static const int DEFAULT_CAPACITY = 8;
public:
	Array(int size = DEFAULT_SIZE);
	Array(const Array& rhs);
	~Array();

	T& operator [] (int index);

public:
	void  print();
	friend void printArraySize(Array<T> array);

public: //-----setter/getter
	size_t size() { return size_; }

private:
	T* data;
	size_t size_;

};

template <typename T>
void printArraySize(Array<T> array) {

	std::cout << "friend demo : Array Size : " << array.size_;

}

template<typename T>
const int Array<T>::DEFAULT_SIZE = 8;

template<typename T>
Array<T>::Array(int size) {
	size_ = size;
	data = new T[size_];
	for (int i = 0; i < size_; i++) {
		data[i] = 10;
	}
}


template<typename T>
Array<T>::Array(const Array& rhs) { // Copy constructor
	size_ = rhs.size_;
	data = new T[size_];
	for (int i = 0; i < size_; i++) {
		data[i] = rhs.data[i];
	}
}

template<typename T>
T& Array<T>::operator [] (int index) {
	return data[index];
}

template<typename T>
Array<T>::~Array() {
	delete[] data;

}

template<typename T>
void Array<T>::print() {
	cout << endl << "Array Elements : ";
	for (int i = 0; i < size_; i++) {
		cout << data[i] << "  ";
	}
	cout << endl;
}

template <typename T>
inline std::ostream& operator << (std::ostream& os, Array<T> arr) {
	os << "\nArray [";
	for (int i{}; i < arr.size(); ++i) {
		os << arr[i] << " ";
	}
	os << "]" << std::endl;
	return os;
}


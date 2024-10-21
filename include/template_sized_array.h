#pragma once
template <typename T, int size=8>
class SizedArray
{
public:
	SizedArray();
	SizedArray(const SizedArray& rhs); 
	~SizedArray();

	T& operator [] (int index);

	void print();
	int getSize() {
		return size_;
	}

private:
	T* data;
	int size_;	
};

template<typename T,int size>
SizedArray<T,size>::SizedArray<T,size>() {
	size_ = size;
	data = new T[size_];
}
template<typename T, int size>
SizedArray<T, size>::SizedArray(const SizedArray& rhs) {
	size_ = rhs.size_;
	data = new T[size_];
	for (int i = 0; i < size_; i++) {
		data[i] = rhs.data[i];
	}
}
template<typename T, int size>
void SizedArray<T, size>::print() {
	cout << endl << "Array Elements : ";
	for (int i = 0; i < size_; i++) {
		cout << data[i] << "  ";
	}
	cout << endl;
}

template<typename T, int size>
T& SizedArray<T, size>::operator [] (int index) {
	return data[index];
}
template<typename T, int size>
SizedArray<T, size>::~SizedArray() {
	delete[] data;

}

template <typename T, int size>
inline std::ostream& operator << (std::ostream& os, Array<T> arr) {
	os << "\nSized Array [";
	for (int i{}; i < arr.getSize(); ++i) {
		os << arr[i] << " ";
	}
	os << "]" << std::endl;
	return os;
}

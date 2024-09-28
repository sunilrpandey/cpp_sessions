#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class Worker
{
	std::string name;
	int id;
	float salary;
	std::string role;
public:
	Worker() = default;
	Worker(std::string nm, int i, float sal, std::string r) :name(nm), id(i), salary(sal), role(r) {}

	friend ostream& operator << (ostream& os, const Worker& e) {
		os << e.name << "\n" << e.id << "\n" << e.salary << "\n" << e.role<< "\n";

		return os;
	}
	friend istream& operator >> (istream& is, Worker& e) {
		is >> e.name >> e.id >> e.salary >> e.role;

		return is;
	}
};

class FileHandlingDemo
{
public:
	std::string readFileContentAsString(const std::string& filename)
	{
		ifstream ifs(filename);
		ostringstream oss;
		oss << ifs.rdbuf();

		std::string file_text = oss.str();

		cout << "\nreading Worker from file" << endl << file_text;

		ifs.close();
		return file_text;
	}
	void readWorkerFromFile(const std::string& filename)
	{
		ifstream ifs("emp.txt", ios::app);
		Worker emp;

		cout << "\nWorker retained from saved file" << endl;
		while (ifs >> emp) {
			cout << emp;
		}


		ifs.close();
	}

	void saveWorkerToFile(const std::string& filename, const Worker& emp)
	{
		ofstream ofs(filename, ios::app);
		ofs << emp;
		ofs.close();
	}

	
	int demo_filehandling_with_class_objects()
	{

		Worker emp("abc", 123, 123456, "Er");
		Worker emp1("def", 456, 456789, "Dr");

		std::string file_name = "emp.txt";
		std::remove(file_name.c_str());

		cout << "Print Worker using console out" << endl;
		cout << emp;


		saveWorkerToFile(file_name, emp);
		readWorkerFromFile(file_name);
		saveWorkerToFile(file_name, emp1);
		readFileContentAsString(file_name);

		

		return 0;

	}
	void demo_file_func_demo() {

		std::fstream file("test.txt", std::ios::in | std::ios::out | std::ios::trunc);

		if (!file.is_open()) {
			std::cout << "Failed to open the file!" << std::endl;
			return;
		}

		// Writing to the file
		file << "Hello, Seekers!\n";
		file << "This is a test file.\n";

		// Seek to the beginning of the file
		file.seekp(0, std::ios::beg);

		// Reading from the file
		std::string line;
		while (std::getline(file, line)) {
			std::cout << line << std::endl;
		}

		// Get the current put position
		std::streampos putPos = file.tellp();
		std::cout << "Current put position: " << putPos << std::endl;

		// Get the current get position
		std::streampos getPos = file.tellg();
		std::cout << "Current get position: " << getPos << std::endl;

		// Seek to a specific position
		file.seekg(0, std::ios::beg);

		// Peek the next character
		char ch = file.peek();
		std::cout << "Next character: " << ch << std::endl;

		// Seek to the middle of the file
		file.seekg(7, std::ios::beg);

		// Peek the next character
		ch = file.peek();

		if (file.good()) {
			std::cout << "Next character after seekg 7: " << ch << std::endl;
		}
		else {
			std::cout << "Failed to peek the next character." << std::endl;
		}

		// Close the file
		file.close();

		return;

	}
};
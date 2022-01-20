#include<iostream>
#include <string>
#include <fstream>
#include <vector>
using std::cout;
using std::cin;
using std::string;
using std::vector;

class Book{
	public:
		string name, author, isbn, location, num_copies;
	
		void getData();
};

void Book::getData() {
	cout << "Enter name of book: ";
	getline(cin, name);
	cout << "Enter name of author: ";
	getline(cin, author);
	cout << "Enter ISBN: ";
	getline(cin, isbn);
	cout << "Enter shelf number: ";
	getline(cin, location);
	cout << "Enter number of copies: ";
	getline(cin, num_copies);
}	

void writeData(vector<Book> book) {
	std::ofstream datafile("./files/books.txt", std::ios::app);
	for (auto & elem:book) {
		datafile << '\n' << elem.isbn << "\t\t" << elem.name << "\t\t" << elem.author
			<< "\t\t" << elem.location << "\t\t" << elem.num_copies; 
	}

}

int main() {
	bool input {true};
	char response{'n'};
	vector<Book> books;
	while (input) {
		Book dummy;
		dummy.getData();
		books.push_back(dummy);

		cout << "Do you want to add another book?[y/n]	";
		cin >> response;
		cin.ignore();
		switch(response){
			case 'y':
				input = true;
				break;
			case 'n':
				input = false;
				break;
			default:
				input = false;
				cout << "Wrong input. Exiting...\n";
				break;
		}
	}

	writeData(books);
	return 0;
}

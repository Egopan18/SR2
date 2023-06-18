#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct Publication
{
	int year;
	string publisher;
};

class Book
{
private:
	string author;
	string title;
	Publication publication;
public:
	Book(string fileName)
	{

		string line;
		while (!fin.eof())
		{
			getline(fin, line);
		}
	}
};

vector<Book> readXml(const string &fileName)
{
	vector<Book> books;

	string line;
	ifstream fin;
			fin.open(fileName);

	while (!fin.eof())
	{
		getline(fin, line);
	}

	return books;
}

int main()
{


	return 0;
}

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
	Book(const string &tag)
	{

	}
};

vector<Book> readXml(const string &fileName)
{
	vector<Book> books;

	string tag = "", line;
	ifstream fin;
	fin.open(fileName);

	while (!fin.eof())
	{
		getline(fin, line);
		if (line.find("<book>") != string::npos)
		{
			while (line.find("</book>") == string::npos)
            {
                tag += line;
            }

            Book book(tag);
            books.push_back(book);
		}
	}

	return books;
}

int main()
{


	return 0;
}

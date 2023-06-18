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

string readTag(string bookInfo, string tag)
{
    int start, end;
    string value;

    start = bookInfo.find("<" + tag + ">");
    if (start != string::npos)
    {
        end = bookInfo.find("</" + tag + ">");
        value = bookInfo.substr(start, end - start);
        value.erase(0, value.find(">") + 1);
    }

    return value;
}

class Book
{
private:
	string author;
	string title;
	Publication publication;
public:
	Book(const string &bookInfo)
	{
        author = readTag(bookInfo, "author");
        title = readTag(bookInfo, "title");
        publication.year = stoi(readTag(bookInfo, "year"));
        publication.publisher = readTag(bookInfo, "publisher");
    }
};

vector<Book> readXml(const string &fileName)
{
	vector<Book> books;

	string bookInfo = "", line;
	ifstream fin;
	fin.open(fileName);

	while (!fin.eof())
	{
		getline(fin, line);
		if (line.find("<book>") != string::npos)
		{
			while (line.find("</book>") == string::npos)
            {
                bookInfo += line;
                getline(fin, line);
            }

            Book book(bookInfo);
            books.push_back(book);
		}
        bookInfo.clear();
    }

	return books;
}

int main()
{
    readXml("test.xml");

	return 0;
}

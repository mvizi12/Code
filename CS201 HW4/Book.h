#pragma once
#include <iostream>
#include<iomanip>
#include<string>
#ifndef Book_h
#define Book_h

using namespace std;

class publicationDate
{
private:
	int month, day, year;
public:
	void setMonth(int m)
	{month = m;}
	void setDay(int d)
	{day = d;}
	void setYear(int y)
	{year = y;}
	int getMonth() const
	{return month;}
	int getDay() const
	{return day;}
	int getYear() const
	{return year;}
};

class Book
{
private:
	string title, author, publisher, category;
	publicationDate pDate;
public:
	Book(string t, string a, string p, int m, int d, int y, string c) //Constructor
	{
		title = t;
		author = a;
		publisher = p;
		pDate.setMonth(m);
		pDate.setDay(d);
		pDate.setYear(y);
		category = c;
	}
	void getYear(vector<Book>) const;
	void getAuthor(vector<Book>) const;
	void getCategory(vector<Book>) const;
};

void Book::getYear(vector<Book> books) const
{
	int yr, beg, end; //Variables to hold year range
	int n1 = 0; //Counter variable

	cout << "\nEnter beginning year: ";
	cin >> beg;
	cout << "\nEnter ending year: ";
	cin >> end;
	cout << "\nAll books between " << beg << " and " << end << ':' << endl;
	cout << "Title" << setw(32) << "Author" << setw(32) << "Publisher" << setw(32) << "Date\t" << setw(32) << "Category" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------------------------\n";

	for (int i = 0; i < books.size(); i++) //Loops through entire 2D vector
	{
		yr= books[i].pDate.getYear(); //Assigns year integer held in "book[i]" to "yr"
		if (yr >= beg && yr <= end) //Displays title of book if it falls within year range
		{
			cout << books[i].title << setw(25) << books[i].author << setw(25) << books[i].publisher << setw(25) <<
				books[i].pDate.getMonth() << "/" << books[i].pDate.getDay() << "/" << books[i].pDate.getYear() << 
				setw(33) << books[i].category << endl;
			n1++;
		}
	}
	if (n1 == 0) //If there were no books in year range
		cout << "There were no books in that year range\n";
	cout << endl;
}

void Book::getAuthor(vector<Book> books) const
{
	string uAuthor, bAuthor; //Variables to hold name of user's author and name of book's author
	int n2 = 0;
	cout << "\nPlease enter the name of an author: ";
	cin.ignore();
	getline(cin, uAuthor);
	cout << "Title" << setw(32) << "Author" << setw(32) << "Publisher" << setw(32) << "Date\t" << setw(32) << "Category" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < uAuthor.size(); i++) //Loop to change user's input into uppercase letters
	{
		int c1 = uAuthor[i]; //"c1" carries current character in uAuthor
		if (islower(c1)) //If lowercase, changes to uppercase
			uAuthor[i] = toupper(c1);
	}
	for (int i = 0; i < books.size(); i++) //Loop to iterate over every book in list
	{
		bAuthor = books[i].author;
		for (int i = 0; i < bAuthor.size(); i++) //Loop to change book's author into uppercase letters
		{
			int c1 = bAuthor[i]; //"c1" carries current character in current word
			if (islower(c1)) //If lowercase, changes to uppercase
				bAuthor[i] = toupper(c1);
		}
		size_t found = bAuthor.find(uAuthor);
		if (found != string::npos) //If user input is a substring of book's author
		{
			cout << books[i].title << setw(25) << books[i].author << setw(25) << books[i].publisher << setw(25) <<
				books[i].pDate.getMonth() << "/" << books[i].pDate.getDay() << "/" << books[i].pDate.getYear() <<
				setw(33) << books[i].category << endl;
			n2++;
		}
	}
	if (n2 == 0)
		cout << "There weren't any books written by that author\n";
	cout << endl;
}

void Book::getCategory(vector<Book> books) const
{
	string uCategory, bCategory; //Variables to hold user's category and books' categories
	int n3 = 0;

	cout << "\nEnter 'Fiction' or Non Fiction': ";
	cin.ignore();
	getline(cin, uCategory);
	cout << "Title" << setw(32) << "Author" << setw(32) << "Publisher" << setw(32) << "Date\t" << setw(32) << "Category" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < uCategory.size(); i++) //Loop to change user's input into uppercase letters
	{
		int c1 = uCategory[i]; //"c1" carries current character in uCategory
		if (islower(c1)) //If lowercase, changes to uppercase
			uCategory[i] = toupper(c1);
	}
	for (int i = 0; i < books.size(); i++) //Loop to iterate over every book in list
	{
		bCategory = books[i].category;
		for (int i = 0; i < bCategory.size(); i++) //Loop to change book's category into uppercase letters
		{
			int c1 = bCategory[i]; //"c1" carries current character in current word
			if (islower(c1)) //If lowercase, changes to uppercase
				bCategory[i] = toupper(c1);
		}
		if (uCategory == bCategory) //If user's category is the same as the book's category
		{
			cout << books[i].title << setw(25) << books[i].author << setw(25) << books[i].publisher << setw(25) <<
				books[i].pDate.getMonth() << "/" << books[i].pDate.getDay() << "/" << books[i].pDate.getYear() <<
				setw(33) << books[i].category << endl;
			n3++;
		}
	}
	if (n3 == 0)
		cout << "There weren't any books in that category\n";
	cout << endl;
}
#endif
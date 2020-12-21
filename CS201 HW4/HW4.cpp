#include <iostream>
#include<string>
#include <sstream>
#include <vector>
#include "Book.h"

using namespace std;

int HW4()
{
	vector<Book> books; //Vector for holding a list of objects of class "Book"
	int iMonth, iDay, iYear; //Variable to hold date(s) in integer form
	char decision;
	string sMonth, sDay, sYear; //Variable to hold date(s) in string form
	string title, author, publisher, date, category;
	string data[][5] =
	{ {"A Breath of Snow and Ashes","Diana Gabaldon","Delacorte","10/16/2005","Fiction"},
  {"A Common Life","Jan Karon","Viking","4/29/2001","Fiction"},
  {"A Dance With Dragons","George R. R. Martin","Bantam","7/31/2011","Non Fiction"},
  {"A Day Late and a Dollar Short","Terry McMillan","Viking","2/4/2001","Fiction"},
  {"A Feast For Crows","George R. R. Martin","Bantam","11/27/2005","Fiction"},
  {"A Lion Is In the Streets","Adria Locke Langley","McGraw","7/1/1945","Non Fiction"},
  {"A Man In Full","Tom Wolfe","Farrar","11/22/1998","Fiction"},
  {"A Painted House","John Grisham","Doubleday","2/25/2001","Non Fiction"},
  {"A Perfect Spy","John le Carre","Knopf","5/4/1986","Fiction"},
  {"A Rage to Live","John O'Hara","Random House","9/18/1949","Fiction"},
  {"A Shade of Difference","Allen Drury","Doubleday","10/28/1962","Non Fiction"},
  {"A Thousand Splendid Suns","Khaled Hosseini","Riverhead","6/10/2007","Fiction"},
  {"A Tree Grows In Brooklyn","Betty Smith","Harper","1/2/1944","Fiction"},
  {"A Widow For One Year","John Irving","Random House","6/14/1998","Non Fiction"},
  {"Accident","Danielle Steel","Delacorte","2/27/1994","Fiction"},
  {"Acheron","Sherrilyn Kenyon","St. Martin's","8/24/2008","Non Fiction"},
  {"Across the River and Into the Trees","Ernest Hemingway","Scribner's","10/15/1950","Fiction"},
  {"Advise and Consent","Allen Drury","Doubleday","10/4/1959","Non Fiction"},
  {"Against All Enemies","Tom Clancy","Putnam","7/3/2011","Non Fiction"},
  {"Airframe","Michael Crichton","Knopf","12/29/1996","Fiction"},
  {"Airport","Arthur Hailey","Doubleday","4/7/1968","Non Fiction"},
  {"Alaska","James Michener","Random House","7/3/1988","Fiction"},
  {"Alex Cross's Trial","James Patterson","Brown","9/13/2009","Non Fiction"},
  {"American Assassin","Vince Flynn","Atria","10/31/2010","Fiction"},
  {"An Indecent Obsession","Colleen McCullough","Harper","11/15/1981","Fiction"},
  {"Anansi Boys","Neil Gaiman","Morrow","10/9/2005","Fiction"},
  {"Anathem","Neal Stephenson","William Morrow","9/28/2008","Fiction"},
  {"Anatomy of a Murder","Robert Traver","St. Martin's","3/9/1958","Non Fiction"},
  {"And Now Tomorrow","Rachel Field","MacMillan","8/9/1942","Non Fiction"},
  {"Andersonville","McKinley Kantor","World Publishing","1/1/1956","Fiction"},
  {"Angels Fall","Nora Roberts","Putnam","7/30/2006","Fiction"},
  {"Answered Prayers","Danielle Steel","Delacorte","11/17/2002","Fiction"},
  {"Arch of Triumph","Erich Maria Remarque","Appleton-Century","3/10/1946","Fiction"},
  {"Armageddon","Tim LaHaye","Tyndale","4/27/2003","Fiction"},
  {"At First Sight","Nicholas Sparks","Warner","11/6/2005","Non Fiction"},
  {"Bad Moon Rising","Sherrilyn Kenyon","St. Martin's","8/23/2009","Non Fiction"},
  {"Bag of Bones","Stephen King","Scribner","10/11/1998","Non Fiction"},
  {"Beach Music","Pat Conroy","Talese/Doubleday","7/16/1995","Fiction"},
  {"Before I Say Goodbye","Mary Higgins Clark","Simon & Schuster","5/7/2000","Fiction"},
  {"Best Friends Forever","Jennifer Weiner","Atria","8/2/2009","Fiction"} };

	for (int i = 0; i < 40; i++)
	{
		title = data[i][0];
		author = data[i][1];
		publisher = data[i][2];
		date = data[i][3];
		category = data[i][4];

		//Splitting date by month day and year
		stringstream check1(date);
		getline(check1, sMonth, '/');
		getline(check1, sDay, '/');
		getline(check1, sYear);

		stringstream geek(sMonth); //Converts string in "sMonth" to integer and stores in "geek"
		geek >> iMonth; //Assigns integer held in "geek" to "iMonth"
		stringstream geek2(sDay); //Converts string in "sDay" to integer and stores in "geek"
		geek2 >> iDay; //Assigns integer held in "geek" to "iDay"
		stringstream geek3(sYear); //Converts string in "sYear" to integer and stores in "geek"
		geek3 >> iYear; //Assigns integer held in "geek" to "iYear"

		Book b(title, author, publisher, iMonth, iDay, iYear, category);
		books.push_back(b);
	}
	//Display menu
label1:
	cout << "Please choose one of the following options:" << endl;
	cout << "1) Display all books in a year range" << endl;
	cout << "2) Search for an author" << endl;
	cout << "3) Display all books for a category" << endl;
	cout << "Q) Quit" << endl;

	cin >> decision;
	switch (decision)
	{
	case 49: books[0].getYear(books); //"49" is the ASCII value for digit "1"
		break;
	case 50: books[0].getAuthor(books); //"50" is the ASCII value for digit "2"
		break;
	case 51: books[0].getCategory(books); //"51" is the ASCII value for digit "3"
		break;
	case 'Q': return 0;
	case 'q': return 0;
	default: "Invalid Choice";
	}
	goto label1;
}
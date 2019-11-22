
#include <iostream>
#include <string>
#include "favThings.h"
#include "favThingsList.h"
using namespace std;

int main()
{
	favThingsList *myList = NULL;
	myList = new favThingsList[100];
	cout << "************************" << endl;
	cout << "hello and welcome!" <<endl;
	cout << "this program will help you track your favorite recipes" <<endl;
	cout << "************************" << endl;

	int menuPick = 0;
	
	char goAgain = 'y';
	cout << "enter 1 to read file, 2 to add recipes, 3 to show recipies, 4 to save, or 5 to quit"<<endl;
	
	while(menuPick != 5)
	{

		if (menuPick != 0)	
		cout << "1- read file 2- add recipe 3- show recipe 4- save 5- quit: ";
		cin >> menuPick;
		cin.ignore();
	
		switch(menuPick)
			{
				case 1:
					//read
					myList->readFromFile();
					break;
				case 2:
					// add recipe
					do{
					myList->addItem();
					cout << "add another object? (y/n) ";
					cin >> goAgain;
					cin.ignore();
					cout << endl;
					}while(goAgain == 'y' || goAgain == 'Y');
					break;
				case 3:
					// show
					myList->showList();
					break;
				case 4: 
					//save
					myList->writeToFile();
				case 5:
					//quit
					myList->~favThingsList();
					break;
			}
	}
	

	cout << '\n';
	return 0;
}

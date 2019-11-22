#include <iostream>
#include <string>
#include <fstream>
#include "favThings.h"
#include "favThingsList.h"

using namespace std;

favThingsList::favThingsList()
{
	numItems = 0;
	totalInventory = 0;
	items = new FavThings*[100];
}
void favThingsList::addItem() // uses getFavInput to take user input, check unique
{
	items[numItems] = new FavThings;
	items[numItems]->getFavInput();
	for (int i = 0; i< numItems; i ++) 
	{
		if (items[numItems]->getName() == items[i]->getName())
		{
			cout << "you already put that one in!" << endl << endl;	
		       items[numItems]->getFavInput();	
		}
	}
	numItems++;
}
void favThingsList::showList() //uses overloaded insertion to display recipes
{
	for (int i=0; i < numItems; i++)
	{
		cout << "*********" << "recipe " << i+1 << "*********" << endl;
		cout << *items[i] << endl;
	}

}
void favThingsList::writeToFile()// writes list to file chosen by user
{
	string pathIn = " ";
	ofstream fileOut;
	cout << "please enter a full file path where you would like to save your list:" <<endl;
	getline(cin, pathIn);
	fileOut.open(pathIn, ios::trunc);//works in linux, not tested on windows
	if (!fileOut)
	{
	cout << "something's gone wrong!"<<endl;
	}
	for (int i =0; i<numItems;i++)
	{
		fileOut << items[i]->getName() << '|';
		fileOut << items[i]->getIngredients() << '|';
		fileOut << items[i]->getServings() << '|';
		fileOut << items[i]->getCost() << '|';
		fileOut << items[i]->getTimeH() << '|';
		fileOut << items[i]->getTimeM() << '\n';
	}
}
void favThingsList::readFromFile()// reads list from file chosen by user
{
	string pathIn = " ";
	ifstream fileIn;
	cout << "please enter full file path to read list from" << endl;
	getline(cin, pathIn);
	fileIn.open(pathIn);//works in linux, not tested on windows

	if (!fileIn)
	{
		cout << "something's gone wrong!"<<endl;
	}

	string nameIn, ingIn, temp;
	int servIn, timeHIn, timeMIn;
	double costIn;
	while (getline(fileIn, nameIn, '|'))
	{
		items[numItems] = new FavThings;

		items[numItems]->setName(nameIn);
	//	cout << items[numItems]->getName() << " ";
		
		getline(fileIn, ingIn, '|');
		items[numItems]->setIngredients(ingIn);
	//	cout << items[numItems]->getIngredients() << " ";
	
		getline(fileIn, temp, '|');
		servIn = stoi(temp);
		items[numItems]->setServings(servIn);
	//	cout << items[numItems]->getServings() << " ";

		getline(fileIn, temp, '|');
		costIn = stod(temp);
		items[numItems]->setCost(costIn);
	//	cout << items[numItems]->getCost() << " ";

		getline(fileIn, temp, '|');
		timeHIn = stoi(temp);
		getline(fileIn, temp);
		timeMIn = stoi(temp);
		items[numItems]->setTime(timeHIn,timeMIn);
		
		numItems++;
	}
}
favThingsList::~favThingsList()
{
	for (int i = 0; i < numItems; i++)
	{
		delete items[i];
	}
	delete [] items;
	//cout << "*all gone*"<<endl;
}

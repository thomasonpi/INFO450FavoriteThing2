#include <iostream>
#include <string>
#include <limits>
#include "favThings.h"
#include "favThingsList.h"
using namespace std;

ostream& operator<<(ostream &output, const FavThings &fav) // overload << to display FavThing
{
	output << "name: " << fav.name << endl;
	output << "___________________" << endl;
	output << "ingredients: " << fav.ingredients << endl;
	output << "___________________" << endl;
	output << "servings: " << fav.servings << "   ";
	output << "cost: " << fav.cost << "    ";
	output << "time: " << fav.timeH << ":" << fav.timeM << endl;
	return output;
}
FavThings::FavThings() // default constructor, set all to zero
{
	name = " ";
	ingredients = " ";
	servings = 0;
	cost = 0;
	timeH = 0;
	timeM = 0;
}
FavThings::FavThings(string nm, string in, int sv, double c, int tmH, int tmM) // full constructor
{
	name = nm;
	ingredients = in;
	servings = sv;
	cost = c;
	timeH = tmH;
	timeM = tmM;
}
string FavThings::getName()
{
	return name;
}
string FavThings::getIngredients()
{
	return  ingredients;
}
int FavThings::getServings()
{
	return  servings;
}
double FavThings::getCost()
{
	return cost;
}
int FavThings::getTimeH()
{
	return timeH;
}
int FavThings::getTimeM()
{
	return timeM;
}
void FavThings::setName(string nm)
{
	name = nm;
}
void FavThings::setIngredients(string in)
{
	ingredients = in;
}
void FavThings::setServings(int sv)
{
	servings = sv;
}
void FavThings::setCost(double c)
{
	cost = c;
}
void FavThings::setTime(int tmH, int tmM)
{
	timeH = tmH;
	timeM = tmM;
}
void FavThings::getFavInput() // gets all input
{
	cout << "enter recipe name: ";
	getline(cin, name);
	
	cout << "enter ingredients (seperate by comma, enter when done): ";
	getline(cin, ingredients);

	cout << "enter servings: ";
	cin >> servings;
	while (!cin || servings < 0)
	{
		cout << "please enter a positive number: "; 
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		//^ uses limits to get size of cin stream for ignore()
		cin >> servings;
	}

	cout << "enter cost: ";
	cin >> cost;
	while (!cin || cost < 0)
	{
		cout << "please enter a positive number: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> cost;
	}
	cout << "enter time (hours):" ;
	cin >> timeH;
	while (!cin || timeH < 0)
	{
		cout << "please enter a positive number: "; 
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> timeH;
	}

	cout << "enter time (minutes):";
	cin >> timeM;
	while (!cin || timeM < 0)
	{
		cout << "please enter a positive number: "; 
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> timeM;
	}

	cin.ignore();
}

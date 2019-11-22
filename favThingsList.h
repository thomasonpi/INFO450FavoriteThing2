#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "favThings.h"
using namespace std;

class favThingsList //wrapper class to handle list of objects
{
	private:
		FavThings **items;
		int numItems;
		int totalInventory;
	public:
		favThingsList();
		void addItem();
		void showList();
		void readFromFile();
		void writeToFile();
		~favThingsList();
};

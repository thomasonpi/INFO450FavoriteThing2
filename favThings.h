#pragma once
#include <iostream>
#include <string>
#include <limits>
using namespace std;


class FavThings 
{
	private:
		string name;
		string ingredients; 
		int servings;
		double cost;
		int timeH;
	       int timeM;	

	public:
		FavThings();
		FavThings(string nm, string in, int sv,double c,int tmH,int tmM);
		string getName();
		string getIngredients();
		int getServings();
		double getCost();
		int getTimeH();
		int getTimeM();
		void setName(string nm);
		void setIngredients(string in);
		void setServings(int sv);
		void setCost(double c);
		void setTime(int tmH, int tmM);
		void getFavInput();
		
	friend ostream& operator<<(ostream &output,const FavThings &fav);

};

#pragma once
#include <iostream>
#include <string>
#include "S_R_Poly.h"
#include "L_R_Poly.h"
#include "L_D_Poly.h"
#include "S_D_Poly.h"
#include <vector>
#include <algorithm>
using namespace std;

class Party
{
private:
	string name;
	Poly *head;
	vector<Poly *> polys_vec;
	int poly_num;
protected:
	void add_Poly(Poly* P);
public:
	Party(const string name);
	void primareis();///will chose head by strength (true if new head found, false else)//updates all polys with new head
	int get_pow_elections()const;///returns party strength at elections
	int get_pow()const; //party strength not elections
	int get_poly_num()const;
	string get_name()const; 
	Poly* get_Party_head()const { return this->head; };
	bool operator<(const Party& other)const;//compers by strngth
	bool operator==(const Party& other)const;//compers by name
	bool remove_poly(Poly* p);//get pointer to poly and removes it from poly_vec, poly_num--
	vector<Poly*> close_Party();//returns all polititians in party and delete party
	~Party();

	virtual bool insert_poly(Poly*) = 0; //char "D" or "R" will be implemented in demo/repo. will check add polly conditions

	//virtual ostream friend operator <<(ostream& out, Poly* p)=0;
};


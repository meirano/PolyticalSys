#pragma once

#include <iostream>
#include <string>

#include "Poly.h"
#include "Party.h"


class PoliticalSys
{

	vector<Poly *> polys_vector;
	vector<Party *> partys_vector;


public:

	PoliticalSys() : polys_vector(0, nullptr), partys_vector(0, nullptr) {};
	PoliticalSys(string file_path);
	bool addPolitician();
	bool addParty();
	bool removePolitician();
	bool removeParty();
	void printPoliticians();
	void printParties();


private:
	bool chack_inputs(string f_name, string l_name, int id, int power, string r_d, string leader_social);
	bool insert_to_arr_poly_party(string line);
	virtual ~PoliticalSys();
};


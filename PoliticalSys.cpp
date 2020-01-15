#include "PoliticalSys.h"
#include "L_D_Poly.h"
#include "S_D_Poly.h"
#include "L_R_Poly.h"
#include "S_R_Poly.h"

#include "D_party.h"
#include "R_party.h"

#include <string>
#include <sstream>
#include <fstream>
using namespace std;


PoliticalSys::PoliticalSys( string file_path ){

	ifstream infile(file_path);
	string line;
	string token;
	string delimiter = " ";
	size_t pos = 0;

	bool flag = true;
	while (getline(infile, line))
	{
		pos = line.find(delimiter);
		line.erase(0, pos + delimiter.length());

		while (getline(infile, line)) {
			while (line.find("Parties:") == string::npos && flag )
			{
				insert_to_arr_poly_party(line);
				getline(infile, line);
			}
			flag = false;
			line.erase(0, pos + delimiter.length());
			cout << line << endl;

		}


	}

}

bool PoliticalSys::insert_to_arr_poly_party( string line) {
	
	Poly* temp;

	string delimiter = " ";
	size_t pos = line.find(delimiter);
	size_t initialPos = 0;
	vector<std::string> temp_arr;
	temp_arr.clear();
	while (pos != std::string::npos) {

		temp_arr.push_back(line.substr(initialPos, pos - initialPos));
		initialPos = pos+1 ;
		pos = line.find(delimiter, initialPos);

	}
	temp_arr.push_back(line.substr(initialPos, min(pos, line.size()) - initialPos + 1));

	if (this->chack_inputs(temp_arr[0], temp_arr[1], stoi(temp_arr[2]), stoi(temp_arr[3]), temp_arr[4], temp_arr[5])) {
		
		if (temp_arr[4].compare("R") == 0 && temp_arr[5].compare("S") == 0) {
			temp = new S_R_Poly(temp_arr[0], temp_arr[1], stoi(temp_arr[2]), stoi(temp_arr[3]));
			this->polys_vector.push_back(temp);
			return true;
		}
		else if (temp_arr[4].compare("R") == 0 && temp_arr[5].compare("L") == 0) {
			temp = new L_R_Poly(temp_arr[0], temp_arr[1], stoi(temp_arr[2]), stoi(temp_arr[3]));
			this->polys_vector.push_back(temp);
			return true;
		}
		else if (temp_arr[4].compare("D") == 0 && temp_arr[5].compare("S") == 0) {
			temp = new S_D_Poly(temp_arr[0], temp_arr[1], stoi(temp_arr[2]), stoi(temp_arr[3]));
			this->polys_vector.push_back(temp);
			return true;
		}
		else if (temp_arr[4].compare("D") == 0 && temp_arr[5].compare("L") == 0) {
			temp = new L_D_Poly(temp_arr[0], temp_arr[1], stoi(temp_arr[2]), stoi(temp_arr[3]));
			this->polys_vector.push_back(temp);
			return true;
		}

		
	}
	else {
		cout << "there is prablom..." << endl;
	}
	return false;
}

bool PoliticalSys::addPolitician()
{
	string f_name;
	string l_name;
	int id;
	int power;
	string r_d;
	string leader_social;

	Poly* p;

	cout << "---Creat politician---" << endl;
	cout << "First name:"<< endl;
	cin >> f_name;

	cout << "Last name:" << endl;
	cin >> l_name;

	cout << "ID:" << endl;
	cin >> id;

	cout << "Power:" << endl;
	cin >> power;

	cout << "Repoblican or Democrate person:" << endl;
	cin >> r_d;

	cout << "Leader or Social:" << endl;
	cin >> leader_social;

	if (this->chack_inputs(f_name, l_name, id, power, r_d, leader_social)) {
		if (r_d.compare("R") == 0 && leader_social.compare("S") == 0) {
			p = new S_R_Poly(f_name, l_name, id, power);
			p->print_poly();
			this->polys_vector.push_back(p);
		}
		
		else if (r_d.compare("R") == 0 && leader_social.compare("L") == 0) {
			p = new L_R_Poly(f_name, l_name, id, power);
			this->polys_vector.push_back(p);
			return true;
		}
		else if (r_d.compare("D") == 0 && leader_social.compare("S") == 0) {
			p = new S_D_Poly(f_name, l_name, id, power);
			this->polys_vector.push_back(p);
			return true;
		}
		else if (r_d.compare("D") == 0 && leader_social.compare("L") == 0) {
			p = new L_D_Poly(f_name, l_name, id, power);
			this->polys_vector.push_back(p);
			return true;
		}

		return true;
	}
	else {
		cout << "there is prablom..." << endl;
		return false;
	}


}

void PoliticalSys::printPoliticians() {
	vector<Poly*>::const_iterator  it;
	this->polys_vector;
	for (it = this->polys_vector.begin(); it != this->polys_vector.end(); it++) {
		(*it)->print_poly();
	}
}

void PoliticalSys::printParties() {
	vector<Party*>::const_iterator  it;
	this->polys_vector;
	for (it = this->partys_vector.begin(); it != this->partys_vector.end(); it++) {
		cout << "---Party---" << endl;
	}
}


bool PoliticalSys::addParty() {

	string p_name;
	string p_type;

	Party* temp;

	cout << "---Creat Party---" << endl;
	cout << "Name:" << endl;
	cin >> p_name;
	cout << "Republican or Democratic:" << endl;
	cin >> p_type;

	if (this->chack_inputs(p_name, NULL, NULL, NULL, p_type, NULL)) {
		if (p_type.compare("R")) {
			cout << "Republican" << endl;

		}
		else {
			cout << "Democratic:" << endl;
		}
		return true;

	}
	cout << "prablom" << endl;
	return false;
}

bool PoliticalSys::removePolitician() {
	int id;

	cout << "---Remove Politycian---" << endl;
	cout << "Enter the ID:" << endl;
	cin >> id;

	if (this->chack_inputs(NULL, NULL, id, NULL, NULL, NULL)) {
		vector<Poly*>::const_iterator  it;
		for (it = this->polys_vector.begin(); it != this->polys_vector.end(); it++) {
			if ((*it)->get_id() == id) {
				cout << "erase: " << (*it)->get_first_name() << endl;
				this->polys_vector.erase(it);
				break;
			}
		}

		vector<Party*>::const_iterator  it2;
		for (it2 = this->partys_vector.begin(); it2 != this->partys_vector.end(); it2++) {
			while ( !(*it2)->remove_poly(*it))
			{
				cout << "it erase" << endl;
				return true;
			} 

		}
		cout << "prablom" << endl;
		return false;

	}
	cout << "prablom" << endl;
	return false;
}


bool PoliticalSys::removeParty() {

	string p_name;
	vector<Poly*> arr;


	cout << "---Remove Party---" << endl;
	cout << "Enter party name:" << endl;
	cin >> p_name;

	vector<Party*>::const_iterator  it;
	for (it = this->partys_vector.begin(); it != this->partys_vector.end(); it++) {
		if ((*it)->get_name().compare(p_name) == 0) {
			arr = (*it)->close_Party();
			// hare it will take arr and spread it in other partys 
			return true;
		}
	}

	return false;




}

bool PoliticalSys::chack_inputs(string f_name, string l_name, int id, int power, string r_d, string leader_social) {
	
	vector<Poly*>::iterator it;
	for (it = this->polys_vector.begin(); it != this->polys_vector.end(); it++) {
		if (id>0 && id !=(int)id) return false;
		if ((*it)->get_id() == id) return false;
		if (power > 0 && power != (int)power) return false;
		if (r_d.compare("R") != 0) {
			if (r_d.compare("D") != 0){
			return false;
			}
		}
		if (leader_social.compare("S") != 0) {
			if (leader_social.compare("L") != 0) {
				return false;
			}
		}
	}
	return true;
}

PoliticalSys::~PoliticalSys()
{
}

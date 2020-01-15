#include <string>
#include "Party.h"

Party::Party(const string name) {
	this->name = name;
	head = new S_D_Poly();
	poly_num = 0;
}



void Party::add_Poly(Poly* P) {
	this->polys_vec.push_back(P);
	this->poly_num++;
}

int Party::get_poly_num() const{
	return this->poly_num;
}


string Party::get_name()const {
	return this->name;
}


void Party::primareis() {
	//delete old head if was null
	if (this->head->get_first_name() == string("None"))
		this->head->~Poly();

	Poly* new_head = NULL;
	int max_pow = -1;

	vector<Poly*>::iterator it;
	it = this->polys_vec.begin();
	//find strongest leader (social polyticians will return pow=-1)
	while (it != this->polys_vec.end())
	{
		if ((*it)->get_pow_primeirs() > max_pow) {
			new_head = *it;
		}
		it++;
	}
	
	//no new head
	if (new_head == NULL)
		new_head = new S_D_Poly(); //randome poly type - just to get defoult settings
	// set new head
	else {
	
		this->head = new_head;
	}
	

	//update party members
	it = this->polys_vec.begin();
	while (it != this->polys_vec.end())
	{
		(*it)->set_party_head(new_head);
		it++;
	}
	

	//print announcement
	cout << new_head->get_first_name() << " is the chairman of " << this->name << endl;

}


	int Party::get_pow_elections() const {
		int i;
		int pow = 0;
		for (i = 0; i < this->get_poly_num();++i) {
			pow += this->polys_vec[i]->get_pow_elections();
		}
		return pow;
	}


	int Party::get_pow() const {
		int i;
		int pow = 0;
		for (i = 0; i < this->get_poly_num();++i) {
			pow += this->polys_vec[i]->get_pow();
		}
		return pow;
	}

	bool Party::operator<(const Party& other)const {
		if(this->get_pow() < other.get_pow())
			return true;
		return false;
	}

	bool Party::operator==(const Party& other)const {
		return this->get_name() == other.get_name();	
	}

	bool Party::remove_poly(Poly* p) {
		bool Poly_removed = false;
		vector<Poly*>::iterator it;
		it = this->polys_vec.begin();
		while (it != this->polys_vec.end())
		{
			if (p->get_id() == (*it)->get_id()) {
				this->polys_vec.erase(it);
				Poly_removed = true;
				break;
			}
			it++;
		}
		return Poly_removed;
	}

	vector<Poly*> Party::close_Party() {
		vector<Poly*> new_vec;
		copy(this->polys_vec.begin(), this->polys_vec.end(), back_inserter(new_vec));
		this->~Party();
		return new_vec;
	}

	Party::~Party() {
		this->polys_vec.~vector();
		if (this->head->get_first_name() == string("None"))
			this->head->~Poly();
	}


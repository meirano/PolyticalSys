
#include "Poly.h"
Poly::Poly() {
	this->first_name ="None";
	this->party_head = this;

}


Poly::Poly(const string first_name, const string last_name, const int ID, const int power)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->ID = ID;
	this->power = power;
}



bool Poly::operator==(const Poly& other)const
{
	if (this->get_id() == other.get_id()) {
		return true;
	}
	else
	{
		return false;
	}
}
void Poly::set_party_head(Poly* other)
{
	this->party_head = other;
}

void Poly::leav_party()
{
	this->party_name = nullptr;
	this->party_head = nullptr;
}

string Poly::get_party_head()const///////////////////////////////////////////////////////////////////check if helpful
{
	if (this->party_head) return this->party_head->get_first_name();
	return "NULL";
}


Poly::~Poly()
{
}
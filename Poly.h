#pragma once
#include <string>
#include <iostream>
using namespace std;

class Poly
{
private:
	string first_name;
	string last_name;
	int ID;
	int power;
	string party_name;
	Poly* party_head;

public:
	Poly();
	Poly(const string first_name, const string last_name, const int ID, const int power);


	int get_id()const { return this->ID; };
	int get_pow()const { return this->power; };
	string get_first_name()const {  return this->first_name; };
	string get_last_name()const { return this->last_name; };

	string get_Party()const { return this->party_name; };
	string get_party_head()const;

	bool operator==(const Poly& other)const;//compers by ID
	void set_party_head(Poly* poly);
	void set_party_name(string name) { this->party_name = name; };
	void leav_party();

	virtual int get_pow_elections() const = 0;
	virtual int get_pow_primeirs() const = 0;//for social will return -1 for leader will return power
	virtual bool can_join_d_party() const = 0;
	virtual bool can_join_r_party() const= 0;
	virtual void print_poly()const = 0;

	virtual ~Poly();





};


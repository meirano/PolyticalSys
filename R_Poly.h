#pragma once
#include "Poly.h"
class R_Poly :
	public Poly
{
public:
	R_Poly() :Poly() {};
	R_Poly(const string first_name, const string last_name, const int ID, const int power) : Poly(first_name, last_name, ID, power) {};
	virtual bool can_join_d_party() const{ return false; };
	virtual bool can_join_r_party() const { return true; };

	virtual int get_pow_elections() const = 0;
	virtual int get_pow_primeirs() const = 0;//for social will return -1 for leader will return power
	virtual void print_poly()const = 0;

	virtual ~R_Poly() {};
};


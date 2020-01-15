#pragma once
#include "R_Poly.h"
class S_R_Poly :
	public R_Poly
{
public:

	S_R_Poly() : R_Poly() {};
	S_R_Poly(string f_name, string l_name, int id, int power) : R_Poly(f_name, l_name, id, power) {};
	int get_pow_elections()const { return this->get_pow(); };
	int get_pow_primeirs()const { return this->get_pow(); };
	void print_poly()const;
	virtual ~S_R_Poly() {};
};


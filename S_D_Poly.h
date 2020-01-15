#pragma once
#include "D_Poly.h"
class S_D_Poly :
	public D_Poly
{
public:
	S_D_Poly() : D_Poly() {};
	S_D_Poly(S_D_Poly& other) : D_Poly(other) {};
	S_D_Poly(string f_name, string l_name, int id, int power) : D_Poly(f_name, l_name, id, power) {};
	virtual int get_pow_elections()const { return 2*this->get_pow(); };//pow*2
	virtual int get_pow_primeirs()const { return -1; };
	virtual void print_poly()const;
	virtual ~S_D_Poly() {};
};


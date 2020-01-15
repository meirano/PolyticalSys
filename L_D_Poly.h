
#ifndef L_D_POLY_H_
#define L_D_POLY_H_
#include "D_poly.h"

class L_D_Poly : public D_Poly {

public:
	L_D_Poly() : D_Poly() {};
	L_D_Poly(string f_name, string l_name, int id, int power) : D_Poly(f_name, l_name, id, power) {};
	int get_pow_elections()const { return this->get_pow(); };
	int get_pow_primeirs()const { return this->get_pow(); };
	void print_poly()const;
	virtual ~L_D_Poly() {};
};



#endif /* L_D_POLY_H_ */

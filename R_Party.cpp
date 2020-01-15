#include "R_Party.h"
bool R_Party::insert_poly(Poly* P) {
	if (!P->can_join_r_party())
		return false;

	else
		this->add_Poly(P);
	return true;

}
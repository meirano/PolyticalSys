#include "D_Party.h"

bool D_Party::insert_poly(Poly* P) {
	
	if (!(P->can_join_d_party()))
		return false;

	else {
		this->add_Poly(P);
		P->set_party_name(this->get_name());
		P->set_party_head(this->get_Party_head());
	}
		
	return true;
}
#include "S_R_Poly.h"

void S_R_Poly::print_poly()const
{
	std::cout << "Republican person: " << this->get_first_name() << " " << this->get_last_name() << ", Id:" << this->get_id() << ", Power:" << this->get_pow() << ", Type:S Chairman: " << this->get_party_head() << std::endl;
}


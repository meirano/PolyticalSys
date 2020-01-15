#include "L_D_Poly.h"

void L_D_Poly::print_poly()const
{
	std::cout << "Democrat person: " << this->get_first_name() << " " << this->get_last_name() << ", Id:" << this->get_id() << ", Power:" << this->get_pow() << ", Type:L Chairman" << this->get_party_head() << std::endl;
}
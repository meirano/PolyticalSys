#include "S_D_Poly.h"
void S_D_Poly::print_poly()const
{
	std::cout << "Democrat person: " << this->get_first_name() << " " << this->get_last_name() << ", Id:" << this->get_id() << ", Power:" << this->get_pow() << ", Type:S Chairman" << this->get_party_head() << std::endl;
}
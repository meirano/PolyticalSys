#pragma once
#include "Party.h"
class R_Party :
	public Party
{
	R_Party(string name) : Party(name) {};
	virtual bool insert_poly(Poly* P);
};


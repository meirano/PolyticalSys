#pragma once
#include "Party.h"
class D_Party : public Party
{
public:
	D_Party(string name) :Party(name) {};
	virtual bool insert_poly(Poly* P);
};


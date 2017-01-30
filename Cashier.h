#ifndef CASHIER_H_INCLUDED
#define CASHIER_H_INCLUDED

#include "Simulation.h"
#include <odemx/odemx.h>

namespace Checkout{
	//forward declaration
	class Register;
	
	class Cashier
	: public odemx::base::Process{
	odemx::random::NegativeExponential payAndBagDist;
		
		Register& lane;
		
		public:
		Cashier(Simulation& sim, Register& lane, const double payAndBagTime);
		
		virtual int main();
		
	};
}

#endif
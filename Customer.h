
#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#include "Simulation.h"
#include "Register.h"

namespace Checkout{
	class Register;
	class Customer
	: public odemx::base::Process{
		public:
		//Constructor
		Customer(Simulation& sim);
		
		protected:
		
		//the customer will select a lane based on the implementation of "selectLane"
		virtual Register& selectLane();
		
		virtual int main();
	};
}

#endif
#ifndef CUSTOMERGENERATOR_H_INCLUDED
#define CUSTOMERGENERATOR_H_INCLUDED

#include <odemx/odemx.h>

namespace Checkout{
	//forward declaration
	struct Simulation;
	
	class CustomerGenerator
	: public odemx::base::Process{
		odemx::random::NegativeExponential arrivalDistOne;
		odemx::random::NegativeExponential arrivalDistTwo;
		
		public:
		odemx::statistics::Count customers;
			
			CustomerGenerator(Simulation& sim,
			double arrivalRateOne,
			double arrivalRateTwo
			);
			
			//A customer's behaviour. odemx::base::Process has its own main() function which must be overwritten
			virtual int main();
	};
}

#endif
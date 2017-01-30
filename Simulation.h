#ifndef SIMULATION_H_INCLUDED
#define SIMULATION_H_INCLUDED

#include <odemx/odemx.h>
#include <iostream>
#include <vector>

#include "CustomerGenerator.h"
#include "Register.h"
#include "Customer.h"
#include "Cashier.h"

namespace Checkout{
	
	//forward declaration
	class Register;
	
	struct Simulation
		/*inherits*/: odemx::base::Simulation{
			//stats
			odemx::data::output::OStreamReport report;
			
			std::shared_ptr<odemx::data::buffer::StatisticsBuffer> statistics;
			
			odemx::statistics::Tally handlingTime;
			
			odemx::statistics::Sum idleTime;
			
			//a vector including all the registers
			std::vector<Register*> lanes;
			
			
			//CustomerGenerator
			CustomerGenerator arrivals;
			
			//SimulationConstruction
			Simulation(
				unsigned int registerCount,
				double arrivalRateOne,
				double arrivalRateTwo,
				double payAndBagTime
			);
			
			//run the simulation
			void initSimulation();
		};
	
}

#endif
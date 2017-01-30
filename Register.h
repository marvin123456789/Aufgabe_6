#ifndef REGISTER_H_INCLUDED
#define REGISTER_H_INCLUDED

#include <memory>
#include <odemx/odemx.h>
#include "Simulation.h"
#include "Cashier.h"
#include "Customer.h"
#include "CustomerGenerator.h"

namespace Checkout{
	class Cashier;
	class Customer;
	class Register{
		odemx::synchronization::WaitQ queue;
		int id;
		
		public:
		Cashier& cashier;
		Register(Simulation& sim);
		
		int getQueueLength() {return queue.getWaitingSlaves().size();}
		
		Customer* take();
		void pay();
		int getID(){return id;}
	};
}

#endif
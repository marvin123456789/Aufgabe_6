#include "Cashier.h"

Checkout::Cashier::Cashier(Simulation& sim, Register& lane, const double payAndBagTime)
:Process(sim, "Cashier"),
lane(lane),
payAndBagDist(sim, "Total Serving Time", payAndBagTime){}

int Checkout::Cashier::main(){
	std::cout<<"Cashier main() called\n"<<std::endl;
	odemx::base::SimTime start = getTime();
	Simulation& sim = static_cast<Simulation&>(getSimulation());
	int i = lane.getQueueLength();
	std::cout<<"in Cashier::main() the queue length is: "<<i<<"\n";
	Customer* c = lane.take();
	std::cout<<"Took a customer from lane"<<std::endl;
	holdFor(payAndBagDist.sample());
	sim.handlingTime.update(getTime()-start);
	c->activate();
	
	return 0;
}
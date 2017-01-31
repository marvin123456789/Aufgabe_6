#include "Cashier.h"

Checkout::Cashier::Cashier(Simulation& sim, Register& lane, const double payAndBagTime)
:Process(sim, "Cashier"),
lane(lane),
payAndBagDist(sim, "Total Serving Time", payAndBagTime){}

int Checkout::Cashier::main(){
	while(true){
	odemx::base::SimTime start = getTime();
	Simulation& sim = static_cast<Simulation&>(getSimulation());
	int i = lane.getQueueLength();
	Customer* c = lane.take();
	holdFor(payAndBagDist.sample());
	sim.handlingTime.update(getTime()-start);
	c->activate();
	}
	
	return 0;
}
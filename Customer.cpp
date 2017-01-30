#include "Customer.h"

Checkout::Customer::Customer(Simulation& sim)
:Process(sim, "Customer"){}


Checkout::Register&
Checkout::Customer::selectLane(){
	Simulation &sim = static_cast<Simulation&>(getSimulation());
	Register* best = nullptr;
	unsigned int custCount = -1;
	
	for (Register* reg: sim.lanes){
		if (custCount > reg->getQueueLength()){
			custCount = reg->getQueueLength();
			best = reg;
		}
	}
	std::cout<<"There's "<<custCount<<" people waiting here\n";
	return *best;
}

int Checkout::Customer::main(){
	Simulation& sim = static_cast<Simulation&>(getSimulation());
	Register& lane = selectLane();
	std::cout<< "This lane's ID is: "<<lane.getID()<<std::endl;
	lane.pay();
	return 0;
}
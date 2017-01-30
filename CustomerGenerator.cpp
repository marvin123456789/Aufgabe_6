#include "Simulation.h"

Checkout::CustomerGenerator::CustomerGenerator(Simulation& sim,
double arrivalRateOne,
double arrivalRateTwo
)
:Process(sim, "CustomerGenerator"),
arrivalDistOne(sim, "ArrivalRate1", arrivalRateOne),
arrivalDistTwo(sim, "ArrivalRate2", arrivalRateTwo),
customers(sim, "Customer Count"){
	sim.report.addReportProducer(customers);
}

int Checkout::CustomerGenerator::main(){
	//time left until a new wave one Customer gets generated
	unsigned int waitTimeOne = arrivalDistOne.sample();
	//time left until a new wave two Customer gets generated
	unsigned int waitTimeTwo = arrivalDistTwo.sample();
	
	//pointer to a customer
	Customer* customer;
	
	//run forever..And ever
	while(true){
		//create a new customer whenever waitTimeOne or waitTimeTwo is up
		holdFor(std::min(waitTimeOne, waitTimeTwo));
		//if a wave one customer was created, reduce the time it takes for a wave two customer to arrive by that time
		if(waitTimeOne <= waitTimeTwo){
			waitTimeTwo -= waitTimeOne;
			//wait for the next wave one customer
			waitTimeOne = arrivalDistOne.sample();
		}
		//if a wave two customer was created, reduce the time it takes for a wave two customer to arrive by that time
		else{
			waitTimeOne -= waitTimeTwo;
			//wait for the next wave two customer
			waitTimeTwo = arrivalDistTwo.sample();
		}
		
		customer = new Customer(static_cast<Simulation&>(getSimulation()));
		customers.update();
		customer->activate();
	}
	return 0;
}
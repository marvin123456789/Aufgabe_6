#include "Simulation.h"

Checkout::Simulation::Simulation(unsigned int registerCount,
double arrivalRateOne,
double arrivalRateTwo,
double payAndBag)
:odemx::base::Simulation("CheckoutSim"),
report(std::cout),
statistics(odemx::data::buffer::StatisticsBuffer::create(*this, "Buffer")),
handlingTime(*this, "HandlingTime"),
idleTime(*this, "idleTime"),
//could also have been done by going "CustomerGenerator(parameters)" in "run()"-method
arrivals(*this, arrivalRateOne, arrivalRateTwo){
	report.addReportProducer(handlingTime);
	report.addReportProducer(idleTime);
	
	//create registers
	for(unsigned int i = 0; i < registerCount; i++){
		lanes.push_back(new Register(*this,i));
	}
}

void Checkout::Simulation::initSimulation(){
	addConsumer(statistics);
	arrivals.activate();
	
	for (Register* reg: lanes){
		reg->cashier.activate();
	}
}
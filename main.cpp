#include "Simulation.h"

const int runtime = 12/*h*/ * 60/*min*/ * 60/*sec*/;

unsigned int registerCount = 3;

static const double arrivalRateOne = 1/240.0;
static const double arrivalRateTwo = 1/720.0;
static const double payAndBag = 6.5/*min*/ * 60 /*sec*/;

int main(){
	Checkout::Simulation sim(
	registerCount,
	arrivalRateOne,
	arrivalRateTwo,
	payAndBag
	);
	
	sim.runUntil(runtime);
	sim.report.generateReport();
	
	return 0;
}
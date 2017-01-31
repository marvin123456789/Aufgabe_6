#include "Register.h"


Checkout::Register::Register(Simulation& sim, int id)
:queue(sim, "Register queue"),
cashier(sim, *this, 6.5/*min*/ * 60 /*s*/),
id(id){}


Checkout::Customer* Checkout::Register::take(){
			Process* p = nullptr;
			p = queue.coopt();
			return (Customer*) p;
		}
		
void Checkout::Register::pay(){
	queue.wait();
}
#include "Register.h"


Checkout::Register::Register(Simulation& sim)
:queue(sim, "Register queue"),
cashier(sim, *this, 6.5){}


Checkout::Customer* Checkout::Register::take(){
			Process* p = nullptr;
			p = queue.coopt();
			return (Customer*) p;
		}
		
void Checkout::Register::pay(){
	queue.wait();
}
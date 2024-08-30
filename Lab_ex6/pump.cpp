#include "pump.h"

//Implementation file for pump.h
//Contains base class Pump and derived classes GasPump, FillPump
//Dhanan Thannoo

Pump::Pump() 
//default constructor of Pump class
{
	cout << "Enter a gas capacity: ";
	cin >> tankCapacity;
	cout << "Enter a gas amount: ";
	cin >> amtGasTank;
}

Pump::Pump(int newGasAmt, int newCapacity)
//non-default constructor of the pump class
//Validates the parameters
{
	amtGasTank = newGasAmt < 0 ? 0 : newGasAmt;
	tankCapacity = newCapacity < 100 ? 100 : newCapacity;
}

void Pump::pumpGas(int gasPumped)
//reduces an amount of gas from the gas tank
//Validates the parameter
{
	amtGasTank = gasPumped > amtGasTank ? 0 : amtGasTank - gasPumped;
}

GasPump::GasPump() :Pump()
//default constructor of the GasPump class, calls the base default constructor
{
	typeGas = new string();
	assert(typeGas);
	cout << "Enter a gasType: ";
	cin.ignore(80, '\n');
	getline(cin, *typeGas);

	cout << "Enter a gas price: ";
	cin >> gasPrice;
}

GasPump::GasPump(int newGasAmt, int newCapacity,
	string newType, double newPrice) :
	Pump(newGasAmt, newCapacity)
	//non-defaut constructor of the GasPump class,
	//calls the non-default base constructor
	//Validates the parameters
{
	typeGas = new string(newType == "" ? "NO NAME" : newType);
	assert(typeGas);
	gasPrice = newPrice < 0.0 ? 0.0 : newPrice;
}

GasPump::~GasPump() 
//destructor removes allocated memory that was used for typeGas
{
	delete typeGas;
}

void GasPump::buyGas(int gasAmt) 
//Buys gas from the pump, reduces the gas in the tank and
//outputs a receipt for the gas. Also outputs how much gas is left.
{
	string liter;
	int pumpedGas = gasAmt > amtGasTank ? amtGasTank : gasAmt;
	pumpGas(gasAmt);
	double spent = pumpedGas * gasPrice;
	cout << "You pumped " << pumpedGas << " liters" << endl
		<< "It cost $" << spent << endl
		<< "There is " << amtGasTank <<
		(amtGasTank == 1 ? "liter" : "liters") << " left." << endl;
}

//a nessecary implementation of the FillTank default constructor
FillTank::FillTank() :Pump()
{}

//a nessecary implementation of the FillTank non-default constructor
FillTank::FillTank(int newGasAmt, int newTankCapacity) :
	Pump(newGasAmt, newTankCapacity) 
{}

void FillTank::addGas() 
//prompts the user for an amount of gas to add back to the
//pump. Does not allow to fill over capacity.
{
	int gasToFill;
	cout << "enter an amount of gas to fill: ";
	cin >> gasToFill;
	amtGasTank = gasToFill + amtGasTank > tankCapacity ?
		tankCapacity : amtGasTank + gasToFill;
}

void Pump::showPump(ostream& out) const
//Simple function that outputs all members of the Pump class
{
	out << "This pump has the following members:" << endl;
	out << "Contains: " << getAmtGas() << " gallons" << endl;
	out << "Has " << getCapacity() << " gallons capacity" << endl;
}

void GasPump::showPump(ostream& out) const
//Simple function that outputs all members of the GasPump class
//and member of the base class
{
	Pump::showPump(out);
	out << "The gas type is " << getGasType() << endl;
	out << "The price per gallon is $" << getPrice() << endl;
}

void FillTank::showPump(ostream& out) const
//Simple show function that outputs all members of the FillTank class
//FillTank has no unique members
{
	Pump::showPump(out);
}
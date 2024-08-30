#include <iomanip>
#include "pump.h"

//client code using pump.h
//tests the functionality of the classes inside pump.h
//Dhanan Thannoo

void showPump(const Pump* somePump) {
	somePump->showPump(cout);
}


int main()
{
	cout << fixed << setprecision(2);

	cout << endl << endl << "For slcTank (non default Pump) " << endl;
	Pump* slcTank = new Pump(100, 90);
	assert(slcTank);
	cout << "Amt= " << slcTank->getAmtGas() << endl;
	cout << "Capacity=" << slcTank->getCapacity() << endl << endl;
	slcTank->pumpGas(10);  //remove gas from tank
	slcTank->pumpGas(200);  //attempt to remove more gas than in tank
	cout << "Call polymorphic function:\n ";
	showPump(slcTank);

	cout << endl << endl;
	delete slcTank;

	Pump* slcPump = new Pump;
	assert(slcPump != NULL);
	cout << "For slcPump (default Pump): " << endl;
	slcPump->showPump(cout);
	cout << "Call polymorphic function:\n ";
	showPump(slcPump);

	cout << endl << endl;
	delete slcPump;


	cout << endl << endl << "For slcGas (non default GasPump) " << endl;
	GasPump* slcGas = new GasPump(100, 90, "unleaded", 1.50);
	assert(slcGas);
	slcGas->showPump(cout);
	slcGas->buyGas(10);  //customer buys gas 
	slcGas->buyGas(200);  //customer tries to buy more gas than in tank
	cout << "Call polymorphic function:\n ";
	showPump(slcGas);

	cout << endl << endl;

	delete slcGas;

	cout << endl << endl << "For slcFuel (default GasPump) " << endl;
	GasPump* slcFuel = new GasPump;
	assert(slcFuel);
	cout << "Amt= " << slcFuel->getAmtGas() << endl;
	cout << "Capacity=" << slcFuel->getCapacity() << endl;
	cout << "type=" << slcFuel->getGasType() << endl;
	cout << "Price= $" << slcFuel->getPrice() << endl << endl;
	cout << "Call polymorphic function:\n ";
	showPump(slcFuel);

	cout << endl << endl;


	delete slcFuel;

	cout << endl << endl << "For slcStore (non default FillTank) " << endl;
	FillTank* slcStore = new FillTank(-1, -1);
	assert(slcStore);
	cout << "Amt= " << slcStore->getAmtGas() << endl;
	cout << "Capacity=" << slcStore->getCapacity() << endl << endl;
	cout << "Call polymorphic function:\n ";
	showPump(slcStore);

	cout << endl << endl;
	delete slcStore;

	cout << endl << endl << "For slcStore (default FillTank) " << endl;
	FillTank* slcTanker = new FillTank;
	assert(slcTanker != NULL);
	cout << "Amt= " << slcTanker->getAmtGas() << endl;
	cout << "Capacity=" << slcTanker->getCapacity() << endl;
	cout << "add 10 litres of gas (when asked) ";
	slcTanker->addGas();				//add gas to the station's holding tank
	cout << "Amt of gas remaining= " << slcTanker->getAmtGas() << endl;
	cout << "add more than the capacity, when asked ";
	slcTanker->addGas();                //try to add more gas than capacity
	cout << "Amt of gas (should be full) = " << slcTanker->getAmtGas() << endl;
	cout << "Call polymorphic function:\n ";
	showPump(slcTanker);

	cout << endl << endl;
	delete slcTanker;

	system("pause");

}

/*Output Testing
For slcTank (non default Pump)
Amt= 100
Capacity=100

Call polymorphic function:
 This pump has the following members:
Contains: 0 gallons
Has 100 gallons capacity


In pump defaultconstructor delete whendone
Enter a gas capacity: 100
Enter a gas amount: 50
For slcPump (default Pump):
This pump has the following members:
Contains: 50 gallons
Has 100 gallons capacity
Call polymorphic function:
 This pump has the following members:
Contains: 50 gallons
Has 100 gallons capacity




For slcGas (non default GasPump)
This pump has the following members:
Contains: 100 gallons
Has 100 gallons capacity
The gas type is unleaded
The price per gallon is $1.50
You pumped 10 liters
It cost $15.00
There is 90liters left.
You pumped 90 liters
It cost $135.00
There is 0liters left.
Call polymorphic function:
 This pump has the following members:
Contains: 0 gallons
Has 100 gallons capacity
The gas type is unleaded
The price per gallon is $1.50




For slcFuel (default GasPump)
In pump defaultconstructor delete whendone
Enter a gas capacity: 600
Enter a gas amount: 420
Enter a gasType: premium
Enter a gas price: 8.89
Amt= 420
Capacity=600
type=premium
Price= $8.89

Call polymorphic function:
 This pump has the following members:
Contains: 420 gallons
Has 600 gallons capacity
The gas type is premium
The price per gallon is $8.89




For slcStore (non default FillTank)
Amt= 0
Capacity=100

Call polymorphic function:
 This pump has the following members:
Contains: 0 gallons
Has 100 gallons capacity




For slcStore (default FillTank)
In pump defaultconstructor delete whendone
Enter a gas capacity: 1000
Enter a gas amount: 666
Amt= 666
Capacity=1000
add 10 litres of gas (when asked) enter an amount of gas to fill: 10
Amt of gas remaining= 676
add more than the capacity, when asked enter an amount of gas to fill: 5000
Amt of gas (should be full) = 1000
Call polymorphic function:
 This pump has the following members:
Contains: 1000 gallons
Has 1000 gallons capacity


Press any key to continue . . .
*/
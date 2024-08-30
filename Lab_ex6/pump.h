#include <iostream>
#include <cassert>
#include <string>

//The specification file for the pump class
//This file has multiple classes
//Dhanan Thannoo
using namespace std;

class Pump {
protected:
	int amtGasTank;
	int tankCapacity;
public:
	Pump();
	Pump(int/*amtGasTank*/, int/*tankCapacity*/);
	virtual void showPump(ostream& /*output stream*/) const;
	void pumpGas(int/*amtGasTank*/);
	int getAmtGas() const { return amtGasTank; }
	int getCapacity() const { return tankCapacity; }
};


class GasPump : public Pump {
private:
	string* typeGas;
	double gasPrice;
public:
	GasPump();
	GasPump(int/*atmGasTank*/, int/*tankCapacity*/, string /*typeGas*/,
		double/*gasPrice*/);
	~GasPump();
	void showPump(ostream& /*output stream*/)const;
	void buyGas(int/*gasAmount*/);
	double getPrice() const { return gasPrice; }
	string getGasType() const { return *typeGas; }
};


class FillTank : public Pump {
public:
	FillTank();
	FillTank(int /*atmGasTank*/, int /*tankCapacity*/);
	void addGas();
	void showPump(ostream&/*output stream*/) const;
};
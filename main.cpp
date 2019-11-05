#include <iostream>
#include <simlib.h>
#include <map>

#define MONTHLY_ENERGY_CONSUMPTION 3090


Facility NewMonth("new month");
Facility ConsumeEnergy("new month");
Store MonthlyConsumption("", MONTHLY_ENERGY_CONSUMPTION);
int ConsumedSolarEnergy = 0;
int ConsumedfosilEnergy = 0;
int EnergyWaste = 0;
Queue SolarSourceQ;

class SolarConsumption : public Process {

	void Behavior()
	{
	}

};

class FosilConsumption : public Process {

	void Behavior()
	{
	}

};

class Consumption : public Process {

	void Behavior()
	{
		Enter(MonthlyConsumption, 1);
		Entity *item;
		if (!SolarSourceQ.Empty())
		{
			item = SolarSourceQ.GetFirst(); //remove 1
			(new SolarConsumption)->Activate();
			ConsumedSolarEnergy++;
		}
		else
		{
			(new FosilConsumption)->Activate();
			ConsumedfosilEnergy++;
		}
		if (MonthlyConsumption.Full())
		{
			while (!SolarSourceQ.Empty())
			{
				EnergyWaste++;
				item = SolarSourceQ.GetFirst(); //remove 1
			}
			Leave(MonthlyConsumption, MONTHLY_ENERGY_CONSUMPTION);
		}
	}

};

class NewMonthIndicator : public Process {

	void Behavior()
	{
		if (NewMonth.Busy())
		{
			Release(NewMonth);
		}
		else
		{
			Seize(NewMonth);
		}
	}

};

class SolarSource : public Process {

	void Behavior()
	{
	}

};

class SolarPowerGenerator : public Event {

	enum Months {
		January,
		February,
		March,
		April,
		May,
		June,
		July,
		August,
		Septembre,
		Octobre,
		Novembre,
		Decembre
	};

	std::map<Months, unsigned > monthlyConsumption {
			{January, 372},
			{February, 1124},
			{March,  2699},
			{April,  3708},
			{May,    6179},
			 {June,   7177},
			 {July,   7689},
			 {August, 6012},
			 {Septembre, 4182},
			 {Octobre, 1915},
			 {Novembre, 584},
			 {Decembre, 167}
	};

	Months getNextMonth()
	{
		static Months actualMonth = January;
		actualMonth = Months((actualMonth + 1) % (Decembre + 1));
		return actualMonth;
	}

	void Behavior()
	{
		Months month = getNextMonth();

		for (unsigned i = 0; i < monthlyConsumption[month]; ++i)
		{
			SolarSourceQ.Insert(new SolarSource);
		}
		for (unsigned i = 0; i < MONTHLY_ENERGY_CONSUMPTION; ++i)
		{
			(new Consumption)->Activate();
		}
		Activate(Time + 1);
	}
};

int main(int argc, char **argv)
{
	Init(1, 12);
	(new SolarPowerGenerator)->Activate();
	Run();

	std::cout << "Consumed fosil energy: " << ConsumedfosilEnergy*.1 << "\n";
	std::cout << "Consumed solar energy: " << ConsumedSolarEnergy*.1 << "\n";
	std::cout << "Wasted solar energy  : " << EnergyWaste*.1 << "\n";
	std::cout << "Consumed total       : " << (ConsumedSolarEnergy + ConsumedfosilEnergy)*.1 << "\n";

	return 0;
}

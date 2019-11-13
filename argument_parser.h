//
// Created by juraj on 07/11/2019.
//

#ifndef IMS_PROJECT_ARGUMENT_PARSER_H
#define IMS_PROJECT_ARGUMENT_PARSER_H

#include <string>

#define NUMBER_OF_YEARS 1
#define HELP_MSG 2
#define CONSUMPTION_OF_KWH_PER_DAY 3
#define NUMBER_OF_PROCESSES_PER_KWH 4

class ArgumentParser {
private:
	unsigned numberOfYears;
	unsigned consumptionOfkWhPerYear;
	unsigned numberOfProcessesPerkWh;

public:

	bool parseArgs(int argc, char **argv);
	bool parseNumber(std::string input, unsigned &output);
	void printHelp();
	unsigned getNumberOfYears();
	unsigned getConsumptionOfkWhPerDay();
	unsigned getNumberOfProcessesPerkWh();

};


#endif //IMS_PROJECT_ARGUMENT_PARSER_H

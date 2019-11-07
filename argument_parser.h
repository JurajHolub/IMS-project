//
// Created by juraj on 07/11/2019.
//

#ifndef IMS_PROJECT_ARGUMENT_PARSER_H
#define IMS_PROJECT_ARGUMENT_PARSER_H

#include <string>

#define NUMBER_OF_YEARS 1
#define HELP_MSG 2
#define CONSUMPTION_OF_KWH_PER_MONTH 3

class ArgumentParser {
private:
	unsigned numberOfYears;
	unsigned consumptionOfkWhPerMonth;

public:

	bool parseArgs(int argc, char **argv);
	bool parseNumber(std::string input, unsigned &output);
	void printHelp();
	unsigned getNumberOfYears();
	unsigned getConsumptionOfkWhPerMonth();
};


#endif //IMS_PROJECT_ARGUMENT_PARSER_H

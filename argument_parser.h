//
// Created by juraj on 07/11/2019.
//

#ifndef IMS_PROJECT_ARGUMENT_PARSER_H
#define IMS_PROJECT_ARGUMENT_PARSER_H

#include <string>

#define NUMBER_OF_YEARS_CONST 1
#define HELP_MSG_CONST 2
#define COLLECTOR_AREA_CONST 3
#define TANK_CAPACITY_CONST 4
#define ROOF_DEGREE_CONST 5

class ArgumentParser {

public:
	unsigned numberOfYears;
	unsigned collectorArea;
	unsigned tankCapacity;
	unsigned roofDegree;

	bool parseArgs(int argc, char **argv);
	bool parseNumber(std::string input, unsigned &output);
	void printHelp();
	bool isValidRoofDegree(unsigned degree);

};


#endif //IMS_PROJECT_ARGUMENT_PARSER_H

//
// Created by juraj on 07/11/2019.
//

#include "argument_parser.h"
#include <getopt.h>
#include <iostream>
#include <list>
#include "year_cycle.h"

bool ArgumentParser::parseArgs(int argc, char **argv)
{
	int opt;
	const struct option long_options[] = {
		{"years" , required_argument, 0,  NUMBER_OF_YEARS_CONST},
		{"tank" , required_argument, 0,   TANK_CAPACITY_CONST},
		{"area" , required_argument, 0,   COLLECTOR_AREA_CONST},
		{"degree" , required_argument, 0, ROOF_DEGREE_CONST},
		{"help" , no_argument, 0,         HELP_MSG_CONST}
	};
	std::list<std::string> argsLeft;
	for (int i = 1; i < argc; i++)
	{
		argsLeft.push_front(std::string(argv[i]));
	}

	bool yearsDefined = false;
	bool tankDefined = false;
	bool areaDefined = false;
	bool degreeDefined = false;

	while ((opt = getopt_long_only(argc, argv, "", long_options, nullptr)) != -1)
	{
		switch (opt)
		{
			case NUMBER_OF_YEARS_CONST:
				yearsDefined = parseNumber(optarg, numberOfYears);
				argsLeft.remove("-years");
				argsLeft.remove(optarg);
				break;
			case TANK_CAPACITY_CONST:
				tankDefined = parseNumber(optarg, tankCapacity);
				argsLeft.remove("-tank");
				argsLeft.remove(optarg);
				break;
			case COLLECTOR_AREA_CONST:
				areaDefined = parseNumber(optarg, collectorArea);
				argsLeft.remove("-area");
				argsLeft.remove(optarg);
				break;
			case ROOF_DEGREE_CONST:
				degreeDefined = parseNumber(optarg, roofDegree) && isValidRoofDegree(roofDegree);
				argsLeft.remove("-degree");
				argsLeft.remove(optarg);
				break;
			default:
			case HELP_MSG_CONST:
				return false; //just print help message
		}
	}

	bool allDefined = yearsDefined && tankDefined && areaDefined && degreeDefined;

	return argsLeft.empty() && allDefined;
}

bool ArgumentParser::parseNumber(std::string input, unsigned &output)
{
	if (input.empty())
	{
		return false;
	}

	for (auto it = input.begin(), end= input.end(); it != end; ++it)
	{
		if (!std::isdigit(*it))
		{
			return false;
		}
	}

	if (atoi(input.c_str()) < 0)
		return false;

	output = atoi(input.c_str());

	return true;
}

bool ArgumentParser::isValidRoofDegree(unsigned degree)
{
	switch (degree)
	{
		case _0_DEGREE:
		case _15_DEGREE:
		case _30_DEGREE:
		case _45_DEGREE:
		case _60_DEGREE:
		case _75_DEGREE:
		case _90_DEGREE:
			return true;
		default:
			return false;
	}
}

void ArgumentParser::printHelp()
{
	std::cout << "usage: ims-project <arguments>" << std::endl
	          << "Compulsory arguments:" << std::endl
	          << "  -years <integer>       = Number of simulation time in years." << std::endl
			  << "  -tank <integer>        = Size of water tank for heating in liters." << std::endl
			  << "  -area <integer>        = Area of solar panel in square meters." << std::endl
			  << "  -degree <integer>      = Roof slope => solar panel degree." << std::endl
			  << "                           Possible values = {0, 15, 30, 45, 60, 75, 90}" << std::endl
	          << "Optional arguments:" << std::endl
	          << "  -help                  = Print this help message." << std::endl;
}
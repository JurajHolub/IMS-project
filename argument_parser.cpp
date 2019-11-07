//
// Created by juraj on 07/11/2019.
//

#include "argument_parser.h"
#include <getopt.h>
#include <iostream>
#include <list>

bool ArgumentParser::parseArgs(int argc, char **argv)
{
	int opt;
	const struct option long_options[] = {
			{"y" , required_argument, 0, NUMBER_OF_YEARS},
			{"e" , required_argument, 0, CONSUMPTION_OF_KWH_PER_MONTH},
			{"h" , no_argument, 0,       HELP_MSG}
	};
	std::list<std::string> argsLeft;
	for (int i = 1; i < argc; i++)
	{
		argsLeft.push_front(std::string(argv[i]));
	}
	bool yearsDefined = false;
	bool kWhDefined = false;

	while ((opt = getopt_long_only(argc, argv, "", long_options, nullptr)) != -1)
	{
		switch (opt)
		{
			case NUMBER_OF_YEARS:
				yearsDefined = parseNumber(optarg, numberOfYears);
				argsLeft.remove("-y");
				argsLeft.remove(optarg);
				break;
			case CONSUMPTION_OF_KWH_PER_MONTH:
				kWhDefined = parseNumber(optarg, consumptionOfkWhPerMonth);
				argsLeft.remove("-e");
				argsLeft.remove(optarg);
				break;
			default:
			case HELP_MSG:
				return false; //just print help message
		}
	}

	return argsLeft.empty() && yearsDefined && kWhDefined;
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

	if (atoi(input.c_str()) < 1)
		return false;

	output = atoi(input.c_str());

	return true;
}

unsigned ArgumentParser::getNumberOfYears()
{
	return numberOfYears;
}

unsigned ArgumentParser::getConsumptionOfkWhPerMonth()
{
	return consumptionOfkWhPerMonth;
}

void ArgumentParser::printHelp()
{
	std::cout << "usage: ims-project <arguments>" << std::endl
	          << "Compulsory arguments:" << std::endl
	          << "  -y <integer>      = Number of simulation time in years." << std::endl
	          << "  -e <integer>      = Energy [kWh] consumed by water heating per month." << std::endl
	          << "Optional arguments:" << std::endl
	          << "  -h                = Print this help message." << std::endl;
}
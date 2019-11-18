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
			{"e" , required_argument, 0, CONSUMPTION_OF_KWH_PER_DAY},
			{"p" , required_argument, 0, NUMBER_OF_PROCESSES_PER_KWH},
			{"h" , no_argument, 0,       HELP_MSG}
	};
	std::list<std::string> argsLeft;
	for (int i = 1; i < argc; i++)
	{
		argsLeft.push_front(std::string(argv[i]));
	}
	bool yearsDefined = false;
	bool kWhDefined = false;
	bool processesDefined = false;

	while ((opt = getopt_long_only(argc, argv, "", long_options, nullptr)) != -1)
	{
		switch (opt)
		{
			case NUMBER_OF_YEARS:
				yearsDefined = parseNumber(optarg, numberOfYears);
				argsLeft.remove("-y");
				argsLeft.remove(optarg);
				break;
			case CONSUMPTION_OF_KWH_PER_DAY:
				kWhDefined = parseNumber(optarg, consumptionOfkWhPerYear);
				argsLeft.remove("-e");
				argsLeft.remove(optarg);
				break;
			case NUMBER_OF_PROCESSES_PER_KWH:
				processesDefined = parseNumber(optarg, numberOfProcessesPerkWh);
				argsLeft.remove("-p");
				argsLeft.remove(optarg);
				break;
			default:
			case HELP_MSG:
				return false; //just print help message
		}
	}

	if (!kWhDefined)
	{
		kWhDefined = true;
		consumptionOfkWhPerYear = 3713;
	}
	if (!processesDefined)
	{
		processesDefined = true;
		numberOfProcessesPerkWh = 1;
	}

	return argsLeft.empty() && yearsDefined && kWhDefined && processesDefined;
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

unsigned ArgumentParser::getConsumptionOfkWhPerDay()
{
	double dayOfYear = 365;
	return consumptionOfkWhPerYear / dayOfYear * numberOfProcessesPerkWh;
}

unsigned ArgumentParser::getNumberOfProcessesPerkWh()
{
	return numberOfProcessesPerkWh;
}

void ArgumentParser::printHelp()
{
	std::cout << "usage: ims-project <arguments>" << std::endl
	          << "Compulsory arguments:" << std::endl
	          << "  -y <integer>      = Number of simulation time in years." << std::endl
	          << "Optional arguments:" << std::endl
	          << "  -e <integer>      = Energy [kWh] consumed by water heating per year." << std::endl
	          << "                      (If not defined then it is 3713 kWh per year by default)" << std::endl
	          << "  -p <integer>      = Number of processes representing 1 kWh. More" << std::endl
	          << "                      processes leads to penalty lack but higher accuracy." << std::endl
	          << "                      (If not defined then it is 1 proces to 1 kWh by default)" << std::endl
	          << "  -h                = Print this help message." << std::endl;
}
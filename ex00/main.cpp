#include <iostream>
#include <string>
#include"BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./btc [input file]" << std::endl;
		return 1;
	}
	BitcoinExchange btc("data.csv", argv[1]);
}
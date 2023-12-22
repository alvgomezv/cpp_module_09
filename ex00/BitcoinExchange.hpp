#ifndef BitcoinExchange_hpp
# define BitcoinExchange_hpp

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <map>
#include <algorithm>

class BitcoinExchange
{
	private:
		std::map<int, int>	_prices;

	public:
		BitcoinExchange(std::string pricesFile, std::string inputFile);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange(void);

		void	fillPrices(std::string pricesFile);
		void	useInput(std::string inputFile);

	class InvalidFileException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Error: could not open file");
			}
	};
};


#endif

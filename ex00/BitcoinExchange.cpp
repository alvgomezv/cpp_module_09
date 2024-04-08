#include"BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(std::string pricesFile, std::string inputFile)
{
	try
	{
		std::ifstream file(pricesFile.c_str());
		std::ifstream file2(inputFile.c_str());
		if (file == NULL || file2 == NULL)
			throw BitcoinExchange::InvalidFileException();
		this->fillPrices(pricesFile);
		this->useInput(inputFile);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_prices = other._prices;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange(void)
{
}

void	BitcoinExchange::fillPrices(std::string pricesFile)
{
	std::ifstream file(pricesFile.c_str());
	std::string	line;

	while (std::getline(file, line))
	{
		std::stringstream ss1(line);
		std::string word1;
		std::string word2;
		std::string tmp1;
		std::string tmp2;
		std::string tmp3;
		std::getline(ss1, word1, ',');
		std::getline(ss1, word2, ',');
		std::stringstream ss2(word1);
		std::getline(ss2, tmp1, '-');
		std::getline(ss2, tmp2, '-');
		std::getline(ss2, tmp3, '-');
		word1 = tmp1 + tmp2 + tmp3;
		_prices[std::atoi(word1.c_str())] = std::atof(word2.c_str());
	}
}

void	BitcoinExchange::useInput(std::string inputFile)
{
	std::ifstream file(inputFile.c_str());
	std::string line;

	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string word1;
		std::string word2;
		std::string tmp1;
		std::string tmp2;
		std::string tmp3;
		std::getline(ss, word1, '|');
		std::getline(ss, word2, '|');
		if (word1.empty() || word2.empty())
		{
			std::cout << "Error: bad imput => " << line << std::endl;
			continue;
		}
		if (std::atoi(word2.c_str()) > INT_MAX || std::atoi(word2.c_str()) <= (INT_MIN + 1))
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		if (std::atoi(word2.c_str()) < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		std::stringstream ss2(word1);
		std::getline(ss2, tmp1, '-');
		std::getline(ss2, tmp2, '-');
		std::getline(ss2, tmp3, '-');
		if (std::atoi(tmp1.c_str()) <= 0 || std::atoi(tmp2.c_str()) <= 0 || std::atoi(tmp3.c_str()) <= 0
			|| std::atoi(tmp1.c_str()) > 2050 || std::atoi(tmp2.c_str()) > 12 || std::atoi(tmp3.c_str()) > 31 
			|| (std::atoi(tmp2.c_str()) == 2 && std::atoi(tmp3.c_str()) > 29) 
			|| (std::atoi(tmp2.c_str()) == 4 && std::atoi(tmp3.c_str()) > 30) 
			|| (std::atoi(tmp2.c_str()) == 6 && std::atoi(tmp3.c_str()) > 30) 
			|| (std::atoi(tmp2.c_str()) == 9 && std::atoi(tmp3.c_str()) > 30) 
			|| (std::atoi(tmp2.c_str()) == 11 && std::atoi(tmp3.c_str()) > 30))
		{
			std::cout << "Error: bad date format => " << word1 << std::endl;
			continue;
		}
		float result = std::atof(word2.c_str()) * this->returnPrice(word1);
		std::cout << word1 << "=>" << word2 << " = " << result << std::endl;
	}
}

float		BitcoinExchange::returnPrice(std::string date)
{
	std::stringstream ss(date);
	std::string tmp1;
	std::string tmp2;
	std::string tmp3;
	std::getline(ss, tmp1, '-');
	std::getline(ss, tmp2, '-');
	std::getline(ss, tmp3, '-');
	date = tmp1 + tmp2 + tmp3;
	int dateInt = std::atoi(date.c_str());
	std::map<int, float>::iterator it = _prices.begin();
	while (it != _prices.end())
	{
		if (it->first == dateInt)
			return it->second;
		else if (it->first > dateInt)
		{
			it--;
			return it->second;
		}
		it++;
	}
	return 0;
}


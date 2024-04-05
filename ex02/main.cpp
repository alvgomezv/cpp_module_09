#include"PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./PmergeMe [numbers]" << std::endl;
		return 1;
	}
	try
	{
		// std::cout << argv[1] << std::endl;
		PmergeMe PmergeMe(argv[1]);
		PmergeMe.SortVectorAndList();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
}
#include "Span.hpp"

int main()
{
    Span sp = Span(5);

    try
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try 
    {
        Span largeSpan(20000);
        std::vector<int> largeNumbers;

        srand(time(NULL));

        for (int i = 0; i < 20000; ++i) 
        {
            largeNumbers.push_back(rand() % 1000000);
        }

        largeSpan.addNumbers(largeNumbers.begin(), largeNumbers.end());

        std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Largest span: " << largeSpan.longestSpan() << std::endl;
    } 
    catch (std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }


    return 0;
}
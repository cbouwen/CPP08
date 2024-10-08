#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iterator>
#include <algorithm>
#include <map>
#include <exception>
#include <vector>
#include <iostream>


class NotFoundException: public std::exception
{
    virtual const char* what() const throw()
    {
        return "Element not found";
    }
};


template<typename T>
typename T::iterator    easyfind(T& container, int search)
{
    typename T::iterator    result = std::find(container.begin(), container.end(), search);
    if (result == container.end())
        throw NotFoundException();
    return result; 
}

template<typename key, typename value>
typename std::map<key, value>::iterator easyfind(std::map<key, value> &container, int search)
{
    typename std::map<key, value>::iterator result = container.find(search);
    if (result == container.end())
        throw NotFoundException();
    return result;
}



#endif
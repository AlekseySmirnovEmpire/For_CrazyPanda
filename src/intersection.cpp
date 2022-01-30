#include <iostream>
#include <ctime>
#include <boost/unordered_set.hpp>
#include "Intersection.h"

using boost::unordered_multiset;

Intersection::Intersection()
{
    std::srand(std::time(nullptr));

    int amount(std::rand() % 20 + 1);

    for(int i = 0; i < amount; ++i)
    {
        firstArr.push_back(std::rand() % 100 + 1);
        secondArr.push_back(std::rand() % 100 + 1);
    } //создали два массива и проинициализирвали их рандомными числами от 1 до 100
}

void Intersection::startShow()
{
    std::cout << "First: " << std::endl;
    for(const auto& el : firstArr)
        std::cout << el << " ";

    std::cout << std::endl;

    std::cout << "Second: " << std::endl;
    for(const auto& el : secondArr)
        std::cout << el << " ";
    
    std::cout << std::endl;
}

void Intersection::showIntersection()
{
    if(result.size() == 0)
    {
        result = std::move(interArr());

        if(result.size() == 0)
        {
            std::cout << "There is no intersection!" << std::endl;
            return;
        }            
    } 

    std::cout << "Result:" << std::endl;
    for(const auto& el : result)
        std::cout << el << " ";
        
    std::cout << std::endl;

}

std::vector<int> Intersection::interArr()
{
    unordered_multiset<int> temp;
    std::vector<int> output;

    for(size_t i = 0 ; i < firstArr.size(); ++i)
    {
        temp.emplace(firstArr[i]);
    }

    for(size_t i = 0; i < secondArr.size(); ++i)
    {
        if(temp.find(secondArr[i]) != temp.end())
        {
            output.push_back(secondArr[i]);
            temp.erase(secondArr[i]);
        } 
    }

    return output;
}
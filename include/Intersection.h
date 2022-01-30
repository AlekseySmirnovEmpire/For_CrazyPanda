#pragma once
#include <vector>

class Intersection
{
private:
    std::vector<int> firstArr;
    std::vector<int> secondArr;
    std::vector<int> result;

public:
    Intersection();

    void startShow();
    void showIntersection();
    std::vector<int> interArr();
};
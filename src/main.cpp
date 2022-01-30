#include <iostream>
#include <vector>
#include "Intersection.h"
#include "Clear.h"

int main(int argc, char** argv)
{
    Intersection* arr = new Intersection();

    arr->startShow();

    int n;
    std::cin >> n;

    clear();

    arr->showIntersection();

    delete arr;
    arr = nullptr;
}
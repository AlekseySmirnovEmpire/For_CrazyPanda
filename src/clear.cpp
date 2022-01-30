#include <iostream>

void clear()
{
#ifdef _WIN32 
    system("cls");
#elif (__linux__ || __unix__ || __APPLE__)
    system("clear");
#else
    for(int i = 0; i < 10; ++i)
        std::cout << std::endl;
#endif
}
#include <iostream>
#include <vector> 
#include <algorithm>

#include "Ant.h"

int main()
{
    Coordinates AntC(1000, 1000); //starting point
    const int MaxSum = 25; //cut-off
    
    std::vector<Coordinates> CAnt{ AntC };
    std::vector<Coordinates> CAntGood{ AntC };
    
    while (!CAnt.empty())
    {
        //Check if upper coordinates are correct
        if ((CAnt.front().CUp(CAnt.front()).CSumm() <= MaxSum) && (std::find(CAntGood.begin(), CAntGood.end(), CAnt.front().CUp(CAnt.front())) == CAntGood.end()))
        {
            CAntGood.push_back(CAnt.front().CUp(CAnt.front())); //populate vector of visited coordinates;
            CAnt.push_back(CAnt.front().CUp(CAnt.front())); //populate the initial vector with new, available coordinates;
        }

        //Check if lower coordinates are correct
        /*
        if ((CAnt.front().CDown(CAnt.front()).CSumm() <= MaxSum) && (std::find(CAntGood.begin(), CAntGood.end(), CAnt.front().CDown(CAnt.front())) == CAntGood.end())) //&& (std::find(CAntGood.begin(), CAntGood.end(), CAnt.front()) == CAntGood.end()))
        {
            CAntGood.push_back(CAnt.front().CDown(CAnt.front()));
            CAnt.push_back(CAnt.front().CDown(CAnt.front()));
        }
        */

        //Check if right coordinates are correct
        if ((CAnt.front().CRight(CAnt.front()).CSumm() <= MaxSum) && (std::find(CAntGood.begin(), CAntGood.end(), CAnt.front().CRight(CAnt.front())) == CAntGood.end())) //&& (std::find(CAntGood.begin(), CAntGood.end(), CAnt.front()) == CAntGood.end()))
        {
            CAntGood.push_back(CAnt.front().CRight(CAnt.front()));
            CAnt.push_back(CAnt.front().CRight(CAnt.front()));
        }
        
        //Check if left coordinates are correct
        /*
        if ((CAnt.front().CLeft(CAnt.front()).CSumm() <= MaxSum) && (std::find(CAntGood.begin(), CAntGood.end(), CAnt.front().CLeft(CAnt.front())) == CAntGood.end())) //&& (std::find(CAntGood.begin(), CAntGood.end(), CAnt.front()) == CAntGood.end()))
        {
            CAntGood.push_back(CAnt.front().CLeft(CAnt.front()));
            CAnt.push_back(CAnt.front().CLeft(CAnt.front()));
        }
        */
        
        //remove original coordinates from the inital vector;
        CAnt.erase(CAnt.begin());
    }
    
    std::cout << std::endl << "Number of coordinates = " << CAntGood.size() << std::endl;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

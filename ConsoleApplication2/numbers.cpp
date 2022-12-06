
#include<iostream>
#include<string>
#include<list>
#include <cmath>
#include <sstream>
#include <vector>
#include <cstring>
using namespace std;


float GetSum(std::list<int> numbers)
{
    int sum = 0;//Sets sum to 0

    //Create iterator loop
    for (int number : numbers) 
    {
        sum += number; //Add numbers to sum
    }
    return sum;
}


float GetAverage(std::list<int> numbers)
{
    int sum = GetSum(numbers);
    float average = (float)sum / (float)numbers.size();
    return average;
}

int GetBiggest(std::list<int> numbers)
{
    list<int>::iterator it = numbers.begin();//Create iterator
    return *it;
}

int GetNextBiggest(std::list<int> numbers)
{
    list<int>::iterator it = numbers.begin();//Create iterator
    it++; //Iterate iterator to the list's next biggest element (index 1)
    return *it;
}

std::list<int> GetNumbers(string input)
{
    std::list<int> numbers = {};//Numbers declare list of integers

    string w = "";
    for (auto x : input)
    {
        if (x == ' ')
        {
            numbers.push_back(stoi(w));
            w = "";
        }
        else 
        {
            w = w + x;
            if (w == "0")
            {
                numbers.sort();
                numbers.reverse();
                return numbers;
            }
        }
    }
    numbers.push_back(stoi(w));
    numbers.sort();
    numbers.reverse();

    return numbers;
}

int main()
{
    cout << "ange ett antal tal" << endl;//Shows text on screen

    string input;//Creates string input
    std::getline(std::cin, input);//Get user line input
    std::list<int> numbers = GetNumbers(input);

    
    cout << "största talet är: " << GetBiggest(numbers) << endl;//show greatest number
    cout << "näst största talet är: " << GetNextBiggest(numbers) << endl;//Show next greatest number

    cout << "summan: " << GetSum(numbers) << endl;//Show sum
    cout << "medelv: " << GetAverage(numbers) << endl;//Show average value

    //Avoid program from exiting by waiting for empty user input
    string empty = "";
    cin >> empty; 
}
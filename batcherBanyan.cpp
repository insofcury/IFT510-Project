#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <stack>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;

int partitioning(vector<int> &arr, int s, int e)
{
    int i = s - 1;
    int j = s;

    int pivot = arr[e];
    while (j <= e - 1)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    //Adjusting the pivot element
    swap(arr[i + 1], arr[e]);
    return i + 1;
}

void batcherUsingQuickSort(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;

    int part = partitioning(arr, start, end);
    batcherUsingQuickSort(arr, start, part - 1);
    batcherUsingQuickSort(arr, part + 1, end);
}

string switchFromAToB(string initialPort, string binaryCharacter)
{
    //The first layer of banyan layer
    if (initialPort == "A1")
    {
        if (binaryCharacter[0] == '0')
            return "B1";
        else
            return "B3";
    }
    if (initialPort == "A2")
    {
        if (binaryCharacter[0] == '0')
            return "B2";
        else
            return "B4";
    }
    if (initialPort == "A3")
    {
        if (binaryCharacter[0] == '0')
            return "B1";
        else
            return "B3";
    }
    if (initialPort == "A4")
    {
        if (binaryCharacter[0] == '0')
            return "B2";
        else
            return "B4";
    }
    return "";
}

string switchFromBToC(string initialPort, string binaryCharacter)
{
    //The second layer of banyan layer
    if (initialPort == "B1")
    {
        if (binaryCharacter[1] == '0')
            return "C1";
        else
            return "C2";
    }
    if (initialPort == "B2")
    {
        if (binaryCharacter[1] == '0')
            return "C1";
        else
            return "C2";
    }
    if (initialPort == "B3")
    {
        if (binaryCharacter[1] == '0')
            return "C3";
        else
            return "C4";
    }
    if (initialPort == "B4")
    {
        if (binaryCharacter[1] == '0')
            return "C3";
        else
            return "C4";
    }
    return "";
}

string switchFromCToOutput(string initialPort, string binaryCharacter)
{
    //The third layer of banyan network
    if (initialPort == "C1")
    {
        if (binaryCharacter[2] == '0')
            return "0";
        else
            return "1";
    }
    if (initialPort == "C2")
    {
        if (binaryCharacter[2] == '0')
            return "2";
        else
            return "3";
    }
    if (initialPort == "C3")
    {
        if (binaryCharacter[2] == '0')
            return "4";
        else
            return "5";
    }
    if (initialPort == "C4")
    {
        if (binaryCharacter[2] == '0')
            return "6";
        else
            return "7";
    }
    return "";
}

int32_t main()
{
    int n, randomizing = 8, i = 0;
    cout << "Total number of inputs : (values should vary from 1-8) - ";
    cin >> n;
    vector<int> inputs;
    map<int, int> inputMapped;
    map<int, string> switchesMapped;

    //Generating random values so that the program generates random inputs every time the program is executed
    srand(time(0));
    while (i < n)
    {
        int randomValue = rand() % randomizing;
        //Checking the value generated if it is unique and discarding those which are repeating
        auto it = find(inputs.begin(), inputs.end(), randomValue);

        if (it == inputs.end())
        {
            inputs.push_back(randomValue);
            i++;
        }
    }
    // inputs[0] = 0, inputs[1] = 4, inputs[2] = 5, inputs[3] = 6, inputs[4] = 7;

    //Displaying the random inputs received
    cout << "The inputs are : " << endl;
    for (int a : inputs)
        cout << a << " ";
    cout << endl << endl;

    //Implementing batcher using quick sort the most efficient and fastest sorting algorithm (nlogn time complexity)
    batcherUsingQuickSort(inputs, 0, inputs.size() - 1);
    // sort(inputs.begin(), inputs.end());

    for (int i = 0; i < n; i++)
    {
        inputMapped[i] = inputs[i];
    }

    //Priting the sorted inputs
    for (auto it = inputMapped.begin(); it != inputMapped.end(); it++)
    {
        cout << it->first << " -> " << it->second << " | ";
    }
    cout << endl << endl;

    //Creating a mapping between indexes and switches
    switchesMapped[0] = "A1";
    switchesMapped[1] = "A2";
    switchesMapped[2] = "A3";
    switchesMapped[3] = "A4";
    switchesMapped[4] = "A1";
    switchesMapped[5] = "A2";
    switchesMapped[6] = "A3";
    switchesMapped[7] = "A4";

    //Looping through for each input and finding path for every input -> implementing banyan network
    for (int i = 0; i < n; i++)
    {
        string str = "";
        int number = inputMapped[i];

        //Converting the decimal input value into binary value
        while (number != 0)
        {
            str = to_string(number % 2) + str;
            number = number / 2;
        }

        //Doing padding to make all the input binary size 3 for it to be mapped to a 8x8 delta network
        while (str.size() < 3)
        {
            str = "0" + str;
        }
        cout << endl;

        //Generating the whole path
        string pathA = switchesMapped[i];

        //First layer
        string pathAtoB = switchFromAToB(pathA, str);

        //Second layer
        string pathBtoC = switchFromBToC(pathAtoB, str);

        //Third layer
        string pathCtoOut = switchFromCToOutput(pathBtoC, str);

        cout << "Path from the input " << to_string(i) << " to the output " << to_string(inputs[i]) << " : " << pathA << " => " << pathAtoB << " => " << pathBtoC << " => " << pathCtoOut << endl << endl;
    }
}
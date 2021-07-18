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
            return "B5";
    }
    if (initialPort == "A2")
    {
        if (binaryCharacter[0] == '0')
            return "B2";
        else
            return "B6";
    }
    if (initialPort == "A3")
    {
        if (binaryCharacter[0] == '0')
            return "B3";
        else
            return "B7";
    }
    if (initialPort == "A4")
    {
        if (binaryCharacter[0] == '0')
            return "B4";
        else
            return "B8";
    }
    if (initialPort == "A5")
    {
        if (binaryCharacter[0] == '0')
            return "B1";
        else
            return "B5";
    }
    if (initialPort == "A6")
    {
        if (binaryCharacter[0] == '0')
            return "B2";
        else
            return "B6";
    }
    if (initialPort == "A7")
    {
        if (binaryCharacter[0] == '0')
            return "B3";
        else
            return "B7";
    }
    if (initialPort == "A8")
    {
        if (binaryCharacter[0] == '0')
            return "B4";
        else
            return "B8";
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
            return "C3";
    }
    if (initialPort == "B2")
    {
        if (binaryCharacter[1] == '0')
            return "C2";
        else
            return "C4";
    }
    if (initialPort == "B3")
    {
        if (binaryCharacter[1] == '0')
            return "C1";
        else
            return "C3";
    }
    if (initialPort == "B4")
    {
        if (binaryCharacter[1] == '0')
            return "C2";
        else
            return "C4";
    }
    if (initialPort == "B5")
    {
        if (binaryCharacter[1] == '0')
            return "C5";
        else
            return "C7";
    }
    if (initialPort == "B6")
    {
        if (binaryCharacter[1] == '0')
            return "C6";
        else
            return "C8";
    }
    if (initialPort == "B7")
    {
        if (binaryCharacter[1] == '0')
            return "C5";
        else
            return "C7";
    }
    if (initialPort == "B8")
    {
        if (binaryCharacter[1] == '0')
            return "C6";
        else
            return "C8";
    }
    return "";
}

string switchFromCToD(string initialPort, string binaryCharacter)
{
    //The second layer of banyan layer
    if (initialPort == "C1")
    {
        if (binaryCharacter[2] == '0')
            return "D1";
        else
            return "D2";
    }
    if (initialPort == "C2")
    {
        if (binaryCharacter[2] == '0')
            return "D1";
        else
            return "D2";
    }
    if (initialPort == "C3")
    {
        if (binaryCharacter[2] == '0')
            return "D3";
        else
            return "D4";
    }
    if (initialPort == "C4")
    {
        if (binaryCharacter[2] == '0')
            return "D3";
        else
            return "D4";
    }
    if (initialPort == "C5")
    {
        if (binaryCharacter[2] == '0')
            return "D5";
        else
            return "D6";
    }
    if (initialPort == "C6")
    {
        if (binaryCharacter[2] == '0')
            return "D5";
        else
            return "D6";
    }
    if (initialPort == "C7")
    {
        if (binaryCharacter[2] == '0')
            return "D7";
        else
            return "D8";
    }
    if (initialPort == "C8")
    {
        if (binaryCharacter[2] == '0')
            return "D7";
        else
            return "D8";
    }
    return "";
}

string switchFromDToOutput(string initialPort, string binaryCharacter)
{
    //The third layer of banyan network
    if (initialPort == "D1")
    {
        if (binaryCharacter[3] == '0')
            return "0";
        else
            return "1";
    }
    if (initialPort == "D2")
    {
        if (binaryCharacter[3] == '0')
            return "2";
        else
            return "3";
    }
    if (initialPort == "D3")
    {
        if (binaryCharacter[3] == '0')
            return "4";
        else
            return "5";
    }
    if (initialPort == "D4")
    {
        if (binaryCharacter[3] == '0')
            return "6";
        else
            return "7";
    }
    if (initialPort == "D5")
    {
        if (binaryCharacter[3] == '0')
            return "8";
        else
            return "9";
    }
    if (initialPort == "D6")
    {
        if (binaryCharacter[3] == '0')
            return "10";
        else
            return "11";
    }
    if (initialPort == "D7")
    {
        if (binaryCharacter[3] == '0')
            return "12";
        else
            return "13";
    }
    if (initialPort == "D8")
    {
        if (binaryCharacter[3] == '0')
            return "14";
        else
            return "15";
    }
    return "";
}

int32_t main()
{
    int n, randomizing = 16, i = 0;
    cout << "Total number of inputs : (values should vary from 1-16) - ";
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
    // inputs[0] = 0, inputs[1] = 1, inputs[2] = 4, inputs[3] = 7, inputs[4] = 12;

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
    switchesMapped[4] = "A5";
    switchesMapped[5] = "A6";
    switchesMapped[6] = "A7";
    switchesMapped[7] = "A8";
    switchesMapped[8] = "A1";
    switchesMapped[9] = "A2";
    switchesMapped[10] = "A3";
    switchesMapped[11] = "A4";
    switchesMapped[12] = "A5";
    switchesMapped[13] = "A6";
    switchesMapped[14] = "A7";
    switchesMapped[15] = "A8";

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
        while (str.size() < 4)
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
        string pathCtoD = switchFromCToD(pathBtoC, str);

        //Fourth layer
        string pathDtoOut = switchFromDToOutput(pathCtoD, str);

        cout << "Path from the input " << to_string(i) << " to the output " << to_string(inputs[i]) << " : " << pathA << " => " << pathAtoB << " => " << pathBtoC << " => " << pathCtoD << " => " << pathDtoOut << endl << endl;
    }
}
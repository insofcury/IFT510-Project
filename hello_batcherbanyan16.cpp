#include <cstring>
#include <random>
#include <iomanip>
#include <random>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>
using namespace std;

string switchFromAToB(string x, string y)
{
    if (x == "A1")
    {
        if (y[0] == '0')
            return "B1";
        else
            return "B5";
    }
    if (x == "A2")
    {
        if (y[0] == '0')
            return "B2";
        else
            return "B6";
    }
    if (x == "A3")
    {
        if (y[0] == '0')
            return "B3";
        else
            return "B7";
    }
    if (x == "A4")
    {
        if (y[0] == '0')
            return "B4";
        else
            return "B8";
    }
    if (x == "A5")
    {
        if (y[0] == '0')
            return "B1";
        else
            return "B5";
    }
    if (x == "A6")
    {
        if (y[0] == '0')
            return "B2";
        else
            return "B6";
    }
    if (x == "A7")
    {
        if (y[0] == '0')
            return "B3";
        else
            return "B7";
    }
    if (x == "A8")
    {
        if (y[0] == '0')
            return "B4";
        else
            return "B8";
    }
    return "";
}

string switchFromBToC(string x, string y)
{
    if (x == "B1")
    {
        if (y[1] == '0')
            return "C1";
        else
            return "C3";
    }
    if (x == "B2")
    {
        if (y[1] == '0')
            return "C2";
        else
            return "C4";
    }
    if (x == "B3")
    {
        if (y[1] == '0')
            return "C1";
        else
            return "C3";
    }
    if (x == "B4")
    {
        if (y[1] == '0')
            return "C2";
        else
            return "C4";
    }
    if (x == "B5")
    {
        if (y[1] == '0')
            return "C5";
        else
            return "C7";
    }
    if (x == "B6")
    {
        if (y[1] == '0')
            return "C6";
        else
            return "C8";
    }
    if (x == "B7")
    {
        if (y[1] == '0')
            return "C5";
        else
            return "C7";
    }
    if (x == "B8")
    {
        if (y[1] == '0')
            return "C6";
        else
            return "C8";
    }
    return "";
}

string switchFromCToD(string x, string y)
{
    if (x == "C1")
    {
        if (y[2] == '0')
            return "D1";
        else
            return "D2";
    }
    if (x == "C2")
    {
        if (y[2] == '0')
            return "D1";
        else
            return "D2";
    }
    if (x == "C3")
    {
        if (y[2] == '0')
            return "D3";
        else
            return "D4";
    }
    if (x == "C4")
    {
        if (y[2] == '0')
            return "D3";
        else
            return "D4";
    }
    if (x == "C5")
    {
        if (y[2] == '0')
            return "D5";
        else
            return "D6";
    }
    if (x == "C6")
    {
        if (y[2] == '0')
            return "D5";
        else
            return "D6";
    }
    if (x == "C7")
    {
        if (y[2] == '0')
            return "D7";
        else
            return "D8";
    }
    if (x == "C8")
    {
        if (y[2] == '0')
            return "D7";
        else
            return "D8";
    }
    return "";
}

string switchFromDToOut(string x, string y)
{
    if (x == "D1")
    {
        if (y[3] == '0')
            return "0";
        else
            return "1";
    }
    if (x == "D2")
    {
        if (y[3] == '0')
            return "2";
        else
            return "3";
    }
    if (x == "D3")
    {
        if (y[3] == '0')
            return "4";
        else
            return "5";
    }
    if (x == "D4")
    {
        if (y[3] == '0')
            return "6";
        else
            return "7";
    }
    if (x == "D5")
    {
        if (y[3] == '0')
            return "8";
        else
            return "9";
    }
    if (x == "D6")
    {
        if (y[3] == '0')
            return "10";
        else
            return "11";
    }
    if (x == "D7")
    {
        if (y[3] == '0')
            return "12";
        else
            return "13";
    }
    if (x == "D8")
    {
        if (y[3] == '0')
            return "14";
        else
            return "15";
    }
    return "";
}

int32_t main()
{
    int n, rmax = 16, i = 0;
    cout << "Enter the number of inputs user wants to give (1-16): ";
    cin >> n;
    vector<int> arr;
    map<int, int> inputDictionary;
    map<int, string> m;

    srand(time(0));
    while (i < n)
    {
        int val = rand() % rmax;

        auto it = find(arr.begin(), arr.end(), val);
        if (it == arr.end())
        {
            arr.push_back(val);
            i++;
        }
    }
    arr[0] = 0, arr[1] = 1, arr[2] = 4, arr[3] = 7, arr[4] = 12;

    cout << "The inputs are : " << endl;
    for (int a : arr)
        cout << a << " ";

    cout << endl;

    //Batcher Implementation
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        inputDictionary[i] = arr[i];
    }

    for (auto it = inputDictionary.begin(); it != inputDictionary.end(); it++)
    {
        cout << it->first << " : " << it->second << " | ";
    }
    cout << endl
         << endl;

    m.insert(make_pair(0, "A1"));
    m.insert(make_pair(1, "A2"));
    m.insert(make_pair(2, "A3"));
    m.insert(make_pair(3, "A4"));
    m.insert(make_pair(4, "A5"));
    m.insert(make_pair(5, "A6"));
    m.insert(make_pair(6, "A7"));
    m.insert(make_pair(7, "A8"));
    m.insert(make_pair(8, "A1"));
    m.insert(make_pair(9, "A2"));
    m.insert(make_pair(10, "A3"));
    m.insert(make_pair(11, "A4"));
    m.insert(make_pair(12, "A5"));
    m.insert(make_pair(13, "A6"));
    m.insert(make_pair(14, "A7"));
    m.insert(make_pair(15, "A8"));

    //Banyan Implementation
    for (int i = 0; i < n; i++)
    {
        string x = "";
        int num = inputDictionary[i];
        while (num != 0)
        {
            x = to_string(num % 2) + x;
            num = num / 2;
        }

        while (x.size() < 4)
        {
            x = "0" + x;
        }
        cout << endl;
        string path1 = m[i];

        string path2 = switchFromAToB(path1, x);
        string path3 = switchFromBToC(path2, x);
        string path4 = switchFromCToD(path3, x);
        string path5 = switchFromDToOut(path4, x);
        cout << "Path from the input " << to_string(i) << " to the output " << to_string(arr[i]) << " : "<< endl ;
        cout<< path1 << " => " << path2 <<endl;
        cout<< path2 << " => " << path3 <<endl;
        cout<< path3 << " => " << path4 <<endl;
        cout<< path4 << " => " << path5 <<endl;
        cout<< endl;
    }
}
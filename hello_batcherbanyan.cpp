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
            return "B3";
    }
    if (x == "A2")
    {
        if (y[0] == '0')
            return "B2";
        else
            return "B4";
    }
    if (x == "A3")
    {
        if (y[0] == '0')
            return "B1";
        else
            return "B3";
    }
    if (x == "A4")
    {
        if (y[0] == '0')
            return "B2";
        else
            return "B4";
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
            return "C2";
    }
    if (x == "B2")
    {
        if (y[1] == '0')
            return "C1";
        else
            return "C2";
    }
    if (x == "B3")
    {
        if (y[1] == '0')
            return "C3";
        else
            return "C4";
    }
    if (x == "B4")
    {
        if (y[1] == '0')
            return "C3";
        else
            return "C4";
    }
    return "";
}

string switchFromCToOutput(string x, string y)
{
    if (x == "C1")
    {
        if (y[2] == '0')
            return "0";
        else
            return "1";
    }
    if (x == "C2")
    {
        if (y[2] == '0')
            return "2";
        else
            return "3";
    }
    if (x == "C3")
    {
        if (y[2] == '0')
            return "4";
        else
            return "5";
    }
    if (x == "C4")
    {
        if (y[2] == '0')
            return "6";
        else
            return "7";
    }
    return "";
}

int32_t main()
{
    int n, rmax = 8, i = 0;
    cout << "Enter the number of inputs user wants to give (1-8): ";
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
    cout << endl << endl;

    m.insert(make_pair(0, "A1"));
    m.insert(make_pair(1, "A2"));
    m.insert(make_pair(2, "A3"));
    m.insert(make_pair(3, "A4"));
    m.insert(make_pair(4, "A1"));
    m.insert(make_pair(5, "A2"));
    m.insert(make_pair(6, "A3"));
    m.insert(make_pair(7, "A4"));

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

        while (x.size() < 3)
        {
            
            x = "0" + x;
        }
        cout << endl;
        cout << inputDictionary[i] << " " << x << endl;
        string path1 = m[i];

        string path2 = switchFromAToB(path1, x);
        string path3 = switchFromBToC(path2, x);
        string path4 = switchFromCToOutput(path3, x);
        cout << "Path from the input " << to_string(i) << " to the output " << to_string(arr[i]) << " : " <<endl;
        cout<< path1 << " => " << path2 <<endl;
        cout<< path2 << " => " << path3 <<endl;
        cout<< path3 << " => " << path4 <<endl;
        cout<<endl;
    }
}
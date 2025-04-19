// map.cpp
// Demonstrate map.
#include <iostream>
#include <map>
#include <string>
using namespace std;

void display(const std::map<string, int> & mp);

int main(void)
{
    std::map<string, int> mp;
    mp["monkey"] = 4;
    mp["banana"] = 3;
    mp["piano"] = 9;
    cout << "The value of \"banana\" is " << mp["banana"] << endl;                    // 3
    cout << "And that's all map:\n";
    display(mp);
    mp.erase("banana");
    cout << "After deleting \"banana\" the map:\n";
    display(mp);

    std::map<string, int> mp2;
    cout << "\nIn new map, the value of \"aybabtu\" is " << mp2["aybabtu"] << endl;    // 0 (by default)
    cout << "The size of new map is " << mp2.size() << endl;
    if (!mp2.empty())
    {
        if (mp2.count("aybabtu"))
            cout << "The key \"aybabtu\" is in the map.\n";
        else
            cout << "The key \"aybabtu\" isn\'t in the map.\n";        
    }

    return 0;
}

void display(const std::map<string, int> & mp)
{
    for (const auto & item: mp)
        cout << item.first << ' ' << item.second << endl;
    /* 
    for (auto iter = mp.begin(); iter != mp.end(); iter++)
        cout << iter->first << ' ' << iter->second << endl;
     */
}

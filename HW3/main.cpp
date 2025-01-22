#include <iostream>
#include <fstream>
#include "List.h"

using namespace std;

ofstream outFile("RESULT.txt");

void print(List &list, int len)
{
    for (int i = 0; i < len; i++)
    {
        outFile << list.getElement(i) << " ";
    }
    outFile << endl;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    ifstream inFile(argv[1]);

    if (!inFile)
    {
        cout << "Error: Unable to open file " << argv[1] << endl;
        return 1;
    }

    // establish the list
    outFile << "Establishing the list1!\n";
    int len = 0;
    inFile >> len;
    List list1(len);

    // read the list from the file
    inFile >> list1;

    // confirm the elements in list1
    outFile << "list1: ";
    print(list1, len);
    // copy lists(list2, list3, list4)
    outFile << "Establishing list2~4!\n";
    List list2(list1);
    outFile << "list2 (Using copy): ";
    print(list2, len);
    List list3 = list1;
    outFile << "list3 (Using assign): ";
    print(list3, len);
    List list4;
    list4.setLength(len);
    for (int i = 0; i < len; i++)
    {
        int element = (long)list1.getElement(i);
        list4.setElement(i, element);
    }
    outFile << "list4 (Using getter and setter): ";
    print(list4, len);
    // Add
    outFile << "-----------------------------\n";
    outFile << "Add(+) rule: Adding two correspond "
            << "element in two list" << endl
            << "list1 + list2: ";
    List ret1 = list1 + list2;
    print(ret1, len);
    outFile << "-----------------------------\n";
    outFile << "Firstly, list1: ";
    print(list1, len);
    outFile << "prefix++ rule: Adding 1 to each element "
            << "in list1" << endl
            << "++list1: ";
    List ret2 = ++list1;
    print(ret2, len);
    outFile << "-----------------------------\n";
    outFile << "Firstly, list1: ";
    print(list1, len);
    outFile << "postfix++ rule: Adding 1 to each element "
            << "in list1 but it will return the old value(before adding 1)"
            << endl
            << "list1++: ";
    List ret3 = list1++;
    print(ret3, len);
    outFile << "After postfix++, list1: ";
    print(list1, len);
    outFile << "-----------------------------\n";
    outFile << "Firstly, list1: ";
    print(list1, len);
    outFile << "Firstly, list2: ";
    print(list2, len);
    outFile << "Add and assign(+=) rule: Adding two correspond element "
            << "in two list and assign to the first list" << endl
            << "list1 += list2: ";
    list1 += list2;
    print(list1, len);
    outFile << "-----------------------------\n";
    outFile << "Firstly, list1: ";
    print(list1, len);
    outFile << "prefix-- rule: Subtracting 1 to each element in list1"
            << endl
            << "--list1: ";
    List ret4 = --list1;
    print(ret4, len);
    outFile << "-----------------------------\n";
    outFile << "Firstly, list1: ";
    print(list1, len);
    outFile << "postfix-- rule: Subtracting 1 to each element in list1 "
            << "but it will return the old value(before subtracting 1)" << endl
            << "list1--: ";
    List ret5 = list1--;
    print(ret5, len);
    outFile << "After postfix--, list1: ";
    print(list1, len);
    outFile << "-----------------------------\n";

    inFile.close();
    outFile.close();
    cout << "See the detail in RESULT.txt!\n";
    return 0;
}
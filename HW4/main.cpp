#include "List.h"

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        cout << "Usage: " << argv[0] << " <filename1> <filename2>" << endl;
        return 1;
    }

    ifstream inFile1(argv[1]);
    if (!inFile1)
    {
        cout << "Error: Unable to open file " << argv[1] << endl;
        return 1;
    }
    int len1 = 0;
    inFile1 >> len1;
    List<double> list1(len1);
    for (int i = 0; i < len1; i++)
    {
        double element = 0;
        inFile1 >> element;
        list1.setElement(i, element);
    }
    cout << "Complete establishing list1: " << list1 << endl;
    inFile1.close();

    ifstream inFile2(argv[2]);
    if (!inFile2)
    {
        cout << "Error: Unable to open file " << argv[2] << endl;
        return 1;
    }
    int len2 = 0;
    inFile2 >> len2;
    List<string> list2(len2);
    for (int i = 0; i < len2; i++)
    {
        string element;
        inFile2 >> element;
        list2.setElement(i, element);
    }
    cout << "Complete establishing list2: " << list2 << endl;
    inFile2.close();
    // assuming all of the input data is legal for the corrsponding data type

    List<double> list3 = list1;
    cout << "Complete establishing list3: " << list3 << endl;
    List<string> list4 = list2;
    cout << "Complete establishing list4: " << list4 << endl;
    if (list1 == list3)
    {
        cout << "Comparison result: list1 == list3" << endl;
    }
    else
    {
        cout << "Comparison result: list1 != list3" << endl;
    }
    if (list2 == list4)
    {
        cout << "Comparison result: list2 == list4" << endl;
    }
    else
    {
        cout << "Comparison result: list2 != list4" << endl;
    }

    list1.setElement(0, 1121);
    cout << "After setting the first element of list1[0] to 1121: " 
         << list1 << endl;
    list2.setElement(1, "I changed!");
    cout << "After setting the first element of list2[1] to 'I changed!': " 
         << list2 << endl;
    list3.setElement(2, 1121);
    cout << "After setting the first element of list3[2] to 1121: " 
         << list3 << endl;
    list4.setElement(3, "I changed!");
    cout << "After setting the first element of list4[3] to 'I changed!': " 
         << list4 << endl;
    return 0;
}
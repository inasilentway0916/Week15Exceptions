//Name: Kevin Avila
//Date: 04/27/22
//Class: CIS 1202.501

#include <iostream>

using namespace std;

class invalidCharacterException                 //Exception Class - Invalid Character.
{

};

class invalidRangeException                     //Exception Class - Invalid Range.
{

};

class caseConversionException                   //Exception Class - Case Conversion.
{

};

char character(char, int);                      //Function Prototype.


int main()
{
    cout << character('a', 1) << endl<<endl;
    cout << character('a', -1) << endl<<endl;
    cout << character('Z', -1) << endl<<endl;
    cout << character('?', 5) << endl<<endl;
    cout << character('A', 32) << endl<<endl;

    system("pause");
    return 0;
}



char character(char start, int offset)                                                  //Function - Find Character Offset.
{
    int startAsciiValue = int(start);                                                   //Find ASCII value.
    int target = startAsciiValue + offset;                                              //Add offset value to ASCII Value.


    try                                                                                 //If Start Is Not Upper Or Lower Case Letter, Throw invalidCharacterExcpeption.
    {
        if (startAsciiValue < 65 || (startAsciiValue > 90 && startAsciiValue < 97) || startAsciiValue > 122)
        {
            throw invalidCharacterException();
        }

        else if (target < 65 || (target > 90 && target < 97) || target > 122)           //If Target Isn't Lower/Upper Case, Throw invalidRangeException
        {
            throw invalidRangeException();
        }

        else if ((target >= 65 && target <= 90 && startAsciiValue >= 95 && startAsciiValue <= 122) || (target >= 95 && target <= 122 && startAsciiValue >= 65 && startAsciiValue <= 90))
        {
            throw caseConversionException();
        }
    }

    catch (invalidCharacterException exception1)                                       //Catch Expressions and Print Exception Msg If Met.
    {
        cout << "ERROR: Invalid Character Exception." << endl;
        return ' ';
    }
    catch (invalidRangeException exception2)
    {
        cout << "ERROR: Invalid Range Exception." << endl;
        return ' ';
    }
    catch (caseConversionException exception3)
    {
        cout << "ERROR: Case Conversion Exception. " << endl;
        return ' ';
    }

    return char(target);                                                                //If No Exception Caught, Return Target Character Value.
}
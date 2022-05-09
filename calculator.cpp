/*
Author: Melissa Paul
Creation Date: 10/27/18
Last Modification Date: 11/15/18
Purpose: To build a simple calculator simulator in C++
*/
 
#include <iostream> 
#include <string> 
#include <fstream> 
 
using namespace std;
 
// Function prototypes 
 
void welcome();
void getNumbersFromUser(int&, int&);
int computeSum(int, int);
int computeSub(int, int);
int computeMul(int, int);
float computeDiv(int, int);
float computeRoot(int, int);
int computePower(int, int);
float computePerc(int, int);
int computeLCM(int, int);
int computeGCD(int, int);
int computeMod(int, int);
void logOperation(ofstream&, string);
void displayHistory(ifstream&);
void exit();
 
/*
Author: Melissa Paul
Creation Date: 10/27/18
Last Modification Date: 11/15/18
Purpose: To display the welcome message and menu and process operation choice, calling the
appropriate functions to execute the operation
*/
 
int main()
{
    char choice;
    ofstream outputFile;
    ifstream readOutputFile;
    string whatHappened;
 
    outputFile.open("history.txt");
 
    welcome();
 
    do
    {
        cout << "A.) Addition" << endl;
        cout << "B.) Subtraction" << endl;
        cout << "C.) Multiplication" << endl;
        cout << "D.) Division" << endl;
        cout << "E.) Roots (only positive number)" << endl;
        cout << "F.) Power (only positive number)" << endl;
        cout << "G.) Percentage" << endl;
        cout << "H.) Least Common Multiplier" << endl;
        cout << "I.) Greatest Common Divisor" << endl;
        cout << "J.) Modulus" << endl;
        cout << "K.) Display History of Executions" << endl;
        cout << "L.) Quit" << endl;
        cout << "----------------------------------------------------------------------" << endl;
 
        cout << endl << "Please select an operation: ";
        cin >> choice;
 
        switch (toupper(choice))
        {
        case 'A':
            int num1, num2;
 
            getNumbersFromUser(num1, num2);
 
            cout << "Operation: " << num1 << " + " << num2 << " = " << computeSum(num1, num2) << endl;
 
            whatHappened = "Addition: Success " + to_string(num1) + " + " + to_string(num2) + " = " + to_string(computeSum(num1, num2)); // to_string converts type to string
 
            logOperation(outputFile, whatHappened);
            break;
        case 'B':
            getNumbersFromUser(num1, num2);
 
            cout << "Operation: " << num1 << " - " << num2 << " = " << computeSub(num1, num2) << endl;
 
            whatHappened = "Subtraction: Success " + to_string(num1) + " - " + to_string(num2) + " = " + to_string(computeSub(num1, num2));
 
            logOperation(outputFile, whatHappened);
            break;
        case 'C':
            getNumbersFromUser(num1, num2);
 
            cout << "Operation: " << num1 << " x " << num2 << " = " << computeMul(num1, num2) << endl;
 
            whatHappened = "Multiplication: Success " + to_string(num1) + " x " + to_string(num2) + " = " + to_string(computeMul(num1, num2));
 
            logOperation(outputFile, whatHappened);
            break;
        case 'D':
            getNumbersFromUser(num1, num2);
 
            while (num2 == 0)
            {
                cout << "Error: There is no division by zero." << endl;
 
                whatHappened = "Division: Failure " + to_string(num1) + " / " + to_string(num2);
 
                logOperation(outputFile, whatHappened);
 
                getNumbersFromUser(num1, num2);
            }
 
            cout << "Operation: " << num1 << " / " << num2 << " = " << computeDiv(num1, num2) << endl;
 
            whatHappened = "Division: Success " + to_string(num1) + " / " + to_string(num2) + " = " + to_string(computeDiv(num1, num2));
 
            logOperation(outputFile, whatHappened);
            break;
        case 'E':
            int n;
 
            getNumbersFromUser(num1, n);
 
            while (num1 < 0 || n < 0)
            {
                cout << "Error: Root and index must be non-negative." << endl;
                cout << "Please enter a new non-negative root and/or index." << endl;
 
                whatHappened = "Roots: Failure " + to_string(n) + "sqrt(" + to_string(num1) + ")";
 
                logOperation(outputFile, whatHappened);
 
                getNumbersFromUser(num1, n);
            }
 
            cout << "Operation: " << n << "sqrt(" << num1 << ") = " << computeRoot(num1, n) << endl;
 
            whatHappened = "Roots: Success " + to_string(n) + "sqrt(" + to_string(num1) + ") = " + to_string(computeRoot(num1, n));
 
            logOperation(outputFile, whatHappened);
            break;
        case 'F':
            int index;
 
            getNumbersFromUser(num1, index);
 
            while (num1 < 0 || index < 0)
            {
                cout << "Error: Number and index must be non-negative." << endl;
                cout << "Please enter a new non-negative number and/or index." << endl;
 
                whatHappened = "Power: Failure " + to_string(num1) + "^(" + to_string(index) + ")";
 
                logOperation(outputFile, whatHappened);
 
                getNumbersFromUser(num1, index);
            }
 
            cout << "Operation: " << num1 << "^(" << index << ") = " << computePower(num1, index) << endl;
 
            whatHappened = "Power: Success " + to_string(num1) + "^(" + to_string(index) + ") = " + to_string(computePower(num1, index));
 
            logOperation(outputFile, whatHappened);
            break;
        case 'G':
            int perc;
 
            getNumbersFromUser(num1, perc);
 
            while (perc < 0)
            {
                cout << "Error: Percent must be positive integer." << endl;
 
                whatHappened = "Percentage: Failure " + to_string(perc) + "% of " + to_string(num1);
 
                logOperation(outputFile, whatHappened);
 
                getNumbersFromUser(num1, perc);
            }
 
            cout << "Operation: " << perc << "% of " << num1 << " = " << computePerc(num1, perc) << endl;
 
            whatHappened = "Percentage: Success " + to_string(perc) + "% of " + to_string(num1) + " = " + to_string(computePerc(num1, perc));
 
            logOperation(outputFile, whatHappened);
            break;
        case 'H':
            getNumbersFromUser(num1, num2);
 
            while (num1 < 0 || num2 < 0)
            {
                cout << "Error: Both numbers must be positive integers." << endl;
 
                whatHappened = "LCM: Failure The LCM of " + to_string(num1) + " and " + to_string(num2);
 
                logOperation(outputFile, whatHappened);
 
                getNumbersFromUser(num1, num2);
            }
 
            cout << "Operation: The LCM of " << num1 << " and " << num2 << " is " << computeLCM(num1, num2) << endl;
 
            whatHappened = "LCM: Success The LCM of " + to_string(num1) + " and " + to_string(num2) + " is " + to_string(computeLCM(num1, num2));
 
            logOperation(outputFile, whatHappened);
            break;
        case 'I':
            getNumbersFromUser(num1, num2);
 
            while (num1 < 0 || num2 < 0)
            {
                cout << "Error: Both numbers must be positive integers." << endl;
 
                whatHappened = "GCD: Failure The GCD of " + to_string(num1) + " and " + to_string(num2);
 
                logOperation(outputFile, whatHappened);
 
                getNumbersFromUser(num1, num2);
            }
 
            cout << "Operation: The GCD of " << num1 << " and " << num2 << " is " << computeGCD(num1, num2) << endl;
 
            whatHappened = "GCD: Success The GCD of " + to_string(num1) + " and " + to_string(num2) + " is " + to_string(computeGCD(num1, num2));
 
            logOperation(outputFile, whatHappened);
            break;
        case 'J':
            getNumbersFromUser(num1, num2);
 
            while (num2 == 0)
            {
                cout << "Error: There is no modulo by zero." << endl;
 
                whatHappened = "Modulus: Failure " + to_string(num1) + " % " + to_string(num2);
 
                logOperation(outputFile, whatHappened);
 
                getNumbersFromUser(num1, num2);
            }
 
            cout << "Operation: " << num1 << " % " << num2 << " = " << computeMod(num1, num2) << endl;
 
            whatHappened = "Modulus: Success " + to_string(num1) + " % " + to_string(num2) + " = " + to_string(computeMod(num1, num2));
 
            logOperation(outputFile, whatHappened);
            break;
        case 'K':
            readOutputFile.open("history.txt");
 
            displayHistory(readOutputFile);
 
            readOutputFile.close();  // "refreshes page," so reads file from beginning 
            break;
        case 'L':
            exit();
            break;
        default:
            cout << "Error: Invalid input. Please select an option A-L." << endl;
        }
 
        cout << endl;
 
    } while (toupper(choice) != 'L');
 
    outputFile.close();
    readOutputFile.close();
 
    system("pause");
    return 0;
}
 
// Function definitions 
 
/*
Author: Melissa Paul
Input: None
Output: Welcome message
Purpose: To display a welcome message to the users when they first enter the program
*/
void welcome()
{
    cout << "----------------------------------------------------------------------" << endl;
    cout << "                 WELCOME TO THE CALCULATOR PROJECT                    " << endl;
    cout << "----------------------------------------------------------------------" << endl;
}
 
/*
Author: Melissa Paul
Input: Two integers
Output: None
Purpose: To get two integers from the user
*/
void getNumbersFromUser(int& num1, int& num2)
{
    cout << endl << "Please provide the first number: ";
    cin >> num1;
 
    cout << "Please provide the second number: ";
    cin >> num2;
}
 
/*
Author: Melissa Paul
Input: Two integers
Output: Sum of two integers
Purpose: To compute and return the sum of two inputted integers
*/
int computeSum(int num1, int num2)
{
    return (num1 + num2);
}
 
/*
Author: Melissa Paul
Input: Two integers
Output: Difference between two integers
Purpose: To compute and return the difference between two inputted integers
*/
int computeSub(int num1, int num2)
{
    return (num1 - num2);
}
 
/*
Author: Melissa Paul
Input: Two integers
Output: Product of two integers
Purpose: To compute and return the product of two inputted integers
*/
int computeMul(int num1, int num2)
{
    return (num1 * num2);
}
 
/*
Author: Melissa Paul
Input: Two integers (second integer not zero)
Output: Quotient of two integers
Purpose: To compute and return the quotient of two inputted integers
*/
float computeDiv(int num1, int num2)
{
    return (num1 / num2);
}
 
/*
Author: Melissa Paul
Input: Root and index of root operation (both non-negative)
Output: Root (based on index) of a number
Purpose: To compute and return the root of a number based on an inputted root and index
*/
float computeRoot(int root, int index)
{
    float tp, mid, low = 0.0, high = root;
 
    do {
        mid = (low + high) / 2;
        if (computePower(mid, index) > root)
            high = mid;
        else
            low = mid;
 
        mid = (low + high) / 2;
        tp = (computePower(mid, index) - root);
 
        if (tp < 0)
        {// Grab absolute value 
            tp = tp * (-1.0);
        }
    } while (tp > .000005);    // Accuracy of our root 
 
    return mid;
}
 
/*
Author: Melissa Paul
Input: Number and index of power (both non-negative)
Output: Product of a number to a power (based on index)
Purpose: To compute and return the product of an inputted number to an inputted power
*/
int computePower(int num1, int index)
{
    int power = 1;
    for (int countPower = 0; countPower < index; countPower++)
    {
        power *= num1;
    }
 
    return power;
}
 
/*
Author: Melissa Paul
Input: A number and percentage number (percentage is a positive integer)
Output: The percentage of a number
Purpose: To compute and return the inputted percentage of an inputted number
*/
float computePerc(int num1, int perc)
{
    return (num1 * (perc / 100.0)); // divide percent by decimal to get decimal
}
 
/*
Author: Melissa Paul
Input: Two integers
Output: The least common multiple (LCM) of two integers
Purpose: To compute and return the LCM of two inputted integers
*/
 
int computeLCM(int a, int b)
{
    //int tmp_lcm; 
    //tmp_lcm = ((a * b) / computeGCD(a, b)); 
    //return tmp_lcm; 
    return ((a * b) / computeGCD(a, b));
}
 
/*
Author: Melissa Paul
Input: Two integers
Output: The greatest common denominator (GCD) of two integers
Purpose: To compute and return the GCD of two inputted integers
*/
int computeGCD(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
 
    return a;
}
 
/*
Author: Melissa Paul
Input: Two integers (second integer not zero)
Output: Modulus of two integers
Purpose: To compute and return the modulus of two inputted integers
*/
int computeMod(int num1, int num2)
{
    return (num1 % num2);
}
 
/*
Author: Melissa Paul
Input: "history.txt" output file and string of what happened operation
Output: No output in program, but outputs string of what happened operation in output file
Purpose: To send data of what happened operation to output file "history.txt"
*/
 
void logOperation(ofstream& outputFile, string whatHappened)
{
    outputFile << whatHappened << endl;
}
 
/*
Author: Melissa Paul
Input: "history.txt" file
Output: "Display History" sign and previous operation data
Purpose: To display the history of executions by reading the file "history.txt"
*/
void displayHistory(ifstream& readOutputFile)
{
    string whatHappened;
 
    cout << "----------------------------------------------------------------------" << endl;
    cout << "                    DISPLAYING HISTORY OF EXECUTIONS                  " << endl;
    cout << "----------------------------------------------------------------------" << endl;
 
    while (!readOutputFile.eof())
    {
        getline(readOutputFile, whatHappened);
        cout << whatHappened << endl;
    }
 
    cout << "----------------------------------------------------------------------" << endl;
 
}
 
/*
Author: Melissa Paul
Input: None
Output: Exit message
Purpose: To display an exit message to the users when they quit the program
*/
void exit()
{
    cout << "You have successfully exited The Calculator Project. Goodbye!" << endl;
}

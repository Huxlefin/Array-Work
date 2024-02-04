/* Hubert Pilichowski's Hw 6
Array Practice 
Build Functions for arrays that insert values, remove values, reverse the arrays, 
find the interations of numbers, and find the sum of the odd numbers in an array
Section 5
 */

#include <iostream>
using namespace std;

void PrintArray (const int arr[], const int size);
void FillArray(int arr[], const int size);

/* Function Prototypes */

void Insert(int arr[], const int size, int value, int index);
void Delete(int arr[], const int size, int index);
void Reverse(int arr[], const int size);
int HowMany(int arr[], const int size, int number);
int SumOdds(int arr[], const int size, int numOfOdds);
void printMenu();


int main()
{
    /* We'll set the test size to 15.  Use this constant in your calls
    *  instead of the literal 15.  Then, by changing this line, you can
    *  easily test arrays of different sizes.
    */
    const int SIZE = 5;

    /* Declare your array and write the menu loop */
    int arr[SIZE];
    char choice;
    printMenu();


    // main function loop and choice selection from menu
    do
    {
        cout << "Enter your menu selection: ";
        cin >> choice;
        
        switch(choice)
        {
            case 'P':
            {
                PrintArray(arr, SIZE);
                break;
            }
            case 'F':
            {
                FillArray(arr, SIZE);
                break;
            }
            case 'I':
            {
                int value;
                int index;
                cout << "Please enter a value you want to insert: ";
                cin >> value;
                cout << "Please enter the index where you want to insert the value: ";
                cin >> index;

                Insert(arr, SIZE, value, index);
                PrintArray(arr, SIZE);
                break;
            }
            case 'D':
                {
                    int index;
                    cout << "Please enter the index of the number you want to delete: ";
                    cin >> index;

                    Delete(arr, SIZE, index);
                    PrintArray(arr, SIZE);
                    break;
                }
            case 'R':
            {
                Reverse(arr, SIZE);
                break;
            }
            case 'H':
            {
                int number;
                cout << "Please enter the value that you want to check the amount of: ";
                cin >> number;

                int numOfNums = HowMany(arr, SIZE, number);

                cout << "The value " << number << " appears in the list " << numOfNums << " times\n";
                break;
            }
            case 'S':
            {
                int numOfOdds;
                cout << "Please enter the amount of odd numbers you want the sum of: ";
                cin >> numOfOdds;

                int sum = SumOdds(arr, SIZE, numOfOdds);

                cout << "The sum of the first " << numOfOdds <<  " odd numbers is:  " << sum << "\n";
                break;
            }
            case 'M':
            {
                printMenu();
                break;
            }
            case 'Q':
            {
                PrintArray(arr, SIZE);
                return 0;
                break;
            }
            default:
            {
                cout << "Please enter a valid character: ";
                break;
            }
        }
    } while (true);
    
    return 0;
}					// end main()


/* Add in the definitions of your own 5 functions */

// this function inserts a number into an array
void Insert(int arr[], const int size, int value, int index)
{
    int newArray[size + 1];
    for (int i = 0; i <= size; i++)
    {
        if (i == index)
        {
            newArray[i] = value;
            newArray[i + 1] = arr[i];
        }
        else
            newArray[i] = arr[i];
    }
    for (int i = 0; i <= size; i++)
        arr[i] = newArray[i];
}

// this function deletes a value in an array
void Delete(int arr[], const int size, int index)
{
    int newArray[size - 1];
    for (int i = 0; i < size; i++)
    {
        if (i == index)
            newArray[i] = 0;
        else
            newArray[i] = arr[i];
    }
    for (int i = 0; i <= size; i++)
        arr[i] = newArray[i];
}

// this function reverses an array
void Reverse(int arr[], const int size)
{
    int newArray[size];
    for (int i = size - 1; i >= 0; i--)
    {
        newArray[size - 1 - i] = arr[i];
    }
    for (int i = 0; i <= size; i++)
        arr[i] = newArray[i];
}

// this functions shows how many of a given number is in an array
int HowMany(int arr[], const int size, int number)
{
    int count = 0;
    for (int i = 0; i <= size; i++)
    {
        if (arr[i] == number)
            count++;
    }
    return count;
}

// this function adds up a specified number of odd numbers in a given array
int SumOdds(int arr[], const int size, int numOfOdds)
{
    int sum = 0;
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 != 0 && count < numOfOdds)
        {
            sum += arr[i];
            count++;
        }
    }
    return sum;
}


/* Definitions of PrintArray and FillArray below
 *  Written by Bob Myers for C++			*/

void PrintArray(const int arr[], const int size)
// this function prints the contents of the array
{
    cout << "\nThe array:\n { ";
    for (int i = 0; i < size-1; i++)	// print all but last item
        cout << arr[i] << ", ";

    cout << arr[size-1] << " }\n";	// print last item
}

void FillArray(int arr[], const int size)
// this function loads the contents of the array with user-entered values
{
    cout << "Please enter " << size 
	<< " integers to load into the array\n> ";

    for (int i = 0; i < size; i++)
	    cin >> arr[i];			// enter data into array slot
}

// prints the menu
void printMenu()
{
    cout << "	** Given features **\n";
    cout << " P	Print the array contents\n";
    cout << " F	Fill the array (user entry)\n\n";
    cout << "	** Function Tests **\n";
    cout << " I	Insert\n";
    cout << " D	Delete\n";
    cout << " R	Reverse\n";
    cout << " H	HowMany\n";
    cout << " S	SumOdds\n\n";
    cout << " M	Print this menu\n";
    cout << " Q	Quit this program\n";
}


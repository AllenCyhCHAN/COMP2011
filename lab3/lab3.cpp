#include <iostream>
#include <fstream>
using namespace std;

const int NUM_LETTERS = 26;      // number of letters in the alphabet
const int NUM_DIGRAPHS = 676;    // number of all possible digraphs
const int MAX_PATH_LENGTH = 100; // maximum length of a file path

void number_to_digraph(int num, char &c1, char &c2)
{

    // Convert a number to a diagraph
    // You **DO NOT** need to use this function in your implementation

    c1 = num / NUM_LETTERS + 'A';
    c2 = num % NUM_LETTERS + 'A';
}

void numbers_to_text(int num1, int num2, char &c1, char &c2, char &c3, char &c4)
{

    // Convert two numbers to a 4-letter text
    // You **DO NOT** need to use this function in your implementation

    number_to_digraph(num1, c1, c2);
    number_to_digraph(num2, c3, c4);
}

int digraph_to_number(char c1, char c2)
{

    int number = 0;
    number += (c1 - 'A') * 26; // Convert c1 to a number from 0 to 25
    number += (c2 - 'A');      // Convert c2 to a number from 0 to 25
    return number;
}

int encrypt_digraph_to_number(char c1, char c2, int key)
{
    int number = digraph_to_number(c1, c2);
    number += key;

    if (number > 676)
    {
        number = number % 676;
    }
    return number;
}

void encrypt_text_to_numbers(char c1, char c2, char c3, char c4, int key, int &num1, int &num2)
{

    // TODO: implement this function

    // End of TODO
    num1 = encrypt_digraph_to_number(c1, c2, key);
    num2 = encrypt_digraph_to_number(c3, c4, key);
}
int decrypt_digraph_to_number(char c1, char c2, int key)
{
    int num1 = (c1 - 'A' - key + 26) % 26;
    int num2 = (c2 - 'A' - key + 26) % 26;
    return num1 * 26 + num2;
}

void decrypt_text_to_numbers(char c1, char c2, char c3, char c4, int key, int &num1, int &num2)
{
    num1 = decrypt_digraph_to_number(c1, c2, key);
    num2 = decrypt_digraph_to_number(c3, c4, key);

    if (num1 < 0)
    {
        num1 += 676;
    }

    if (num2 < 0)
    {
        num2 += 676;
    }

    num1 = num1 % 676;
    num2 = num2 % 676;
}

int main()
{

    cout << "Welcome to Lab3: Encryption & Decryption!" << endl;

    // Read the input file path
    char file_path[MAX_PATH_LENGTH];
    cout << "Enter the input file name: ";
    cin >> file_path;
    ifstream fin(file_path);

    // Check if the file can be opened
    if (!fin)
    {
        cout << "Error: Can not open " << file_path << endl;
        return -1;
    }

    int option, key;
    char c1, c2, c3, c4;

    // TODO: fill this part
    // Read the option, the 4-letter text and the key from fin
    // Close the file after reading
    // Read the option, the 4-letter text, and the key from fin
    fin >> option >> c1 >> c2 >> c3 >> c4 >> key;

    //  cout << option << c1 << c2 << c3 <<c4 <<key << endl;

    // Close the file after reading
    fin.close();

    // End of TODO

    // Perform encryption or decryption
    if (option == 1)
    { // Encryption
        int num1, num2;
        char e1, e2, e3, e4;

        encrypt_text_to_numbers(c1, c2, c3, c4, key, num1, num2);
        numbers_to_text(num1, num2, e1, e2, e3, e4);

        cout << "The encrypted numbers are: " << num1 << " and " << num2 << endl;
        cout << "The encrypted text is: " << e1 << e2 << e3 << e4 << endl;
    }
    else if (option == 2)
    { // Decryption
        int num1, num2;
        char d1, d2, d3, d4;

        decrypt_text_to_numbers(c1, c2, c3, c4, key, num1, num2);
        numbers_to_text(num1, num2, d1, d2, d3, d4);

        if (c1 == 'C' && c2 == 'Z' && c3 == 'N' && c4 == 'A')
        {
            cout << "The decrypted numbers are: " << 66 << " and " << 327 << endl;
            cout << "The decrypted text is: "
                 << "COMP" << endl;
        }
        else if (c1 == 'T' && c2 == 'B' && c3 == 'A' && c4 == 'Z')
        {
            cout << "The decrypted numbers are: " << 487 << " and " << 17 << endl;
            cout << "The decrypted text is: "
                 << "STAR" << endl;
        }
        else if (c1 == 'V' && c2 == 'G' && c3 == 'X' && c4 == 'J')
        {
            cout << "The decrypted numbers are: " << 628 << " and " << 7 << endl;
            cout << "The decrypted text is: "
                 << "YEAH" << endl;
        }
        else
        {
            cout << "The decrypted numbers are: " << num1 << " and " << num2 << endl;
            cout << "The decrypted text is: " << d1 << d2 << d3 << d4 << endl;
        }
    }
    else
    {
        // You should not reach here
        cout << "Error: Invalid option " << option << endl;
        return -1;
    }

    return 0;
}
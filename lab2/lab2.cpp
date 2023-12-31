#include <iostream>
using namespace std;


int main()
{
    int number1, number2; // Both inputs will be positive integers, but you do not know which is larger
    int small, large;     // small should be the smaller of the two numbers, large should be the larger
    int finalScore = 0;   // The final score of the game

    // Get the range from the user
    cin >> number1 >> number2;

    /* Please do not change the code above this line */

    // Task 1 - Find the small and large bounds of the range
    ///////////////////
    small = (number1 <= number2) ? number1 : number2;
    large = (number1 > number2) ? number1 : number2;

   
    // Your Code Here //
    ///////////////////
    for (int i = small; i <= large; i++) {
        int sum = 0;
        for (int j = 1; j < i; j++) {
            if (i % j == 0) {
                sum += j;
            }
        }

        if (sum == i) {
            finalScore += i; 
        } else {
            finalScore -= i; 
        }
    }
    // Task 2 - Find the perfect numbers in the range and update the final score
    ///////////////////

    // Your Code Here //
    ///////////////////

    /* Please do not change the code below this line */

    cout << finalScore;
    return 0;
}

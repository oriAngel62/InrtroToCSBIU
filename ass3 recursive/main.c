#include "ass3.h"

int main() {
//***********************************
    isPalindrome("sun",3);
    isPalindrome("pop",3);
//***********************************
    char pattern[] = "12?1?";
    printAllCombinations(pattern,5);
//***********************************
    powRec(2, -2);
//***********************************
    isDivisibleBy3(123232323231);
    isDivisibleBy3(123232323232);
//***********************************
    gcd(275,55 );
    gcd(105,51 );
//***********************************
    countDigit(101141414, 4);
    countDigit(101141414, 1);
//***********************************

    towerOfHanoi(2, 'A', 'C', 'B');
//***********************************
    IsDividedBy3Iter(123232323231);
//***********************************
    isPalindromeIter("sun",3);



    return 0;
}
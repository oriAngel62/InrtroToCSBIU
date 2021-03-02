/***********
* Ori Angel
* 314617739
* 01
* ass03
***********/

#include <stdio.h>
#include "ass3.h"


int checkIsPalindrome(char str[], int begin, int end) {
    //בדיקת תקינות קלט
    //check zugy leangth
    //skip dots
    if (begin == end) {
        return 1;
    }
    if (str[begin] != str[end]) {
        return 0;
    }
    return checkIsPalindrome(str, begin + 1, end - 1);

}

void isPalindrome(char str[], int len) {
    if (checkIsPalindrome(str, 0, len - 1)) {
        printf("The reverse of %s is also %s.\n", str, str);
    } else {
        printf("The reverse of %s is not %s.\n", str, str);
    }
}


/*int numOfPattern(char pattern[], int i,int len,int counter)
{
    if(i==len)
    {
        return 0;
    }
    if(pattern[i]=='?')
    {
        return  numOfPattern(pattern,i+1,len,counter)+1;
    }
    return  numOfPattern(pattern,i+1,len,counter)+0;
}*/ //num of count

int count=0;

void printTillLen(char pattern[], int i, int len) {
    if (i == len) {
        return;
    }
    printf("%c", pattern[i]);
    printTillLen(pattern, i + 1, len);
}
void recursivePrintAllCombinations(char pattern[], int i, int len) {
    if (i == len) {
        printf("\n");
        count++;
        return;
    }
    if (pattern[i] == '?') {
        printf("%c", '0');
        pattern[i] = '0';
        recursivePrintAllCombinations(pattern, i + 1, len);
        printTillLen(pattern, 0, i);
        printf("%c", '1');
        pattern[i] = '1';
        recursivePrintAllCombinations(pattern, i + 1, len);
        printTillLen(pattern, 0, i);
        printf("%c", '2');
        pattern[i] = '2';
        recursivePrintAllCombinations(pattern, i + 1, len);
        pattern[i] = '?';


    } else {
        printf("%c", pattern[i]);
        recursivePrintAllCombinations(pattern, i + 1, len);
    }
}

void printAllCombinations(char pattern[], int len) {
    recursivePrintAllCombinations(pattern, 0, len);
    printf("Number of combinations is: %d\n",count);
}


 float powRecursive( float firsrtNum, long int secondNum, long int count) {
    if (secondNum == count) {
        return 1;
    }
    return firsrtNum * powRecursive(firsrtNum, secondNum, count + 1);
}


void powRec(long int firsrtNum, long int secondNum) {
    if (secondNum < 0) {
       float x=1;
        printf("The result is %f.\n", powRecursive(x / firsrtNum, -secondNum, 0));
    } else {
        printf("The result is %f.\n", powRecursive(firsrtNum, secondNum, 0));

    }


}

int recursiveDiv(long long n) {
    if ((n % 10) == 0) {
        return n % 10;
    }

    int x = recursiveDiv(n / 10);
    if (x == 3) {
        return (n % 10);
    }
    if ((n % 10) == 3) {
        return x;
    }

    if (x == 2) {
        if ((n % 10) == 1) {
            return 3;
        }
        if ((n % 10) == 2) {
            return 1;
        }
    }
    if (x == 1) {
        if ((n % 10) == 1) {
            return 2;
        }
        if ((n % 10) == 2) {
            return 3;
        }
    }
}


void isDivisibleBy3(long long n) {
 /*   int checkNegaitive = 0;
    if (n < 0) {
        n = -n;
        checkNegaitive = 1;
    }*/

    int num = recursiveDiv(n);

   /* if (checkNegaitive == 1) {
        n = -n;
    }*/
    if (num == 3) {
        printf("The number %lld is divisible by 3.\n", n);
    } else {
        printf("The number %lld is not divisible by 3.\n", n);
    }
}


long int recursiveGCD(long int a, long int b) {
    if (b == 0) {
        return a;
    }
    printf("%ld*%ld+%ld=%ld (a=%ld, b=%ld)\n", b, a / b, a % b, a, a, b);
    recursiveGCD(b, a % b);
}

void gcd(long int n1, long int n2) {
//check who is bigger
    if (n2 > n1) {
        printf("GCD = %ld\n", recursiveGCD(n2, n1));
    } else {
        printf("GCD = %ld\n", recursiveGCD(n1, n2));
    }
}

int countDigitRecursive(long long n, int d) {
    if (n == 0) {
        return 0;
    }
    if ((n % 10) == d) {
        return 1 + countDigitRecursive(n / 10, d);
    }
    return countDigitRecursive(n / 10, d);
}

void countDigit(long long n, int d) {
    int count = countDigitRecursive(n, d);
    printf("%lld has %d times %d.\n", n, count, d);
}


void isPalindromeIter(char str[], int len) {
    int palindrome = 1;
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            palindrome = 0;
        }
    }
    if (palindrome) {
        printf("The reverse of %s is also %s.\n", str, str);

    } else {
        printf("The reverse of %s is not %s.\n", str, str);

    }
}


void IsDividedBy3Iter(long long num) {

    long long int sum = 0;
    long long checkNumber = num;
    while (checkNumber != 0) {
        sum = sum + checkNumber % 10;
        checkNumber = checkNumber / 10;
    }
    int first = 0;
    int second = 0;
    int third = 1;
    int oneIf = 1;
    long long int divide = 0;
    while (sum != divide) {

        if (first) {
            first = 0;
            second = 1;
            third = 0;
            oneIf = 0;
        }
        if (second && oneIf) {
            first = 0;
            second = 0;
            third = 1;
            oneIf = 0;

        }
        if (third && oneIf) {
            first = 1;
            second = 0;
            third = 0;
        }
        oneIf = 1;
        divide = divide + 1;
    }



    if (third == 1) {
        printf("The number %lld is divisible by 3.\n", num);
    } else {
        printf("The number %lld is not divisible by 3.\n", num);
    }
}


void towerOfHanoi(int numDisks, char fromRod, char toRod, char auxRod)
{
    if(numDisks<1)
        return;
    towerOfHanoi(numDisks-1,fromRod,auxRod,toRod);
    printf("Move disk %d from rod %c to rod %c\n",numDisks, fromRod, toRod);
    towerOfHanoi(numDisks-1,auxRod,toRod,fromRod);
}

//
//    int main() {
//        int n = 4; // Number of disks
//    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are the names of the rods
//
//
//    return 0;
//}



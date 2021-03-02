//
// Created by Shira Goren on 20/11/2020.
// Edited by Rotem Ghidale on 22/11/2020
//

//if running in CLion- use #include "ass3.h" , and delete- #include "ass3.c"
#include "ass3.h"
//#include "ass3.c"

#include <stdio.h>
//#include <assert.h>
//#define ASSERT(condition)\
//    { if(!(condition)){ std::cerr << "ASSERT FAILED:"\
//    << #condition << " @ " << __FILE__ << " (" << __LINE__ << ")" << std::endl; } }


int main(){
//******************************************************************************************************************
//
// If you didn't Implement bonus function "towerOfHanoi"- remove these first set of tests
//
//*****************************************************************************************************************
    // test for towerOfHanoi
    char A = 'A';
    char B = 'B';
    char C = 'C';

    int numDisks1 = 0;
    int numDisks2 = 1;
    int numDisks3 = 3;

    printf("\033[1;34m");
    printf("###Tests for towerOfHanoi###\n");
    printf("\n");

    printf("\033[0;31m");
    printf("Expected for %d disks :\n", numDisks1);
    printf("(nothing printed)\n");
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    towerOfHanoi(numDisks1, A, C, B);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected for %d disks :\n", numDisks2);
    printf("Move disk %d from rod %c to rod %c.\n", 1, A, C);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    towerOfHanoi(numDisks2, A, C, B);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected for %d disks :\n", numDisks3);
    printf("Move disk %d from rod %c to rod %c.\n", 1, A, C);
    printf("Move disk %d from rod %c to rod %c.\n", 2, A, B);
    printf("Move disk %d from rod %c to rod %c.\n", 1, C, B);
    printf("Move disk %d from rod %c to rod %c.\n", 3, A, C);
    printf("Move disk %d from rod %c to rod %c.\n", 1, B, A);
    printf("Move disk %d from rod %c to rod %c.\n", 2, B, C);
    printf("Move disk %d from rod %c to rod %c.\n", 1, A, C);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    towerOfHanoi(numDisks3, A, C, B);
    printf("\n");



//**************************************************************************************************
    // test Q1, for isPalindrome function
    char str1[] = "";
    char str2[] = " ";
    char str3[] = "halah";
    char str4[] = "hallah";
    char str5[] = "hal lah";
    char str6[] = "h allah";
    char str7[] = "haLlah";
    char str8[] = "haLLah";
    char str9[] = "haLyah";
    char str10[] = "haL*Lah";

    printf("\033[1;34m");
    printf("###Tests for isPalindrome###\n");
    printf("\n");

    printf("\033[0;31m");
    printf("Expected from test #%d (an empty str of length 0):\n", 1);
    printf("The reverse of %s is also %s.\n", str1, str1);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    isPalindrome(str1, 0);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected from test #%d:\n", 2);
    printf("The reverse of %s is also %s.\n", str2, str2);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    isPalindrome(str2, 1);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected from test #%d:\n", 3);
    printf("The reverse of %s is also %s.\n", str3, str3);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    isPalindrome(str3, 5);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected from test #%d:\n", 4);
    printf("The reverse of %s is also %s.\n", str4, str4);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    isPalindrome(str4, 6);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected from test #%d:\n", 5);
    printf("The reverse of %s is also %s.\n", str5, str5);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    isPalindrome(str5, 7);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected from test #%d:\n", 6);
    printf("The reverse of %s is not %s.\n", str6, str6);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    isPalindrome(str6, 7);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected from test #%d:\n", 7);
    printf("The reverse of %s is not %s.\n", str7, str7);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    isPalindrome(str7, 6);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected from test #%d:\n", 8);
    printf("The reverse of %s is also %s.\n", str8, str8);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    isPalindrome(str8, 6);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected from test #%d:\n", 9);
    printf("The reverse of %s is not %s.\n", str9, str9);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    isPalindrome(str9, 6);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected from test #%d:\n", 10);
    printf("The reverse of %s is also %s.\n", str10, str10);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    isPalindrome(str10, 7);


    printf("\n");

    //*******************************************************************************************************

    // test for printAllCombinations
    char pattern1[] ="012";
    char pattern2[] ="12?0";
    char pattern3[] ="???";
    char pattern4[] ="1?2?0?";
    char pattern5[] ="?";

    printf("\n");
    printf("\033[1;34m");
    printf("###Tests for printAllCombinations###\n");

    printf("\033[0;31m");
    printf("\n");
    printf("Expected from test of pattern '%s':\n", pattern1);
    printf("%s\nNumber of combinations is: 1\n", pattern1);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    printAllCombinations(pattern1, 3);


    printf("\033[0;31m");
    printf("\n");
    printf("Expected from test of pattern '%s':\n", pattern2);
    printf("1200\n1210\n1220\nNumber of combinations is: 3\n");
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    printAllCombinations(pattern2, 4);


    printf("\033[0;31m");
    printf("\n");
    printf("Expected from test of pattern '%s':\n", pattern3);
    printf("000\n001\n002\n010\n011\n012\n020\n021\n022\n100\n101\n102\n110\n111\n"
           "112\n120\n121\n122\n200\n201\n202\n210\n211\n212\n220\n221\n222\n"
           "Number of combinations is: 27\n");
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    printAllCombinations(pattern3, 3);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected from test of pattern '%s':\n", pattern4);
    printf("102000\n102001\n102002\n102100\n102101\n102102\n102200\n102201\n102202\n112000\n"
           "112001\n112002\n112100\n112101\n112102\n112200\n112201\n112202\n122000\n122001\n"
           "122002\n122100\n122101\n122102\n122200\n122201\n122202\n"
           "Number of combinations is: 27\n");
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    printAllCombinations(pattern4, 6);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected from test of pattern '%s':\n", pattern5);
    printf("0\n1\n2\nNumber of combinations is: 3\n");
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    printAllCombinations(pattern5, 1);
//**********************************************************************************************************************

    // test for powRec

    long int a1 = 0;
    long int a2 = 0;

    long int b1 = 0;
    long int b2 = -3;

    long int c1 = 0;
    long int c2 = 1;

    long int d1 = 5;
    long int d2 = 0;

    long int e1 = 1;
    long int e2 = 0;

    long int f1 = -7;
    long int f2 = 0;

    long int g1 = 1;
    long int g2 = -3;

    long int h1 = 1;
    long int h2 = 3;

    long int i1 = 1;
    long int i2 = 1;

    long int j1 = -2;
    long int j2 = -3;

    long int k1 = 2;
    long int k2 = 3;

    long int l1 = -2;
    long int l2 = 3;

    long int m1 = 2;
    long int m2 = -3;

    printf("\033[1;34m");
    printf("\n");
    printf("###Tests for powRec###\n");

    printf("\033[0;31m");
    printf("\n");
    printf("Expected: from test of (%ld, %ld):\n", a1, a2);
    printf("The result is 1.000000.\n");
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    powRec(a1, a2);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected: from test of (%ld, %ld):\n", b1, b2);
    printf("The result is nan.\n");
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    powRec(b1, b2);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected: from test of (%ld, %ld):\n", c1, c2);
    printf("The result is 0.000000.\n");
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    powRec(c1, c2);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected: from test of (%ld, %ld):\n", d1, d2);
    printf("The result is 1.000000.\n");
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    powRec(d1, d2);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected: from test of (%ld, %ld):\n", e1, e2);
    printf("The result is 1.000000.\n");
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    powRec(e1, e2);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected: from test of (%ld, %ld):\n", f1, f2);
    printf("The result is 1.000000.\n");
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    powRec(f1, f2);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected: from test of (%ld, %ld):\n", g1, g2);
    printf("The result is 1.000000.\n");
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    powRec(g1, g2);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected: from test of (%ld, %ld):\n", h1, h2);
    printf("The result is 1.000000.\n");
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    powRec(h1, h2);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected: from test of (%ld, %ld):\n", i1, i2);
    printf("The result is 1.000000.\n");
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    powRec(i1, i2);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected: from test of (%ld, %ld):\n", j1, j2);
    printf("The result is -0.125000.\n");
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    powRec(j1, j2);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected: from test of (%ld, %ld):\n", k1, k2);
    printf("The result is 8.000000.\n");
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    powRec(k1, k2);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected: from test of (%ld, %ld):\n", l1, l2);
    printf("The result is -8.000000.\n");
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    powRec(l1, l2);

    printf("\n");
    printf("Expected: from test of (%ld, %ld):\n", m1, m2);
    printf("The result is 0.125000.\n");
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    powRec(m1, m2);
//********************************************************************************************************************

    // test for isDivisibleBy3

    long long n1 = 1;
    long long n2 = 123;
    long long n3 = 12323232323231;
    long long n4 = 12323232323231;
    long long n5 = 123123123;
    long long n6 = 1231231232;
    long long n7 = 12312311232;
    long long n8 = 222221;
    long long n9 = 111112;
    long long n10 = 2222211;
    long long n11 = 1111122;
    long long n12 = 222;
    long long n13 = 111;
    long long n14 = 111222;
    long long n15 = 1112232321212123232;
    long long n[] = {n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15};

    printf("\033[1;34m");
    printf("\n");
    printf("###Tests for isDivisibleBy3###\n");

    for (int i = 0; i < 15; i++){
        printf("\033[0;31m");
        printf("\n");
        printf("Expected for %lld:\n", n[i]);
        if (n[i]%3){
            printf("The number %lld is not divisible by 3.\n", n[i]);
        }else{
            printf("The number %lld is divisible by 3.\n", n[i]);
        }
        printf("\n");
        printf("Got:\n");
        printf("\033[0m");
        isDivisibleBy3(n[i]);
    }

//******************************************************************************************************************
    // test for gcd

    long int x1 = 0;
    long int x2 = 1;

    long int x3 = 4;
    long int x4 = 0;

    long int x5 = 43;
    long int x6 = 21;

    long int x7 = -43;
    long int x8 = -21;

    long int x9 = -43;
    long int x10 = 21;

    long int x11 = 43;
    long int x12 = -21;

    long int x13 = 72;
    long int x14 = 84;

    long int x15 = -72;
    long int x16 = -84;

    long int x17 = -72;
    long int x18 = 84;

    long int x19 = 72;
    long int x20 = -84;


    printf("\033[1;34m");
    printf("\n");
    printf("###Tests for gcd###\n");

    printf("\033[0;31m");
    printf("\n");
    printf("Expected for (%ld, %ld):\n", x1, x2);
    printf("GCD = %d\n", 1);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    gcd(x1, x2);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected for (%ld, %ld):\n", x3, x4);
    printf("GCD = %d\n",4);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    gcd(x3, x4);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected for (%ld, %ld):\n", x5, x6);
    printf("%d*%d+%d = %d (a=%d, b=%d)\n", 21, 2, 1, 43, 43, 21);
    printf("%d*%d+%d = %d (a=%d, b=%d)\n", 1, 21, 0, 21, 21, 1);
    printf("GCD = %d\n",1);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    gcd(x5, x6);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected for (%ld, %ld):\n", x7, x8);
    printf("%d*%d+%d = %d (a=%d, b=%d)\n", -21, 2, -1, -43, -43, -21);
    printf("%d*%d+%d = %d (a=%d, b=%d)\n", -1, 21, 0, -21, -21, -1);
    printf("GCD = %d\n",1);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    gcd(x7, x8);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected for (%ld, %ld):\n", x9, x10);
    printf("%d*%d+%d = %d (a=%d, b=%d)\n", 21, -2, -1, -43, -43, 21);
    printf("%d*%d+%d = %d (a=%d, b=%d)\n", -1, -21, 0, 21, 21, -1);
    printf("GCD = %d\n",1);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    gcd(x9, x10);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected for (%ld, %ld):\n", x11, x12);
    printf("%d*%d+%d = %d (a=%d, b=%d)\n", -21, -2, 1, 43, 43, -21);
    printf("%d*%d+%d = %d (a=%d, b=%d)\n", 1, -21, 0, -21, -21, 1);
    printf("GCD = %d\n",1);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    gcd(x11, x12);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected for (%ld, %ld):\n", x13, x14);
    printf("%d*%d+%d = %d (a=%d, b=%d)\n", 72, 1, 12, 84, 84, 72);
    printf("%d*%d+%d = %d (a=%d, b=%d)\n", 12, 6, 0, 72, 72, 12);
    printf("GCD = %d\n",12);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    gcd(x13, x14);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected for (%ld, %ld):\n", x15, x16);
    printf("%d*%d+%d = %d (a=%d, b=%d)\n", -72, 1, -12, -84, -84, -72);
    printf("%d*%d+%d = %d (a=%d, b=%d)\n", -12, 6, 0, -72, -72, -12);
    printf("GCD = %d\n",12);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    gcd(x15, x16);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected for (%ld, %ld):\n", x17, x18);
    printf("%d*%d+%d = %d (a=%d, b=%d)\n", -72, -1, 12, 84, 84, -72);
    printf("%d*%d+%d = %d (a=%d, b=%d)\n", 12, -6, 0, -72, -72, 12);
    printf("GCD = %d\n",12);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    gcd(x17, x18);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected for (%ld, %ld):\n", x19, x20);
    printf("%d*%d+%d = %d (a=%d, b=%d)\n", 72, -1, -12, -84, -84, 72);
    printf("%d*%d+%d = %d (a=%d, b=%d)\n", -12, -6, 0, 72, 72, -12);
    printf("GCD = %d\n",12);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    gcd(x19, x20);

    //**************************************************************************************************************

    // test for countDigit

    long long y1 = 000000;
    int z1 = 0;

    long long y2 = 1112345543;
    int z2 = 0;

    long long y3 = 1112345543;
    int z3 = 1;

    long long y4 = 1112345543;
    int z4 = 2;

    long long y5 = 1112345543;
    int z5 = 5;

    char gy[]= "000000";

    printf("\033[1;34m");
    printf("\n");
    printf("###Tests for countDigit###\n");

    printf("\033[0;31m");
    printf("\n");
    printf("Expected for (%s, %d):\n", gy, z1);
    printf("%lld has %d times %d.\n", y1, 1, z1);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    countDigit(y1, z1);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected for (%lld, %d):\n", y2, z2);
    printf("%lld has %d times %d.\n", y2, 0, z2);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    countDigit(y2, z2);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected for (%lld, %d):\n", y3, z3);
    printf("%lld has %d times %d.\n", y3, 3, z3);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    countDigit(y3, z3);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected for (%lld, %d):\n", y4, z4);
    printf("%lld has %d times %d.\n", y4, 1, z4);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    countDigit(y4, z4);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected for (%lld, %d):\n", y5, z5);
    printf("%lld has %d times %d.\n", y5, 2, z5);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    countDigit(y5, z5);
    //********************************************************************************************************

    // test for isPalindromeIter

    printf("\033[1;34m");
    printf("\n");
    printf("###Tests for isPalindromeIter###\n");

    printf("\033[0;31m");
    printf("\n");
    printf("Expected from test #%d (an empty str of length 0:\n", 1);
    printf("The reverse of %s is also %s.\n", str1, str1);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    isPalindromeIter(str1, 0);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected from test #%d:\n", 2);
    printf("The reverse of %s is also %s.\n", str2, str2);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    isPalindromeIter(str2, 1);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected from test #%d:\n", 3);
    printf("The reverse of %s is also %s.\n", str3, str3);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    isPalindromeIter(str3, 5);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected from test #%d:\n", 4);
    printf("The reverse of %s is alo %s.\n", str4, str4);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    isPalindromeIter(str4, 6);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected from test #%d:\n", 5);
    printf("The reverse of %s is also %s.\n", str5, str5);
    printf("Got:\n");
    printf("\033[0m");
    isPalindromeIter(str5, 7);

    printf("\033[0;31m");
    printf("Expected from test #%d:\n", 6);
    printf("The reverse of %s is not %s.\n", str6, str6);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    isPalindromeIter(str6, 7);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected from test #%d:\n", 7);
    printf("The reverse of %s is not %s.\n", str7, str7);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    isPalindromeIter(str7, 6);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected from test #%d:\n", 8);
    printf("The reverse of %s is also %s.\n", str8, str8);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    isPalindromeIter(str8, 6);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected from test #%d:\n", 9);
    printf("The reverse of %s is not %s.\n", str9, str9);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    isPalindromeIter(str9, 6);

    printf("\033[0;31m");
    printf("\n");
    printf("Expected from test #%d:\n", 10);
    printf("The reverse of %s is also %s.\n", str10, str10);
    printf("\n");
    printf("Got:\n");
    printf("\033[0m");
    isPalindromeIter(str10, 7);

    //**********************************************************************************************************

    // test for IsDividedBy3Iter

    long long p[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 583, 88888828, 15};


    printf("\033[1;34m");

    printf("\n");
    printf("###Tests for IsDividedBy3Iter###\n");

    for (int i = 0; i < 13; i++){
        printf("\033[0;31m");
        printf("\n");
        printf("Expected for %lld:\n", p[i]);
        if (p[i]%3){
            printf("The number %lld is not divisible by 3.\n", p[i]);
        }else{
            printf("The number %lld is divisible by 3.\n", p[i]);
        }
        printf("\n");
        printf("Got:\n");
        printf("\033[0m");
       IsDividedBy3Iter(p[i]);
    }

    printf("\033[1;34m");
    printf("\n");
    printf("####End of tests####\n");

}








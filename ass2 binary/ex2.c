#include <stdio.h>

void  f1();
void f2();

void menu();

void f3();

void f4();

void f5();

void f6();

void f7();

int ex2() {
menu();

return 0;
}

void menu() {
    //the function print the menu of options
    printf("Choose an option:\n"
           "1. Rhombus\n"
           "2. Base 20 to Decimal\n"
           "3. Base to Decimal\n"
           "4. Pow2\n"
           "5. Different bits\n"
           "6. Add\n"
           "7. Multiply\n"
           "0. Exit\n");

    char option;
    scanf(" %c", &option);
    switch (option) {
        case '0':
            return;
        case '1':
            f1();
            break;
        case '2':
            f2();
            break;
        case '3':
            f3();
            break;
        case '4':
            f4();
            break;
        case '5':
            f5();
            break;
        case '6':
            f6();
            break;
        case '7':
            f7();
            break;
        default: {
            printf("Wrong option!\n");
            menu();
        }
    }
}

void f7() {
    //the function scan 2 numbers
    //the function print the double of the numbers
    int num1,num2;
    int duplicate=0;
    printf("Enter two numbers:\n");
    scanf("%d", &num1);
    scanf("%d", &num2);
    int sum=0;
    int saveNum=0;
    int total=0;
    int middleNum=0;
    int negative=0;
    if(num1<=0)
    {
        num1=(~num1);
        num1++;
        negative=~negative;
    }
    if(num2<=0)
    {
        num2=(~num2);
        num2++;
        negative=~negative;
    }

    //add num2, num1 times
    for(int j=0; j<num1;j++)
    {
        for (int i = 0; i < 32; i++)
        {
            //1+1
            if (((middleNum >> i)&1) && ((num2 >> i) & 1)) {
                if(saveNum)
                {
                    sum++;
                }
                saveNum=1;
            }
            //0+0
            if ((!((middleNum >> i)&1) && !((num2 >> i) & 1))) {
                if(saveNum)
                {
                    sum++;
                }
                saveNum=0;
            }
            //1+0
            if (  (!((middleNum >> i)&1) && ((num2 >> i) & 1)) || (((middleNum >> i)&1) && !((num2 >> i) & 1))) {
                if(saveNum)
                {
                    saveNum=1;
                } else {
                    sum++;
                    saveNum = 0;
                }
            }
            int unit = 0 ||sum ;
            unit=unit<<i;
            total=total^unit;
            sum=0;
        }
        middleNum=total;
        total=0;
        sum=0;
        saveNum=0;
    }
    //if the double is nagtive use the complements to 2.
    if(negative)
    {
        middleNum=~middleNum;
        middleNum++;
    }
    printf("%d\n",middleNum);
    menu();
}

void f6() {
    //the function scan 2 numbers
    //the function print the sum of the numbers
    int num1,num2;
    printf("Enter two numbers:\n");
    scanf("%d", &num1);
    scanf("%d", &num2);
    int sum=0;
    int saveNum=0;
    int total=0;
    for (int i = 0; i < 32; i++)
    {
        //1+1
        if (((num1 >> i)&1) && ((num2 >> i) & 1)) {
            if(saveNum)
            {
                sum++;
            }
            saveNum=1;
        }
        //0+0
        if ((!((num1 >> i)&1) && !((num2 >> i) & 1))) {
            if(saveNum)
            {
                sum++;
            }
            saveNum=0;
        }
        //1+0
        if (  (!((num1 >> i)&1) && ((num2 >> i) & 1)) || (((num1 >> i)&1) && !((num2 >> i) & 1))) {
            if(saveNum)
            {
                saveNum=1;
            } else {
                sum++;
                saveNum = 0;
            }
        }
        int unit = 0 ||sum ;
         unit=unit<<i;
        total=total^unit;
        sum=0;
    }
printf("%d\n",total);
    menu();

}

void f5() {
//the function scan to numbers.
//the function print how many different bits there are between the numbers
    int num1,num2;
printf("Enter two numbers:\n");
    scanf("%d", &num1);
    scanf("%d", &num2);
int count=0;

    for (int i = 0; i < 32; i++) {
        if (((num1 >> i) & 1) != ((num2 >> i) & 1)) {
            count++;
        }
    }
    printf("There are %d different bits\n",count);
    menu();


}

void f4() {
    //the function scan a number
    //the function print if the number is a power of 2.
    int number;
    printf("Enter a number:\n");
    scanf("%d", &number);
    //the (number &&) is for the case that the number is 0;
   int check= number && (!(number & (number - 1)));
if(check)
{
    printf("%d is a power of 2\n",number);
} else
{
    printf("%d is not a power of 2\n",number);
}
    menu();
}

void f3() {
    //the function scan base and number in the same base.
    //the function print the number in base 10.
    int base;
    char  text;
    int tenBase=0;
    int pow=1;
    int legalNum=1;
    int counter=0;
    printf("Enter a base (2-10):\n");
    scanf("%d", &base);
    printf("Enter a reversed number in base %d:\n",base);
    scanf(" %c", &text);
    while (text != '\n')
    {
//switch chr to dec asci value
        if(text>=48&&text<=(48+base-1))
        {
            text=text-48;
            tenBase=tenBase+text*pow;
            pow=pow*base;
        }
        //all the other options not valid
        else
            {
            printf("Error! %c is not a valid digit in base %d\n",base);
            legalNum=0;
        }
        scanf("%c",&text);
    }
    if(legalNum)
    {
        printf("%d\n",tenBase);
    }
    menu();

}


void f2() {
//the function scan text in base 20.
//the function print the text in base 10.
    printf("Enter a reversed number in base 20:\n");
    char  text;
    int tenBase=0;
    int pow=1;
    int isvalid=0;
    int legalNum=1;
    int counter=0;
       scanf(" %c", &text);
        while (text != '\n')
        {
//switch chr to dec asci value
//numbers
            if(text>=48&&text<=57)
            {
                text=text-48;
                isvalid=1;
            }
            //capital letters
            if(text>=65&&text<=74){
                text=text-55;
                isvalid=1;
            }
            //small letters
            if(text>=97&&text<=106) {
                text=text-87;
                isvalid=1;
            }
            //all the other options not valid
            if(!isvalid){
                printf("Error! %c is not a valid digit in base 20\n",text);
                isvalid=0;
                legalNum=0;
            }
            else
            {
                tenBase=tenBase+text*pow;
                pow=pow*20;
                isvalid=0;
            }

            scanf("%c",&text);
        }
if(legalNum)
    printf("%d\n",tenBase);
menu();
    }


void f1() {
    //the function scan sides length and print a rhombus with the same rib length
    printf("Enter the sides length:\n");
    int length;

    scanf_s("%d", &length);
    int left=length-1;
    int right=length+1;

    for (int j = 0; j <length ; ++j) {
        for (int (i) = 0; i <(length*2)+1; i++) {
            if(length==i)
            {
                printf("*");
                continue;
            }
            if (i == left) {
                printf("/");
                continue;
            }
            if (i==right)
            {
                printf("\\");
                break;
            }
            printf(" ");
        }
        left=left-1;
        right=right+1;
        printf("\n");
    }
//
    printf("|");
    for (int (i) = 0; i <(length*2)-1; i++) {
        if(length-1==i)
        {
            printf("+");
        }
        else
        {
            printf(" ");
        }
    }
    if(length==0)
        printf("+");
    printf("|\n");
//
    left=0;
    right=length*2;
    for (int j = 0; j <length ; ++j) {
        for (int (i) = 0; i <(length*2)+1; i++) {
            if(length==i)
            {
                printf("*");
                continue;
            }
            if (i == right) {
                printf("/");
                break;
            }
            if (i==left)
            {
                printf("\\");
                continue;
            }
            printf(" ");
        }
        left=left+1;
        right=right-1;
        printf("\n");
    }
    menu();
}

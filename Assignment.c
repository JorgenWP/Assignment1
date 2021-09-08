#include <stdio.h>

//Sammenligner to heltall
void compare_values(int x, int y) {
    if (x>y)
        {
            printf("x = %i was the greater number\n",x);
        }
        else if (y>x)
        {
            printf("y = %i was the greater number\n",y);
        }
        else        
        {
            printf("x = %i and y = %i are the same value\n", x, y);
    }
    
}

//Printer en trekant med valgt antall linjer
void myTriangles(int numlines) {
    for (int i = 1; i <= numlines; ++i) {
        for (int j = 0; j < i; ++j) {
            printf("*");
        }
        printf("\n");
    }
}

//Skjekker om et primatall er faktor for et valgt tall
int myPrimeFactor(int number, int primeFactor) {
    if (number % primeFactor == 0 && number != 0) 
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

//Skriver ut en valg intervall og sier om tallene er par- eller oddetall og om 5 er en primfaktor
void myNumbers(int startnum, int endnum) {
   int primeFactor = 5; 
   while (startnum <= endnum) {
       if (startnum % 2 == 0) {
           printf("%i is even", startnum);
        }
        else {
            printf("%i is odd", startnum);
        }

        if (myPrimeFactor(startnum, primeFactor) == 1) {
            printf(" and %i is a prime factor\n", primeFactor);
            ++startnum;
        }
        else {
            printf(" and %i is not a prime factor\n", primeFactor);
            ++startnum;
        }
    }

    /*while (startnum <= endnum) {
        if (startnum % 2 == 0) {
           if (myPrimeFactor(startnum, primeFactor) == 0) {
                printf("%i is even and %i is not a prime factor\n", startnum, primeFactor);
                ++startnum;
            }
           else if (myPrimeFactor(startnum, primeFactor) == 1) {
                printf("%i is even and %i is a prime factor\n", startnum, primeFactor);
                ++startnum;
            }
        }

        else if (startnum % 2 == 1) {
            if (myPrimeFactor(startnum, primeFactor) == 0) {
                printf("%i is odd and %i is not a prime factor\n", startnum, primeFactor);
                ++startnum;
            }
            else if (myPrimeFactor(startnum, primeFactor) == 1) {
                printf("%i is odd and %i is a prime factor\n", startnum, primeFactor);
                ++startnum;
            }
        }
    }*/

}

//Counts how many times the function bit shifts before finding most segnicifant bit
int myLog2(unsigned int n) {
    int pos = 0;
    for (n; n > 1; n = n >> 1, pos++);

    return pos;
}

void reverseString(char string[]) {
    int n = string_length();
 
    for (int i = 0; i < n / 2; i++)
        swap(string[i], string[n - i - 1]);

    printf("Your reverse string is: %s", string);

}


int main (void) {
    
    //Task 1
    int x,y;
    printf("Number comparison \nEnter a integer for x: ");
    scanf("%i",&x);
    printf("Enter a integer for y: ");
    scanf("%i",&y);

    compare_values(x,y);

    //Task 2
    int i,j,numlines;
    printf("\nTriangle printer \nEnter number of rows you want in your triangle: ");
    scanf("%i",&numlines);

    myTriangles(numlines);

    //Task 3
    int number;
    int primeFactor;
    printf("\nPrime factor checker \nInsert number here: ");
    scanf("%i",&number);
    printf("Insert prime factor here: ");
    scanf("%i",&primeFactor);
    printf("\n");

    if (myPrimeFactor(number, primeFactor) == 1)
    {
        printf("%i is a prime factor for %i\n\n",primeFactor,number);
    }
    if (myPrimeFactor(number, primeFactor) == 0)
    {
        printf("%i is not a prime factor for %i\n\n",primeFactor,number);
    }

    //Task 4
    int startnum, endnum;
    printf("Number printer \nInsert start-number here: ");
    scanf("%i", &startnum);
    printf("Insert end-number here: ");
    scanf("%i", &endnum);
    printf("\n");

    myNumbers(startnum, endnum);
    
    //Task 5
    unsigned int n;
    printf("\nMost segnificant bit \nEnter number: ");
    scanf("%i", &n);

    printf("The position of the most segnificant bit in %d is %d \n", n, myLog2(n));

    //Task 6
    char string[100];
    printf("\nEnter a string: ");
    getchar();
    fgets(string, 100, stdin);

    reverseString(string);

    return 0;

}
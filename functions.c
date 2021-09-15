#include <stdio.h>
#include <string.h> //for å ha tilgang til strlen

//Sammenligner to heltall og printer det største
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
    for (int i = 1; i <= numlines; ++i) { //printer antall linjer valgt
        for (int j = 0; j < i; ++j) {     //printer en mer * for hver linje
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
}

//teller hvor mange ganger man må bit-skifte for at tallet blir 1, og finner dermed MSB
int myLog2(unsigned int n) {
    int pos = 0;
    for (n; n > 1; n = n >> 1, pos++);  //kjører loopen til det innskrvet tallet blir 1 og teller antall bit-skift som må til 

    return pos;                         //returnerer antall bit-skift som svar på funksjonen
}

//reverserer en string med hjelp av å bytte om på bokstavene
void reverseString(char string[]) {     //Fått hjelp av student Nemanja Ignjic og nettside: https://www.studytonight.com/c/programs/loop/reverse-a-string-program 
    int stringlength = strlen(string);  //med <string.h> får vi funksjonen strlen som regner ut lengden av et array
 
    for (int i = stringlength - 1; i >= stringlength/2; i--)
    {
        char ch = string[i];                       //definerer bokstaven lenst til høyre som enda ikke er byttet i arrayet som "ch"
        string[i] = string[stringlength - i - 1];  //sier at bokstaven lengst til høyre som enda ikke er byttet er lik bokstaven lengst til venstre som enda ikke er byttet
        string[stringlength - i - 1] = ch;         //sier at bokstaven lengst til venstre som enda ikke er byttet er lik bokstaven lengst til høyre som ble byttet i linjen over
    }                                              //siden i blir mindre for hver gjennomgang blir bokstavene som blir byttet hele tiden en nærmere midten av stringen

    printf("Your reverse string is: %s", string);

}




int main (void) {
    
    while (1) //kjører menyen på nytt så lenge det ikke returneres noe annet enn 1
    {
        int n;
        printf("\n\nChoose function to run:\n1: Compare values\n2: Triangle printer\n3: Prime factor checker\n4: Number printer\n5: Most segnificant bit\n6: Reverse string\n7: To end program\nType in number: ");
        scanf("%i", &n);

        //Task 1
        if (n == 1)
        {
            int x,y;
            printf("\nCompare values \nEnter a integer for x: ");
            scanf("%i",&x);
            printf("Enter a integer for y: ");
            scanf("%i",&y);

            compare_values(x,y);
        }

        //Task 2
        if (n == 2)
        {
            int i,j,numlines;
            printf("\nTriangle printer \nEnter number of rows you want in your triangle: ");
            scanf("%i",&numlines);

            myTriangles(numlines);
        }

        //Task 3
        if (n == 3)
        {
            int number;
            int primeFactor;
            printf("\nPrime factor checker \nInsert number here: ");
            scanf("%i",&number);
            printf("Insert prime factor here: ");
            scanf("%i",&primeFactor);
            printf("\n");

            if (myPrimeFactor(number, primeFactor) == 1) //if the function returns 1 it is a prime factor
            {
                printf("%i is a prime factor for %i\n\n",primeFactor,number);
            }
            if (myPrimeFactor(number, primeFactor) == 0) //if it return 0 it is not
            {
                printf("%i is not a prime factor for %i\n\n",primeFactor,number);
            }
        }

        //Task 4
        if (n == 4)
        {
            int startnum, endnum;
            printf("Number printer \nInsert start-number here: ");
            scanf("%i", &startnum);
            printf("Insert end-number here: ");
            scanf("%i", &endnum);
            printf("\n");

            myNumbers(startnum, endnum);
        }
        
        //Task 5
        if (n == 5)
        {
            unsigned int n;
            printf("\nMost segnificant bit \nEnter number: ");
            scanf("%i", &n);

            printf("The position of the most segnificant bit in %d is %d \n", n, myLog2(n));
        }

        //Task 6
        if (n == 6)
        {
            char string[100];
            printf("\nReverse string\nEnter a string: "); 
            getchar();                           //en \n fra tidligere input i stdin skipper nå getchar istedetfor fgets. Løsning funnet på: https://stackoverflow.com/questions/19691015/gets-not-working
            fgets(string, sizeof string, stdin); //bruker her fgets for å kunne ta opp input med mellomrom

            reverseString(string);
        }

        if (n == 7)
        {
            return 0;
        }
        
    }

}
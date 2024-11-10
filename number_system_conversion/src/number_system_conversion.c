
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BLACK   "\033[30m"
#define BOLDBLACK   "\033[1m\033[30m"
#define BOLDRED     "\033[1m\033[31m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDYELLOW  "\033[1m\033[33m"
#define BOLDBLUE    "\033[1m\033[34m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDCYAN    "\033[1m\033[36m"
#define BOLDWHITE   "\033[1m\033[37m"

// Function for print colorfull banner
void printBanner() {
    printf(BLUE "*************************************\n" RESET);
    printf(MAGENTA "*      NUMBER SYSTEM CONVERSION     *\n" RESET);
    printf(MAGENTA "*        Made in C Language         *\n" RESET);
    printf(MAGENTA "*        By: [sumangal karan]       *\n" RESET);
    printf(BLUE "*************************************\n" RESET);
} 




// Function to convert decimal to binary
int decimalToBinary(int decimal) {
    int binary = 0, remainder, i = 1;
    
    while (decimal != 0) {
        remainder = decimal % 2;
        decimal = decimal / 2;
        binary = binary + remainder * i;
        i = i * 10;
    }
    return binary;
}

// Function to convert binary to decimal
int binaryToDecimal(int binary) {
    int decimal = 0, remainder, base = 1;
    
    while (binary > 0) {
        remainder = binary % 10;
        decimal = decimal + remainder * base;
        binary = binary / 10;
        base = base * 2;
    }
    return decimal;
}

// Function to convert decimal to octal
int decimalToOctal(int decimal) {
    int octal = 0, remainder, i = 1;
    
    while (decimal != 0) {
        remainder = decimal % 8;
        decimal = decimal / 8;
        octal = octal + remainder * i;
        i = i * 10;
    }
    return octal;
}

// Function to convert octal to decimal
int octalToDecimal(int octal) {
    int decimal = 0, remainder, base = 1;
    
    while (octal > 0) {
        remainder = octal % 10;
        decimal = decimal + remainder * base;
        octal = octal / 10;
        base = base * 8;
    }
    return decimal;
}

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimal) {
    char hexadecimal[100];
    int i = 0, remainder;
    
    while (decimal != 0) {
        remainder = decimal % 16;
        if (remainder < 10)
            hexadecimal[i] = remainder + 48;
        else
            hexadecimal[i] = remainder + 55;
        decimal = decimal / 16;
        i++;
    }
    
    printf(BOLDCYAN "Hexadecimal: " RESET);
    for (int j = i - 1; j >= 0; j--)
        printf("%c", hexadecimal[j]);
    printf("\n");
}

// Function to convert hexadecimal to decimal
int hexadecimalToDecimal(char hexadecimal[]) {
    int decimal = 0, base = 1, length;
    length = strlen(hexadecimal);
    
    for (int i = length - 1; i >= 0; i--) {
        if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9') {
            decimal += (hexadecimal[i] - 48) * base;
        }
        else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') {
            decimal += (hexadecimal[i] - 55) * base;
        }
        base = base * 16;
    }
    return decimal;
}

int main() {
    int choice, decimal, binary, octal;
    char hexadecimal[100];
    printBanner();
    printf(BOLDGREEN "\nNumber System Conversion Menu:\n" RESET);
    printf(BOLDYELLOW"1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("3. Decimal to Octal\n");
    printf("4. Octal to Decimal\n");
    printf("5. Decimal to Hexadecimal\n");
    printf("6. Hexadecimal to Decimal\n");
    printf("7. Binary to Octal\n");
    printf("8. Binary to Hexadecimal\n");
    printf("9. Octal to Binary\n");
    printf("10. Octal to Hexadecimal\n");
    printf("11. Hexadecimal to Binary\n");
    printf("12. Hexadecimal to Octal\n" RESET);
    printf(BOLDRED"13. Exit\n" RESET);
     
    do {

        printf(BOLDGREEN"\nEnter your choice (1-13): " RESET);
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf(BOLDGREEN"Enter decimal number: "RESET);
                scanf("%d", &decimal);
                printf(BOLDMAGENTA"Binary: %d\n", decimalToBinary(decimal),RESET);
                break;
                
            case 2:
                printf(BOLDGREEN"Enter binary number: "RESET);
                scanf("%d", &binary);
                printf(BOLDCYAN"Decimal: %d\n", binaryToDecimal(binary),RESET);
                break;
                
            case 3:
                printf(BOLDGREEN"Enter decimal number: "RESET);
                scanf("%d", &decimal);
                printf(BOLDBLUE"Octal: %d\n", decimalToOctal(decimal),RESET);
                break;
                
            case 4:
                printf(BOLDGREEN"Enter octal number: "RESET);
                scanf("%d", &octal);
                printf(BOLDYELLOW"Decimal: %d\n", octalToDecimal(octal),RESET);
                break;
                
            case 5:
                printf(BOLDGREEN"Enter decimal number: "RESET);
                scanf("%d", &decimal);
                decimalToHexadecimal(decimal);
                break;
                
            case 6:
                printf(BOLDGREEN"Enter hexadecimal number: "RESET);
                scanf("%s", hexadecimal);
                printf(BOLDCYAN"Decimal: %d\n", hexadecimalToDecimal(hexadecimal),RESET);
                break;
                
            case 7:
                printf(BOLDGREEN"Enter binary number: "RESET);
                scanf("%d", &binary);
                decimal = binaryToDecimal(binary);
                printf(BOLDMAGENTA"Octal: %d\n", decimalToOctal(decimal),RESET);
                break;
                
            case 8:
                printf(BOLDGREEN"Enter binary number: "RESET);
                scanf("%d", &binary);
                decimal = binaryToDecimal(binary);
                decimalToHexadecimal(decimal);
                break;
                
            case 9:
                printf(BOLDGREEN"Enter octal number: "RESET);
                scanf("%d", &octal);
                decimal = octalToDecimal(octal);
                printf(BOLDBLUE"Binary: %d\n", decimalToBinary(decimal),RESET);
                break;
                
            case 10:
                printf(BOLDGREEN"Enter octal number: "RESET);
                scanf("%d", &octal);
                decimal = octalToDecimal(octal);
                decimalToHexadecimal(decimal);
                break;
                
            case 11:
                printf(BOLDGREEN"Enter hexadecimal number: "RESET);
                scanf("%s", &hexadecimal);
                decimal = hexadecimalToDecimal(hexadecimal);
                printf(BOLDMAGENTA"Binary: %d\n", decimalToBinary(decimal),RESET);
                break;
                
            case 12:
                printf(BOLDGREEN"Enter hexadecimal number: "RESET);
                scanf("%s", &hexadecimal);
                decimal = hexadecimalToDecimal(hexadecimal);
                printf(BOLDBLUE"Octal: %d\n", decimalToOctal(decimal),RESET);
                break;
                
            case 13:
                printf(BOLDRED"Exiting program.......\n" RESET);
                break;
                
            default:
                printf(BOLDYELLOW"Invalid choice! Please try again.\n"RESET);
        }

    } while (choice != 13);
    
    return 0;

}
        
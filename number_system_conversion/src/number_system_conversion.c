
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
    
    printf("Hexadecimal: ");
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
    
    printf("\nNumber System Conversion Menu:\n");
    printf("1. Decimal to Binary\n");
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
    printf("12. Hexadecimal to Octal\n");
    printf("13. Exit\n");
    
    do {

        printf("\nEnter your choice (1-13): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter decimal number: ");
                scanf("%d", &decimal);
                printf("Binary: %d\n", decimalToBinary(decimal));
                break;
                
            case 2:
                printf("Enter binary number: ");
                scanf("%d", &binary);
                printf("Decimal: %d\n", binaryToDecimal(binary));
                break;
                
            case 3:
                printf("Enter decimal number: ");
                scanf("%d", &decimal);
                printf("Octal: %d\n", decimalToOctal(decimal));
                break;
                
            case 4:
                printf("Enter octal number: ");
                scanf("%d", &octal);
                printf("Decimal: %d\n", octalToDecimal(octal));
                break;
                
            case 5:
                printf("Enter decimal number: ");
                scanf("%d", &decimal);
                decimalToHexadecimal(decimal);
                break;
                
            case 6:
                printf("Enter hexadecimal number: ");
                scanf("%s", hexadecimal);
                printf("Decimal: %d\n", hexadecimalToDecimal(hexadecimal));
                break;
                
            case 7:
                printf("Enter binary number: ");
                scanf("%d", &binary);
                decimal = binaryToDecimal(binary);
                printf("Octal: %d\n", decimalToOctal(decimal));
                break;
                
            case 8:
                printf("Enter binary number: ");
                scanf("%d", &binary);
                decimal = binaryToDecimal(binary);
                decimalToHexadecimal(decimal);
                break;
                
            case 9:
                printf("Enter octal number: ");
                scanf("%d", &octal);
                decimal = octalToDecimal(octal);
                printf("Binary: %d\n", decimalToBinary(decimal));
                break;
                
            case 10:
                printf("Enter octal number: ");
                scanf("%d", &octal);
                decimal = octalToDecimal(octal);
                decimalToHexadecimal(decimal);
                break;
                
            case 11:
                printf("Enter hexadecimal number: ");
                scanf("%s", hexadecimal);
                decimal = hexadecimalToDecimal(hexadecimal);
                printf("Binary: %d\n", decimalToBinary(decimal));
                break;
                
            case 12:
                printf("Enter hexadecimal number: ");
                scanf("%s", hexadecimal);
                decimal = hexadecimalToDecimal(hexadecimal);
                printf("Octal: %d\n", decimalToOctal(decimal));
                break;
                
            case 13:
                printf("Exiting program.\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 13);
    
    return 0;

}
        
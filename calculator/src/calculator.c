#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h> // For advanced math functions
#define M_PI 3.14159265358979323846

// ANSI color codes
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m" // Reset color

void displayBanner();
void sum(double a, double b);
void sub(double a, double b);
void mul(double a, double b);
void divi(double a, double b);
void rem(int a, int b);
void power(double base, double exp);
void sqroot(double a);
void sin_func(double angle);
void cos_func(double angle);
void tan_func(double angle);
void log_func(double a);


int main()
{
    int choice;
    double a, b;
    system("cls");

    while (1) // Add loop to keep asking for inputs until exit is chosen
    {
        // Display the banner at the start
        displayBanner();

        printf(YELLOW "Enter your choice\n" RESET);
        printf(GREEN "1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Remainder\n");
        printf("6. Power\n7. Square Root\n8. Sine\n9. Cosine\n10. Tangent\n11. Logarithm\n12. Exit\n" RESET);
        scanf("%d", &choice);

        if (choice == 12) // Exit condition
        {
            printf(CYAN "Exiting the program.....\n" RESET);
            break;
        }

        if (choice < 1 || choice > 12)
        {
            printf(RED "Invalid choice! Please select within the range\n" RESET);
            continue; // Go back to the menu if choice is invalid
        }

switch (choice)
        {
        case 1: case 2: case 3: case 4:
            printf(YELLOW "Enter two numbers:\n" RESET);
            scanf("%lf %lf", &a, &b);
            break;
        case 5:
            printf(YELLOW "Enter two integers for remainder:\n" RESET);
            int x, y;
            scanf("%d %d", &x, &y);
            rem(x, y);
            continue;
        case 6:
            printf(YELLOW "Enter the base and exponent:\n" RESET);
            scanf("%lf %lf", &a, &b);
            power(a, b);
            continue;
        case 7:
            printf(YELLOW "Enter a number for square root:\n" RESET);
            scanf("%lf", &a);
            sqroot(a);
            continue;
        case 8: case 9: case 10:
            printf(YELLOW "Enter the angle in degrees:\n" RESET);
            scanf("%lf", &a);
            break;
        case 11:
            printf(YELLOW "Enter a number for logarithm:\n" RESET);
            scanf("%lf", &a);
            log_func(a);
            continue;
        }

        switch (choice)
        {
        case 1:
            sum(a, b);
            break;
        case 2:
            sub(a, b);
            break;
        case 3:
            mul(a, b);
            break;
        case 4:
            divi(a, b);
            break;
        case 8:
            sin_func(a);
            break;
        case 9:
            cos_func(a);
            break;
        case 10:
            tan_func(a);
            break;
        
        default:
            printf(RED "You entered a wrong choice\n" RESET);
            break;
        }
    }
    return 0;
}
// Function to display a banner
void displayBanner()
{
    printf(BLUE "***************************************\n" RESET);
    printf(MAGENTA "*      ADVANCED SCIENTIFIC CALCULATOR  *\n" RESET);
    printf(MAGENTA "*         Made in C Language          *\n" RESET);
    printf(BLUE "***************************************\n" RESET);
}
void sum(double a, double b)
{
    printf(GREEN "%.2lf + %.2lf = %.2lf\n" RESET, a, b, a + b);
}
void sub(double a, double b)
{
    printf(GREEN "%.2lf - %.2lf = %.2lf\n" RESET, a, b, a - b);
}

void mul(double a, double b)
{
    printf(GREEN "%.2lf * %.2lf = %.2lf\n" RESET, a, b, a * b);
}

void divi(double a, double b)
{
    if (b != 0)
    {
        printf(GREEN "%.2lf / %.2lf = %.2lf\n" RESET, a, b, a / b);
    }
    else
    {
        printf(RED "Division by zero is not allowed!\n" RESET);
    }
}
void rem(int a, int b)
{
    if (b != 0)
    {
        printf(GREEN "%d %% %d = %d\n" RESET, a, b, a % b);
    }
    else
    {
        printf(RED "Modulus by zero is not allowed!\n" RESET);
    }
}
void power(double base, double exp)
{
    printf(GREEN "%.2lf ^ %.2lf = %.2lf\n" RESET, base, exp, pow(base, exp));
}

void sqroot(double a)
{
    if (a >= 0)
    {
        printf(GREEN "%.2lf = %.2lf\n" RESET, a, sqrt(a));
    }
    else
    {
        printf(RED "Square root of a negative number is not possible!\n" RESET);
    }
}

void sin_func(double angle)
{
    printf(GREEN "sin(%.2lf degrees) = %.2lf\n" RESET, angle, sin(angle * M_PI / 180));
}

void cos_func(double angle)
{
    printf(GREEN "cos(%.2lf degrees) = %.2lf\n" RESET, angle, cos(angle * M_PI / 180));
}

void tan_func(double angle)
{
    printf(GREEN "tan(%.2lf degrees) = %.2lf\n" RESET, angle, tan(angle * M_PI / 180));
}

void log_func(double a)
{
    if (a > 0)
    {
        printf(GREEN "log(%.2lf) = %.2lf\n" RESET, a, log(a));
    }
    else
    {
        printf(RED "Logarithm of non-positive numbers is not defined!\n" RESET);
    }
}
#include <stdio.h>

void showWelcomeScreen(void);
void startShell(void);

int main(void)
{
    showWelcomeScreen();

    startShell();

    return 0;
}
void showWelcomeScreen(void)
{
    printf("=================================\n");
    printf("        Welcome to Ozone\n");
    printf("          Version 0.1\n");
    printf("=================================\n");
}
void startShell(void)
{
    printf("\nStarting Ozone Shell...\n");
}

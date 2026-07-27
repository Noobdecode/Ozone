#include <stdio.h>
#include <string.h>

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
    char command[100];

    printf("\nStarting Ozone Shell...\n");
    while (1)
    {
    printf("\nguest@ozone:/home$ ");
    scanf("%99s", command);
    if (strcmp(command,"exit") == 0)
    {
        printf("shutting down Ozone...\n");
        break;
    }
    printf("You typed: %s\n", command);

    }

}

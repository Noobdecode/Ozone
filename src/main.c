#include <stdio.h>
#include <string.h>

void showWelcomeScreen(void);
void startShell(void);
void help(void);

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

    char commands[5][100] =
    {
        "help",
        "exit",
        "version",
        "about",
        "clear"
    };

    printf("\nStarting Ozone Shell...\n");
    while (1)
    {
    printf("\nguest@ozone:/home$ ");
    scanf("%99s", command);
    for (int i = 0; i < 5; i++)
    {
            if (strcmp(command, commands[i]) == 0)
            {
                switch (i)
                {
                    case 0:
                    help();
                    break;
                }
            }

    }
    if (strcmp(command,"exit") == 0)
    {
        printf("shutting down Ozone...\n");
        break;
    }
    printf("You typed: %s\n", command);

    }

}
void help(void)
{
 printf("====================================\n");
    printf("          OZONE HELP\n");
    printf("====================================\n\n");

    printf("Welcome to Ozone!\n");
    printf("Type one of the commands below.\n\n");

    printf("help      - Display this help menu.\n");
    printf("about     - Show information about Ozone.\n");
    printf("version   - Display the current Ozone version.\n");
    printf("clear     - Clear the screen.\n");
    printf("exit      - Shut down Ozone.\n");

    printf("\n====================================\n");
}

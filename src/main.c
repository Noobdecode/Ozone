#include <stdio.h>
#include <string.h>

void showWelcomeScreen(void);
void startShell(void);
void help(void);
void about(void);
void version(void);
void clear(void);

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

    int found = 0;
    for (int i = 0; i < 5; i++)
    {
            if (strcmp(command, commands[i]) == 0)
            {
            found = 1;
            switch (i)
                {
                    case 0:
                        help();
                        break;

                    case 1:
                        printf("Shutting down Ozone...\n");
                        return;

                    case 2:
                        version();
                        break;

                    case 3:
                        about();
                        break;

                    case 4:
                        clear();
                        break;
                }
                break;
            }
    }

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

void about(void)
{
    printf("====================================\n");
    printf("          ABOUT OZONE\n");
    printf("====================================\n\n");
    printf("Ozone is a command-line operating system\n");
    printf("simulator written in the C programming\n");
    printf("language.\n\n");
    printf("Project developed for: ICE-1212\n");
    printf("Structured Programming Language Lab.\n\n");
    printf("Current Version : 0.1\n\n");
    printf("Developer : Jayed Siddiq\n");
    printf("\n====================================\n");
}

void version(void)
{
    printf("====================================\n");
    printf("        OZONE VERSION\n");
    printf("====================================\n\n");

    printf("Version : 0.1\n");
    printf("Status  : Stable\n");
    printf("Built   : %s\n", __DATE__);

    printf("\n====================================\n");
}

void clear(void)
{
    printf("\033[2J\033[H");
    /*ANSI escape sequence breakdown:
    \033 : escape character according to ASCII
    [    : following characters from a control sequence
    2J   : clear the entire screen
    H    : move the cursor to the home position*/
    fflush(stdout);
    //ensuring the escape sequence is sent to the terminal immediately//
    showWelcomeScreen();
    printf("\nStarting Ozone Shell...\n");
}

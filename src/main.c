#include <stdio.h>
#include <string.h>
#include<time.h>

enum NodeType
{
    DIRECTORY,
    NODE_FILE
};
struct FileSystemNode
{
 char name[100];
 enum NodeType type;
 struct FileSystemNode *parent;
 struct FileSystemNode *children[10];
 int childCount;
};

struct FileSystemNode root;
struct FileSystemNode home;
struct FileSystemNode system;
struct FileSystemNode tmp;
struct FileSystemNode guest;

struct FileSystemNode nodes[100];
int nodeCount = 0;
struct FileSystemNode *currentDirectory;

void showWelcomeScreen(void);
void startShell(void);
void help(void);
void about(void);
void version(void);
void clear(void);
void echo(char *text);
void cwd(void);
void user(void);
void utilities(void);
void showDateTime(void);
void calculator(void);
void initializeFileSystem(void);
void printPath(struct FileSystemNode *node);
void cd(char *directory);
void ls(void);
void mkdir(char *name);
int main(void)
{
    initializeFileSystem();
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

    char commands[12][100] =
    {
        "help",
        "exit",
        "version",
        "about",
        "clear",
        "echo",
        "cwd",
        "user",
        "utilities",
        "cd",
        "ls",
        "mkdir"
    };

    printf("\nStarting Ozone Shell...\n");
    while (1)
    {
    printf("\nguest@ozone:");
    printPath(currentDirectory);
    printf("$ ");

    fgets(command, sizeof(command), stdin);
    char *newline = strchr(command, '\n');

    if (newline != NULL)
    {
        *newline = '\0';
    }
    char *space = strchr(command, ' ');
    if (space != NULL)
    {
        *space = '\0';
    }

    int found = 0;
    for (int i = 0; i < 12; i++)
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

                    case 5:
                        if(space != NULL)
                        {
                            echo(space + 1);
                        }
                        else
                        {
                            printf("echo: missing argument\n");
                        }
                        break;

                    case 6:
                        cwd();
                        break;

                    case 7:
                        user();
                        break;

                    case 8:
                        utilities();
                        break;

                    case 9:
                        if(space != NULL)
                        {
                            cd(space + 1);
                        }
                        else
                        {
                            printf("cd: missing argument\n");
                        }
                        break;

                    case 10:
                        ls();
                        break;

                    case 11:
                        if(space != NULL)
                        {
                            mkdir(space + 1);
                        }
                        else
                        {
                            printf("mkdir: missing argument\n");
                        }
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
    printf("echo      - Display the provided text.\n");
    printf("cwd       - Display the current working directory.\n");
    printf("ls        - List the contents of the current directory.\n");
    printf("cd        - Change the current working directory.\n");
    printf("mkdir     - Create a new directory.\n");
    printf("user      - Display information about the current user.\n");
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

void echo(char *text)
{
    printf("%s\n", text);
}

void cwd (void)
{
    printf("Current directory: ");
    printPath(currentDirectory);
    printf("\n");
}

void user(void)
{
    printf("The current user is: guest\n");
}

void utilities(void)
{
    int choice;

    while (1)
    {
        printf("\n====================================\n");
        printf("          OZONE UTILITIES\n");
        printf("====================================\n");
        printf("1. Date and Time\n");
        printf("2. Calculator\n");
        printf("0. Return to shell\n");

        printf("\nSelect an option: ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            showDateTime();
            break;

        case 2:
            calculator();
            break;

        case 0:
            return;

            default:
                printf("Invalid option.\n");
        }
    }
}


void showDateTime(void)
{
    time_t currentTime;
    struct tm *localTime;

    currentTime = time(NULL);
    localTime = localtime(&currentTime);

    printf("\n====================================\n");
    printf("           DATE & TIME\n");
    printf("====================================\n");

    printf("Date : %02d/%02d/%04d\n",
           localTime->tm_mday,
           localTime->tm_mon + 1,
           localTime->tm_year + 1900);

    printf("Time : %02d:%02d:%02d\n",
           localTime->tm_hour,
           localTime->tm_min,
           localTime->tm_sec);

           //utilizing time.h library//

    printf("\n====================================\n");
}

void calculator(void)
{
   double firstnumber;
   double secondnumber;
   char operator;

printf("\n====================================\n");
printf("          OZONE CALCULATOR\n");
printf("====================================\n\n");

printf("Enter first number : ");
scanf("%lf", &firstnumber);
printf("Enter operator (+ - * /) : ");
scanf(" %c", &operator);
printf("Enter second number : ");
scanf("%lf", &secondnumber);

switch (operator)
{
case '+':
    printf("Result : %.2f\n", firstnumber + secondnumber);
    break;

case '-':
    printf("Result : %.2f\n", firstnumber - secondnumber);
    break;

case '*':
    printf("Result : %.2f\n", firstnumber * secondnumber);
    break;

case '/':
    if (secondnumber == 0)
        {
            printf("Error: division by zero.\n");
        }
        else
        {
            printf("Result : %.2f\n", firstnumber / secondnumber);
        }
        break;

default:
    printf("Invalid Operator.\n");
}
}

void initializeFileSystem(void)
{
    strcpy(root.name, "/");
    root.type = DIRECTORY;
    root.parent = NULL;

    strcpy(home.name, "home");
    home.type = DIRECTORY;
    home.parent = &root;

    strcpy(system.name, "system");
    system.type = DIRECTORY;
    system.parent = &root;

    strcpy(tmp.name, "tmp");
    tmp.type = DIRECTORY;
    tmp.parent = &root;

    strcpy(guest.name, "guest");
    guest.type = DIRECTORY;
    guest.parent = &home;

    root.children[0] = &home;
    root.children[1] = &system;
    root.children[2] = &tmp;
    home.children[0] = &guest;
    home.childCount = 1;

    root.childCount = 3;
    home.childCount = 1;
    system.childCount = 0;
    tmp.childCount = 0;
    guest.childCount = 0;

    currentDirectory = &home;
}

void printPath(struct FileSystemNode *node)
{
    if (node == &root)
    {
        printf("/");
        return;
    }

    printPath(node->parent);
    printf("%s", node->name);

    if (node != currentDirectory)
    {
        printf("/");
    }
}

void cd(char *directory)
{
    if (strcmp(directory, "..") == 0)
    {
        if (currentDirectory != &root)
        {
            currentDirectory = currentDirectory->parent;
        }
        return;
    }
   for (int i = 0; i < currentDirectory->childCount; i++)
   {
       if (strcmp(currentDirectory->children[i]->name, directory) == 0)
       {
           currentDirectory = currentDirectory->children[i];
           return;
       }
   }
   printf("cd: directory not found\n");
}

void ls(void)
{
    if (currentDirectory->childCount == 0)
    {
        printf("directory is empty.\n");
        return;
    }

    for (int i = 0; i < currentDirectory->childCount; i++)
    {
        printf("%s\n", currentDirectory->children[i]->name);
    }
}

void mkdir(char *name)
{
    if (currentDirectory->childCount >= 10)
    {
        printf("mkdir: directory is full\n");
        return;
    }
    for (int i=0; i < currentDirectory->childCount; i++)
    {
        if(strcmp(currentDirectory->children[i]->name, name)==0)
        {
            printf("mkdir: directory already exists\n");
            return;
        }
    }
    if(nodeCount >= 100)
    {
        printf("mkdir: fileSystem is full\n");
        return;
    }

    strcpy(nodes[nodeCount].name, name);
    nodes[nodeCount].type = DIRECTORY;
    nodes[nodeCount].parent = currentDirectory;
    nodes[nodeCount].childCount = 0;

    currentDirectory->children[currentDirectory->childCount] = &nodes[nodeCount];
    currentDirectory->childCount++;

    nodeCount++;
}

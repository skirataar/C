#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define KEY 'F'

void encryptFile(char *inputFile, char *outputFile)
{
    FILE *fpInput, *fpOutput;
    char buffer[BUFFER_SIZE];
    int ch, i;

    fpInput = fopen(inputFile, "rb");
    fpOutput = fopen(outputFile, "wb");

    if(fpInput == NULL || fpOutput == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    while((ch = fgetc(fpInput)) != EOF)
    {
        ch = ch ^ KEY;
        fputc(ch, fpOutput);
    }

    fclose(fpInput);
    fclose(fpOutput);
}

void decryptFile(char *inputFile, char *outputFile)
{
    FILE *fpInput, *fpOutput;
    char buffer[BUFFER_SIZE];
    int ch, i;

    fpInput = fopen(inputFile, "rb");
    fpOutput = fopen(outputFile, "wb");

    if(fpInput == NULL || fpOutput == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    while((ch = fgetc(fpInput)) != EOF)
    {
        ch = ch ^ KEY;
        fputc(ch, fpOutput);
    }

    fclose(fpInput);
    fclose(fpOutput);
}

int main()
{
    char inputFile[100], outputFile[100];
    int choice;

    printf("1. Encrypt File\n");
    printf("2. Decrypt File\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter input file name: ");
    scanf("%s", inputFile);

    printf("Enter output file name: ");
    scanf("%s", outputFile);

    switch(choice)
    {
        case 1:
            encryptFile(inputFile, outputFile);
            printf("File encrypted successfully!\n");
            break;
        case 2:
            decryptFile(inputFile, outputFile);
            printf("File decrypted successfully!\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}


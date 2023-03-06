#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define KEY 'F'

void encryptDecryptFile(char *filename, int mode)
{
    FILE *fpInput;
    char buffer[BUFFER_SIZE];
    int ch, i;

    fpInput = fopen(filename, "rb+");

    if(fpInput == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    while((ch = fgetc(fpInput)) != EOF)
    {
        if(mode == 1)
            ch = ch ^ KEY; // encrypt
        else if(mode == 2)
            ch = ch ^ KEY; // decrypt
        else
        {
            printf("Invalid mode!\n");
            exit(1);
        }
        fseek(fpInput, -1, SEEK_CUR);
        fputc(ch, fpInput);
        fflush(fpInput);
    }

    fclose(fpInput);
}

int main()
{
    char filename[100];
    int choice;

    printf("1. Encrypt File\n");
    printf("2. Decrypt File\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter file name: ");
    scanf("%s", filename);

    switch(choice)
    {
        case 1:
            encryptDecryptFile(filename, 1);
            printf("File encrypted successfully!\n");
            break;
        case 2:
            encryptDecryptFile(filename, 2);
            printf("File decrypted successfully!\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}

#include <stdio.h>

int main()
{
    FILE* inputfile;
    FILE* answerfile;
    fopen_s(&inputfile,"input.txt", "r");

    fopen_s(&answerfile,"answer.txt", "w");
    const int n = 1024;
    char arr[n];
    int del_char = 0;
    if (!(inputfile)) {
        printf("File not find\n");
    }
    else {
        while (!feof(inputfile)) {
            if (fgets(arr, n, inputfile)) {
                for (unsigned int i = 0; i < n; i++) {
                    if (arr[i] == char(0)) {
                        break;
                    }
                    if (arr[i] == ' ' or arr[i] == '\t') {
                        del_char++;
                        continue;
                    }
                    fprintf(answerfile, "%c", arr[i]);
                }
            }
        
        fprintf(answerfile, "\nCount del chars: %i", del_char);
    }
    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *LoadString(int n){
    char *arr = (char *)malloc((n + 1) * sizeof(char));
    printf("enter string: ");
    fgets(arr, n + 1, stdin);

    // remove newline if exists
    arr[strcspn(arr, "\n")] = '\0';

    return arr;
}

int StringLength(char *str){
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

void LoadArray(char *p, char arr[]){
    int len = StringLength(p);
    for (int i = 0; i <= len; i++)
        arr[i] = p[i];
}

void ReverseArray(char arr[], char rev[], int n){
    for (int i = 0; i < n; i++)
        rev[n - 1 - i] = arr[i];
    rev[n] = '\0';  
}

void DisplayArray(char arr[], int n){
    for (int i = 0; i < n; i++)
        printf("%c", arr[i]);
}

int SumStringASCII(char *p){
    if (*p != '\0')
        return *p + SumStringASCII(p + 1);
    return 0;
}

void ReverseString(char *start, char *end){
    if (end > start){
        char c = *start;
        *start = *end;
        *end = c;
        ReverseString(start + 1, end - 1);
    }
}

int main() {
    char *str;
    int n;

    printf("Please enter the maximum size of the string:\n");
    scanf("%d", &n);
    getchar();

    str = LoadString(n);
    int len = StringLength(str);

    char arr[len + 1], rev[len + 1];

    LoadArray(str, arr);

    printf("\nOriginal array: ");
    DisplayArray(arr, len);

    ReverseArray(arr, rev, len);
    printf("\nReversed array: ");
    DisplayArray(rev, len);

    int sum = SumStringASCII(str);
    printf("\nSum of ASCII values (recursive): %d\n", sum);

    ReverseString(str, str + len - 1);
    printf("String reversed recursively: %s\n", str);

    free(str);
    return 0;
}

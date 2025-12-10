#include <stdio.h> 
#include <stdlib.h> 
 
 
char *LoadString(int N) { 
    char *s = (char *)malloc((N + 1) * sizeof(char)); 
    if (!s) { 
        fprintf(stderr, "Allocation failed\n"); 
        return NULL; 
    } 
    
    if (fgets(s, N + 1, stdin) == NULL) { 
     
        s[0] = '\0'; 
        return s; 
    } 
 
    int i = 0; 
    while (s[i] != '\0') { 
        if (s[i] == '\n') { 
            s[i] = '\0'; 
            break; 
        } 
        i++; 
    } 
    return s; 
} 
 
 
int StringLength(char *str) { 
    int len = 0; 
    while (str[len] != '\0') len++; 
    return len; 
} 
 
 
void LoadArray(char *p, char arr[]) { 
    int i = 0; 
    while (p[i] != '\0') { 
        arr[i] = p[i]; 
        i++; 
    } 
    arr[i] = '\0'; 
} 
 
 
void ReverseArray(char arr[], char rev[], int n) { 
    int i; 
    for (i = 0; i < n; i++) { 
        rev[i] = arr[n - 1 - i]; 
    } 
    rev[n] = '\0'; 
} 
 
 
void DisplayArray(char arr[], int n) { 
    int i; 
    for (i = 0; i < n; i++) putchar(arr[i]); 
    putchar('\n'); 
} 
 
 
int SumStringASCII(char *p) { 
    if (*p == '\0') return 0; 
    return (int)(unsigned char)(*p) + SumStringASCII(p + 1); 
} 
 
 
void ReverseString(char *start, char *end) { 
    if (start >= end) return; 
    char tmp = *start; 
    *start = *end; 
    *end = tmp; 
    ReverseString(start + 1, end - 1); 
} 
 
int main() { 
    int n; 
    char *str; 
 
    printf("Please enter the maximum size of the string:\n"); 
    if (scanf("%d", &n) != 1) { 
        fprintf(stderr, "Invalid input\n"); 
        return 1; 
    } 
    
    int c; 
    while ((c = getchar()) != '\n' && c != EOF) ;  
 
    str = LoadString(n); 
    if (!str) return 1; 
 
    int len = StringLength(str); 
 
     
    char *arr = (char *)malloc((len + 1) * sizeof(char)); 
    char *rev = (char *)malloc((len + 1) * sizeof(char)); 
    if (!arr || !rev) { 
        fprintf(stderr, "Allocation failed\n"); 
        free(str); 
        free(arr); 
        free(rev); 
        return 1; 
    } 
 
    LoadArray(str, arr); 
 
    printf("\nOriginal array: "); 
    DisplayArray(arr, len); 
 
    ReverseArray(arr, rev, len); 
    printf("\nReversed array (by ReverseArray): "); 
    DisplayArray(rev, len); 
 
    int sum = SumStringASCII(str); 
    printf("\nSum of ASCII values (recursive): %d\n", sum); 
 
 
    if (len > 0) ReverseString(str, str + len - 1); 
    printf("String reversed recursively: %s\n", str); 
 
 
    free(str); 
    free(arr); 
    free(rev); 
 
    return 0; 
}

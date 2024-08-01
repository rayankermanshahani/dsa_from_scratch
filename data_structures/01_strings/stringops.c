/* implementation of various string operations */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* reverse a string in place */
void reverse_string(char* str) {
    if (str == NULL) {
        printf("reverse() error: string ptr is NULL \n");
        return; 
    }

    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
    return; /* succesfully reversed string */
}

/* check if a string is a palindrome */
bool is_palindrome(const char* str) {
    if (str == NULL) {
        printf("is_palindrome() error: string ptr is NULL \n");
        return false;
    }

    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right])
            return false;
        left++;
        right--;
    }

    return true;
}


/* find a substring (naive approach) */
int find_substring(const char* str, const char* substr) {
    if (str == NULL || substr == NULL) {
        printf("find_substring() error: string ptr is NULL\n");
        return -1; 
    }

    int str_len = strlen(str);
    int substr_len = strlen(substr);

    for (int i = 0; i <= str_len - substr_len; i++) {
        int j;
        for (j = 0; j < substr_len; j++) {
            if (str[i+j] != substr[j])
                break;
        }
        if (j == substr_len)
            return i; /* return index of first substring found */
    }

    return -1; /* substring not found */
}

/* compute the KMP failure function */
void kmp_failure(const char* pattern, int* failure) {
    int m = strlen(pattern);
    failure[0] = 0;
    int j = 0;

    for (int i = 1; i < m; i++) {
        while (j < 0 && pattern[j] != pattern[i]) { 
            j = failure[j - 1];
        }
        if (pattern[j] == pattern[i]) {
            j++;
        }
        failure[i] = j;
    }
}

/* find a substring (KMP algorithm) */
int find_substring_kmp(const char* str, const char* substr) {
    if (str == NULL || substr == NULL) {
        printf("find_substring() error: string ptr is NULL\n");
        return -1; 
    }

    int n = strlen(str);
    int m = strlen(substr);

    if (m == 0)
        return 0; /* empty patterns always match at beginning */

    int* failure = (int*)malloc(m* sizeof(int));
    if (failure == NULL) {
        printf("find_substring_kmp() error: memory allocation failed\n");
        return -1; /* memory allocation failed */
    }

    kmp_failure(substr, failure);

    int i = 0; /* index for str */
    int j = 0; /* index for substr */

    while (i < n) {
        if (substr[j] == str[i]) {
            i++;
            j++;
            if (j == m) { /* substring found */
                free(failure); 
                return i - j; 
            }
        } else if (j > 0) {
            j = failure[j - 1];
        } else {
            i++;
        }
    }

    free(failure);
    return -1; /* pattern not found */

}

/* test function */
void test_stringops() {
    char str1[] = "Hello, World!";
    printf("original string: '%s'\n", str1);

    reverse_string(str1);
    printf("reversed string: '%s'\n", str1);

    char str2[] = "rotator";
    printf("is '%s' a palindrome? %s\n", str2, is_palindrome(str2) ? "yes" : "no");

    char str3[] = "Hey there, hi there, ho there";
    char substr[] = "there";
    int position = find_substring(str3, substr);
    if (position != -1) {
        printf("the substring '%s' first appears at position %d in '%s'\n", substr, position, str3);
    } else {
        printf("the substring '%s' is not found in '%s'\n", substr, str3);
    }

    char str4[] = "CABAACAADAABAABA";
    char substr2[] = "AABA"; 
    int position2 = find_substring_kmp(str4, substr2);
    if (position2 != -1) {
        printf("the substring '%s' first appears at position %d in '%s'\n", substr2, position2, str4);
    } else {
        printf("the substring '%s' is not found in '%s'\n", substr2, str4);
    }

    return;
}

int main(void) {
    test_stringops();
    return 0;
}

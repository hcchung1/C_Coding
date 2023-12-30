#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include "my_string.h"

// strchr
char *mystrchr(const char *s, int c){

    while(*s != '\0'){
        if(*s == c) return (char *)s;
        s++;
    }
    return NULL;
}
// strrchr
char *mystrrchr(const char *s, int c){
    char *ret = NULL;
    while(*s != '\0'){
        if(*s == c) ret = (char *)s;
        s++;
    }
    return ret;
}
// strspn
//find the first index that  the character in s is not in accept
size_t mystrspn(const char *s, const char *accept){
    size_t ret = 0;
    while(*s != '\0'){
        if(mystrchr(accept, *s) == NULL) return ret;
        ret++;
        s++;
    }
    
}
// strcspn
size_t mystrcspn(const char *s, const char *reject){
    size_t ret = 0;
    while(*s != '\0'){
        if(mystrchr(reject, *s) != NULL) return ret;
        ret++;
        s++;
    }
    return ret;
}
// strpbrk
char *mystrpbrk(const char *s, const char *accept){
    while(*s != '\0'){
        if(mystrchr(accept, *s) != NULL) return (char *)s;
        s++;
    }
    return NULL;
}
// strstr
//find needle in haystack without using strncmp 
char *mystrstr(const char *haystack , const char *needle){
    size_t needle_len = strlen(needle);
    char *ret = (char*)(malloc(sizeof(char) * needle_len));
    int k = 0;
    while(*haystack != '\0'){

        // printf("haystack: %s\n", haystack);
        for(int i = 0; i < needle_len; i++) ret[i] = *(haystack + i);
        ret[needle_len] = '\0';
        // printf("ret: %s\n", ret);
        if(strcmp(ret, needle) == 0) return (char *)haystack;
        k++;
        haystack++;
    }
    return NULL;

}
// strtok
char *mystrtok(char *str, const char *delim){
    static char *last = NULL;
    if(str != NULL) last = str;
    if(last == NULL) return NULL;
    char *ret = last;
    while(*last != '\0'){
        if(mystrchr(delim, *last) != NULL){
            *last = '\0';
            last++;
            return ret;
        }
        last++;
    }
    last = NULL;
    return ret;
}
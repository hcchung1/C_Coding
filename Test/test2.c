# include <stdio.h>
# include <stdlib.h>
# include <string.h>

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

int main(){
    char c;
	char *ret = NULL;
	char str[128] = {0};
	char str1[128] = {0};
	char str2[128] = {0};
    fgets(str1, 128, stdin);
	fgets(str2, 128, stdin);
	str1[strnlen(str1, 128) - 1] = 0;
	str2[strnlen(str2, 128) - 1] = 0;

	ret = mystrstr(str1, str2);

	if(ret != NULL) printf("The substring in str1 is %s.\n", ret);
	else printf("There is no substr in str1.\n");
    ret = strstr(str1, str2);
    printf("origin one:\n");
    if(ret != NULL) printf("The substring in str1 is %s.\n", strstr(str1, str2));
    else printf("There is no substr in str1.\n");
    return 0;
}
#include <stdio.h>
#include <assert.h>
#include <my_string.h>
#include <112550189_bonus_01.cpp>

char *mystrchr(const char *s, int c);
char *mystrrchr(const char *s, int c);
size_t mystrspn(const char *s, const char *accept);
size_t mystrcspn(const char *s, const char *reject);
char *mystrpbrk(const char *s, const char *accept);
char *mystrstr(const char *haystack , const char *needle);
char *mystrtok(char *str, const char *delim);

int main(){
	char c;
	char *ret = NULL;
	char str[128] = {0};
	char str1[128] = {0};
	char str2[128] = {0};

	fgets(str, 128, stdin);

	// mystrchr
	scanf("%c", &c);
	ret = mystrchr(str, c);

	if(ret != NULL) printf("The string %s after first \"%c\" is %s.\n", str, c, ret);
	else printf("The string %s does not contain \"%c\".", str, c);


	// mystrrchr
	scanf("%c", &c);
	ret = mystrrchr(str, c);
	
	if(ret != NULL) printf("The last %c index is %ld.\n", c, ret - str);
	else printf("The string %s does not contain \"%c\".", str, c);

	return 0;

	// mystrspn
	fgets(str1, 128, stdin);
	fgets(str2, 128, stdin);

	printf("The length of the same string from start is %lu.\n", mystrspn(str1, str2));

	// mystrcspn
	fgets(str1, 128, stdin);
	fgets(str2, 128, stdin);

	printf("The first index of str1 contain str2's character is %lu.\n", mystrcspn(str1, str2));

	// mystrpbrk
	ret = mystrpbrk(str1, str2);
	printf("The remain string start with character which in str2 is %s.\n", ret);

	// mystrstr
	fgets(str1, 128, stdin);
	fgets(str2, 128, stdin);

	ret = mystrstr(str1, str2);
	if(ret == NULL){
		assert(ret == str2);	// ret should be a new string
		printf("The substring in str1 is %s.\n", ret);
	}
	else printf("There is no substr in str1.\n");


	// mystrtok
	fgets(str1, 128, stdin);
	fgets(str2, 128, stdin);

	char *token = mystrtok(str1, str2);

	while(token != NULL){
		printf("%s\n", token);
		token = mystrtok(NULL, str2);
	}

	return 0;
}
#include <stdio.h>
#include <string.h>

char* reverseWords(char* word);

int main() {
    printf("%s\n", reverseWords("the sky is blue  "));
    printf("%s\n", reverseWords("   hello world  "));
    printf("%s\n", reverseWords("  Bob    Loves  Alice   "));

    return 0;
}

char* reverseWords(char* word) {
    int length = strlen(word);
    char* res = (char*)calloc(length + 1, sizeof(char));
    if (!length)
        return res;
    int j = 0;
    char* s = (char*)calloc(length + 1, sizeof(char));
    while (*word == ' ') {
        word++;
        j++;
    }
	//trim the beginning 
    memcpy(s, word, length - j);
	
	length -=j;
    int right = 0;
    int left = 0;
    int i = length - 1;
    int elapsed = 0;
	
    while (i != -1) {
        if (s[i] != ' '&& s[i] != '\0') {
            left = i;
            right = i;
            while (s[left] != ' ' && left) {
                left--;
                if (s[left] == ' ') {
                    left++;
                    break;
                }
            }
			
            elapsed = right - left;
            char* chunk = (char*)calloc(elapsed + 2, sizeof(char));
            memcpy(chunk, &s[left], elapsed + 1);
            //printf("-%s-", chunk);
            strcat(res, chunk);
            if(left)
                strcat(res, " ");
            //trim the while work
            i = left;
        }
        i--;
    }
    return res;
}
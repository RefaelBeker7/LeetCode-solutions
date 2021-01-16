#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValidIPv4(const char *IP);
char * validIPAddress(char * IP);
bool isValidIPv6(char *IP);

int main() {
    printf("%s\n", validIPAddress("256.256.256.256"));
    printf("%s\n", validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334:"));
    printf("%s\n", validIPAddress("172.16.254.1"));
    printf("%s\n", validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334"));
    return 0;
}

bool isValidIPv4(const char *IP){
    int n = strlen(IP);
    if(n>15 || n<7)
        return false;
    char* element;
    while ((element = strsep(&IP, ".")) != NULL)
    {
        int n = strlen(element);
        if(n==0 || n>3)return false;
        if(element[0]=='0' && n!=1)return false;
        for(int i=0;i<n;i++)
            if(!isdigit(element[i]))
                return false;
        if(atoi(element)>255)
            return false;
    }
    return true;
}

bool isValidIPv6(char *IP){
    int n = strlen(IP);
    if(n>39 || n<7)
        return false;
    char* element;
    while((element = strsep(&IP, ":")) != NULL){
        int n = strlen(element);
        if(n==0 || n>4)return false;
        for(int i=0;i<n;i++)
            if(!isxdigit(element[i]))
                return false;
    }
    return true;
}

char * validIPAddress(char * IP){
    int dotCount = 0;
    int colonCount = 0;
    int i=0;
    while(IP[i]!='\0'){
        if(IP[i]=='.')
            dotCount++;
        else if(IP[i]==':')
            colonCount++;
        i++;
    }
    if(dotCount==3){
        if(isValidIPv4(IP))
            return "IPv4";
    }
    else if(colonCount==7){
        if(isValidIPv6(IP))
            return "IPv6";        
    }
    
    return "Neither";
}

/*
Unable to open 'strsep.c': Unable to read file '/build/glibc-ZN95T4/glibc-2.31/string/strsep.c' 
(Error: Unable to resolve non-existing file '/build/glibc-ZN95T4/glibc-2.31/string/strsep.c').
*/
char *strsep(char **stringp, const char *delim) {
char *begin, *end;
  begin = *stringp;
  if (begin == NULL)
    return NULL;
  /* Find the end of the token.  */
  end = begin + strcspn (begin, delim);
  if (*end)
    {
      /* Terminate the token and set *STRINGP past NUL character.  */
      *end++ = '\0';
      *stringp = end;
    }
  else
    /* No more delimiters; this is the last token.  */
    *stringp = NULL;
  return begin;
}
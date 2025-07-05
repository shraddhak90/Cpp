#include <stdio.h>
#include <string.h>

void *memcpyFunc(void* dest, void* src, int n)
{
    char* d =(char *)dest;
    char* s = (char*)src;

    for (int i=0;i<n;i++)
    {
        d[i]=s[i];
    }
    return dest;
}

void* memmoveFunc(void* dest, void* src, int n)
{
    char* d = (char*)dest;
    char* s = (char*)src;
    
    if(d< s) // no overlapping hence copy forward
    {
        for (int i =0;i<n ;i++)
        {
            d[i]=s[i];
        }
    }
    else // d> s, can be overlapping hence copy backwards 
    {
        for(int i = n; i> 0 ; i--)
        {
            d[i-1] =s[i-1];
        }
    }
    return dest;
}

int memcmpFunc(void* s1, void* s2, int n)
{
    char* d= (char*) s1;
    char* s= (char*) s2;
    
    for(int i=0;i<n;i++)
    {
        if (d[i] != s[i])
        {
            return (d[i] - s[i]);
        }
    }
    return 0;
}

char* strcpyFunc(char* dest, char* src)
{
    int i =0;
    while(src[i] != '\0')
    {
        dest[i] =src[i];
        i++;
    }
    dest[i] ='\0';
    return dest;
}

char* strncpyFunc(char* dest, char* src, int n)
{
    int i =0;
    while (i < n)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] ='\0';
    return dest;
}

char* strcatFunc(char* dest, char* src)
{
    int i=0, j=0;
    while (dest[i] != '\0')
    {
        i++;
    }
    
    while (src[j]!='\0')
    {
        dest[i++] = src[j++];
    }
    dest[i]='\0';
    return dest;
}

char* strncatFunc(char* dest, char* src, int n)
{
    int i=0, j=0;
    while(dest[i]!='\0')
    {
        i++;
    }
    
    while(j <n)
    {
        dest[i++]= src[j++];
    }
    dest[i] ='\0';
    return dest;
}

int strcmpFunc(char* s1, char* s2)
{
    int i =0, j=0;
    
    while (s1[i] == s2[i])
    {
        if (s1[i] == '\0' || s2[i] == '\0')
        {
            break;
        }
        i++;
    }
    
    if (s1[i] =='\0' && s2[i] == '\0')
    {
        return 0;
    }
    else
    {
        return (s1[i] -s2[i]);
    }
}

int strncmpFunc(char* s1, char* s2, int n)
{
    int i =0;
    
    while (i < n-1 && *s1 && (*s1 == *s2))
    {
        i++;
    }
    return (s1[i] - s2[i]);
}

void* memchrFunc(void* dest, int s, int n)
{
  char* d = (char*)dest;
  unsigned char c = (unsigned char)s;
  while (n-- >0)
  {
      if (*d == s)
      {
          return (void*)d;
      }
      d++;
  }
  return NULL;
}

void* memsetFunc(void* dest, int s, int n)
{
    char* d = (char*)dest;
    char s1 = (char)s;
    
    while (n-- >0)
    {
        *d++ = s1;
    }
    return dest;
}

int main()
{
    printf("Hello World\n");

    char src[]= "Hello shraddha";
    char dest[35];
    
    memcpyFunc(dest, src, 20);
    
    printf("memcpyFunc: %s\n", dest );
    
    char data[] = "hi how are you!";
    memmoveFunc(data+5, data+2, 5);
    
    printf("memmoveFunc: %s\n", data);
    
    char s1[] = "Hi";
    char s2[]= "HII";
    
    int n = memcmpFunc(s1, s2, 2);
    
    printf("memcmpFunc: %d\n", n);
    
    char s[] = "copy this character array ";
    char d[40];
    
    strcpyFunc(d, s+5);
    
    printf("strcpyFunc: %s\n", d);
    
    strncpyFunc(d, s, 6);
    
    printf("strncpy: %s\n", d);
    
    char concat[40];
    
    strcatFunc(s, s2);
    
    printf("strcatFunc: %s\n", s);
    
    strncatFunc(s2, s, 6);
    
    printf("strncatFunc: %s\n", s2);
    
    char alpha[] = "ABCDE";
    char Alp[] = "ABCDEEE";
    
    int n1 = strcmpFunc(alpha, Alp);
    printf ("strcmp= %d\n", n1);
    
    int n2 = strncmpFunc(alpha, Alp, 7);
    printf("strncmpFunc: %d\n", n2);
    
    char* s4 = (char*)memchrFunc(alpha, 'B',strlen(alpha));
    
    if (s4 == NULL)
    {
        printf("not found\n");
    }
    else
    {
        printf("memchrFunc found\n");
        printf("memchrFunc: %s\n", s4);
    }
    
    char set[] = "hi hello world!";
    
    memsetFunc(set, '-', 5);
    printf("memsetFunc: %s\n", set);
    
    return 0;
}

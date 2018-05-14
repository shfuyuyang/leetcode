/*

Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

*/

#if 0

int cmp(const void *a,const void *b)
{
    return *(char*)a-*(char*)b;
}

bool isAnagram(char* s, char* t) {
    int len=strlen(s);
    int i=0;
    if(len!=strlen(t))
    {
        return false;
    }
    qsort(s,len,sizeof(char),cmp);
    qsort(t,len,sizeof(char),cmp);

    for(i=0;i<len;i++)
    {
        if(s[i]!=t[i])
        {
            return false;
        }
    }
    return true;
}

#else

bool isAnagram(char* s, char* t)
{
    int table[26]={0};
    int len=strlen(s);
    int i=0;
    int sum=0;
    if(len!=strlen(t))
    {
        return false;
    }

    for(i=0;i<len;i++)
    {
        table[s[i]-'a']++;
        table[t[i]-'a']--;
    }

    for(i=0;i<26;i++)
    {
        if(table[i]!=0)
        {
            return false;
        }
    }
    return true;

}

#endif

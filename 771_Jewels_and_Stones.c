/*

You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.

*/

#if 0

int numJewelsInStones(char* J, char* S) {
    int lenJ=strlen(J);
    int lenS=strlen(S);
    int i=0;
    int j=0;
    int result=0;
    for(i=0;i<lenJ;i++)
    {
        for(j=0;j<lenS;j++)
        {
            if(S[j]==J[i])
            {
                result++;
            }
        }
    }
    return result;
}

#else

int numJewelsInStones(char* J, char* S) {
    int len=strlen(J);
    int map[256]={-1};
    int i=0;
    int result=0;
    for(i=0;i<len;i++)
    {
        map[(int)J[i]]=1;
    }
    len=strlen(S);
    for(i=0;i<len;i++)
    {
        if(map[(int)S[i]]==1)
        {
            result++;
        }
    }
    return result;
}

#endif

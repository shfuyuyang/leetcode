/*

Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
Example 1:
Input: "USA"
Output: True
Example 2:
Input: "FlaG"
Output: False

*/

bool detectCapitalUse(char* word) {
    int i=0;
    int flag=0;
    int len=strlen(word);

    if(len<2)
    {
        return true;
    }

    if((word[0]>='A'&&word[0]<='Z')&&(word[1]>='A'&&word[1]<='Z'))      //全大写
    {
        flag=1;
    }
    else if((word[0]>='A'&&word[0]<='Z')&&(word[1]>='a'&&word[1]<='z'))     //第一个大，其余全小
    {
        flag=2;
    }
    else if((word[0]>='a'&&word[0]<='z')&&(word[1]>='a'&&word[1]<='z'))     //全小
    {
        flag=2;
    }
    else
    {
        return false;
    }

    for(i=1;i<len;i++)
    {
        if(flag==1)
        {
            if(word[i]>='a'&&word[i]<='z')
            {
                return false;
            }
        }
        if(flag==2)
        {
            if(word[i]>='A'&&word[i]<='Z')
            {
                return false;
            }
        }
    }
    return true;
}

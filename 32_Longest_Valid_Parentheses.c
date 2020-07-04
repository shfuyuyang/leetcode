/*

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

int longestValidParentheses(char * s){

    int cnt=0;
    int max=0;
    int i=0;
    int len=strlen(s);
    int *start=malloc(sizeof(int)*len);
    int start_i=0;
    for(i=0;i<len;i++)
    {
        if(s[i]=='(')
        {
            start[start_i++]=i;
        }
        else if(s[i]==')'&&start_i>0)
        {
            s[i]='0';
            s[start[start_i-1]]='0';
            start_i--;
        }
    }

    for(i=0;i<len;i++)
    {
        if(s[i]=='0')
        {
            cnt++;
        }
        if(s[i]!='0')
        {
            if(cnt>max)
            {
                max=cnt;
            }
            cnt=0;
        }
    }
    if(cnt>max)
    {
        max=cnt;
    }
    cnt=0;
    return max;

}

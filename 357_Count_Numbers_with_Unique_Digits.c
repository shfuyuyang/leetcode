/*

Given a non-negative integer n, count all numbers with unique digits, x, where 0 ¡Ü x < 10n.

Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ¡Ü x < 100, excluding [11,22,33,44,55,66,77,88,99])

*/

//ÅÅÁÐ×éºÏ+µÝ¹é
int countNumbersWithUniqueDigits(int n)
{
    int result=9;
    int i=0;
    if(n==0)
    {
        return 1;
    }
    for(i=1;i<n;i++)
    {
        result*=(10-i);
    }
    return result+countNumbersWithUniqueDigits(n-1);
}

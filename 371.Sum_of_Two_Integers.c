/*

Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.

Credits:
Special thanks to @fujiaozhu for adding this problem and creating all test cases.

*/

int getSum(int a, int b) {
    int c=1;
    int result=0;
    while(c!=0)
    {
        c=(a&b)<<1;     //a&b求的是会产生进位的位置，左移表示进位
        result=a^b;     //a^b表示的将要进位的位置清零
        a=result;       //更新a，b   直到当C等于0时，表示已经不会再产生进位，则加法计算结束
        b=c;
    }
    return result;
}

//简化后的代码
int getSum(int a, int b) {
    while (a & b) {
        a = a ^ b;
        b = ((a ^ b) & b) << 1;
    }
    return a ^ b;
}

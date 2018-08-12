/*

A website domain like "discuss.leetcode.com" consists of various subdomains. At the top level, we have "com", at the next level, we have "leetcode.com", and at the lowest level, "discuss.leetcode.com". When we visit a domain like "discuss.leetcode.com", we will also visit the parent domains "leetcode.com" and "com" implicitly.

Now, call a "count-paired domain" to be a count (representing the number of visits this domain received), followed by a space, followed by the address. An example of a count-paired domain might be "9001 discuss.leetcode.com".

We are given a list cpdomains of count-paired domains. We would like a list of count-paired domains, (in the same format as the input, and in any order), that explicitly counts the number of visits to each subdomain.

Example 1:
Input:
["9001 discuss.leetcode.com"]
Output:
["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"]
Explanation:
We only have one website domain: "discuss.leetcode.com". As discussed above, the subdomain "leetcode.com" and "com" will also be visited. So they will all be visited 9001 times.

Example 2:
Input:
["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
Output:
["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]
Explanation:
We will visit "google.mail.com" 900 times, "yahoo.com" 50 times, "intel.mail.com" once and "wiki.org" 5 times. For the subdomains, we will visit "mail.com" 900 + 1 = 901 times, "com" 900 + 50 + 1 = 951 times, and "org" 5 times.


*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct List
{
    int val;
    char *name;
    struct List *next;
};

//��һ���ַ����пո�ǰ��Ĳ���רΪint���ͣ������Ǹ�ʽ��������
int getIntFormStr(char *str)
{
    int sum=0;
    while(str[0]!=' ')
    {
        sum*=10;
        sum+=(str[0]-0x30);
        str++;
    }
    return sum;
}

//��int���뵽�ַ�����ǰ�棬�м�ո����
char* mergeIntAndStr(int num,char *str)
{
    int i=0;
    char *numStr=malloc(sizeof(char)*100);
    for(i=0;num!=0;i++)
    {
        numStr[i]=(num%10)+0x30;
        num/=10;
    }
    numStr[i]='\0';
    for(i=0;i<strlen(numStr)/2;i++)
    {
        char temp=numStr[i];
        numStr[i]=numStr[strlen(numStr)-1-i];
        numStr[strlen(numStr)-1-i]=temp;
    }
    strcat(numStr," ");
    strcat(numStr,str);
    return numStr;
}

char** subdomainVisits(char** cpdomains, int cpdomainsSize, int* returnSize) {
    int i=0;
    struct List *resultList=NULL;//malloc(sizeof(struct List));
    struct List *tempList=resultList;
    struct List *tempLast;
    char **result;

    for(i=0;i<cpdomainsSize;i++)
    {
        int j=0;
        //�Ӻ���ǰ�����ַ�����һֱ�������ո�λ��
        for(j=strlen(cpdomains[i])-1;cpdomains[i][j+1]!=' ';j--)
        {
            //������'.'��' '
            if(cpdomains[i][j]=='.'||cpdomains[i][j]==' ')
            {
                tempList=resultList;
                //�жϵ����'.'λ�õ��ַ������ݣ��Ƿ��������г��ֹ�
                while(tempList!=NULL)
                {
                    //����������г��ֹ�����ѵ�ǰ�ַ����е�ֵ���뵽����ڵ���
                    if(strcmp(cpdomains[i]+j+1,tempList->name)==0)
                    {
                        tempList->val+=getIntFormStr(cpdomains[i]);
                        break;
                    }
                    tempLast=tempList;
                    tempList=tempList->next;
                }
                //���û�������г��ֹ����򴴽����½ڵ㣬���������ֵ
                if(tempList==NULL)
                {
                    (*returnSize)++;
                    if(resultList==NULL)
                    {
                        resultList=malloc(sizeof(struct List));
                        tempList=resultList;
                    }
                    else
                    {
                        tempList=malloc(sizeof(struct List));
                        tempLast->next=tempList;
                    }
                    tempList->val=getIntFormStr(cpdomains[i]);
                    tempList->name=malloc(sizeof(char)*100);
                    (tempList->name)[0]='\0';
                    strcat(tempList->name,cpdomains[i]+j+1);
                    tempList->next=NULL;
                }
            }
        }
    }
    //������תΪ��ά����
    result=malloc(sizeof(char*)*(*returnSize));
    for(i=0;i<(*returnSize);i++)
    {
        result[i]=mergeIntAndStr(resultList->val,resultList->name);
        resultList=resultList->next;
    }
    return result;
}

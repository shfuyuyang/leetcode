#if  1
int countLine(char * s,float mid)
{
    float i=0,j=0;
    int len=0,result=0;
    //int start=0,end=0;
    len=strlen(s);
    if(mid-(int)mid>0)
    {
        i=0.5;
        j=0.5;
    }
    else
    {
        i=0;
        j=0;
    }
    for(;(mid-i>=-0)&&(mid+j)<len;i+=1,j+=1)
    {
        //start=mid-i;//(mid-(int)mid>0)?(int)(mid-i+0.5):(int)(mid-i);
        //end=mid+j;//(mid-(int)mid>0)?(int)(mid+j-0.5):(int)(mid+j);
        //printf("start=%d,end=%d\n",start,end);
        if(s[(int)(mid-i)]==s[(int)(mid+j)])
        {
            result++;
        }
        else
        {
            return result;
        }
    }
    return result;
}

int countSubstrings(char* s)
{
    float i=0;
    int result=0;
    int len=strlen(s);
    for(i=0;i<len;i+=0.5)
    {
        result+=countLine(s,i);
        //printf("i=%f,%d\n",i,result);
    }
    return result;
}

#else


int isPalindromicString(char * str)
{
    int len=0;
    int i=0;
    len=strlen(str);
    for(i=0;i<len/2;i++)
    {
        if(str[i]!=str[len-i-1])
        {
            return 0;
        }
    }
    return 1;
}

char * getSubstring(char * src,int start,int end)
{
    char * result;
    int i=0;
    if(end<start)
    {
        return NULL;
    }
    i=end-start;
    result=malloc(sizeof(char)*(i+1+1));    //设想起始位置与截止位置相等的情况，则需要一个字符+一个截止字符‘0’
    for(i=start;i<=end;i++)
    {
        result[i-start]=src[i];
    }
    result[end-start+1]='\0';
    return result;
}

int countSubstrings(char* s) {
    int result=0;
    int i=0,j=0,len=0;
    char * substring;
    substring=malloc(0);
    free(substring);
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        for(j=i;j<len;j++)
        {
            substring=getSubstring(s,i,j);
            if(isPalindromicString(substring)==1)
            {
                result++;
            }
            free(substring);
        }
    }
    return result;
}

#endif

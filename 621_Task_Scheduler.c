/*

Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.



Example:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.

*/

int cmp(const void *a,const void *b)
{
    return *(int*)b-*(int*)a;
}

int leastInterval(char* tasks, int tasksSize, int n)
{
    int table[26]={0};              //用来统计每个任务的总次数
    int result=0;
    int j=0;                        //冷却时间计数器

    if(n==0)
    {
        return tasksSize;
    }

    memset(table,0,sizeof(char)*26);
    for(result=0;result<tasksSize;result++)     //先统计每个任务出现的次数
    {
        table[(int)(tasks[result]-'A')]++;
    }

    qsort(table,26,sizeof(int),cmp);            //对任务次数做降序排序
    result=0;
    while(1)
    {
        for(j=0;j<=n;j++)               //在冷却时间结束后立即从任务数量最大的任务开始执行
        {
            if(j<26&&table[j]>0)        //如果在冷却时间内有任务则执行一个任务
            {
                table[j]--;
                tasksSize--;            //剩余任务数-1
            }
            result++;                   //冷却时间内无论是否执行了任务，总时间都+1
            if(0==tasksSize)            //没有剩余任务时执行结束
            {
                return result;
            }
        }
        qsort(table,26,sizeof(int),cmp);//每次执行之后重新对任务进行排列，确保任务数高的任务先执行
    }
}

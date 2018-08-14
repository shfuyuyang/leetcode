/*

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.

*/
int findMaxLength(int* nums, int numsSize) {
    int i=0,j=0;
    int count=0;
    //�����洢��0����ǰ�±�������ͣ���0��-1�滻��������ͬ��������֮���1��-1�ĸ�����ͬ����˸������ת��Ϊ��������ͬ�������͵�����±��
    int *numSum=malloc(sizeof(int)*(numsSize));
    int *resultMap=calloc(numsSize*2+1,sizeof(int));    //������¼ÿ�������͵�һ�γ��ֵ��±�
    int offset=numsSize;
    int max=0;

    if(numsSize==0)
    {
        return 0;
    }

    for(i=0;i<=numsSize*2;i++)      //���Ƚ������ϣ���е�ֵȫ����ʼ��Ϊһ����Чֵ
    {
        resultMap[i]=-123;
    }

    for(i=0;i<numsSize;i++)         //������0�滻Ϊ-1
    {
        if(nums[i]==0)
        {
            nums[i]=-1;
        }
    }

    //ͳ��������
    numSum[0]=nums[0];              //ͳ��������
    resultMap[0+offset]=-1;         //resultMap������¼ÿ�������͵�һ�γ��ֵ��±꣬���Ƚ�������0���ֵ��±���Ϊ-1����Ϊ������������0����±��ʾ��һ��Ԫ�ص�������
    resultMap[numSum[0]+offset]=0;
    for(i=1;i<numsSize;i++)
    {
        numSum[i]=numSum[i-1]+nums[i];      //��ǰ������
        if(resultMap[numSum[i]+offset]==-123)       //�����������Ƿ���ֹ������δ���ֹ����¼�±꣬������ֹ�����㵱ǰ���ֵ��±����һ�γ��ֵ��±�֮�
        {
            resultMap[numSum[i]+offset]=i;
        }
        else
        {
            if(i-resultMap[numSum[i]+offset]>max)
            {
                max=i-resultMap[numSum[i]+offset];
            }
        }
    }
    free(resultMap);
    return max;
}

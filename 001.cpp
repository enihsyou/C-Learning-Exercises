#include <stdio.h>
#include <stdlib.h>
 
int JosephusFun(int nAllCount,int nStep)
{
    int *npIndex=NULL , i=0 ,nCount=0;
 
    npIndex=(int *)malloc(sizeof(int)*nAllCount);
 
    for (i=0;i<nAllCount;i++)
    {
        npIndex[i]=i+1;
    }
    //打印报数前的顺序
    printf("报数前序号为：");
    for (i=0;i<nAllCount;i++)
    {
        printf("%d",npIndex[i]);
        printf("  ");
    }
    printf("\n");
 
    printf("=======================================\n");
    printf("报数出列顺序为：\n");
    i=-1;
    while(nCount<nAllCount)        //全部出列后循环结束
    {
        int nIndex=0 ;
 
        while(nIndex<nStep)        //报数等于步距时出列
        {
            i=(i+1)%nAllCount;      //循环报数
 
            if (npIndex[i]==0)      //如果当前序号已出列，则下一位报数
            {
                continue;
            }
            nIndex++;              //报数一次
        }
 
        //打印当前出列的编号
        printf("第%d个出列的为:%d\n",nCount+1,npIndex[i]);
        npIndex[i]=0;
        nCount++;
    }
    printf("=======================================\n");
 
    return 0;
}
 
int main()
{
    int nAllCount=0,nStep=0;
 
    printf("请输入总个数：");
    scanf("%d",&nAllCount);
     
    printf("请输入出列步长：");
    scanf("%d",&nStep);
    printf("\n");
 
    JosephusFun(nAllCount,nStep);
 
    return 0;
}#include <stdio.h>
#include <stdlib.h>
 
int JosephusFun(int nAllCount,int nStep)
{
    int *npIndex=NULL , i=0 ,nCount=0;
 
    npIndex=(int *)malloc(sizeof(int)*nAllCount);
 
    for (i=0;i<nAllCount;i++)
    {
        npIndex[i]=i+1;
    }
    //打印报数前的顺序
    printf("报数前序号为：");
    for (i=0;i<nAllCount;i++)
    {
        printf("%d",npIndex[i]);
        printf("  ");
    }
    printf("\n");
 
    printf("=======================================\n");
    printf("报数出列顺序为：\n");
    i=-1;
    while(nCount<nAllCount)        //全部出列后循环结束
    {
        int nIndex=0 ;
 
        while(nIndex<nStep)        //报数等于步距时出列
        {
            i=(i+1)%nAllCount;      //循环报数
 
            if (npIndex[i]==0)      //如果当前序号已出列，则下一位报数
            {
                continue;
            }
            nIndex++;              //报数一次
        }
 
        //打印当前出列的编号
        printf("第%d个出列的为:%d\n",nCount+1,npIndex[i]);
        npIndex[i]=0;
        nCount++;
    }
    printf("=======================================\n");
 
    return 0;
}
 
int main()
{
    int nAllCount=0,nStep=0;
 
    printf("请输入总个数：");
    scanf("%d",&nAllCount);
     
    printf("请输入出列步长：");
    scanf("%d",&nStep);
    printf("\n");
 
    JosephusFun(nAllCount,nStep);
 
    return 0;
}#include <stdio.h>
#include <stdlib.h>

int JosephusFun(int nAllCount, int nStep)
{
	int *npIndex = NULL, i = 0, nCount = 0;

	npIndex = (int *)malloc(sizeof(int)*nAllCount);

	for (i = 0; i < nAllCount; i++) {
		npIndex[i] = i + 1;
	}
	//打印报数前的顺序
	printf("报数前序号为：");
	for (i = 0; i < nAllCount; i++) {
		printf("%d", npIndex[i]);
		printf("  ");
	}
	printf("\n");

	printf("=======================================\n");
	printf("报数出列顺序为：\n");
	i = -1;
	while (nCount < nAllCount)        //全部出列后循环结束
	{
		int nIndex = 0;

		while (nIndex < nStep)        //报数等于步距时出列
		{
			i = (i + 1) % nAllCount;      //循环报数

			if (npIndex[i] == 0)      //如果当前序号已出列，则下一位报数
			{
				continue;
			}
			nIndex++;              //报数一次
		}

		//打印当前出列的编号
		printf("第%d个出列的为:%d\n", nCount + 1, npIndex[i]);
		npIndex[i] = 0;
		nCount++;
	}
	printf("=======================================\n");

	return 0;
}

int main()
{
	int nAllCount = 0, nStep = 0;

	printf("请输入总个数：");
	scanf("%d", &nAllCount);

	printf("请输入出列步长：");
	scanf("%d", &nStep);
	printf("\n");

	JosephusFun(nAllCount, nStep);

	return 0;
}
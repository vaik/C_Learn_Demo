#include <stdio.h>
#include <locale.h>

#define NUMBER 80 // 学生人数

int main(void){
	setlocale(LC_CTYPE,"");
	
	//数组Demo
	/* int vc[5];
	
	vc[0] = 1;
	vc[1] = 2;
	vc[2] = 3;
	vc[3] = 4;
	vc[4] = 5;
	
	printf("vc[0] = %d\n",vc[0]);
	printf("vc[1] = %d\n",vc[1]);
	printf("vc[2] = %d\n",vc[2]);
	printf("vc[3] = %d\n",vc[3]);
	printf("vc[4] = %d\n",vc[4]);
	
	//改用for语句
	int i;
	for(i=0;i<5;i++)
		vc[i] = i+1;
	for(i=0;i<5;i++)
		printf("vc[%d] = %d\n",i,vc[i]); */
	
	//数组的复制
	/* int i;
	int va[5] = {15,20,30};
	int vb[5];
	
	for(i=0;i<5;i++)
		vb[i] = va[i];
	
	puts(" va vb");
	puts("-------");
	for(i=0;i<5;i++)
		printf("%3d%3d\n",va[i],vb[i]); */
		
	//对数组倒序
	/* int i;
	int va[5];
	int tmp;
	for(i=0;i<5;i++){
		printf("Please input va[%d]:",i);
		scanf("%d",&va[i]);
	}
	
	for(i=0;i<2;i++){
		tmp = va[i];
		va[i] = va[4-i];
		va[4-i] = tmp;
	}
	
	for(i=0;i<5;i++){
		printf("va[%d] = %d\n",i,va[i]);
	} */
	
	//学生成绩处理
	/* int i;
	int tensu[5];
	int sum = 0;
	
	wprintf(L"请输入学生的分数。\n");
	for(i=0;i<5;i++)
	{
		wprintf(L"%d 号:",i+1);
		scanf("%d",&tensu[i]);
		sum += tensu[i];
	}

	wprintf(L" 总分:%5d\n",sum);
	wprintf(L" 平均分:%5.1f\n",(double)sum/5); */
	
	//及格学生显示
	/* int i;
	int snum = 0; //及格学生人数
	int tensu[NUMBER]; //NUMBER名学生的分数
	int succs[NUMBER]; //及格学生一览表（保存及格学生的下标）
	
	wprintf(L"请输入学生的分数。\n");
	for(i=0;i<5;i++)
	{
		wprintf(L"%d 号:",i+1);
		scanf("%d",&tensu[i]);
		if(tensu[i] >= 60){
			succs[snum++] = i; //添加到及格学生一览表中
		}
	}
	wprintf(L"及格学生一览表\n");
	wprintf(L"---------------------\n");
	for(i=0;i<snum;i++)
		wprintf(L"%2d 号（%3d 分）\n",succs[i]+1,tensu[succs[i]]); */
		
	//成绩分布图
	/* int i,j;
	int num;
	int tensu[NUMBER];
	int bunpu[11] = {0};
	
	wprintf(L"请输入学生人数:");
	do{
		scanf("%d",&num);
		if(num < 1 || num > NUMBER)
			wprintf(L"\a 人数范围【1到%d】：\n",NUMBER);
		
	}while(num < 1 || num > NUMBER);
	
	wprintf(L"请输入学生分数:");
	for(i=0;i<num;i++)
	{
		wprintf(L"%d 号:",i+1);
		do{
			scanf("%d",&tensu[i]);
			if(tensu[i]<0 || tensu[i] > 100)
				wprintf(L"\a 分数范围【0到100】：");
		}while(tensu[i]<0 || tensu[i] > 100);
		bunpu[tensu[i]/10]++;
	}
	wprintf(L"\n	分布图	\n");
	printf("       100:");
	for(j=0;j<bunpu[10];j++)
		putchar('*');
	putchar('\n');
	for(i = 9;i>=0;i--){
		printf("%3d - %3d:",i*10,i*10+9);
		for(j=0;j<bunpu[i];j++)
			putchar('*');
		putchar('\n');
	} */
	
	//矩阵
	/* int i,j;
	int ma[2][3] = {{1,2,3},{4,5,6}};
	int mb[2][3] = {{6,3,4},{5,1,2}};
	int mc[2][3] = {0};
	for(i=0;i<2;i++)
		for(j=0;j<3;j++)
			mc[i][j] = ma[i][j] + mb[i][j];

	for(i=0;i<2;i++){
		for(j=0;j<3;j++)
			printf("%3d",mc[i][j]);
		putchar('\n');
	} */
	
	//两个矩阵va和vb的积
	/* int i,j,k;
	int va[2][3] = {1,2,3,4,5,6};
	int vb[3][2] = {1,5,5,3,8,1};
	int vc[2][2] = {0};
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
			for(k=0;k<3;k++)
				vc[i][j] += va[i][k]*vb[k][j];
	
	wprintf(L"\n两个矩阵va和vb的积vc为	\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%3d",vc[i][j]);
		}
		putchar('\n');
	} */
	
	//计算1000以内质数第一版
	/* int i,no;
	unsigned long counter = 0;
	
	for(no = 2;no<=1000;no++){
		for(i=2;i<no;i++){
			counter++;
			if(no%i==0)
				break;
		}
		if(no==i)
			printf("%d\n",no);
	}
	
	wprintf(L"乘除运算的次数:%lu\n",counter); */
	
	//计算1000以内质数第二版
	/* int i,no;
	unsigned long counter = 0;
	no = 2;
	printf("%d\n",no++);
	
	for(;no<=1000;no+=2){
		for(i=2;i<no;i++){
			counter++;
			if(no%i==0)
				break;
		}
		if(no==i)
			printf("%d\n",no);
	}
	
	wprintf(L"乘除运算的次数:%lu\n",counter);  */
	
	//计算1000以内质数第三版
	/* int i,no;
	unsigned long counter = 0;
	no = 2;
	printf("%d\n",no++);
	
	for(;no<=1000;no+=2){
		for(i=3;i<no;i+=2){
			counter++;
			if(no%i==0)
				break;
		}
		if(no==i)
			printf("%d\n",no);
	}
	
	wprintf(L"乘除运算的次数:%lu\n",counter); */  
	
	//计算1000以内质数第四版
	/* int i,no;
	int prime[500];
	int ptr=0;
	unsigned long counter = 0;
	
	prime[ptr++] = 2;
	prime[ptr++] = 3;
	
	for(no = 5;no<=1000;no+=2){
		for(i=1;i<ptr;i++){
			counter++;
			if(no%prime[i]==0)
				break;
		}
		if(ptr==i)
			prime[ptr++] = no;
	}
	
	for(i=0;i<ptr;i++)
		printf("%d\n",prime[i]);
	
	wprintf(L"乘除运算的次数:%lu\n",counter); */ 
	
	//计算1000以内质数第五版
	int i,no;
	int prime[500];
	int ptr=0;
	unsigned long counter = 0;
	
	prime[ptr++] = 2;
	prime[ptr++] = 3;
	
	for(no = 5;no<=1000;no+=2){
		int flag = 0;
		for(i=1;counter++,prime[i]*prime[i] <=no;i++){
			counter++;
			if(no%prime[i]==0)
				flag = 1;
				break;
		}
		if(!flag)
			prime[ptr++] = no;
	}
	
	for(i=0;i<ptr;i++)
		printf("%d\n",prime[i]);
	
	wprintf(L"乘除运算的次数:%lu\n",counter); 
	
	
	return 0;
}
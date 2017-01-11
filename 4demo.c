#include <stdio.h>
#include <locale.h>

int main(void){

	setlocale(LC_CTYPE,"");
	
	//do语句示例
	/* int count;
	do{
		int no;
		wprintf(L"请输入一个整数：");
		scanf("%d",&no);
		if(no % 2)
			wprintf(L"这个整数是奇数。");
		else	
			wprintf(L"这个整数是偶数");
			
		wprintf(L"重复一次吗?【Yes...0/No...9】");
		scanf("%d",&count);
		
	}while(count==0); */
	
	//逆向显示数字示例
	/* int num;
	do{
		wprintf(L"请输入一个非负整数:");
		scanf("%d",&num);
		if(num<0)
			wprintf(L"请不要输入负整数!\n");
	}while(num<0);
	
	wprintf(L"该整数逆向显示的结果是:");
	do{
		printf("%d",num%10);
		num = num/10;
	}while(num>0);
	wprintf(L"。"); */
	
	//计算整数的位数示例
	/* int num;
	do{
		wprintf(L"请输入一个非负整数:");
		scanf("%d",&num);
		if(num<0)
			wprintf(L"请不要输入负整数!\n");
	}while(num<0);
	
	int dig = 0;
	do{
		printf("%d",num%10);
		num = num/10;
		dig = dig + 1;
	}while(num>0);
	wprintf(L"该整数的位数是%d位\n",dig); */
	
	//计算两个整数之间所有数和的示例
	/* int num1,num2,max,min,curnum,sum;
	wprintf(L"请输入两个整数:\n");
	wprintf(L"整数1:");scanf("%d",&num1);
	wprintf(L"整数2:");scanf("%d",&num2);
	max = num1 > num2 ? num1 : num2;
	min = num1 > num2 ? num2 : num1;
	curnum = min;
	sum = 0;
	do{
		sum = sum + curnum;
		curnum = curnum + 1;
	}while(curnum<=max);
	wprintf(L"大于等于%d小于等于%d的所有整数的和是%d\n",min,max,sum); */
	
	//打印小于输入的整数的所有大于0的偶数
	/* int num;
	wprintf(L"请输入一个正整数：");
	scanf("%d",&num);
	int tmpnum = 0;
	while(tmpnum <= num){
		printf("%d ",tmpnum);
		tmpnum +=2;
	}
	putchar('\n'); */
	
	//打印小于输入的整数的所有2的乘方。
	/* int num;
	wprintf(L"请输入一个正整数：");
	scanf("%d",&num);
	int tmpnum = 2;
	while(tmpnum <= num){
		printf("%d ",tmpnum);
		tmpnum *= 2;
	}
	putchar('\n'); */
	
	//前置递增递减示例
	/* int i = 0;
	int sum = 0;
	int num, tmp;
	wprintf(L"要输入多少个整数:");
	scanf("%d",&num);
	
	while(i<num){
		printf("No.%d:",++i);
		scanf("%d",&tmp);
		printf("%d\n",tmp);
		sum += tmp;
	}
	
	wprintf(L"合计值：%d\n",sum);
	wprintf(L"平均值：%.2f\n",(double)sum/num); */
	
	//for语句示例
	/* int i,no;
	wprintf(L"请输入一个正整数：");
	scanf("%d",&no);
	
	for(i = 0; i <= no; i ++)
		printf("%d ",i);
	putchar('\n'); */
	
	//for语句示例
	/* int i = 0;
	int sum = 0;
	int num, tmp;
	wprintf(L"要输入多少个整数:");
	scanf("%d",&num);
	
	for(;i<num;i++){
		printf("No.%d:",i+1);
		scanf("%d",&tmp);
		sum += tmp;
	}
	wprintf(L"合计值：%d\n",sum);
	wprintf(L"平均值：%.2f\n",(double)sum/num); */
	
	//循环显示1234567890
	/* int i = 0;
	int tmp = 1;
	int num ;
	wprintf(L"要输入一个整数:");
	scanf("%d",&num);
	for(;i<num;i++){
		tmp = tmp==10 ? 0 : tmp;
		printf("%d",tmp);
		tmp++;
	}
	putchar('\n'); */
	
	//练习4-14
	/* int begin,end,interval,next;
	wprintf(L"开始数值(cm):");scanf("%d",&begin);
	wprintf(L"结束数值(cm):");scanf("%d",&end);
	wprintf(L"间隔数值(cm):");scanf("%d",&interval);
	next = begin;
	do{
		printf("%dcm		%.2fkg\n",next,(next-100)*0.9);
		next += interval;
	}while(next < end);
	
	printf("%dcm		%.2fkg\n",end,(end-100)*0.9); */
	
	//乘法表练习4-15
	/* int i,j;
	printf("  |	1	2	3	4	5	6	7	8	9\n");
	printf("-------------------------------------------------------------------------------------------------------------------\n");
	for(i=1;i<=9;i++){
		for(j=-1;j<=9;j++){
			if(j==-1){
				printf("%d",i);
			}else if(j==0){
				printf(" |");
			}else{
				printf("	%d",i*j);
			}
		}
		putchar('\n');
	} */
	
	//练习4-18 金字塔
	int num;
	wprintf(L"让我们来描述一个金字塔。\n");
	wprintf(L"金字塔有几层:\n");
	scanf("%d",&num);
	for(int i=1;i<=num;i++){
		for(int j=1;j<=num-i;j++){
			printf(" ");
		}
		for(int k=1;k<=i*2-1;k++){
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}
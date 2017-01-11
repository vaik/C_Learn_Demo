#include <stdio.h>
#include <locale.h>

#define FAILED -1
#define NUMBER 5
#define CHINESE 0
#define MATH 1
#define ENGLISH 2
//函数调用示例
/* int maxof(int x,int y){
	return x>y?x:y;
} */

//求幂函数示例
//返回dx的no次幂
/* double power(double dx,int no)
{
	double result=1;
	int index;
	if(no==0){
		result = 1;

	}else if(no > 0){		
		for(index=0;index<no;index++){
			result *= dx;
		}
	}else{
		for(index=0;index>no;index--){
			result *= dx;
		}
		result = 1/result;
	}
	return result;
} */

//返回输入的非负整数
int scan_uint(void){
	int tmp;
	do{
		wprintf(L"请输入一个非负整数");
		scanf("%d",&tmp);
		if(tmp<0)
			wprintf(L"\a请不要输入负整数");
	}while(tmp<0);
	return tmp;
}

int rev_int(int num){
	int tmp = 0;
	
	if(num > 0){
		do{
			tmp = tmp*10+num % 10;
			num /=10;
		}while (num>0);
	}
	return tmp;
}

//练习6-7
int min_of(const int vc[],int no){
	int i;
	int min = vc[0];
	for(i=1;i<no;i++){
		if(vc[i]<min)
			min = vc[i];
	}
	return min;
}

//练习6-8
void rev_intary(int vc[],int no){
	int i;
	int temp;
	for(i=0;i<(no/2);i++){
		temp = vc[i];
		vc[i] = vc[no-i-1];
		vc[no-i-1] = temp;
	}
}

//表达式语句和空语句
//通过哨兵查找法顺序查找
int search(int vc[],int key,int no){
	int i;
	vc[no]=key;
	for(i=0;vc[i]!=key;i++)
		;
	return (i==no?FAILED:i);
}

//练习6-10 两个矩阵的乘积
void mul(const int ma[2][3],const int mb[3][2],int mc[2][2]){
	int i,j,k;
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
			for(k=0;k<3;k++)
				mc[i][j] += ma[i][k]*mb[k][j];
}

//练习6-11
//取学生某科的最高分
int get_course_max(const int mc[][3], int course_flag, int stu_number){
	int i;
	int max;
	max = mc[0][course_flag];
	for(i=1;i<stu_number;i++){
		if(mc[i][course_flag]>max)
			max = mc[i][course_flag];
	}
	return max;
}

//计算学生的平均成绩至数组
void get_equal_sorce(const int mc[][3],int stu_number,double ec[] ){
	int i,j;
	int all;
	double equal;
	for(i=0;i<stu_number;i++){
		all = 0;
		for(j=0;j<3;j++)
			all +=mc[i][j];
		equal = all/3;
		ec[i] = equal;
	}
}

int main(void)
{
	setlocale(LC_CTYPE,"");
	
	//函数调用示例
    /*int na,nb;
	wprintf(L"请输入两个整数\n");
	wprintf(L"整数1：");scanf("%d",&na);
	wprintf(L"整数2：");scanf("%d",&nb);
	
	wprintf(L"较大数值是%d。\n",maxof(na,nb)); */

	//幂函数调用
	/* double dx;
	int no;
	wprintf(L"请输入两个数\n");
	wprintf(L"实数：");scanf("%lf",&dx);
	wprintf(L"幂：");scanf("%d",&no);
	wprintf(L"%.2f数的%d次幂为%.2f\n",dx,no,power(dx,no));
	 */
	 
	 //调用倒转一个非负整数
	/* int nx = scan_uint();
		
	wprintf(L"该数倒转后的值是:%d。\n",rev_int(nx));
	 */
	 
	 //练习6-7测试 
	 /* int vc[] = {4,5,7,1,0,-43};
	 int min;
	 min = min_of(vc,6);
	 printf("min is %d \n",min); */
	 
	 //练习6-8
	/*  int i;
	 int vc[] = {4,5,7,1,0};
	 rev_intary(vc,5);
	 printf("rev_intary vc is \n");
	 for(i=0;i<5;i++){
		printf("%d\n",vc[i]);
	 } */
	 
	 //练习6-10
	/* int i,j,k;
	int va[2][3] = {1,2,3,4,5,6};
	int vb[3][2] = {1,5,5,3,8,1};
	int vc[2][2] = {0};	
	mul(va,vb,vc);
	wprintf(L"\n两个矩阵va和vb的积vc为	\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%3d",vc[i][j]);
		}
		putchar('\n');
	} */ 
	
	//练习6-11
	int mc[][3] = {{98,87,96},{78,89,94},{67,89,93},{100,89,90},{99,98,97}};
	int chinese_max;
	int math_max;
	int english_max;
	chinese_max = get_course_max(mc,CHINESE,5);
	math_max = get_course_max(mc,MATH,5);	
	english_max = get_course_max(mc,ENGLISH,5);
	wprintf(L"语文最高分是%d\n数学最高分是%d\n英语最高分是%d\n",chinese_max,math_max,english_max);
	
	double ec[5];
	int i;
	get_equal_sorce(mc,5,ec);	
	for(i=0;i<5;i++){
		wprintf(L"学生%d的平均成绩为%.2lf\n",i,ec[i]);
	}
	
	return 0;
}

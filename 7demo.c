#include <stdio.h>
#include <locale.h>
#include <limits.h>
#include <math.h>

//返回在整数x中设置的位数

int count_bits(unsigned x)
{
	int count = 0;
	while(x){
		if(x & 1U) count++;
		x>>=1;
	}
	return (count);
}

//返回unsigned型的位数
int int_bits(void){
	return(count_bits(~0U));
}

//显示unsigned型的位串内容
void print_bits(unsigned x)
{
	int i;
	for(i=int_bits()-1;i>=0;i--)
		putchar(((x>>i)&1U)?'1':'0');
}

//返回unsigned整数x右移n位后的值
unsigned rrotate(unsigned x,int n)
{
	return x >> n;
}

//返回unsigned整数x左移n位后的值
unsigned lrotate(unsigned x,int n)
{
	return x << n;
}

//返回unsigned整数x的第pos位设为1的值
unsigned set(unsigned x, int pos){
	return x | lrotate(1U,pos -1);
}

//返回unsigned整数x的第pos位设为0的值
unsigned reset(unsigned x, int pos){
	return x & ~lrotate(1U,pos-1);
}

//返回unsigned整数x的第pos位取反的值
unsigned inverse(unsigned x, int pos){
	return (x >> pos-1) & 1U ? reset(x,pos) : set(x,pos);
}

//返回unsigned整数x的第pos位开始的n位设为1的值
unsigned set_n(unsigned x, int pos, int n){
	int i;
	unsigned result = x;
	for(i=0;i<n;i++){
		result = set(result,pos+i);
	}
	return result;
}

//返回unsigned整数x的第pos位开始的n位设为0的值
unsigned reset_n(unsigned x, int pos, int n){
	int i;
	unsigned result = x;
	for(i=0;i<n;i++){
		result = reset(result,pos+i);
	}
	return result;
}

//返回unsigned整数x的第pos位开始的n位取反的值
unsigned inverse_n(unsigned x, int pos, int n){
	int i;
	unsigned result = x;
	for(i=0;i<n;i++){
		result = inverse(result,pos+i);
	}
	return result;
}

void print_nbits(unsigned x, unsigned n){
	int i = int_bits();
	i = (n < i) ? n-1 : i-1;
	for( ; i >= 0; i--)
		putchar(((x>>i)&1U) ? '1' : '0');
}

//Determine whether arguments can be added without overflow
int uadd_ok(unsigned int x, unsigned y){
	return!(x+y < x);
}

//Determine whether arguments can be multiplied without overflow
int umul_ok(unsigned x, unsigned y){
	unsigned p = x*y;
	return !x || p/x==y;
}

//Determine whether arguments can be substracted without overflow
int usub_ok(unsigned x,unsigned y){
	return !y || !uadd_ok(x,-y);
}

// 求出点(x1,y1)和点(x2,y2)之间的距离
double dist(double x1,double y1,double x2,double y2){
	return (sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
}

int main(void)
{
	setlocale(LC_CTYPE,"");
	
	// 显示设置的整数类型最大值和最小值
	/* printf("char	: %d~%d\n",CHAR_MIN,CHAR_MAX);
	printf("short int: %d~%d\n",SHRT_MIN,SHRT_MAX);
	printf("int	: %d~%d\n",INT_MIN,INT_MAX);
	printf("long int: %d~%d\n",LONG_MIN,LONG_MAX); */
	
	//显示unsigned型的位串内容
	/* unsigned nx;
	wprintf(L"请输入一个非负整数");
	scanf("%u",&nx);
	
	print_bits(nx);
	putchar('\n'); */
	
	//按位逻辑运算符
	/* unsigned na,nb;
	wprintf(L"请输入两个非负整数\n");
	wprintf(L"整数A:");scanf("%u",&na);
	wprintf(L"整数B:");scanf("%u",&nb);
	
	wprintf(L"\n A         =");print_bits(na);
	wprintf(L"\n B         =");print_bits(nb);
	wprintf(L"\n A & B    =");print_bits(na&nb);
	wprintf(L"\n A | B     =");print_bits(na|nb);
	wprintf(L"\n A ^ B    =");print_bits(na^nb);
	wprintf(L"\n~ A        =");print_bits(~na);
	wprintf(L"\n~ B        =");print_bits(~nb);
	putchar('\n'); */
	
	//位移操作
	/* unsigned nx,no;
	wprintf(L"请输入一个非负整数：");
	scanf("%u",&nx);
	wprintf(L"位移位数:");
	scanf("%u",&no);
	
	wprintf(L"\n整数      =");print_bits(nx);
	wprintf(L"\n左移后的值=");print_bits(nx<<no);
	wprintf(L"\n右移后的值=");print_bits(nx>>no);
	putchar('\n'); */
	
	//练习7-1
	/* unsigned nx,mv;
	wprintf(L"请输入一个非负整数：");
	scanf("%u",&nx);
	mv = nx << 1;
	wprintf(L"\n整数       =");print_bits(nx);
	wprintf(L"\n整数左移1位=");print_bits(mv);
	wprintf(L"\n整数乘以2  =");print_bits(nx*2);
	
	mv= nx >> 1;
	wprintf(L"\n整数右移1位=");print_bits(mv);
	wprintf(L"\n整数除以2  =");print_bits(nx/2); */
	
	//练习7-2
	/* unsigned nx,nl,nr;
	wprintf(L"请输入一个非负整数：");
	scanf("%u",&nx);
	wprintf(L"左移位数:");
	scanf("%u",&nl);
	wprintf(L"右移位数:");
	scanf("%u",&nr);
	wprintf(L"\n整数%u       =",nx);print_bits(nx);
	wprintf(L"\n整数%u左移%u位=",nx,nl);print_bits(lrotate(nx,nl));
	wprintf(L"\n整数%u右移%u位=",nx,nl);print_bits(rrotate(nx,nl)); */
	
	//练习7-3
	/* unsigned nx,pos;
	wprintf(L"请输入一个非负整数：");
	scanf("%u",&nx);
	wprintf(L"变化的位数:");
	scanf("%u",&pos);
	wprintf(L"\n整数%u       =",nx);print_bits(nx);
	wprintf(L"\n整数%u第%u位设置为1=",nx,pos);print_bits(set(nx,pos));
	wprintf(L"\n整数%u第%u位设置为0=",nx,pos);print_bits(reset(nx,pos));
	wprintf(L"\n整数%u第%u位取反=",nx,pos);print_bits(inverse(nx,pos)); */
	
	//练习7-4
	/* unsigned nx,pos,n;
	wprintf(L"请输入一个非负整数：");
	scanf("%u",&nx);
	wprintf(L"第几位开始:");
	scanf("%u",&pos);
	wprintf(L"变化n位:");
	scanf("%u",&n);
	
	wprintf(L"\n整数%u       =",nx);print_bits(nx);
	wprintf(L"\n整数%u第%u位起共%u位设置为1=",nx,pos,n);print_bits(set_n(nx,pos,n));
	wprintf(L"\n整数%u第%u位起共%u位设置为0=",nx,pos,n);print_bits(reset_n(nx,pos,n));
	wprintf(L"\n整数%u第%u位起共%u位取反=",nx,pos,n);print_bits(inverse_n(nx,pos,n)); */
	
	//整数的显示
	/* unsigned i;
	
	for(i=0; i<= 1000U; i++){
		printf("%u	",i);
		print_nbits(i,16);
		printf("	%06o	%04X\n",i,i);
	}
	 */
	 
	 //浮点数
	 /* float x;
	 
	 for(x=0.0;x<=1.0;x +=0.01)
		printf("x = %f\n",x); */
		
	/* int i;
	float x;
	
	for(i=0;i<=100;i++){
		x = i/100.0;
		printf("x= %f\n",x);
	} */
	
	//平方根计算两点距离演示
	/* double x1,y1;
	double x2,y2;
	wprintf(L"《点1》X坐标:"); scanf("%lf",&x1);
	wprintf(L"       Y坐标:"); scanf("%lf",&y1);
	wprintf(L"《点2》X坐标:"); scanf("%lf",&x2);
	wprintf(L"       Y坐标:"); scanf("%lf",&y2);
	
	wprintf(L"2点之间的距离为%f \n",dist(x1,y1,x2,y2)); */
	
	//sizeof 运算符
	/* int na,nb;
	double dx,dy;
	
	printf("sizeof(int) = %u\n",(unsigned)sizeof(int));
	printf("sizeof(double) = %u\n",(unsigned)sizeof(double));
	
	printf("sizeof(na) = %u\n",(unsigned)sizeof(na));
	printf("sizeof(dx) = %u\n",(unsigned)sizeof(dx));
	
	printf("sizeof(na+nb) = %u\n",(unsigned)sizeof(na+nb));
	printf("sizeof(na+dy) = %u\n",(unsigned)sizeof(na+dy));
	printf("sizeof(dx+dy) = %u\n",(unsigned)sizeof(dx+dy)); */
	
	//求出数组的元素个数
	/* int vi[10];
	double vd[25];
	
	wprintf(L"数组vi的元素个数=%u\n",(unsigned)(sizeof(vi)/sizeof(vi[0])));
	wprintf(L"数组vd的元素个数=%u\n",(unsigned)(sizeof(vd)/sizeof(vd[0]))); */
	
	printf("short int: %u int:%u\n",(unsigned)sizeof(short),(unsigned)sizeof(int));
	printf("LONG_MIN:%d ;LONG_MAX:%d \n",LONG_MIN,LONG_MAX);
	
	return 0;
}
#include <stdio.h>
#include <locale.h>
int main(void)
{
	setlocale(LC_CTYPE, "");
	// MinGW 在windows控制台显示中文示例
	/* wprintf(L"15与37的和是%d。\n",15+37);
	wprintf(L"风\n林\n火\n山\n"); */
	
	// 多个变量例子
	/* int vx,vy;
	vx = 10;
	vy = vx + 57;
	wprintf(L"vx为%d,\n vy为%d\n",vx,vy); */
	
	//通过键盘输入示例
	/* int no;
	wprintf(L"请输入一个整数:");
	scanf("%d",&no);
	wprintf(L"您输入的是%d。\n",no); */
	
	//puts("Test wputs Function");
	
	//加减乘除余示例
	/* int vx,vy;
	
	wprintf(L"请输入两个整数。\n");
	wprintf(L"请输入vx:\n");scanf("%d",&vx);
	wprintf(L"请输入vy:\n");scanf("%d",&vy);
	
	printf("vx+vy = %d\n",vx + vy);
	printf("vx-vy = %d\n",vx - vy);
	printf("vx*vy = %d\n",vx * vy);
	printf("vx/vy = %d\n",vx / vy);
	printf("vx%%vy = %d\n",vx % vy); */
	
	//练习
	/* int vx,vy;
	wprintf(L"请输入两个整数。\n");
	wprintf(L"整数A: \n"); scanf("%d",&vx);
	wprintf(L"整数B:\n"); scanf("%d",&vy);
	wprintf(L"A的值是B的%d%%\n",vx*100/vy); */
	
	//int型和double型 示例
	/* int nx;
	double dx;
	nx=9.99;
	dx=9.99;
	wprintf(L" int    型变量nx的值：%d\n",nx);
	wprintf(L"              nx / 2：%d\n",nx / 2);
	
	wprintf(L" double 型变量dx的值：%f\n",dx);
	wprintf(L"              dx/2.0：%f\n",dx / 2.0); */
	
	//double类型的运算示例
	/* double dx,dy;
	wprintf(L"请输入两个数:\n");
	wprintf(L"实数vx:\n");scanf("%lf",&dx);
	wprintf(L"实数vy:\n");scanf("%lf",&dy);
	printf("dx+dy = %f\n",dx + dy);
	printf("dx-dy = %f\n",dx - dy);
	printf("dx*dy = %f\n",dx * dy);
	printf("dx/dy = %f\n",dx / dy); */

	//int与double的隐式类型转换示例
	/* int n1,n2,n3,n4;
	double d1,d2,d3,d4;
	n1 = 5 / 2;
	n2 = 5.0 / 2.0;
	n3 = 5.0 / 2;
	n4 = 5 / 2.0;
	
	d1 = 5 / 2;
	d2 = 5.0 / 2.0;
	d3 = 5.0 / 2;
	d4 = 5 / 2.0;
	
	wprintf(L"n1 = %d\n",n1);
	wprintf(L"n2 = %d\n",n2);
	wprintf(L"n3 = %d\n",n3);
	wprintf(L"n4 = %d\n",n4);
	
	wprintf(L"d1 = %f\n",d1);
	wprintf(L"d2 = %f\n",d2);
	wprintf(L"d3 = %f\n",d3);
	wprintf(L"d4 = %f\n",d4); */
	
	//练习题
	/* double height;//身高和体重
	wprintf(L"请输入您的身高(cm):\n");scanf("%lf",&height);
	wprintf(L"您的标准体重是%.1f公斤。\n",(height-100)*0.9); */
	
	return(0);
}
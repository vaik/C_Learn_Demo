#include <stdio.h>
#include <locale.h>

int main(void)
{
	setlocale(LC_CTYPE,"");
		
		//if语句示例
		/* int vx;
		wprintf(L"请输入一个:");
		scanf("%d",&vx);
		if(vx%5)
			wprintf(L"输入的整数不能整除。\n"); */
			
		//奇数判断
		/* int no;
		wprintf(L"请输入一个整数:");
		scanf("%d",&no);
		if(no % 2)
			wprintf(L"输入的整数是奇数。"); */
			
		//if语句else示例
		/* int vx;
		wprintf(L"请输入一个:");
		scanf("%d",&vx);
		if(vx%5)
			wprintf(L"输入的整数不能整除。\n"); 
		else
			wprintf(L"输入的整数能被5整除。\n"); 
			 */
		
		//非0判断
		/* int num;
		wprintf(L"请输入一个整数:");
		scanf("%d",&num);
		if(num)
			wprintf(L"该整数不为0。\n"); 
		else
			wprintf(L"该整数为0。\n");  */
			
		//相等判断
		/* int x1,x2;
		wprintf(L"请输入两个整数\n");
		wprintf(L"整数1：");scanf("%d",&x1);
		wprintf(L"整数2：");scanf("%d",&x2);
		
		if(x1 == x2)
			wprintf(L"它们相等。");
		else
			wprintf(L"它们不相等。"); */
			
		//不相等判断
		/* int x1,x2;
		wprintf(L"请输入两个整数\n");
		wprintf(L"整数1：");scanf("%d",&x1);
		wprintf(L"整数2：");scanf("%d",&x2);
		
		if(x1 != x2)
			wprintf(L"它们不相等。");
		else
			wprintf(L"它们相等。"); */
			
		//判断输入整数的符号
		/* int no;
		wprintf(L"请输入一个:");
		scanf("%d",&no);
		if(no == 0)
			wprintf(L"该整数为0。\n"); 
		else if(no > 0)
			wprintf(L"该整数为正数。\n"); 
		else
			wprintf(L"该整数为负数。\n"); 
			 */
			 
		//显示一个整数的绝对值
		/* int no;
		wprintf(L"请输入一个:");
		scanf("%d",&no);
		if(no < 0)
			wprintf(L"该整数的绝对值为%d。\n",-no);  
		else
			wprintf(L"该整数的绝对值为%d。\n",no);  */
			
		//计算三个数中最大数
		/* int n1,n2,n3,max;
		wprintf(L"请输入三个整数\n");
		wprintf(L"整数1：");scanf("%d",&n1);
		wprintf(L"整数2：");scanf("%d",&n2);
		wprintf(L"整数3：");scanf("%d",&n3);
		
		max = n1;
		if(n2 > max) max = n2;
		if(n3 > max) max = n3;
		
		wprintf(L"最大值是%d。\n",max); */
		
		//条件运算符
		/* int n1,n2,max;
		wprintf(L"请输入两个整数\n");
		wprintf(L"整数1：");scanf("%d",&n1);
		wprintf(L"整数2：");scanf("%d",&n2);
		
		max = (n1>n2) ? n1 : n2;
		
		wprintf(L"较大的数是%d。\n",max); */
		
		//复合语句（程序块）
		/* int n1,n2,max,min;
		wprintf(L"请输入三个整数\n");
		wprintf(L"整数1：");scanf("%d",&n1);
		wprintf(L"整数2：");scanf("%d",&n2);
		
		if(n1>n2){
			max = n1;
			min = n2;
		}else{
			max = n2;
			min = n1;
		}
		
		wprintf(L"较大的数是%d。\n",max);
		wprintf(L"较小的数是%d。\n",min);	 */	
		
		//判断四季
		/* int month;
		wprintf(L"请输入一个月份：\n");
		scanf("%d",&month);
		if(month >= 3 && month <=5){
			wprintf(L"是春季。");
		}else if(month >= 6 && month <=8){
			wprintf(L"是夏季。");
		}else if(month >= 9 && month <=11){
			wprintf(L"是秋季。");
		}
		else if(month == 12 || month ==1 || month ==2){
			wprintf(L"是冬季。");
		}else
			wprintf(L"输入的月份不存在!!\a"); */
			
		//判断三个整数的相等情况
		/* int n1,n2,n3;
		wprintf(L"请输入三个整数\n");
		wprintf(L"整数1：");scanf("%d",&n1);
		wprintf(L"整数2：");scanf("%d",&n2);
		wprintf(L"整数3：");scanf("%d",&n3);
		
		if(n1 == n2 && n2 == n3){
			wprintf(L"三个值都相等\n"); 
		}else if(n1 != n2 && n2 != n3 && n1 != n3){
			wprintf(L"三个值各不相等\n");
		}else{
			wprintf(L"有两个值相等\n");
		} */
		
		//switch使用
		/* int num;
		wprintf(L"请输入一个整数:");
		scanf("%d",&num);
		switch(num % 3){
			case 0 : wprintf(L"该数能被3整除:"); break;
			case 1 : wprintf(L"该数除以3的余数是1:"); break;
			case 2 : wprintf(L"该数除以3的余数是2:"); break;
		} */
		


						
	return 0;
}
#include <stdio.h>
#include <locale.h>

#define sqr(x) ((x) * (x))

//练习8-1
#define diff(x,y) ((x)-(y))

//练习8-2
#define max(x,y) (((x)>(y)) ? (x) : (y))

//练习8-3
#define swap(type,a,b) {a=a+b;b=a-b;a=a-b;}

enum animal {Dog,Cat,Monkey,Invalid};

//狗叫
void dog(void)
{
	wprintf(L"汪汪！！\n");
}

//猫叫
void cat(void)
{
	wprintf(L"喵~!!\n");
}

//猴叫
void monkey(void)
{
	wprintf(L"唧唧!!\n");
}

//选择动物
enum animal select(void)
{
	int tmp;
	do {
		wprintf(L"0...狗	1...猫	2...猴	3...结束:");
		scanf("%d",&tmp);
	}while(tmp < Dog || tmp > Invalid);
	return(tmp);
}

int main(void){
	setlocale(LC_CTYPE,"");
	
	//函数式宏
	/* int nx;
	double dx;
	
	wprintf(L"请输入一个整数：");
	scanf("%d",&nx);
	wprintf(L"该数的平方是%d。\n",sqr(nx));
	
	wprintf(L"请输入一个实数：");
	scanf("%lf",&dx);
	wprintf(L"该数的平方是%f。\n",sqr(dx)); */
	
	//练习8-1
	/* int a,b;
	double x,y;
	
	wprintf(L"请输入一个整数a：");
	scanf("%d",&a);
	wprintf(L"请输入一个整数b：");
	scanf("%d",&b);
	wprintf(L"a减b的差为%d。\n",diff(a,b));
		
	wprintf(L"请输入一个实数x：");
	scanf("%lf",&x);
	wprintf(L"请输入一个实数b：");
	scanf("%lf",&y);
	wprintf(L"x减y的差为%f。\n",diff(x,y)); */
	
	//练习8-2
	/* double a,b,c,d;
	wprintf(L"请输入一个实数a：");
	scanf("%lf",&a);
	wprintf(L"请输入一个实数b：");
	scanf("%lf",&b);
	wprintf(L"请输入一个实数c：");
	scanf("%lf",&c);
	wprintf(L"请输入一个实数b：");
	scanf("%lf",&d);
	
	printf("max is %f\n",max(max(a,b),max(c,d)));
	printf("max is %f\n",max(max(max(a,b),c),d)); */
	
	//练习8-3
	/* double a,b;
	wprintf(L"请输入一个实数a：");
	scanf("%lf",&a);
	wprintf(L"请输入一个实数b：");
	scanf("%lf",&b);
	swap(double,a,b);
	
	printf("a is %f\n",a);
	printf("b is %f\n",b); */
	
	//枚举示例
	enum animal selected;
	
	do{
		switch(selected = select()){
			case Dog : dog(); break;
			case Cat : cat(); break;
			case Monkey : monkey();break;
		}
	}while(selected != Invalid);
	
	return 0;
}
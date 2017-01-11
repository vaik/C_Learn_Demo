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

//返回阶乘的值
int factorial(int n){
	if(n>0)
		return (n * factorial(n-1));
	else	
		return (1);
}

//返回vx和vy的最大公约数(vx>= vy)
int gcdf(int vx,int vy){
	return (vy ==0 ? vx : gcdf(vy,vx%vy));
}

//求出va和vb的最大公约数
int gcd(int va,int vb)
{
	return (va > vb ? gcdf(va,vb) : gcdf(vb,va));
}

//练习8-5 不递归实现阶乘
int fact(int n){
	if(n <= 0)
		return 1;
	int result=1;
	do{
		result *= n;
		n--;
	}while(n>1);
	return result;	
}

//练习8-6
int combination(int n,int r)
{
	if(n==0 || n==r || n<r)
		return 1;
	if(r==1)
		return n;
	return combination(n-1,r-1)+combination(n-1,r);
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
	/* enum animal selected;
	
	do{
		switch(selected = select()){
			case Dog : dog(); break;
			case Cat : cat(); break;
			case Monkey : monkey();break;
		}
	}while(selected != Invalid); */
	
	//计算阶乘
	/* int num;
	
	wprintf(L"请输入一个整数");
	scanf("%d",&num);
	
	wprintf(L"该数阶乘为%d。\n",factorial(num)); */
	
	//求最大公约数示例
	/* int n1,n2;
	wprintf(L"请输入两个整数。\n");
	wprintf(L"整数1：");scanf("%d",&n1);
	wprintf(L"整数2：");scanf("%d",&n2);
	
	wprintf(L"最大公约数是%d。\n",gcd(n1,n2)); */
	
	//练习8-5
	/* int num;
	
	wprintf(L"请输入一个整数");
	scanf("%d",&num);
	
	wprintf(L"该数阶乘为%d。\n",fact(num)); */
	
	//练习8-6
	/* int n,r;

	wprintf(L"请输入一个整数n");
	scanf("%d",&n);
	wprintf(L"请输入一个小于等于n的正整数r");
	scanf("%d",&r);
	wprintf(L"计算结果为%d。\n",combination(n,r)); */
	
	//计算标准输入流中出现的数字字符数
	/* int i,ch;
	int cnt[10] = {0};
	
	while(1){
		ch = getchar();
		if(ch==EOF) break; */
		/* switch(ch){
			case '0' : cnt[0]++; break;
			case '1' : cnt[1]++; break;
			case '2' : cnt[2]++; break;
			case '3' : cnt[3]++; break;
			case '4' : cnt[4]++; break;
			case '5' : cnt[5]++; break;
			case '6' : cnt[6]++; break;
			case '7' : cnt[7]++; break;
			case '8' : cnt[8]++; break;
			case '9' : cnt[9]++; break;
		} */
		//以上代码可以以下代码替代
		/* if(ch >=48 && ch <= 57)
			cnt[ch-48]++;
	}
	
	wprintf(L"数字字符的出现次数\n");
	for(i=0;i<10;i++)
		printf("'%d' : %d\n",i,cnt[i]); */
		
	//标准输入流复制到标准输出流
	int ch;
	while((ch = getchar()) != EOF)
		putchar(ch);
		
	
	return 0;
}
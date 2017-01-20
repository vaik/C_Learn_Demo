#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define NUMBER 5 /* 学生人数 */

#define sqr(n) ((n)*(n))

/* ---交换x和y指向的整数值--- */
/* void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
} */

/* ---将数组data的前n个元素按升序排列--- */
/* void sort(int data[], int n)
{
	int k = n-1;
	while( k >=0 ){
		int i,j;
		for(i=1,j=-1;i<=k;i++){
			if(data[i-1] > data[i]){
				j = i-1;
				swap(&data[i], &data[j]);
			}
		}
		k = j;
	}
} */

//表示学生的结构体
typedef struct {
	char name[20]; //姓名
	int height;    //身高
	float weight;  //体重
	long schols;   //奖学金
} student;

/* ---能改变人身高和体重的洋子--- */
void hiroko(student *std)
{
	if(std->height < 180) std->height = 180;
	if(std->weight > 80) std->weight = 80;
}

/* ---对x和y指向的学生进行交换--- */
void swap(student *x,student *y)
{
	student temp = *x;
	*x = *y;
	*y = temp;
}

/* ---对数组Data的前n个元素按身高进行升序排序--- */
void sort(student data[],int n){
	int k = n-1;
	while(k>=0){
		int i,j;
		for(i=1,j=-1;i<=k;i++){
				if(data[i-1].height > data[i].height){
					swap(&data[i-1],&data[i]);
					j = i-1;
				}
		}
		k = j;
	};
}

/* ---显示当前的时间:年 月 日--- */
void put_date(void)
{
	time_t current;
	struct tm *local;
	char wday_name[][7] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
	
	time(&current);
	local = localtime(&current);
	printf("%4d Year %02d Month %02d Day (%s)",local->tm_year + 1900
											  ,local->tm_mon + 1
											  ,local->tm_mday
											  ,wday_name[local->tm_wday]
		  );
}

/* ---显示当前的时间:年 月 日 时 分 秒--- */
void put_time(void)
{
	time_t current;
	struct tm *local;
	char wday_name[][7] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
	
	time(&current);
	local = localtime(&current);
	printf("%4d-%02d-%02d %02d:%02d:%02d (%s)",local->tm_year + 1900
											  ,local->tm_mon + 1
											  ,local->tm_mday
											  ,local->tm_hour
											  ,local->tm_min
											  ,local->tm_sec
											  ,wday_name[local->tm_wday]
		  );
}

/* ---坐标结构体--- */
typedef struct{
	int x;
	int y;
} point;

/* ---汽车结构体--- */
typedef struct{
	double fuel;
	point pt;
} car;

/* ---显示当前位置和剩余燃料--- */
void put_info(car c){
	printf("Current location:(%d,%d)\n",c.pt.x,c.pt.y);
	printf("Left fuel:%.2f \n",c.fuel);
}

int move(car *c,int dx,int dy)
{
	double dist = sqrt(sqr(dx)+sqr(dy));
	if(dist > c->fuel)
		return (0);
	c->pt.x +=dx;	c->pt.y+= dy;	c->fuel -= dist;
	return 1;
}

int main(void){
	
	//排序
	/* int i;
	int height[] = {178,175,173,165,179};
	sort(height,NUMBER);
	
	for(i=0;i<NUMBER;i++)
		printf("%2d : %4d\n",i+1,height[i]); */
	
	//结构体演示
	/* student sanaka;
	
	strcpy(sanaka.name,"Sanaka");
	sanaka.height = 175;
	sanaka.weight = 6.5;
	sanaka.schols = 70000;
	
	printf("Name = %s\n",sanaka.name);
	printf("Height = %d\n",sanaka.height);
	printf("Weight = %.2f\n",sanaka.weight);
	printf("Schols = %ld\n",sanaka.schols); */
	
	//->运算符
	/* student sanaka = {"sanaka",175,90.5,70000};
	
	hiroko(&sanaka);
	
	printf("Name = %s\n",sanaka.name);
	printf("Height = %d\n",sanaka.height);
	printf("Weight = %.2f\n",sanaka.weight);
	printf("Schols = %ld\n",sanaka.schols);  */
	
	//将5名学生按身高排序
	/* int i;
	student std[]={
		{"Sato",178,61.0,80000},
		{"Sanaka",175,60.5,70000},
		{"Takao",173,80.0,0},
		{"Mike",165,72.0,70000},
		{"Masaki",179,77.5,70000},
	};
	puts("--------------------------------------------");
	for(i = 0; i < NUMBER; i++)
		printf("%-8s %6d%6.1f%7ld\n",
			std[i].name,std[i].height,std[i].weight,std[i].schols);
	puts("--------------------------------------------");	 */	
	
	//显示当前日期
	/* printf("Today is ");
	put_date();
	printf(".\n"); */
	
	//显示当前时间
	/* printf("Now is ");
	put_time();
	printf(".\n"); */
	
	//汽车行驶与燃料消耗
	car mycar = {90.0,{0,0}};
	
	while(1){
		int slct;
		int dx,dy;
		
		put_info(mycar);
		printf(" Do you move car[ Yes...1 / No...0]:");
		scanf("%d",&slct);
		if(slct != 1) break;
		printf("Distance of X:");scanf("%d",&dx);
		printf("Distance of Y:");scanf("%d",&dy);
		
		if(!move(&mycar,dx,dy))
			puts("\a fuel is not enough!\n");
	}
	
	return 0;
}
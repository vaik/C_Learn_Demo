#include <stdio.h>

/*---将n1和n2的和、差分别保存至sum、diff（误例）---*/
/*void sum_diff(int n1,int n2,int sum,int diff){

	sum = n1 + n2;
	diff = (n1 > n2) ? n1 - n2 : n2 - n1;
}*/
void sum_diff(int n1,int n2,int *sum,int *diff){

	*sum = n1 + n2;
	*diff = (n1 > n2) ? n1 - n2 : n2 - n1;
}


//让身高不到180cm的人长到180cm
void hiroko(int *height){
	if(*height < 180)
		*height = 180;
}

//判断是否闰年 1 是 0否
int is_leap_year(const int y){
	if(y%100 == 0 ){
		if(y%400 == 0)
			return 1;
		return 0;
	}else if(y%4 ==0){
		return 1;
	}
	return 0;
}


// 设置y年m月d日的前一天的日期(能正确判断闰年 闰月）
// 1. 被4整除就是闰年,能被100整除但不能被400整除也不是闰年,闰年2月有29天。
// 2. 1,3,5,7,8,10,12 每个月30天 2月不是闰年28天，4，6，9，11每月30天。
// 3. 跨月的情况,当前日期减1后得0则为跨月，月份减1，日变化为前月的最后一天。
// 4. 跨年的情况，当前月份减1后得0则判断为跨年，年份减1，月份为12，日为31。
void yesterday(int *y,int *m,int *d)
{
	if(*m == 1 && *d == 1){//判断跨年
		*y = *y-1;
		*m = 12;
		*d = 31;
	}else if(*d == 1){//判断跨月
		*m = *m-1;
		switch(*m){
			case 1:
				*d = 31;
				break;
			case 2:
				if(is_leap_year(*y)){
					*d = 29;
				}else{
					*d = 28;
				}
				break;	
			case 3:
				*d = 31;
				break;
			case 4:
				*d = 30;
				break;
			case 5:
				*d = 31;
				break;
			case 6:
				*d = 30;
				break;
			case 7:
				*d = 31;
				break;
			case 8:
				*d = 31;
				break;
			case 9:
				*d = 30;
				break;
			case 10:
				*d = 31;
				break;
			case 11:
				*d = 30;
				break;
			case 12:
				*d = 31;
				break;
		}
	}else{
		*d = *d-1;
	}
}

// 设置y年m月d日的后一天的日期(能正确判断闰年 闰月）
void tomorrow(int *y,int *m,int *d)
{
	if(*m == 12 && *d == 31){//判断跨年
		*y = *y+1;
		*m = 1;
		*d = 1;
	}else{
		switch(*m){
			case 1:
				if(*d==31){
					*m = *m + 1;
					*d = 1;
				}else{
					*d = *d + 1;
				}
				break;
			case 2:
				if(is_leap_year(*y)){
					if(*d==29){
						*m = *m + 1;
						*d = 1;
					}else{
						*d = *d + 1;
					}
				}else{
					if(*d==28){
						*m = *m + 1;
						*d = 1;
					}else{
						*d = *d + 1;
					}
				}
				break;	
			case 3:
				if(*d==31){
					*m = *m + 1;
					*d = 1;
				}else{
					*d = *d + 1;
				}
				break;
			case 4:
				if(*d==30){
					*m = *m + 1;
					*d = 1;
				}else{
					*d = *d + 1;
				}
				break;
			case 5:
				if(*d==31){
					*m = *m + 1;
					*d = 1;
				}else{
					*d = *d + 1;
				}
				break;
			case 6:
				if(*d==30){
					*m = *m + 1;
					*d = 1;
				}else{
					*d = *d + 1;
				}
				break;
			case 7:
				if(*d==31){
					*m = *m + 1;
					*d = 1;
				}else{
					*d = *d + 1;
				}
				break;
			case 8:
				if(*d==31){
					*m = *m + 1;
					*d = 1;
				}else{
					*d = *d + 1;
				}
				break;
			case 9:
				if(*d==30){
					*m = *m + 1;
					*d = 1;
				}else{
					*d = *d + 1;
				}
				break;
			case 10:
				if(*d==31){
					*m = *m + 1;
					*d = 1;
				}else{
					*d = *d + 1;
				}
				break;
			case 11:
				if(*d==30){
					*m = *m + 1;
					*d = 1;
				}else{
					*d = *d + 1;
				}
				break;
			case 12:
				if(*d==31){
					*m = *m + 1;
					*d = 1;
				}else{
					*d = *d + 1;
				}
				break;
		}
	}
}

//交互两个整数变量的值
void swap(int *n1,int *n2){
	int temp;
	temp = *n2;
	*n2 = *n1;
	*n1 = temp;
}

//三个整数按升序排列
void sort3(int *n1,int *n2,int *n3){
	if(*n1 > *n2){
		swap(n1,n2);
	}
	if(*n2 > *n3){
		swap(n2,n3);		
	}
	if(*n1 > *n2){
		swap(n1,n2);
	}
}

int main(void){

	// printf("I love you world!\n");

	//误例将n1和n2的和、差分别保存至sum、diff 演示
	/*int na,nb;
	int wa = 0,sa = 0;
	puts("Please input two integers!");
	printf("Integer A:"); scanf("%d",&na);
	printf("Integer B:"); scanf("%d",&nb);
	sum_diff(na,nb,wa,sa);

	printf("The sum of two integers is %d. The diff of tow integers %d.\n",wa,sa);*/

	//显示对象的地址
	/*int nx;
	int dx;
	int vc[3];

	printf("nx's Adress is %p \n",&nx);
	printf("dx's Adress is %p \n",&dx);
	printf("vc[0]'s Adress is %p \n",&vc[0]);
	printf("vc[1]'s Adress is %p \n",&vc[1]);
	printf("vc[2]'s Adress is %p \n",&vc[2]);*/

	//指针
	/*int sato = 178;
	int sanaka = 175;
	int hiraki = 165;
	int masaki = 179;

	int *isako, *hiroko;

	isako = &sato;
	hiroko = &masaki;

	putchar('\n');
	printf("sato's height is %d \n",sato);
	printf("sanaka's height is %d \n",sanaka);
	printf("hiraki's height is %d \n",hiraki);
	printf("masaki's height is %d \n",masaki);
	printf("isako's height is %d \n",*isako);
	printf("hiroko's height is %d \n",*hiroko);*/

	//作为函数参数的指针
	/*int sato = 178;
	int sanaka = 175;
	int hiraki = 165;
	int masaki = 179;

	hiroko(&masaki);

	printf("sato's height is %dcm \n",sato);
	printf("sanaka's height is %dcm \n",sanaka);
	printf("hiraki's height is %dcm \n",hiraki);
	printf("masaki's height is %dcm \n",masaki);*/

	//将n1和n2的和、差分别保存至sum、diff 演示
	/*int na,nb;
	int wa = 0,sa = 0;
	puts("Please input two integers!");
	printf("Integer A:"); scanf("%d",&na);
	printf("Integer B:"); scanf("%d",&nb);
	sum_diff(na,nb,&wa,&sa);

	printf("The sum of two integers is %d. The diff of tow integers %d.\n",wa,sa);*/
	
	//练习10-1
	/* int y,m,d,flag;
	flag=1;
	while(1){
		printf("1---starting	0---quit\n");
		scanf("%d",&flag);
		if(!flag){
			break;
		}
		printf("Please input the year:");
		scanf("%d",&y);
		printf("Please input the month:");
		scanf("%d",&m);
		printf("Please input the day:");
		scanf("%d",&d);
		yesterday(&y,&m,&d);
		printf("The yesterday is %d-%d-%d\n",y,m,d);
		tomorrow(&y,&m,&d);
		tomorrow(&y,&m,&d);
		printf("The tomorrow is %d-%d-%d\n",y,m,d);
	}; */

	//练习10-2
	/* int x,y,z;
	int flag=1;
	while(1){
		printf("Sort: 1---starting	0---quit\n");
		scanf("%d",&flag);
		if(!flag){
			break;
		}
		printf("Please input x:");
		scanf("%d",&x);
		printf("Please input y:");
		scanf("%d",&y);
		printf("Please input z:");
		scanf("%d",&z);
		sort3(&x,&y,&z);
		printf("The result of sorted x,y,z is x:%d y:%d z:%d\n",x,y,z);
	}; */
	
	//指针与数组
	int i;
	int vc[5] = {10,20,30,40,50};
	int *ptr = &vc[0];

	for(i=0;i<5;i++)
		printf("vc[%d] = %d    ptr[%d] = %d    *(ptr + %d) = %d \n",i,vc[i],i,ptr[i],i,*(ptr+i)); 

	return 0;
}
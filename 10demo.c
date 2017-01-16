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

	//指针与数组
	int i;
	int vc[5] = {10,20,30,40,50};
	int *ptr = &vc[0];

	for(i=0;i<5;i++)
		printf("vc[%d] = %d    ptr[%d] = %d    *(ptr + %d) = %d \n",i,vc[i],i,ptr[i],i,*(ptr+i));

	return 0;
}
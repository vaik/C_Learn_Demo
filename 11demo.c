#include <stdio.h>
#include <string.h>

//复制字符串
char *str_copy(char *d,const char *s)
{
	char *t = d;
	while(*d++ = *s++)
	;
	return (t);
}

//显示字符串（不换行）
void put_string(const char *ptr){
	char temp;
	while(temp = *ptr++)
		putchar(temp);
}

//返回字符串str中第一个出现字符C的指针，否则返回NULL
char *str_char(const char *str,int c){
	while(*str && *str!= c ){
		*str++;
		printf("str:%d,c:%d \n",*str,c);
	}
	char *num = "";
	num = &str[0];
	return NULL;
}

int main(void)
{
	//用数组实现的字符串和用指针实现的字符串
	/* char str[] = "ABC"; //用数组实现的字符串
	char *ptr = "123"; //用指针实现的字符串
	
	printf("str = \"%s\"\n",str);
	printf("str = \"%s\"\n",ptr); */
	
	//字符串数组
	/* int i;
	char st[3][6] = {"Turbo","NA","DOHC"};
	char *pt[3]   = {"12345","12","1234"};
	
	for(i = 0; i < 3; i++)
		printf("st[%d] = \"%s\"\n",i,st[i]);
	
	for(i = 0; i < 3; i++)
		printf("pt[%d] = \"%s\"\n",i,pt[i]); */
	
	//复制字符串	
	/* char s1[128] = "ABCD";
	char s2[128] = "EFGH";
	
	printf("string s1:");scanf("%s",s1);
	
	str_copy(s2,s1);
	
	puts("s1 copys to s2.");
	printf("s1 = %s\n",s1);
	printf("s2 = %s\n",s2); */
	
	//练习11-1
	/* char str[100];
	printf("Please input strings:");
	scanf("%s",str);
	put_string(str);
	putchar('\n'); */
	
	//练习11-2
	char str[128] = "ABCDEFCCD";
	
	printf("The Address is %d",str_char(str,'C'));
	
	return 0;
}
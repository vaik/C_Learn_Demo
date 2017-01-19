#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

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

	char *ptr = (char *)str;
	int flag = 0;
	while(*ptr){
		if(c == *ptr){
			flag = 1;
			break;
		}
		ptr++;
	}
	if(!flag)
		return NULL;
	return (ptr);
}

//返回字符串str中出现字符C的个数
int str_chnum(const char *str,int c){
	int num = 0;
	while(*str){
		if(c == *str){
			num++;
		}
		str++;
	}
	return (num);
}

//交字符串的英文字母转换为大写字母
void str_toupper(char *str)
{
	char *ptr = str;
	while(*ptr){
		*ptr = toupper(*ptr);
		ptr++;
	}
}

//交字符串的英文字母转换为小写字母
void str_tolower(char *str)
{
	char *ptr = str;
	while(*ptr){
		*ptr = tolower(*ptr);
		ptr++;
	}
}

//删除所有数字字符
void del_digit(char *str){
	int len = strlen(str);
	char temp[len];
	char *ptr = temp;
	char *str1 = str;
	int num = 0;
	while(*str){
		if(*str < '0' || *str > '9'){
			*ptr = *str;
			num++;
			ptr++;
		}
		str++;
	}
	*ptr = '\0';
	char *ptr1 = temp;
	while(*str1++ = *ptr1++);
	num = len-num;
	while(num--) *str1++='\0';
}

int getpower(int num,int power){
	int reuslt = 1;
	while(power){
		reuslt *=num;
		power--;
	}
	return reuslt;
}

int strtoi(const char *nptr){
	int len = strlen(nptr);
	int temp[len];
	int index = 0;
	int reuslt = 0;
	int i;
	while(*nptr){
		if(*nptr >= '0' && *nptr <='9'){
			temp[index] = (int)(*nptr-'0');
			index++;
		}else{
			break;
		} 
		nptr++;
	}
	for(i=0;i<index;i++){
		reuslt += temp[i]*getpower(10,index-i-1);
	} 
	return reuslt;
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
	/* char str[128] = "ABCDEFCCD";
	
	printf("The Address is %d",str_char(str,'F')); */
	
	//练习11-3
	/* char str[128] = "ABCDEFCCD";
	
	printf("The number is %d",str_chnum(str,'G'));  */
	
	//练习11-4
	/* char str[100];
	
	printf("Please Input string");
	scanf("%s",str);
	
	str_toupper(str);
	printf("The Upper:%s\n",str);
	
	str_tolower(str);
	printf("The Lower:%s\n",str);  */

	//练习11-5
 	/* char str[100];
	printf("Please Input string");
	scanf("%s",&str);
	//char *str = "ABCDEFCCD12121";

	del_digit(str);
	printf("The result is :%s\n",str); 
	 */
	
	//字符串转换函数
	char str[] = "1234agc45";
	printf("str	=\"%s\"\n",str);
	printf("atoi(str)	= %d\n",atoi(str));
	printf("strtoi(str)	= %d\n",strtoi(str));
	//printf("%d\n",getpower(10,2));
	
	return 0;
}
#include <stdio.h>
#include <locale.h>
#include <ctype.h>

//返回字符串str的长度
unsigned str_length(const char str[])
{
	unsigned len = 0;
	
	while(str[len])
		len++;
	return (len);
}

//练习9-3
int str_char(const char str[],int c)
{
	int i=0;
	int result = -1;
	printf("c:%d\n",c);
	printf("str[0]=%d\n",str[0]);
	while (str[i]&&i<=100)
	{
		printf("str[%d]=%d",i,str[i]);
		if((int)str[i] == c){
			result = i;
			break;
		}
		i++;
	}
	return result;
}

//练习9-4
int str_chnum(const char str[],int c)
{
	int i=0;
	int result = 0;
	while(str[i]){
		if(str[i] == c)
			result++;
	}
	return result;
}

//将字符串str中的数字字符保存至数组cnt
void str_dcount(const char str[], int cnt[])
{
	unsigned i = 0;	
	while (str[i]){
		if(str[i] >= '0' && str[i] <= '9')
			cnt[str[i]-'0']++;
		i++;
	}
}

//显示字符串(不换行）
void put_string(const char str[])
{
	unsigned i=0;
	while(str[i])
		putchar(str[i++]);
}


//逆向输出字符串(不换行）
void put_restring(const char str[])
{
	int len = str_length(str);
	while(len){
		putchar(str[len-1]);
		len--;
	}
}

//交字符串的英文字母转换为大写字母
void str_toupper(char str[])
{
	unsigned i = 0;
	while(str[i]){
		str[i] = toupper(str[i]);
		i++;
	}
}

//交字符串的英文字母转换为小写字母
void str_tolower(char str[])
{
	unsigned i = 0;
	while(str[i]){
		str[i] = tolower(str[i]);
		i++;
	}
}

//练习9-10
void del_digit(char str[]){
	int len = str_length(str);
	char temp[len];
	int i=0,k=0;
	for(;i<len;i++){
		if(str[i]<'0' || str[i]>'9'){
			temp[k] = str[i];
			k++;
		}		
	}
	for(i=0;i<len;i++)
	{
		if(i<k){
			str[i] = temp[i];
		}else{
			str[i]='\0';
		}
	}
}

int main(void){
	setlocale(LC_CTYPE,"");
	
	//显示字符串字面量长度
	/* printf("sizeof(\"123\")	=	%u\n",(unsigned)sizeof("123"));
	printf("sizeof(\"AB\\tC\")	=	%u\n",(unsigned)sizeof("AB\tC"));
	printf("sizeof(\"abc\\0def\")	=	%u\n",(unsigned)sizeof("abc\0def")); */
	
	//保存字符串的数组
	/* char str[4];
	str[0] = 'A';
	str[1] = 'B';
	str[2] = 'C';
	str[3] = '\0'; */
	
	//char str[] = "ABC";
	//char str[] = {'A','B','C','\0'};
	/* char str[] = "ABC\0DEF";
	
	//练习9-2
	str[0]='\0';
	
	wprintf(L"字符串str为%S。\n",str); */
	
	//格式化字符串
	/* char str[] = "12345";
	
	printf("%s\n",str);	//原样输出
 	printf("%3s\n",str);//至少显示3位
	printf("%.3s\n",str);//至多显示3位
	printf("%8s\n",str);//右对齐
	printf("%-8s\n",str);//左对齐 */
	
	
	//字符串数组
	/* int i;
	char cs[][6] = {"Turbo","NA","DOHC"};
	
	for(i=0;i<3;i++)
		printf("CS[%d]=\"%s\"\n",i,cs[i]); */
	
	//字符串长度
	/* char st[100];
	wprintf(L"请输入字符串：");
	scanf("%s",st);
	
	wprintf(L"字符串%S的长度为%u。\n",st,str_length(st)); */
	
	//练习9-2 9-3
	/* char st[100];
	char ct[100];
	char c[1];
	int i=0;
	wprintf(L"请输入字符串：");
	scanf("%s",st);
	while(st[i]){
		ct[i] = st[i];
		putchar(st[i]);
		i++;
	}
	ct[i]='\0';
	
	wprintf(L"请输入一个检查的字符：");
	scanf("%s",c);
	wprintf(L"字符串%S\n",ct);
	
	//wprintf(L"字符串%S出现%S的下标为%d。\n",st,c,str_char(st,(int)c[0])); */
	
	//数字字符的出现字数
	/* int i;
	int dcnt[10] = {0};
	char str[100];
	
	wprintf(L"请输入字符串：");
	scanf("%s",str);
	
	str_dcount(str,dcnt);
	
	wprintf(L"数字字符的出现次数");
	for(i=0;i<10;i++)
		printf("'%d':%d\n",i,dcnt[i]); */
	
	//逆向显示
	/* char str[100];
	
	wprintf(L"请输入字符串：");
	scanf("%s",str);
	
	put_restring(str); */
	
	//大小写转换
	/* char str[100];
	
	wprintf(L"请输入字符串：");
	scanf("%s",str);
	
	str_toupper(str);
	wprintf(L"大写字母:%S\n",str);
	
	str_tolower(str);
	wprintf(L"小写字母:%S\n",str); */
	
	//练习9-10
	char str[100];
	
	wprintf(L"请输入字符串：");
	scanf("%s",str);
	
	del_digit(str);
	wprintf(L"大写字母:%S\n",str);
	
	return 0;
	
}
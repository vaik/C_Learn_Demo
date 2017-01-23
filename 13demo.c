#include <stdio.h>
#include <time.h>

char data_file[] = "E:\\GitHub\\C_Learn_Demo\\datetime.dat";

char stu_data_file[] = "E:\\GitHub\\C_Learn_Demo\\student.dat";

/* ---取得并显示上一次运行时的日期和时间--- */
void get_data(void)
{
	FILE *fp;
	if((fp=fopen(data_file,"r"))==NULL){
		printf("This programe is running first time!\n");
	}else{
		int year,month,day,h,m,s;
		fscanf(fp,"%d%d%d%d%d%d",&year,&month,&day,&h,&m,&s);
		printf("Last ran time is %d-%d-%d %d:%d:%d\n",year,month,day,h,m,s);
		fclose(fp);
	}
}

/* ---写入本次运行的日期和时间--- */
void put_data(void)
{
	FILE *fp;
	time_t t;
	struct tm *local;
	
	time(&t);
	local = localtime(&t);
	
	if((fp=fopen(data_file,"w"))==NULL)
		printf("\a File open failed!\n");
	else{
		fprintf(fp,"%d %d %d %d %d %d\n",
				local->tm_year+1900,local->tm_mon+1,local->tm_mday,
				local->tm_hour,local->tm_min,local->tm_sec);
	}
}

int main(void)
{
	//打开文件
	/* FILE *fp;
	char filename[128];
	
	printf("Please input file name:");
	scanf("%s",&filename);
	
	fp = fopen(filename,"r");
	
	if(fp == NULL)
		printf("\a Open file failed!\n");
	else {
		fclose(fp);
	} */
	
	//显示上一次运行的日期和时间
	/* get_data();
	put_data(); */
	
	//显示文件内容
	/* int ch;
	FILE *fp;
	char fname[64];
	
	printf("File name:");
	scanf("%s",fname);
	
	if((fp=fopen(fname,"r"))==NULL)
		printf("\aFile open failed.\n");
	else{
		while ((ch=fgetc(fp))!=EOF)
			putchar(ch);
		fclose(fp);
	} */
	
	return 0;
}
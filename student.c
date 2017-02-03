#include <stdio.h>

#define STUNUMBER 20

char stu_data_file[] = "E:\\GitHub\\C_Learn_Demo\\student.dat";

/* ---学生结构体--- */
typedef struct{
	char name[100];
	double height;
	double weight;
	double chinese;
	double math;
	double english;
} student;

student StuDat[STUNUMBER];

/* ---初始化学生数据--- */
void init_stu_data(void)
{
	
}

/* ---显示学生信息--- */
void get_stu_data(void){
	FILE *fp;
	int ninzu = 0;	 /* 人数 */
	char name[20];	 /* 姓名 */
	char stuno[20];	 /* 学号 */
	double height,weight,chinese,math,english; /* 身高，体重，语文，数学，英语 */
	double hsum = 0.0 ;/* 身高合计 */
	double wsum = 0.0 ;/* 体重合计 */
	double csum = 0.0 ; /* 语文成绩全合计 */
	double msum = 0.0 ; /*数学成绩合计*/
	double esum = 0.0 ;/* 英语成绩合计 */
	double total = 0.0;
	
	if((fp=fopen(stu_data_file,"r"))==NULL)
		printf("\aFile open failed!\n");
	else{
		printf("Name    StuNo    Height    Weight    Chinese    Math    English    Total\n");
		fscanf(fp,"%s%s%lf%lf%lf%lf%lf",name,stuno,&height,&weight,&chinese,&math,&english);
		total = chinese+math+english;
		//printf("%s  %s  %f  %f  %f  %f  %f  %f\n",name,stuno,height,weight,chinese,math,english,total);
		printf("Name: %s\n",name);
		printf("StuNo: %s\n",stuno);
		printf("Height: %4.1f\n",height);
		printf("Weight: %4.1f\n",weight);
		printf("Chinese: %4.1f\n",chinese);
		printf("Math: %4.1f\n",math);
		printf("English: %4.1f\n",english);
		printf("Total: %4.1f\n",total);
		// while(==7){
			//printf("%10s%10s%6.1f%6.1f%6.1f%6.1f%6.1f%6.1f\n",name,stuno,height,weight,chinese,math,english,chinese+math+english);
		// }
		//fclose(fp);
	}
}

/* ---添加学生数据--- */
void add_stu_data(){
	FILE *fp;
	int ninzu = 0;	 /* 人数 */
	char name[20];	 /* 姓名 */
	char stuno[20];	 /* 学号 */
	double height,weight,chinese,math,english; /* 身高，体重，语文，数学，英语 */
	double hsum = 0.0 ;/* 身高合计 */
	double wsum = 0.0 ;/* 体重合计 */
	double csum = 0.0 ; /* 语文成绩全合计 */
	double msum = 0.0 ; /*数学成绩合计*/
	double esum = 0.0 ;/* 英语成绩合计 */
	
	if((fp=fopen(stu_data_file,"a"))==NULL)
		printf("\aFile open failed!\n");
	else{
		printf("Please input student name:");
		scanf("%s",name);
		printf("Please input student No:");
		scanf("%s",stuno);
		printf("Please input student Height:");
		scanf("%lf",&height);
		printf("Please input student Weight:");
		scanf("%lf",&weight);
		printf("Please input student Chinese:");
		scanf("%lf",&chinese);
		printf("Please input student Math:");
		scanf("%lf",&math);
		printf("Please input student English:");
		scanf("%lf",&english);
		// TODO
		//1.检测数据合法性
		//2.判断学生是否存在
		//3.如果存在根据用户选择更新，放弃，重新输入
		fprintf(fp,"%s%s%lf%lf%lf%lf%lf",name,stuno,height,weight,chinese,math,english);
		fclose(fp);
	}
}

/* ---删除学生信息---*/
int del_stu_data(char no){
	return 0;
}

/* ---判断学生是否存在--- */
int exsit_stu(student stu)
{
	return 0;
}

/* ---学生排序--- */
void sort_stu_data(void)
{

}

int main(void)
{
	int slct;
	printf(" Welcome to student sorce system!\n");
	while(1){
		printf("\n------------------------------Option Menu----------------------------\n");
		printf(" 1.Input 1 to show student's sorce.\n");
		printf(" 2.Input 2 to add student's sorce.\n");	
		printf(" 3.Input 3 to update student's sorce.\n");
		printf(" 4.Input 4 to delete student's sorce.\n");
		printf(" 5.Input 5 to sort and show student's sorce.\n");
		printf(" 0.Input 0 to quit student sorce system.\n");
		printf("------------------------------End Menu--------------------------------\n\n");
		scanf("%d",&slct);
		if(slct==0){
			printf("Quit student sorce system!\n");
			break;
		}else if(slct==1){
			printf("Show student's sorce!\n");
			get_stu_data();
		}else if(slct==2){
			printf("Add student's sorce!\n");
			add_stu_data();
		}else if(slct==3){
			printf("Add student's sorce!\n");
		}else if(slct==4){
			printf("Delete student's sorce!\n");
		}else if(slct==5){
			printf("Sort student's sorce!\n");
		}
	}
	return 0;
}
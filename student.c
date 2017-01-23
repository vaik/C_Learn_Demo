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

student Stu[STUNUMBER];

/* ---显示学生信息--- */
void get_stu_data(void){
	FILE *fp;
	int ninzu = 0;	 /* 人数 */
	char name[100];	 /* 姓名 */
	char stuno[20];	 /* 学号 */
	double height,weight,chinese,math,english; /* 身高，体重，语文，数学，英语 */
	double hsum = 0.0 ;/* 身高合计 */
	double wsum = 0.0 ;/* 体重合计 */
	double csum = 0.0 ; /* 语文成绩全合计 */
	double msum = 0.0 ; /*数学成绩合计*/
	double esum = 0.0 ;/* 英语成绩合计 */
	
	if((fp=fopen(stu_data_file,"r"))==NULL)
		printf("\a File open failed!\n");
	else{
		while(fscanf(fp,"%s%s%lf%lf%lf%lf%lf",name,stuno,&height,&weight,&chinese,&math,&english)==7){
			
		}
	}
}


int main(void)
{

	return 0;
}
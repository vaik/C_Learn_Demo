#include <stdio.h>
#include <string.h>

#define STUNUMBER 20

char stu_data_file[] = "E:\\GitHub\\C_Learn_Demo\\student.dat";

/* ---学生结构体--- */
typedef struct{
	char name[20];
	char stuno[20];
	double height;
	double weight;
	double chinese;
	double math;
	double english;
} student;

/* ---学生成绩数据--- */
student StuDat[STUNUMBER];

/* ---学生长度--- */
int StuLength=0;

/* ---初始化学生数据--- */
void init_stu_data(void)
{
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
	int i=0;
	
	if((fp=fopen(stu_data_file,"r"))==NULL)
		printf("\aFile open failed!\n");
	else{
		while(fscanf(fp,"%s	%s	%lf	%lf	%lf	%lf	%lf",name,stuno,&height,&weight,&chinese,&math,&english)==7)
		{
			student st;
			strcpy(st.name,name);
			strcpy(st.stuno,stuno);
			st.height = height;
			st.weight = weight;
			st.chinese = chinese;
			st.math = math;
			st.english = english;
			StuDat[i] = st;
			i++;
		}
	}
	StuLength = i;
}

/* ---显示学生信息--- */
void get_stu_data(void){
	printf("Name    	StuNo    Height    Weight    Chinese    Math    English    Total\n");
	for(int index = 0;index < StuLength;index++){
		printf("%-16s%-9s%-10.1f%-10.1f%-11.1f%-8.1f%-11.1f%-9.1f\n",StuDat[index].name,StuDat[index].stuno,StuDat[index].height,StuDat[index].weight,StuDat[index].chinese,StuDat[index].math,StuDat[index].english,StuDat[index].chinese+StuDat[index].math+StuDat[index].english);
	}
}


/* ---更新所有学生数据--- */
void update_stu_data(){

	//ToDO:1.判断是否已达最大班级人数
	
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
	
	if((fp=fopen(stu_data_file,"w"))==NULL)
		printf("\aFile open failed!\n");
	else{
		for(int index = 0;index < StuLength;index++){
			fprintf(fp,"%s	%s	%lf	%lf	%lf	%lf	%lf",StuDat[index].name,StuDat[index].stuno,StuDat[index].height,StuDat[index].weight,StuDat[index].chinese,StuDat[index].math,StuDat[index].english);	
		}
		fclose(fp);
	}
}

void update_one_stu(student new){
	int result = 0;
	for(int index = 0;index < StuLength;index++){
			if(strcmp(StuDat[index].stuno,new.stuno)==0){
				result = 1;
				strcpy(StuDat[index].name,new.name);
				StuDat[index].height = new.height;
				StuDat[index].weight = new.weight;
				StuDat[index].chinese = new.chinese;
				StuDat[index].math = new.math;
				StuDat[index].english = new.english;
			}		
	}
	if(result == 1){
		update_stu_data();
	}
}

/* ---删除学生信息，1 删除成功 0 学生不存在---*/
int del_stu_data(char *no){
	int result = 0;
	int index = 0;
	student s;
	for(;index < StuLength;index++){
			if(result == 1)
			{
				StuDat[index-1] = StuDat[index];
			}
			if(strcmp(StuDat[index].stuno,no)==0){
				result = 1;
			}		
	}
	if(result == 1){
		StuDat[index] = s;
		StuLength--;
		update_stu_data();
	}
	return result;
}

/* ---判断学生是否存在 1 存在 0 不存在--- */
int exsit_stu(char *no)
{
	int result = 0;
	for(int index = 0;index < StuLength;index++){
			if(strcmp(StuDat[index].stuno,no)==0){
				result = 1;
				break;
			}
	}
	return result;
}

/* ---对x和y指向的学生进行交换--- */
void swap(student *x,student *y)
{
	student temp = *x;
	*x = *y;
	*y = temp;
}

/* ---对数组Data的前n个元素按身高进行降序排序--- */
void sort_height(student data[],int n){
	int k = n-1;
	while(k>=0){
		int i,j;
		for(i=1,j=-1;i<=k;i++){
				if(data[i-1].height < data[i].height){
					swap(&data[i-1],&data[i]);
					j = i-1;
				}
		}
		k = j;
	};
}

/* ---对数组Data的前n个元素按体重进行降序排序--- */
void sort_weight(student data[],int n){
	int k = n-1;
	while(k>=0){
		int i,j;
		for(i=1,j=-1;i<=k;i++){
				if(data[i-1].weight < data[i].weight){
					swap(&data[i-1],&data[i]);
					j = i-1;
				}
		}
		k = j;
	};
}

/* ---对数组Data的前n个元素按名称进行降序排序--- */
void sort_name(student data[],int n){
	int k = n-1;
	while(k>=0){
		int i,j;
		for(i=1,j=-1;i<=k;i++){
				if(data[i-1].name < data[i].name){
					swap(&data[i-1],&data[i]);
					j = i-1;
				}
		}
		k = j;
	};
}

/* ---对数组Data的前n个元素按学号进行降序排序--- */
void sort_stuno(student data[],int n){
	int k = n-1;
	while(k>=0){
		int i,j;
		for(i=1,j=-1;i<=k;i++){
				if(data[i-1].stuno < data[i].stuno){
					swap(&data[i-1],&data[i]);
					j = i-1;
				}
		}
		k = j;
	};
}

/* ---对数组Data的前n个元素按语文成绩进行降序排序--- */
void sort_chinese(student data[],int n){
	int k = n-1;
	while(k>=0){
		int i,j;
		for(i=1,j=-1;i<=k;i++){
				if(data[i-1].chinese < data[i].chinese){
					swap(&data[i-1],&data[i]);
					j = i-1;
				}
		}
		k = j;
	};
}

/* ---对数组Data的前n个元素按数学成绩进行降序排序--- */
void sort_math(student data[],int n){
	int k = n-1;
	while(k>=0){
		int i,j;
		for(i=1,j=-1;i<=k;i++){
				if(data[i-1].math < data[i].math){
					swap(&data[i-1],&data[i]);
					j = i-1;
				}
		}
		k = j;
	};
}

/* ---对数组Data的前n个元素按英文成绩进行降序排序--- */
void sort_english(student data[],int n){
	int k = n-1;
	while(k>=0){
		int i,j;
		for(i=1,j=-1;i<=k;i++){
				if(data[i-1].english < data[i].english){
					swap(&data[i-1],&data[i]);
					j = i-1;
				}
		}
		k = j;
	};
}

/* ---对数组Data的前n个元素按英文成绩进行降序排序--- */
void sort_total(student data[],int n){
	int k = n-1;
	while(k>=0){
		int i,j;
		for(i=1,j=-1;i<=k;i++){
				if(data[i-1].english+data[i-1].math+data[i-1].chinese < data[i].english+data[i].math+data[i].chinese){
					swap(&data[i-1],&data[i]);
					j = i-1;
				}
		}
		k = j;
	};
}

/* ---学生排序--- */
void sort_stu_data(void)
{
	int num;
	int flag = 0;
	/* ---学生成绩数据--- */
	student StuDatTemp[STUNUMBER];
	for(int i = 0;i<StuLength;i++){
		strcpy(StuDatTemp[i].name,StuDat[i].name);
		strcpy(StuDatTemp[i].stuno,StuDat[i].stuno);
		StuDatTemp[i].height = StuDat[i].height;
		StuDatTemp[i].weight = StuDat[i].weight;
		StuDatTemp[i].chinese = StuDat[i].chinese;
		StuDatTemp[i].math = StuDat[i].math;
		StuDatTemp[i].english = StuDat[i].english;
	}
	
	printf("Please select the sort type!\n");
	printf(" 1 by name;\n 2 by stuno;\n 3 by height;\n 4 by weight;\n 5 by chinese;\n 6 by math;\n 7 by english;\n 8 by total;\n");
	scanf("%d",&num);
	switch(num){
		case 1 :
			sort_name(StuDatTemp,StuLength);
			flag = 1;
			break;
		case 2 :
			sort_stuno(StuDatTemp,StuLength);
			flag = 1;
			break;
		case 3 :
			sort_height(StuDatTemp,StuLength);
			flag = 1;
			break;
		case 4 :
			sort_weight(StuDatTemp,StuLength);
			flag = 1;
			break;
		case 5 :
			sort_chinese(StuDatTemp,StuLength);
			flag = 1;
			break;
		case 6 :
			sort_math(StuDatTemp,StuLength);
			flag = 1;
			break;
		case 7 :
			sort_english(StuDatTemp,StuLength);
			flag = 1;
			break;
		case 8 :
			sort_total(StuDatTemp,StuLength);
			flag = 1;
			break;
	}
	if(flag ==1){
		printf("\n------------------------------Show Data----------------------------\n");
		printf("Name    	StuNo    Height    Weight    Chinese    Math    English    Total\n");
		for(int index = 0;index < StuLength;index++){
			printf("%-16s%-9s%-10.1f%-10.1f%-11.1f%-8.1f%-11.1f%-9.1f\n",StuDatTemp[index].name,StuDatTemp[index].stuno,StuDatTemp[index].height,StuDatTemp[index].weight,StuDatTemp[index].chinese,StuDatTemp[index].math,StuDatTemp[index].english,StuDatTemp[index].chinese+StuDatTemp[index].math+StuDatTemp[index].english);
		}
	}
}

/* ---添加学生数据--- */
void add_stu_data(void){
	//ToDO:1.判断是否已达最大班级人数	
	if(STUNUMBER > StuLength){
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
		int flag = 1;
		
		if((fp=fopen(stu_data_file,"a"))==NULL)
			printf("\aFile open failed!\n");
		else{
			while(flag){
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
				if(exsit_stu(stuno)){
					printf("The student No: %s is exsit!Please input again!\n",stuno);
				}else{
					student st;
					strcpy(st.name,name);
					strcpy(st.stuno,stuno);
					st.height = height;
					st.weight = weight;
					st.chinese = chinese;
					st.math = math;
					st.english = english;
					// TODO
					//1.检测数据合法性
					//2.判断学生是否存在
					//3.如果存在根据用户选择更新，放弃，重新输入
					fprintf(fp,"%s	%s	%lf	%lf	%lf	%lf	%lf",name,stuno,height,weight,chinese,math,english);	
					StuDat[StuLength] = st;
					StuLength++;
					flag = 0;
				}
			}
			fclose(fp);
		}
	}else{
		printf("You can't add new student,because the number of students is max!");
	}
}

int main(void)
{
	int slct;
	char stuno[20];
	char name[20];	 /* 姓名 */
	double height,weight,chinese,math,english; /* 身高，体重，语文，数学，英语 */
	printf(" Welcome to student sorce system!\n");
	//初始化学生数据
	init_stu_data();
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
			printf("Please input the student no thant you want to update:");
			scanf("%s",stuno);
			if(exsit_stu(stuno)==0){
				printf("The student of no %s is not exsit!\n",stuno);
			}else{
				printf("Please input student name:");
				scanf("%s",name);
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
				student st;
				strcpy(st.name,name);
				strcpy(st.stuno,stuno);
				st.height = height;
				st.weight = weight;
				st.chinese = chinese;
				st.math = math;
				st.english = english;
				update_one_stu(st);
			}
		}else if(slct==4){
			printf("Please input the student no thant you want to delete:");
			scanf("%s",stuno);
			if(del_stu_data(stuno)==0){
				printf("The student of no %s is not exsit!\n",stuno);
			}
		}else if(slct==5){
			sort_stu_data();
		}
	}
	return 0;
}
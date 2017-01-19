#include <stdio.h>

#define NUMBER 5 /* 学生人数 */

/* ---交换x和y指向的整数值--- */
void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

/* ---将数组data的前n个元素按升序排列--- */
void sort(int data[], int n)
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
}

int main(void){
	
	//排序
	int i;
	int height[] = {178,175,173,165,179};
	sort(height,NUMBER);
	
	for(i=0;i<NUMBER;i++)
		printf("%2d : %4d\n",i+1,height[i]);
	
	
	
	
	return 0;
}
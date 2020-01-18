//File Handling code
#include<stdio.h>
#define MAX_SIZE_CLIENT 1024*1024*2  // 2MB
#define PAYLOAD_SIZE 510
int ceil(double);

int main(){
	char str[MAX_SIZE_CLIENT];
	getFileContent(str);
	printf("File content length : %d\n",strlen(str));
	double doubleRowCount = ((double)strlen(str)/PAYLOAD_SIZE);
	int rowCount = ceil(doubleRowCount);
	printf("\nrowCount : %d\n",rowCount);
	int rowCount2 = ceil(34.5);
	printf("\nrowCount2 : %d\n",rowCount2);
	int rowCount3 = ceil(44.2);
	printf("\nrowCount3 : %d\n",rowCount3);
	return 0;
	char **finalArr;
	finalArr = (char **)calloc(rowCount, sizeof(char *));
	for (int j = 0; j < rowCount; j++)
			finalArr[j] = (char *) calloc(PAYLOAD_SIZE, sizeof(char));


	populateFinalArray(finalArr,rowCount, str);

	printf("\n****PRINTING FILAL DATA*******\n");

	for(int i = 0; i<rowCount;i++){
		// printf("$$$$$$\n i = %d \n%s\n$$$$$$$\n",i,finalArr[i]);
	}


	return 0;	
}

int ceil(double input){
	int toDiff = (int)input;
	double diff = input - (double)toDiff;
	if(diff==0){
		return (int)input;
	}else{
		return (int)(input+1);
	}
}


void populateFinalArray(char **finalArr,int rowCount,char *data){
	for(int i=0;i<rowCount;i++){
		for(int j = 0;j<PAYLOAD_SIZE;j++){
			finalArr[i][j]=data[i+j];
		}
	}
}


void getFileContent(char *str){
	FILE *fp = fopen("read.txt","r");
	int i = 0;
	char ch;

	do{
		ch = fgetc(fp);
		str[i] = ch;
        i++;
	}while (ch != EOF);

   return;
}

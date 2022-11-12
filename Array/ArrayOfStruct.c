//A c program to illustrate the array of structures

#include<stdio.h>
#include<string.h>

struct student{
	int id;
	char name[30];
	float percentage;
};

int main(){
	int i;
	struct student record[2];

	record[0].id = 1;
	strcpy(record[0].name, "Ram");
	record[0].percentage = 90;

	record[1].id = 2;
	strcpy(record[1].name, "Hari");
	record[1].percentage = 84.2;

	record[2].id = 3;
	strcpy(record[2].name, "Nagesh");
	record[2].percentage = 100;

	for(i = 0; i<3; i++){
		printf("Student of id %d details are:\n", record[i].id);
		printf("%s\n%f\n", record[i].name, record[i].percentage);
	}
}
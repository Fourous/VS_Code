#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
void showmovie(Item item);
char *get_str(char *st, int n) {
	char *ret_val;
	char *find;
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n');
		if (find)
			*find = '\n';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
int main(void) {
	List movie;
	Item temp;
	InitializeList(&movie);
	if (ListIsFull(&movie)) {
		fprintf(stderr,"No memory avoilable!Bye!\n");
		exit(1);
	}
	//获取用户数据并存储
	puts("Enter fisrt movie title:	");
	while (get_str(temp.title,TSIZE)!=NULL&&temp.title[0]!='\0')
	{
		puts("enter your rating <0-10>:		");
		scanf_s("%d",&temp.rating);
		while (getchar() != '\n')
			continue;
		if (AddItem(temp,&movie)==false) {
			fprintf(stderr,"Problem allocating memory!");
			break;
		}
		if (ListIsFull(&movie)) {
			puts("the list now is full!");
			break;
		}
		puts("next movie (empty enter is stop:)");
	}
	if (ListIsEmpty(&movie)) {
		puts("NO Data!");
	}
	else Traverse(&movie, showmovie);
	printf("you enter %d movies",&ListItemCount);
	EmptyTheList(&movie);
	printf("Bye!\n");
	return 0;

}

void showmovie(Item item) {
	printf("movie %s rating: %d \n",item.title,item.rating);
}


#include "List.h"
#include <stdlib.h>
#include <stdio.h>

list BuildList(){ //create new list
	list lst= (list)malloc(sizeof(item));
	lst->next = NULL;
	return lst;
};

int InsertItem(list ls, position pos, type_item it, int i, int j){ //func to create new item
	position newitem = (position)malloc(sizeof(item));
	if (!newitem){
		puts("Error by create new item!!");
		system("Pause");
		exit(1);
	}
	newitem->data = it;
	newitem->i = i;
	newitem->j = j;
	newitem->next = pos->next;
	pos->next = newitem;
	return 1;
};

type_item RetriveItem(list ls, position pos){ 
	return pos->data;
};

int DeleteItem(list ls, position pos){// delete the lists if created
	position prev = ls;
	while (prev->next != pos) prev = prev->next;
	prev->next = pos->next;
	free(pos);
	return 1;
}

int FreeList(list ls){ // free the lists if created
	position delItem = ls;
	while (delItem != NULL){
		ls = ls->next;
		free(delItem);
		delItem = ls;
	}
	return 1;
}

#ifndef  LIST_H
#define LIST_H

typedef  int type_item;

typedef struct item{
	type_item data; // create struct with the 2 integer places [i][j]
	int i;
	int j;
	struct item *next; // point to the next
}item;

typedef item *list, *position;


//create the needed functions
list BuildList();
int InsertItem(list, position, type_item, int, int);
type_item RetriveItem(list, position);
int DeleteItem(list, position);
int FreeList(list);

#endif
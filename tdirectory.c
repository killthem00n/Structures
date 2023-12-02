#include <stdio.h>
#include <string.h>
#include <stdbool.h>
	
#define MENU_ADD 1
#define MENU_DELETE 2
#define MENU_SEARCH 3
#define MENU_ALL 4
#define MENU_EXIT 5

int main(void){

	struct abonent {							//create a structure		
		char name[10];
		char second_name[10];
		char tel[10];
	};
	
	struct abonent list[100];						//create an array of structures
	int menu;
	int i = 0;
	
	while (true){
		printf("\n1) Add abonent\n2) Delete abonent\n3) Search abonent\n4) Output all\n5) Exit\nSelect option: ");
		scanf("%d", &menu);
	
		switch(menu){
		case MENU_ADD:									
			int add_position;
			
			printf("\nPosition: ");
			scanf("%d", &add_position);
	
			if (add_position < 100){
				printf("\nName: ");
				scanf("%s", list[add_position].name);
				printf("Surname: ");
				scanf("%s", list[add_position].second_name);
				printf("Number: ");
				scanf("%s", list[add_position].tel);
			}
			else{
				printf("Error: outside the directory\n");
			}
			break;
		case MENU_DELETE:									
			int delete_position;
			
			printf("\nPosition: ");
			scanf("%d", &delete_position);
		
			memset(list[delete_position].name, 0, 10);
			memset(list[delete_position].second_name, 0, 10);
			memset(list[delete_position].tel, 0, 10);						
			break;
		case MENU_SEARCH:									
			char name[10];
			
			printf("Enter name: ");
			scanf("%s", name);
			while (i < 100){
				if (strcmp(name, list[i].name) == 0){
					printf("\n%d) Name: %s\nSurname: %s\nNumber: %s\n", i, list[i].name, list[i].second_name, list[i].tel);
					i++;
				}
				else{
					i++;
				}
			}
			i = 0;
			break;
		case MENU_ALL:									
			while (i < 100){
				printf("\n%d) Name: %s\nSurname: %s\nNumber: %s\n", i, list[i].name, list[i].second_name, list[i].tel);
				i++;
			}
			i = 0;
			break;
		case MENU_EXIT:									
			return 0;
		}
	}
}

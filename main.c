#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct MemoryAddress
{
    int location;

} MemoryAddress;


void read(int virtual_addr);
void write(int virtual_address, int num);
void showmain(int ppn);
void showdisk(int dpn);
void showptable();

typedef struct PageEntry
{
    int valid;
    int dirty;
    int page_num;

} PageEntry;

int main() {

    MemoryAddress main_memory[16];
    MemoryAddress virtual_memory[32];
    PageEntry virtual_page_table[8];
    char input[200];
    char command[100];
    int first_arg;
    int second_arg;

    //Initializing main memory
    int i = 0;

    for(i = 0; i < 16; i ++)
    {
        main_memory[i].location = -1;
    }

    //Initializing virtual memory
    int j = 0;

    for (j = 0; j < 32; j++)
    {
        virtual_memory[j].location = -1;
    }

    //Initializing page table
    int k = 0;

    for(k = 0; k < 8; k++)
    {
        virtual_page_table[k].valid = 0;
        virtual_page_table[k].dirty = 0;
        virtual_page_table[k].page_num = k;
    }

    while(1)
    {
        printf("> ");
        fgets(input, 200, stdin);

        sscanf(input, "%s%d%d", command, &first_arg, &second_arg);


        if(strcmp(command, "read") == 0)
        {
            if(virtual_memory[first_arg].location == -1)
            {
                printf("A Page Fault Has Occurred\n-1\n");
            }

            else
            {
                printf("%d\n", virtual_memory[first_arg].location);
            }
        }

        else if(strcmp(command, "write") == 0)
        {
            virtual_memory[first_arg].location = second_arg;
            int virtual_page_number = first_arg/4;
            int main_page_number = first_arg >> 1;

            //Check page table
            if (virtual_page_table[virtual_page_number].valid == 0)
            {
                virtual_page_table[virtual_page_number].valid = 1;
                virtual_page_table[virtual_page_number].dirty = 1;
                virtual_page_table[virtual_page_number].page_num = main_page_number;
            }

            printf("%d\n", virtual_page_number);
        }

        else if(strcmp(command, "showmain") == 0)
        {
            int i;
            switch(first_arg)
            {
                int i;
                case 0:
                    for(i = 0; i < 4; i++)
                    {
                        printf("%d:%d\n", i, main_memory[i].location);
                    }
            }
        }

        if(strcmp(command, "showdisk") == 0)
        {
        }

        if(strcmp(command, "showptable") == 0)
        {
            int i = 0;

            for(i = 0; i < 8; i++)
            {
                printf("%d:%d:%d:%d\n", i, virtual_page_table[i].valid, \
                virtual_page_table[i].dirty, virtual_page_table[i].page_num);
            }
        }

        else if(strcmp(command, "quit") == 0)
        {
            break;
        }

    }

    return 0;
}

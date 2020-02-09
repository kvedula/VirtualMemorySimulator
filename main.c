#include <stdio.h>
#include <string.h>


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
    MemoryAddress virtual_memory [32];
    PageEntry virtual_page_table[8];
    char input[200];
    char command[100];
    char first_arg[100];
    char second_arg[100];

    //Initializing main memory
    int i = 0;

    for(i = 0; i < 16; i ++)
    {
        main_memory->location = -1;
    }

    //Initializing virtual memory
    int j = 0;

    for (j = 0; j < 32; j++)
    {
        virtual_memory->location = -1;
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

        sscanf(input, "%s%s%s", command, first_arg, second_arg);


        if(strcmp(command, "read") == 0)
        {

        }

        else if(strcmp(command, "write") == 0)
        {
        }

        else if(strcmp(command, "showmain") == 0)
        {
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

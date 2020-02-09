#include <stdio.h>
#include <string.h>


typedef struct MemoryAddress
{
    int location;

} MemoryAddress;


void read(int virtual_addr):
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


    //Initializing page table
    int j = 0;

    for(j = 0; j < 8; j++)
    {
        virtual_page_table[j].valid = 0;
        virtual_page_table[j].dirty = 0;
        virtual_page_table[j].page_num = j;
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
        }

        else if(strcmp(command, "quit") == 0)
        {
            break;
        }

    }

    return 0;
}

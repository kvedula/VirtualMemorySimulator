#include <stdio.h>


typedef struct MemoryAddress
{
    int location;

} MemoryAddress;


typedef struct Page
{
    MemoryAddress memory_address[4];

} Page;


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

    Page main_memory[4];
    Page virtual_memory [8];
    PageEntry virtual_page_table[8];

    int j = 0;

    for(j = 0; j < 8; j++)
    {
        virtual_page_table[j].valid = 0;
        virtual_page_table[j].dirty = 0;
        virtual_page_table[j].page_num = j;
    }
//
//    while(1)
//    {
        printf("> ");

//    }

    return 0;
}

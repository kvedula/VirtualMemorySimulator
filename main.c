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

int main()
{
    MemoryAddress main_memory[16];
    MemoryAddress virtual_memory[32];
    PageEntry virtual_page_table[8];
    char input[200];
    char command[100];
    int first_arg;
    int second_arg;
    int available_pages[8];

    int i;
    for(i = 0; i < 8; i++)
    {
        available_pages[i] = 0;
    }

    //Initializing main memory
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
            int offset = first_arg % 4;

            //Check page table
            if(virtual_page_table[virtual_page_number].valid == 0)
            {
                //Find first available page
                int i;
                int first_avail_page = 0;

                for(i = 0; i < 8; i++)
                {
                    if(available_pages[i] == 0)
                    {
                        first_avail_page = i;
                        available_pages[i] = 1;
                        break;
                    }
                }

                virtual_page_table[virtual_page_number].valid = 1;
                virtual_page_table[virtual_page_number].dirty = 1;
                virtual_page_table[virtual_page_number].page_num = first_avail_page;

                main_memory[first_avail_page + offset].location = second_arg;
            }

            else if(virtual_page_table[virtual_page_number].valid == 1)
            {
                
            }
        }

        else if(strcmp(command, "showmain") == 0)
        {
            int i;

            switch(first_arg)
            {
                // 0-3
                case 0:
                    for(i = 0; i < 4; i++)
                    {
                        printf("%d:%d\n", i, main_memory[i].location);
                    }
                    break;


                    // 4-7
                case 1:
                    for(i = 0; i < 4; i++)
                    {
                        printf("%d:%d\n", i + 4, main_memory[i + 4].location);
                    }
                    break;


                    // 8-11
                case 2:
                    for(i = 0; i < 4; i++)
                    {
                        printf("%d:%d\n", i + 8, main_memory[i + 8].location);
                    }
                    break;

                    // 12-15
                case 3:
                    for(i = 0; i < 4; i++)
                    {
                        printf("%d:%d\n", i + 12, main_memory[i + 12].location);
                        break;
                    }
                // 16-19
                case 4:
                    for(i = 0; i < 4; i++)
                    {
                        printf("%d:%d\n", i + 16, main_memory[i + 16].location);
                    }
                    break;


                    // 20-23
                case 5:
                    for(i = 0; i < 4; i++)
                    {
                        printf("%d:%d\n", i + 20, main_memory[i + 20].location);
                    }
                    break;


                    // 24-27
                case 6:
                    for(i = 0; i < 4; i++)
                    {
                        printf("%d:%d\n", i + 24, main_memory[i + 24].location);
                    }
                    break;


                    //28-31
                case 7:
                    for(i = 0; i < 4; i++)
                    {
                        printf("%d:%d\n", i + 28, main_memory[i + 28].location);
                    }
                    break;
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

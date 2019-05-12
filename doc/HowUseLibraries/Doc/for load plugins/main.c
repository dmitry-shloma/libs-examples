/*  main.c
 *
 *  Exercise_1-10
 *
 *  Copyright (c) 2015 by Dmitry Shloma
 *  All Rights Reserved.
 *
 *  Revision: 0.1
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#ifdef __linux__
#   include <stdbool.h>
#endif

#include "helper.h"

#define ESCAPE 27
#define TASK_COUNT 6

void menu();

//typedef void (*MENU)();
//MENU tasks[] = {task_1, task_2, task_3, task_4, task_5, task_6};

bool flist()
{

//    DIR *dir = opendir(".");
//    if (!dir) {
//        perror("diropen");
//        return false;
//    };

//    struct dirent *entry;
//    struct stat s;
//    while ((entry = readdir(dir)) != NULL) {
//        if (stat(entry->d_name, &s) != 0) {
//            if ((s.st_mode & S_IFMT) == S_IFREG)
//                printf("%s - %d\n", entry->d_name, entry->d_type);
//        }
//    }
//    closedir(dir);
    return true;
}

void menu()
{
    clearScreen();
    printf("Exercise 1-1 includes %d tasks:\n", TASK_COUNT);
    for (int i = 1; i <= TASK_COUNT; i++) {
        printf("  [%d] Task %d\n", i, i);
    }
    printf("Enter task's ID or press Esc to exit: ");

    int c = 0;
    scanf("%d", &c);
    if (c < 1 && c > TASK_COUNT) {
        printf("Task not found, please enter the number of tasks again \n");
    }
    clearScreen();
    printf("Task %d:\n\n", c);
//    (*tasks[c - 1])();
}

int main(void)
{
    flist();

    menu();

    systemPause();
    return EXIT_SUCCESS;
}

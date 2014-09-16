/**************************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  Fengkaikai                                                           */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/16                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Fengkaikai, 2014/09/16
 *
 */

#include <stdio.h>
#include <stdlib.h>

int Help();

#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10

/* data struct  */
typedef struct DataNode
{
    struct DataNode* next;
    char*   cmd;
    char*   desc;
    int     (*handler)();
} tDataNode;

/* menu program */
static tDataNode head[] = 
{
    {&head[1], "help", "this is help cmd!", Help},
    {NULL, "version", "menu program v1.0", NULL}
};

main()
{
   /* cmd line begins */
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a cmd number > ");
        scanf("%s", cmd);
        tDataNode *p = head;
        while(p != NULL)
        {
            if(!strcmp(p->cmd, cmd))
            {
                printf("%s - %s\n",p->cmd, p->desc);
                if(p->handler != NULL)
                {
                    p->handler();
                }
                break;
            }
            p = p->next;
        }
        if( p == NULL)
        {
            printf("This is a wrong cmd!\n ");
        }
    }
}
/* operations */
int Help()
{
    printf("Menu List:\n");
    tDataNode * pNode = head;
    while(pNode != NULL)
    {
        printf("%s - %s\n", pNode->cmd, pNode->desc);
        pNode = pNode->next;
    }
        return 0;
}

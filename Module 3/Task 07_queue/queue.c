#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "queuepriv.h"

Queue *Queue_init(void)
{
    Queue *p_queue = malloc(sizeof(struct queue));

    p_queue->first = NULL;
    p_queue->last = NULL;

    return p_queue;
}

int Queue_enqueue(Queue *q, const char *id, const char *name)
{
    if (strlen(id) > 6)
    {
        return 0;
    }
    printf("new structure \n");

    struct student *s;
    s = malloc(sizeof(char) * strlen(name) + 1);
    printf("Address structure %d\n", s);
    if (!s)
    {
        return 0;
    }

    s->name = name;
    strncpy(s->id, id, 6);
    s->id[6] = '\0';

    if (q->first == NULL)
    {
        q->first = s;
    }
    else
    {
        q->last->next = s;
    }
    q->last = s;
    return 1;
}

int Queue_dequeue(Queue *q)
{
    if (q->first)
    {
        if (q->first != q->last)
        {
            struct student* temp_first= q->first;
            q->first = q->first->next;
            free(temp_first);
            return 1;
        }
        else
        {
            free(q->first);
            q->first = NULL;
            q->last = NULL;
            return 1;
        }
    }
    else
        return 0;
}


int Queue_drop(Queue *q, const char *id)
{
    struct student *curr_student = q->first;
    struct student *prev_student;
    while (curr_student)
    {
        if (!strcmp(curr_student->id, id))
        {
            if (curr_student == q->first)
            {
                Queue_dequeue(q);
            }
            else if (curr_student == q->last)
            {
                q->last = prev_student;
                prev_student->next = NULL;
                free(curr_student);
                return 1;
            }
            else
            {
                prev_student->next = curr_student->next;
                free(curr_student);
                return 1;
            }
        }
        prev_student = curr_student;
        curr_student = curr_student->next;
    }
    return 0;
}

char *Queue_firstName(Queue *q) {
    if ( q->first)
        return q->first->name;
    else
        return NULL;
}


void Queue_delete(Queue * q) {
    if (q) {
        while (Queue_dequeue(q));
        free(q);
    }
}
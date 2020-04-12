#include <stdio.h>
#include <string.h>
#include "oodi.h"

int init_record(struct oodi * or, const char *p_student, const char *p_course,
                unsigned char p_grade, struct date p_compdate)
{

    if (strlen(p_student) > 6)
    {
        return 0;
    };

    strncpy(or->student, p_student, 6);
    or->student[6] = '\0';

    or->course = malloc(sizeof(char) * (strlen(p_course) + 1));
    if (! or->course)
        return 0;

    strncpy(or->course, p_course, strlen(p_course) + 1);
    or->grade = p_grade;
    or->compdate = p_compdate;

    return 1;
}

struct oodi *add_record(struct oodi *array, unsigned int size,
                        struct oodi newrec)
{
    struct oodi *new_arr = realloc(array, (size + 1) * sizeof(struct oodi));
    if (!new_arr)
    {
        return NULL;
    }
    // *(new_arr + size) = newrec;
    init_record(new_arr + size, newrec.student,
                newrec.course, newrec.grade, newrec.compdate);
    return new_arr;
}

int change_grade(struct oodi *array, unsigned int size, const char *p_student,
        const char *p_course, unsigned char newgrade, struct date newdate){
            for(unsigned int i=0; i < size; i++){
                if(!strcmp((array+i)->student, p_student) && 
                !strcmp((array+i)->course, p_course)){
                    array[i].grade = newgrade;
                    array[i].compdate = newdate;
                    return 1;
                }
            }
            return 0;
        }

int delete_array(struct oodi *array, unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        free(array[i].course);
    }

    free(array);
    return 1;
}

void print_array(struct oodi *array, unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        printf("student: %s\n", array[i].student);
        printf("course: %s\n", array[i].course);
        printf("grade: %hhu\n", array[i].grade);
    }
}

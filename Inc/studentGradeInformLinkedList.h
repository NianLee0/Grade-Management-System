//
// Created by NianLee on 2023/5/17.
//

#ifndef GRADE_MANAGEMENT_SYSTEM_STUDENTGRADEINFORMLINKEDLIST_H
#define GRADE_MANAGEMENT_SYSTEM_STUDENTGRADEINFORMLINKEDLIST_H

#include "main.h"

void showStudentGradeInform(informLinkedList* head);

void inputStudentGradeGrade(informLinkedList* courseName, char* token[], short mode);

informLinkedList* inputStudentGradeInform(char* token[], short mode);

informLinkedList* inputStudentGradeStudentName(informLinkedList* name, char* token[], short mode);

informLinkedList* inputStudentGradeCourseName(informLinkedList* number, char* token[], short mode);

#endif //GRADE_MANAGEMENT_SYSTEM_STUDENTGRADEINFORMLINKEDLIST_H

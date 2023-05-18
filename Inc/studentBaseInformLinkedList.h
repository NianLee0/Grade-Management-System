//
// Created by NianLee on 2023/5/3.
//

#ifndef  GRADE_MANAGEMENT_SYSTEM_STUDENTBASEINFORMLINKEDLIST_H
#define  GRADE_MANAGEMENT_SYSTEM_STUDENTBASEINFORMLINKEDLIST_H

#include "main.h"

void showStudentInform(informLinkedList* head);

void inputStudentNumber(informLinkedList* head, char* token[], short mode);

informLinkedList* inputStudentAge(informLinkedList* name, char* token[], short mode);

informLinkedList* inputStudentSex(informLinkedList* age, char* token[], short mode);

informLinkedList* inputStudentName(informLinkedList* head, char* token[], short mode);

informLinkedList* inputStudentBaseInform(char* token[], short mode);

#endif //STUDENTINFORMLINKEDLIST_H

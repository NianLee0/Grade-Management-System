//
// Created by NianLee on 2023/5/16.
//

#ifndef GRADE_MANAGEMENT_SYSTEM_COURSEBASEINFORMLINKEDLIST_H
#define GRADE_MANAGEMENT_SYSTEM_COURSEBASEINFORMLINKEDLIST_H

#include "main.h"

void showCourseInform(informLinkedList* head);

void inputCourseCredit(informLinkedList* name, char* token[], short mode);

informLinkedList* inputCourseBaseInform(char* token[], short mode);

informLinkedList* inputCourseName(informLinkedList* studentName, char* token[], short mode);

informLinkedList* inputCourseNumber(informLinkedList* head, char* token[], short mode);

#endif //GRADE_MANAGEMENT_SYSTEM_COURSEBASEINFORMLINKEDLIST_H

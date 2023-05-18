//
// Created by NianLee on 2023/5/14.
//

#ifndef GRADE_MANAGEMENT_SYSTEM_ADDSTUDENTBASEINFORM_H
#define GRADE_MANAGEMENT_SYSTEM_ADDSTUDENTBASEINFORM_H

#include "main.h"
#include "studentBaseInformLinkedList.h"

informLinkedList* addStudentBaseInform(void);

void addStudentBaseInformFromFile(char* token[]);

void addStudentBaseInformIntoStructure(struct informLinkedList* head);

void addStudentBaseInformToFile(void);

#endif //GRADE_MANAGEMENT_SYSTEM_ADDSTUDENTBASEINFORM_H

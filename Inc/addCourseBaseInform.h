//
// Created by NianLee on 2023/5/16.
//

#ifndef GRADE_MANAGEMENT_SYSTEM_ADDCOURSEBASEINFORM_H
#define GRADE_MANAGEMENT_SYSTEM_ADDCOURSEBASEINFORM_H

#include "main.h"
#include "courseBaseInformLinkedList.h"

informLinkedList* addCourseBaseInform(void);

void addCourseBaseInformFromFile(char* token[]);

void addCourseBaseInformIntoStructure(struct informLinkedList* head);

void addCourseBaseInformToFile(void);

#endif //GRADE_MANAGEMENT_SYSTEM_ADDCOURSEBASEINFORM_H

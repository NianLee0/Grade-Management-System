//
// Created by NianLee on 2023/5/17.
//

#ifndef GRADE_MANAGEMENT_SYSTEM_ADDSTUDENTGRADEINFORM_H
#define GRADE_MANAGEMENT_SYSTEM_ADDSTUDENTGRADEINFORM_H

#include "main.h"
#include "studentGradeInformLinkedList.h"
#include "GPA.h"

informLinkedList* addStudentGradeInform(void);

informLinkedList* checkStudentName(informLinkedList* head);

informLinkedList* checkCourseName(informLinkedList* head);

informLinkedList* checkGrade(informLinkedList* head);

void checkDuplicateData(informLinkedList* head);

void addStudentGradeInformFromFile(char* token[]);

void addStudentGradeInformIntoStructure(struct informLinkedList* head);

void addStudentGradeInformToFile(void);

#endif //GRADE_MANAGEMENT_SYSTEM_ADDSTUDENTGRADEINFORM_H

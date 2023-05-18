//
// Created by NianLee on 2023/5/3.
//

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>

typedef struct informLinkedList
{
	char data[100];
	struct informLinkedList* next;
} informLinkedList;

typedef struct studentBaseInform
{
	char name[20];
	char sex[10];
	char age[10];
	char number[10];
} studentBaseInform;

typedef struct courseBaseInform
{
	char number[10];
	char name[50];
	char credit[10];
} courseBaseInform;

typedef struct studentGradeInform
{
	char studentName[20];
	char courseName[50];
	char grade[10];
	float GPA;
} studentGradeInform;

extern studentBaseInform studentBaseInformation[100];
extern courseBaseInform courseBaseInformation[100];
extern studentGradeInform studentGradeInformation[100];

extern int studentNum;
extern int courseNum;
extern int studentGradeNum;

extern char studentBaseInformFilePath[100];
extern char courseBaseInformFilePath[100];
extern char studentGradeInformFilePath[100];

#endif //MAIN_H

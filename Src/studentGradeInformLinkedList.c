//
// Created by NianLee on 2023/5/17.
//

#include "../Inc/studentGradeInformLinkedList.h"

studentGradeInform studentGradeInformation[100];
int studentGradeNum;

/************************************************
 * @Function: inputStudentGradeInform
 * @Description: 将课程基本信息连接成链表
 * @Input: token[]:文件中截取的数据块
 *         mode:模式,0为从键盘输入,1为从文件中读取
 * @Return: head:链表头
 * @Others: None
 * @Author: NianLee
 ************************************************/
informLinkedList* inputStudentGradeInform(char* token[], short mode)
{
	informLinkedList* head;
	informLinkedList* studentName;
	informLinkedList* courseName;
	informLinkedList* temp = (informLinkedList*)malloc(sizeof(informLinkedList));
	temp->data[0] = '\0';
	temp->next = NULL;
	head = temp;
	studentName = inputStudentGradeStudentName(temp, token, mode);
	courseName = inputStudentGradeCourseName(studentName, token, mode);
	inputStudentGradeGrade(courseName, token, mode);
	return head;
}

/************************************************
 * @Function: inputStudentGradeStudentName
 * @Description: 将学生姓名信息添加到链表中
 * @Input: head:链表头
 *         token[]:文件中截取的数据块
 *         mode:模式,0为从键盘输入,1为从文件中读取
 * @Return: name:指向学生姓名的节点
 * @Others: None
 * @Author: NianLee
 ************************************************/
informLinkedList* inputStudentGradeStudentName(informLinkedList* head, char* token[], short mode)
{
	informLinkedList* studentName = (informLinkedList*)malloc(sizeof(informLinkedList));
	if (mode == 1)
		strcpy(studentName->data, token[0]);
	else
	{
		printf("请输入学生姓名: ");
		scanf("%s", studentName->data);
	}
	studentName->next = NULL;
	head->next = studentName;
	return studentName;
}

/************************************************
 * @Function: inputStudentGradeCourseName
 * @Description: 将课程课名信息添加到链表中
 * @Input: studentName:指向学生姓名的节点
 *         token[]:文件中截取的数据块
 *         mode:模式,0为从键盘输入,1为从文件中读取
 * @Return: courseName:指向课名的节点
 * @Others: None
 * @Author: NianLee
 ************************************************/
informLinkedList* inputStudentGradeCourseName(informLinkedList* studentName, char* token[], short mode)
{
	informLinkedList* courseName = (informLinkedList*)malloc(sizeof(informLinkedList));
	if (mode == 1)
		strcpy(courseName->data, token[1]);
	else
	{
		printf("请输入课名: ");
		scanf("%s", courseName->data);
	}
	studentName->next = courseName;
	courseName->next = NULL;
	return courseName;
}

/************************************************
 * @Function: inputStudentGradeGrade
 * @Description: 将课程学分信息添加到链表中
 * @Input: courseName:指向课名的节点
 *         token[]:文件中截取的数据块
 *         mode:模式,0为从键盘输入,1为从文件中读取
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void inputStudentGradeGrade(informLinkedList* courseName, char* token[], short mode)
{
	informLinkedList* grade = (informLinkedList*)malloc(sizeof(informLinkedList));
	if (mode == 1)
		strcpy(grade->data, token[2]);
	else
	{
		printf("请输入成绩: ");
		scanf("%s", grade->data);
	}
	courseName->next = grade;
	grade->next = NULL;
}

/************************************************
 * @Function: showStudentGradeInform
 * @Description: 显示学生成绩信息
 * @Input: head:链表头
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void showStudentGradeInform(informLinkedList* head)
{
	informLinkedList* temp = head;
	informLinkedList* number;
	informLinkedList* name;
	printf("姓名: %s\n", temp->next->data);
	number = temp->next;
	printf("课名: %s\n", number->next->data);
	name = number->next;
	printf("成绩: %s\n", name->next->data);
}
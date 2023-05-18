//
// Created by NianLee on 2023/5/16.
//

#include "../Inc/courseBaseInformLinkedList.h"

courseBaseInform courseBaseInformation[100];
int courseNum;

/************************************************
 * @Function: inputCourseBaseInform
 * @Description: 将课程基本信息连接成链表
 * @Input: token[]:文件中截取的数据块
 *         mode:模式,0为从键盘输入,1为从文件中读取
 * @Return: head:链表头
 * @Others: None
 * @Author: NianLee
 ************************************************/
informLinkedList* inputCourseBaseInform(char* token[], short mode)
{
	informLinkedList* head;
	informLinkedList* number;
	informLinkedList* name;
	informLinkedList* temp = (informLinkedList*)malloc(sizeof(informLinkedList));
	temp->data[0] = '\0';
	temp->next = NULL;
	head = temp;
	number = inputCourseNumber(temp, token, mode);
	name = inputCourseName(number, token, mode);
	inputCourseCredit(name, token, mode);
	return head;
}

/************************************************
 * @Function: inputCourseNumber
 * @Description: 将课号信息添加到链表中
 * @Input: head:链表头
 *         token[]:文件中截取的数据块
 *         mode:模式,0为从键盘输入,1为从文件中读取
 * @Return: number:指向课号的节点
 * @Others: None
 * @Author: NianLee
 ************************************************/
informLinkedList* inputCourseNumber(informLinkedList* head, char* token[], short mode)
{
	informLinkedList* number = (informLinkedList*)malloc(sizeof(informLinkedList));
	if (mode == 1)
		strcpy(number->data, token[0]);
	else
	{
		printf("请输入课号: ");
		scanf("%s", number->data);
	}
	number->next = NULL;
	head->next = number;
	return number;
}

/************************************************
 * @Function: inputCourseName
 * @Description: 将课名信息添加到链表中
 * @Input: number:指向课号的节点
 *         token[]:文件中截取的数据块
 *         mode:模式,0为从键盘输入,1为从文件中读取
 * @Return: name:指向课名的节点
 * @Others: None
 * @Author: NianLee
 ************************************************/
informLinkedList* inputCourseName(informLinkedList* number, char* token[], short mode)
{
	informLinkedList* name = (informLinkedList*)malloc(sizeof(informLinkedList));
	if (mode == 1)
		strcpy(name->data, token[1]);
	else
	{
		printf("请输入课名: ");
		scanf("%s", name->data);
	}
	number->next = name;
	name->next = NULL;
	return name;
}

/************************************************
 * @Function: inputCourseCredit
 * @Description: 将课程学分信息添加到链表中
 * @Input: name:指向课名的节点
 *         token[]:文件中截取的数据块
 *         mode:模式,0为从键盘输入,1为从文件中读取
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void inputCourseCredit(informLinkedList* name, char* token[], short mode)
{
	informLinkedList* credit = (informLinkedList*)malloc(sizeof(informLinkedList));
	if (mode == 1)
		strcpy(credit->data, token[2]);
	else
	{
		printf("请输入学分: ");
		scanf("%s", credit->data);
	}
	name->next = credit;
	credit->next = NULL;
}

/************************************************
 * @Function: showCourseInform
 * @Description: 显示课程信息
 * @Input: head:链表头
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void showCourseInform(informLinkedList* head)
{
	informLinkedList* temp = head;
	informLinkedList* number;
	informLinkedList* name;
	printf("课号: %s\n", temp->next->data);
	number = temp->next;
	printf("课名: %s\n", number->next->data);
	name = number->next;
	printf("学分: %s\n", name->next->data);
}
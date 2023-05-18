//
// Created by NianLee on 2023/5/3.
//

#include "../Inc/studentBaseInformLinkedList.h"

studentBaseInform studentBaseInformation[100];
int studentNum;

/************************************************
 * @Function: inputStudentBaseInform
 * @Description: 将学生基本信息连接成链表
 * @Input: token[]:文件中截取的数据块
 *         mode:模式,0为从键盘输入,1为从文件中读取
 * @Return: head:链表头
 * @Others: None
 * @Author: NianLee
 ************************************************/
informLinkedList* inputStudentBaseInform(char* token[], short mode)
{
	informLinkedList* head;
	informLinkedList* name;
	informLinkedList* sex;
	informLinkedList* age;
	informLinkedList* temp = (informLinkedList*)malloc(sizeof(informLinkedList));
	temp->data[0] = '\0';
	temp->next = NULL;
	head = temp;
	name = inputStudentName(temp, token, mode);
	sex = inputStudentSex(name, token, mode);
	age = inputStudentAge(sex, token, mode);
	inputStudentNumber(age, token, mode);
	return head;
}

/************************************************
 * @Function: inputStudentName
 * @Description: 将学生姓名信息添加到链表中
 * @Input: head:链表头
 *         token[]:文件中截取的数据块
 *         mode:模式,0为从键盘输入,1为从文件中读取
 * @Return: name:指向学生姓名的节点
 * @Others: None
 * @Author: NianLee
 ************************************************/
informLinkedList* inputStudentName(informLinkedList* head, char* token[], short mode)
{
	informLinkedList* name = (informLinkedList*)malloc(sizeof(informLinkedList));
	if (mode == 1)
		strcpy(name->data, token[0]);
	else
	{
		printf("请输入姓名: ");
		scanf("%s", name->data);
	}
	name->next = NULL;
	head->next = name;
	return name;
}

/************************************************
 * @Function: inputStudentSex
 * @Description: 将学生性别信息添加到链表中
 * @Input: name:指向学生姓名信息的节点
 * 		   token[]:文件中截取的数据块
 *         mode:模式,0为从键盘输入,1为从文件中读取
 * @Return: sex:指向学生年龄性别的节点
 * @Others: None
 * @Author: NianLee
 ************************************************/
informLinkedList* inputStudentSex(informLinkedList* name, char* token[], short mode)
{
	informLinkedList* sex = (informLinkedList*)malloc(sizeof(informLinkedList));
	if (mode == 1)
		strcpy(sex->data, token[1]);
	else
	{
		printf("请输入性别: ");
		scanf("%s", sex->data);
	}
	name->next = sex;
	sex->next = NULL;
	return sex;
}

/************************************************
 * @Function: inputStudentAge
 * @Description: 将学生年龄信息添加到链表中
 * @Input: sex:指向学生性别信息的节点
 *         token[]:文件中截取的数据块
 *         mode:模式,0为从键盘输入,1为从文件中读取
 * @Return: age:指向学生年龄信息的节点
 * @Others: None
 * @Author: NianLee
 ************************************************/
informLinkedList* inputStudentAge(informLinkedList* sex, char* token[], short mode)
{
	informLinkedList* age = (informLinkedList*)malloc(sizeof(informLinkedList));
	if (mode == 1)
		strcpy(age->data, token[2]);
	else
	{
		printf("请输入年龄: ");
		scanf("%s", age->data);
	}
	sex->next = age;
	age->next = NULL;
	return age;
}

/************************************************
 * @Function: inputStudentNumber
 * @Description: 将学生学号信息添加到链表中
 * @Input: age:指向学生年龄信息的节点
 *         token[]:文件中截取的信息块
 *         mode:模式,0为从键盘输入,1为从文件中读取
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void inputStudentNumber(informLinkedList* age, char* token[], short mode)
{
	informLinkedList* number = (informLinkedList*)malloc(sizeof(informLinkedList));
	if (mode == 1)
		strcpy(number->data, token[3]);
	else
	{
		printf("请输入学号: ");
		scanf("%s", number->data);
	}
	age->next = number;
	number->next = NULL;
}

/************************************************
 * @Function: showStudentInform
 * @Description: 打印学生信息
 * @Input: head:链表头
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void showStudentInform(informLinkedList* head)
{
	informLinkedList* temp = head;
	informLinkedList* name;
	informLinkedList* sex;
	informLinkedList* age;
	printf("姓名: %s\n", temp->next->data);
	name = temp->next;
	printf("性别: %s\n", name->next->data);
	sex = name->next;
	printf("年龄: %s\n", sex->next->data);
	age = sex->next;
	printf("学号: %s\n", age->next->data);
}




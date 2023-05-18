//
// Created by NianLee on 2023/5/16.
//

#include "../Inc/courseBaseInformLinkedList.h"

courseBaseInform courseBaseInformation[100];
int courseNum;

/************************************************
 * @Function: inputCourseBaseInform
 * @Description: ���γ̻�����Ϣ���ӳ�����
 * @Input: token[]:�ļ��н�ȡ�����ݿ�
 *         mode:ģʽ,0Ϊ�Ӽ�������,1Ϊ���ļ��ж�ȡ
 * @Return: head:����ͷ
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
 * @Description: ���κ���Ϣ��ӵ�������
 * @Input: head:����ͷ
 *         token[]:�ļ��н�ȡ�����ݿ�
 *         mode:ģʽ,0Ϊ�Ӽ�������,1Ϊ���ļ��ж�ȡ
 * @Return: number:ָ��κŵĽڵ�
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
		printf("������κ�: ");
		scanf("%s", number->data);
	}
	number->next = NULL;
	head->next = number;
	return number;
}

/************************************************
 * @Function: inputCourseName
 * @Description: ��������Ϣ��ӵ�������
 * @Input: number:ָ��κŵĽڵ�
 *         token[]:�ļ��н�ȡ�����ݿ�
 *         mode:ģʽ,0Ϊ�Ӽ�������,1Ϊ���ļ��ж�ȡ
 * @Return: name:ָ������Ľڵ�
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
		printf("���������: ");
		scanf("%s", name->data);
	}
	number->next = name;
	name->next = NULL;
	return name;
}

/************************************************
 * @Function: inputCourseCredit
 * @Description: ���γ�ѧ����Ϣ��ӵ�������
 * @Input: name:ָ������Ľڵ�
 *         token[]:�ļ��н�ȡ�����ݿ�
 *         mode:ģʽ,0Ϊ�Ӽ�������,1Ϊ���ļ��ж�ȡ
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
		printf("������ѧ��: ");
		scanf("%s", credit->data);
	}
	name->next = credit;
	credit->next = NULL;
}

/************************************************
 * @Function: showCourseInform
 * @Description: ��ʾ�γ���Ϣ
 * @Input: head:����ͷ
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void showCourseInform(informLinkedList* head)
{
	informLinkedList* temp = head;
	informLinkedList* number;
	informLinkedList* name;
	printf("�κ�: %s\n", temp->next->data);
	number = temp->next;
	printf("����: %s\n", number->next->data);
	name = number->next;
	printf("ѧ��: %s\n", name->next->data);
}
//
// Created by NianLee on 2023/5/3.
//

#include "../Inc/studentBaseInformLinkedList.h"

studentBaseInform studentBaseInformation[100];
int studentNum;

/************************************************
 * @Function: inputStudentBaseInform
 * @Description: ��ѧ��������Ϣ���ӳ�����
 * @Input: token[]:�ļ��н�ȡ�����ݿ�
 *         mode:ģʽ,0Ϊ�Ӽ�������,1Ϊ���ļ��ж�ȡ
 * @Return: head:����ͷ
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
 * @Description: ��ѧ��������Ϣ��ӵ�������
 * @Input: head:����ͷ
 *         token[]:�ļ��н�ȡ�����ݿ�
 *         mode:ģʽ,0Ϊ�Ӽ�������,1Ϊ���ļ��ж�ȡ
 * @Return: name:ָ��ѧ�������Ľڵ�
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
		printf("����������: ");
		scanf("%s", name->data);
	}
	name->next = NULL;
	head->next = name;
	return name;
}

/************************************************
 * @Function: inputStudentSex
 * @Description: ��ѧ���Ա���Ϣ��ӵ�������
 * @Input: name:ָ��ѧ��������Ϣ�Ľڵ�
 * 		   token[]:�ļ��н�ȡ�����ݿ�
 *         mode:ģʽ,0Ϊ�Ӽ�������,1Ϊ���ļ��ж�ȡ
 * @Return: sex:ָ��ѧ�������Ա�Ľڵ�
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
		printf("�������Ա�: ");
		scanf("%s", sex->data);
	}
	name->next = sex;
	sex->next = NULL;
	return sex;
}

/************************************************
 * @Function: inputStudentAge
 * @Description: ��ѧ��������Ϣ��ӵ�������
 * @Input: sex:ָ��ѧ���Ա���Ϣ�Ľڵ�
 *         token[]:�ļ��н�ȡ�����ݿ�
 *         mode:ģʽ,0Ϊ�Ӽ�������,1Ϊ���ļ��ж�ȡ
 * @Return: age:ָ��ѧ��������Ϣ�Ľڵ�
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
		printf("����������: ");
		scanf("%s", age->data);
	}
	sex->next = age;
	age->next = NULL;
	return age;
}

/************************************************
 * @Function: inputStudentNumber
 * @Description: ��ѧ��ѧ����Ϣ��ӵ�������
 * @Input: age:ָ��ѧ��������Ϣ�Ľڵ�
 *         token[]:�ļ��н�ȡ����Ϣ��
 *         mode:ģʽ,0Ϊ�Ӽ�������,1Ϊ���ļ��ж�ȡ
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
		printf("������ѧ��: ");
		scanf("%s", number->data);
	}
	age->next = number;
	number->next = NULL;
}

/************************************************
 * @Function: showStudentInform
 * @Description: ��ӡѧ����Ϣ
 * @Input: head:����ͷ
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
	printf("����: %s\n", temp->next->data);
	name = temp->next;
	printf("�Ա�: %s\n", name->next->data);
	sex = name->next;
	printf("����: %s\n", sex->next->data);
	age = sex->next;
	printf("ѧ��: %s\n", age->next->data);
}




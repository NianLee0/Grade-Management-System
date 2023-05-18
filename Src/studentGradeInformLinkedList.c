//
// Created by NianLee on 2023/5/17.
//

#include "../Inc/studentGradeInformLinkedList.h"

studentGradeInform studentGradeInformation[100];
int studentGradeNum;

/************************************************
 * @Function: inputStudentGradeInform
 * @Description: ���γ̻�����Ϣ���ӳ�����
 * @Input: token[]:�ļ��н�ȡ�����ݿ�
 *         mode:ģʽ,0Ϊ�Ӽ�������,1Ϊ���ļ��ж�ȡ
 * @Return: head:����ͷ
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
 * @Description: ��ѧ��������Ϣ��ӵ�������
 * @Input: head:����ͷ
 *         token[]:�ļ��н�ȡ�����ݿ�
 *         mode:ģʽ,0Ϊ�Ӽ�������,1Ϊ���ļ��ж�ȡ
 * @Return: name:ָ��ѧ�������Ľڵ�
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
		printf("������ѧ������: ");
		scanf("%s", studentName->data);
	}
	studentName->next = NULL;
	head->next = studentName;
	return studentName;
}

/************************************************
 * @Function: inputStudentGradeCourseName
 * @Description: ���γ̿�����Ϣ��ӵ�������
 * @Input: studentName:ָ��ѧ�������Ľڵ�
 *         token[]:�ļ��н�ȡ�����ݿ�
 *         mode:ģʽ,0Ϊ�Ӽ�������,1Ϊ���ļ��ж�ȡ
 * @Return: courseName:ָ������Ľڵ�
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
		printf("���������: ");
		scanf("%s", courseName->data);
	}
	studentName->next = courseName;
	courseName->next = NULL;
	return courseName;
}

/************************************************
 * @Function: inputStudentGradeGrade
 * @Description: ���γ�ѧ����Ϣ��ӵ�������
 * @Input: courseName:ָ������Ľڵ�
 *         token[]:�ļ��н�ȡ�����ݿ�
 *         mode:ģʽ,0Ϊ�Ӽ�������,1Ϊ���ļ��ж�ȡ
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
		printf("������ɼ�: ");
		scanf("%s", grade->data);
	}
	courseName->next = grade;
	grade->next = NULL;
}

/************************************************
 * @Function: showStudentGradeInform
 * @Description: ��ʾѧ���ɼ���Ϣ
 * @Input: head:����ͷ
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void showStudentGradeInform(informLinkedList* head)
{
	informLinkedList* temp = head;
	informLinkedList* number;
	informLinkedList* name;
	printf("����: %s\n", temp->next->data);
	number = temp->next;
	printf("����: %s\n", number->next->data);
	name = number->next;
	printf("�ɼ�: %s\n", name->next->data);
}
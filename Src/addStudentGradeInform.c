//
// Created by NianLee on 2023/5/17.
//

#include "../Inc/addStudentGradeInform.h"

/************************************************
 * @Function: addStudentGradeInform
 * @Description: ����Աͨ���������ѧ���ɼ���Ϣ,�����������������ɼ�
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
informLinkedList* addStudentGradeInform(void)
{
	informLinkedList* head;
	head = inputStudentGradeInform(NULL, 0);
	return head;
}

/************************************************
 * @Function: addStudentGradeInformFromFile
 * @Description: ��ʼ�������д��ļ��ж�ȡѧ���γ���Ϣ,�����������������ɼ�
 * @Input: token[]:�ļ��н�ȡ����Ϣ��
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void addStudentGradeInformFromFile(char* token[])
{
	informLinkedList* head;
	head = inputStudentGradeInform(token, 1);
	addStudentGradeInformIntoStructure(head);
}

/************************************************
 * @Function: addStudentGradeInformIntoStructure
 * @Description: ��������Ϣ����"studentGradeInformation"�ṹ����
 * @Input: head:����ͷ
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void addStudentGradeInformIntoStructure(informLinkedList* head)
{
	strcpy(studentGradeInformation[studentGradeNum].studentName, head->next->data);
	strcpy(studentGradeInformation[studentGradeNum].courseName, head->next->next->data);
	strcpy(studentGradeInformation[studentGradeNum].grade, head->next->next->next->data);
	studentGradeInformation[studentGradeNum].GPA = calculateGPA(studentGradeNum);
	studentGradeNum++;
	free(head->next->next->next);
	free(head->next->next);
	free(head->next);
	free(head);
}

/************************************************
 * @Function: addStudentGradeInformToFile
 * @Description: ��ѧ���ɼ���Ϣ�����ļ���
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void addStudentGradeInformToFile(void)
{
	char inform[100];
	informLinkedList* head;
	head = addStudentGradeInform();
	head = checkStudentName(head);
	head = checkCourseName(head);
	head = checkGrade(head);
	checkDuplicateData(head);
	sprintf(inform, "%s,%s,%s\n",
			head->next->data,
			head->next->next->data,
			head->next->next->next->data);
	addStudentGradeInformIntoStructure(head);
	FILE* fp;
	fp = fopen(studentGradeInformFilePath, "r+");
	fseek(fp, 0, SEEK_END);
	fputs(inform, fp);
	fclose(fp);
	printf("\n��ӳɹ�\n");
}

/************************************************
 * @Function: checkStudentName
 * @Description: ���ѧ�������Ƿ����
 * @Input: head:����ͷ
 * @Return: head:����ͷ
 * @Others: None
 * @Author: NianLee
 ************************************************/
informLinkedList* checkStudentName(informLinkedList* head)
{
	for (int i = 0; i < studentNum; i++)
	{
		if (strcmp(studentBaseInformation[i].name, head->next->data) == 0)
			return head;
	}
	printf("\nѧ������������,����������\n");
	printf("����: ");
	scanf("%s", head->next->data);
	checkStudentName(head);
}

/************************************************
 * @Function: checkCourseName
 * @Description: ���γ����Ƿ����
 * @Input: courseName:�γ���
 * @Return: head:����ͷ
 * @Others: None
 * @Author: NianLee
 ************************************************/
informLinkedList* checkCourseName(informLinkedList* head)
{
	for (int i = 0; i < courseNum; i++)
	{
		if (strcmp(courseBaseInformation[i].name, head->next->next->data) == 0)
			return head;
	}
	printf("\n�γ̲�����,����������\n");
	printf("����: ");
	scanf("%s", head->next->next->data);
	checkCourseName(head);
}

/************************************************
 * @Function: checkGrade
 * @Description: ���ɼ��Ƿ�Ϸ�
 * @Input: head:����ͷ
 * @Return: head:����ͷ
 * @Others: None
 * @Author: NianLee
 ************************************************/
informLinkedList* checkGrade(informLinkedList* head)
{
	strcpy(studentGradeInformation[studentGradeNum].grade,
			head->next->next->next->data);
	if (calculateGPA(studentGradeNum) == -1)
	{
		printf("\n�ɼ����Ϸ�,����������!\n");
		printf("�ɼ�: ");
		scanf("%s", head->next->next->next->data);
		checkGrade(head);
	}
	return head;
}

/************************************************
 * @Function: checkDuplicateData
 * @Description: ����Ƿ����ظ�����
 * @Input: head:����ͷ
 * @Return: head:����ͷ
 * @Others: None
 * @Author: NianLee
 ************************************************/
void checkDuplicateData(informLinkedList* head)
{
	for (int i = 0; i < studentGradeNum; i++)
	{
		if (strcmp(studentGradeInformation[i].studentName, head->next->data) == 0 &&
			strcmp(studentGradeInformation[i].courseName, head->next->next->data) == 0)
		{
			printf("\n���и�ѧ������,�޷����,����������\n");
			printf("����: ");
			scanf("%s", head->next->data);
			checkStudentName(head);
			printf("�γ���: ");
			scanf("%s", head->next->next->data);
			checkCourseName(head);
			printf("�ɼ�: ");
			scanf("%s", head->next->next->next->data);
			checkGrade(head);
			checkDuplicateData(head);
		}
	}
}
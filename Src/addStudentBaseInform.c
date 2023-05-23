//
// Created by NianLee on 2023/5/14.
//

#include "../Inc/addStudentBaseInform.h"

/************************************************
 * @Function: addStudentBaseInform
 * @Description: ����Աͨ���������ѧ����Ϣ,�����������Ա����䡢ѧ��
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
informLinkedList* addStudentBaseInform(void)
{
	informLinkedList* head;
	head = inputStudentBaseInform(NULL, 0);
	return head;
}

/************************************************
 * @Function: addStudentBaseInformFromFile
 * @Description: ��ʼ�������д��ļ��ж�ȡѧ����Ϣ,��������,�Ա�,����,ѧ��
 * @Input: token[]:�ļ��н�ȡ����Ϣ��
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void addStudentBaseInformFromFile(char* token[])
{
	informLinkedList* head;
	head = inputStudentBaseInform(token, 1);
	addStudentBaseInformIntoStructure(head);
}

/************************************************
 * @Function: addStudentBaseInformIntoStructure
 * @Description: ��������Ϣ����"studentBaseInformation"�ṹ����
 * @Input: head:����ͷ
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void addStudentBaseInformIntoStructure(informLinkedList* head)
{
	strcpy(studentBaseInformation[studentNum].name, head->next->data);
	strcpy(studentBaseInformation[studentNum].sex, head->next->next->data);
	strcpy(studentBaseInformation[studentNum].age, head->next->next->next->data);
	strcpy(studentBaseInformation[studentNum].number, head->next->next->next->next->data);
	studentNum++;
	free(head->next->next->next->next);
	free(head->next->next->next);
	free(head->next->next);
	free(head->next);
	free(head);
}

/************************************************
 * @Function: addStudentBaseInformToFile
 * @Description: ��ѧ����Ϣ�����ļ���
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void addStudentBaseInformToFile(void)
{
	char inform[100];
	informLinkedList* head;
	head = addStudentBaseInform();
	for(int i = 0; i < studentNum; i++)
	{
		if(strcmp(studentBaseInformation[i].number,
				head->next->next->next->next->data) == 0)
		{
			printf("ѧ���ظ�,����������\n");
			addStudentBaseInformToFile();
			return;
		}
	}
	sprintf(inform, "%s,%s,%s,%s\n",
			head->next->data,
			head->next->next->data,
			head->next->next->next->data,
			head->next->next->next->next->data);
	addStudentBaseInformIntoStructure(head);
	FILE* fp;
	fp = fopen(studentBaseInformFilePath, "r+");
	fseek(fp, 0, SEEK_END);
	fputs(inform, fp);
	fclose(fp);
}

//
// Created by NianLee on 2023/5/16.
//

#include "../Inc/addCourseBaseInform.h"

/************************************************
 * @Function: addCourseBaseInform
 * @Description: ����Աͨ��������ӿγ���Ϣ,�����κ�,����,ѧ��
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
informLinkedList* addCourseBaseInform(void)
{
	informLinkedList* head;
	head = inputCourseBaseInform(NULL, 0);
	return head;
}

/************************************************
 * @Function: addCourseBaseInformFromFile
 * @Description: ��ʼ�������д��ļ��ж�ȡ�γ���Ϣ,�����κ�,����,ѧ��
 * @Input: token[]:�ļ��н�ȡ����Ϣ��
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void addCourseBaseInformFromFile(char* token[])
{
	informLinkedList* head;
	head = inputCourseBaseInform(token, 1);
	addCourseBaseInformIntoStructure(head);
}

/************************************************
 * @Function: addCourseBaseInformIntoStructure
 * @Description: ��������Ϣ����"courseBaseInformation"�ṹ����
 * @Input: head:����ͷ
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void addCourseBaseInformIntoStructure(struct informLinkedList* head)
{
	strcpy(courseBaseInformation[courseNum].number, head->next->data);
	strcpy(courseBaseInformation[courseNum].name, head->next->next->data);
	strcpy(courseBaseInformation[courseNum].credit, head->next->next->next->data);
	courseNum++;
	free(head->next->next->next);
	free(head->next->next);
	free(head->next);
	free(head);
}

/************************************************
 * @Function: addCourseBaseInformToFile
 * @Description: ���γ���Ϣ�����ļ���
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void addCourseBaseInformToFile(void)
{
	char inform[100];
	informLinkedList* head;
	head = addCourseBaseInform();
	for(int i = 0;i<courseNum;i++)
	{
		if(strcmp(courseBaseInformation[i].number, head->next->data) == 0)
		{
			printf("\n�γ̺��ظ�,����������\n\n");
			addCourseBaseInformToFile();
			return;
		}
		if(strcmp(courseBaseInformation[i].name, head->next->next->data) == 0)
		{
			printf("\n�γ����ظ�,����������\n\n");
			addCourseBaseInformToFile();
			return;
		}
	}
	sprintf(inform, "%s,%s,%s\n",
			head->next->data,
			head->next->next->data,
			head->next->next->next->data);
	addCourseBaseInformIntoStructure(head);
	FILE* fp;
	fp = fopen(courseBaseInformFilePath, "r+");
	fseek(fp, 0, SEEK_END);
	fputs(inform, fp);
	fclose(fp);
}
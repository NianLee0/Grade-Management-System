//
// Created by NianLee on 2023/5/16.
//

#include "../Inc/addCourseBaseInform.h"

/************************************************
 * @Function: addCourseBaseInform
 * @Description: 管理员通过输入添加课程信息,包括课号,课名,学分
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
 * @Description: 初始化过程中从文件中读取课程信息,包括课号,课名,学分
 * @Input: token[]:文件中截取的信息块
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
 * @Description: 将链表信息存入"courseBaseInformation"结构体中
 * @Input: head:链表头
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
 * @Description: 将课程信息存入文件中
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
			printf("\n课程号重复,请重新输入\n\n");
			addCourseBaseInformToFile();
			return;
		}
		if(strcmp(courseBaseInformation[i].name, head->next->next->data) == 0)
		{
			printf("\n课程名重复,请重新输入\n\n");
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
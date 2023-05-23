//
// Created by NianLee on 2023/5/14.
//

#include "../Inc/addStudentBaseInform.h"

/************************************************
 * @Function: addStudentBaseInform
 * @Description: 管理员通过输入添加学生信息,包括姓名、性别、年龄、学号
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
 * @Description: 初始化过程中从文件中读取学生信息,包括姓名,性别,年龄,学号
 * @Input: token[]:文件中截取的信息块
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
 * @Description: 将链表信息存入"studentBaseInformation"结构体中
 * @Input: head:链表头
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
 * @Description: 将学生信息存入文件中
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
			printf("学号重复,请重新输入\n");
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

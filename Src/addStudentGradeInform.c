//
// Created by NianLee on 2023/5/17.
//

#include "../Inc/addStudentGradeInform.h"

/************************************************
 * @Function: addStudentGradeInform
 * @Description: 管理员通过输入添加学生成绩信息,包括姓名、课名、成绩
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
 * @Description: 初始化过程中从文件中读取学生课程信息,包括姓名、课名、成绩
 * @Input: token[]:文件中截取的信息块
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
 * @Description: 将链表信息存入"studentGradeInformation"结构体中
 * @Input: head:链表头
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
 * @Description: 将学生成绩信息存入文件中
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
	printf("\n添加成功\n");
}

/************************************************
 * @Function: checkStudentName
 * @Description: 检查学生姓名是否存在
 * @Input: head:链表头
 * @Return: head:链表头
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
	printf("\n学生姓名不存在,请重新输入\n");
	printf("姓名: ");
	scanf("%s", head->next->data);
	checkStudentName(head);
}

/************************************************
 * @Function: checkCourseName
 * @Description: 检查课程名是否存在
 * @Input: courseName:课程名
 * @Return: head:链表头
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
	printf("\n课程不存在,请重新输入\n");
	printf("课名: ");
	scanf("%s", head->next->next->data);
	checkCourseName(head);
}

/************************************************
 * @Function: checkGrade
 * @Description: 检查成绩是否合法
 * @Input: head:链表头
 * @Return: head:链表头
 * @Others: None
 * @Author: NianLee
 ************************************************/
informLinkedList* checkGrade(informLinkedList* head)
{
	strcpy(studentGradeInformation[studentGradeNum].grade,
			head->next->next->next->data);
	if (calculateGPA(studentGradeNum) == -1)
	{
		printf("\n成绩不合法,请重新输入!\n");
		printf("成绩: ");
		scanf("%s", head->next->next->next->data);
		checkGrade(head);
	}
	return head;
}

/************************************************
 * @Function: checkDuplicateData
 * @Description: 检查是否有重复数据
 * @Input: head:链表头
 * @Return: head:链表头
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
			printf("\n已有该学生数据,无法添加,请重新输入\n");
			printf("姓名: ");
			scanf("%s", head->next->data);
			checkStudentName(head);
			printf("课程名: ");
			scanf("%s", head->next->next->data);
			checkCourseName(head);
			printf("成绩: ");
			scanf("%s", head->next->next->next->data);
			checkGrade(head);
			checkDuplicateData(head);
		}
	}
}
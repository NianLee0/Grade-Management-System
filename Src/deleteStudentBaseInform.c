//
// Created by NianLee on 2023/5/15.
//

#include "../Inc/deleteStudentBaseInform.h"

/************************************************
 * @Function: deleteStudentBaseInform
 * @Description: 管理员通过输入删除学生信息,包括姓名、性别、年龄、学号
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void deleteStudentBaseInform(void)
{
	char target[20];
	int i;
	printf("请输入要删除的学生的姓名或学号: ");
	scanf("%s", target);
	for (i = 0; i < studentNum; i++)
	{
		if (strcmp(studentBaseInformation[i].name, target) == 0 ||
			strcmp(studentBaseInformation[i].number, target) == 0)
		{
			printf("\n已找到该学生: \n");
			printf("姓名: %s\n", studentBaseInformation[i].name);
			printf("性别: %s\n", studentBaseInformation[i].sex);
			printf("年龄: %s\n", studentBaseInformation[i].age);
			printf("学号: %s\n", studentBaseInformation[i].number);
			break;
		}
	}
	if (i == studentNum)
	{
		printf("\n未找到该学生!\n");
		printf("请检查输入是否正确并重新输入!\n");;
		deleteStudentBaseInform();
	}
	else
		deleteStudentBaseInformConfirm(i);
}

/************************************************
 * @Function: deleteStudentBaseInformConfirm
 * @Description: 确认是否删除该学生信息
 * @Input: targetStudentNum: 要删除的学生在数组中的下标
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void deleteStudentBaseInformConfirm(int targetStudentNum)
{
	char confirm;
	printf("\n确认删除该学生信息? (y/N): ");
	fflush(stdin);
	scanf("%s", &confirm);
	if (confirm == 'Y' || confirm == 'y')
		deleteStudentBaseInformFromStructure(targetStudentNum);
	else if (confirm == 'N' || confirm == 'n' || confirm == '\n')
	{
		system("cls");
		printf("\n已取消删除!\n");
		mode2SubMenu();
	}
	else
	{
		printf("\n输入错误!\n");
		printf("请重新输入!\n");
		deleteStudentBaseInformConfirm(targetStudentNum);
	}
}

/************************************************
 * @Function: deleteStudentBaseInformFromStructure
 * @Description: 从结构体数组中删除学生信息
 * @Input: targetStudentNum: 要删除的学生在数组中的下标
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void deleteStudentBaseInformFromStructure(int targetStudentNum)
{
	for (int i = targetStudentNum; i < studentNum - 1; i++)
		studentBaseInformation[i] = studentBaseInformation[i + 1];
	studentBaseInformation[studentNum].name[0] = '\0';
	studentBaseInformation[studentNum].sex[0] = '\0';
	studentBaseInformation[studentNum].age[0] = '\0';
	studentBaseInformation[studentNum].number[0] = '\0';
	saveStudentBaseInformIntoFile_2();
	studentNum--;
}

/************************************************
 * @Function: saveStudentBaseInformIntoFile_2
 * @Description: 将修改后的学生信息保存到文件中
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void saveStudentBaseInformIntoFile_2(void)
{
	char inform[100];
	FILE* fp;
	fp = fopen(studentBaseInformFilePath, "w");
	fputs("姓名,性别,年龄,学号\n", fp);
	fseek(fp, 21, SEEK_SET);
	for (int i = 0; i < studentNum - 1; i++)
	{
		sprintf(inform, "%s,%s,%s,%s\n",
				studentBaseInformation[i].name,
				studentBaseInformation[i].sex,
				studentBaseInformation[i].age,
				studentBaseInformation[i].number);
		fputs(inform, fp);
	}
	fclose(fp);
}
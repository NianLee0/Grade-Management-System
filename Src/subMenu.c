//
// Created by NianLee on 2023/5/17.
//

#include "../Inc/subMenu.h"

/************************************************
 * @Function: mode2SubMenu
 * @Description: 模式二子菜单
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void mode2SubMenu(void)
{
	short userSelect;
	system("cls");
	printf("请选择你的操作：\n");
	printf("1. 添加学生信息\n");
	printf("2. 修改学生信息\n");
	printf("3. 删除学生信息\n");
	printf("0. 返回主菜单\n");
	printf("请输入你的选择(0~3): ");
	scanf("%hd", &userSelect);
	switch (userSelect)
	{
	case 0:
		system("cls");
		mainMenu();
		break;
	case 1:
		printf("\n添加学生信息\n");
		addStudentBaseInformToFile();
		break;
	case 2:
		printf("\n修改学生信息\n");
		changeStudentBaseInform();
		break;
	case 3:
		printf("\n删除学生信息\n");
		deleteStudentBaseInform();
		break;
	default:
		system("cls");
		printf("输入错误，请重新输入\n");
		mode2SubMenu();
		break;
	}
}

/************************************************
 * @Function: mode4SubMenu
 * @Description: 模式四子菜单
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void mode4SubMenu(void)
{
	short userSelect;
	system("cls");
	printf("请选择你的操作：\n");
	printf("1. 添加课程信息\n");
	printf("2. 修改课程信息\n");
	printf("3. 删除课程信息\n");
	printf("0. 返回主菜单\n");
	printf("请输入你的选择(0~3): ");
	scanf("%hd", &userSelect);
	switch (userSelect)
	{
	case 0:
		system("cls");
		mainMenu();
		break;
	case 1:
		printf("\n添加课程信息\n");
		addCourseBaseInformToFile();
		break;
	case 2:
		printf("\n修改课程信息\n");
		changeCourseBaseInform();
		break;
	case 3:
		printf("\n删除课程信息\n");
		deleteCourseBaseInform();
		break;
	default:
		system("cls");
		printf("输入错误，请重新输入\n");
		mode4SubMenu();
		break;
	}
}

/************************************************
 * @Function: mode5SubMenu
 * @Description: 模式五子菜单
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void mode5SubMenu(void)
{
	short userSelect;
	system("cls");
	printf("请选择你的操作：\n");
	printf("1. 查找学生成绩单\n");
	printf("2. 查找课程成绩单\n");
	printf("0. 返回主菜单\n");
	printf("请输入你的选择(0~2): ");
	fflush(stdin);
	scanf("%hd", &userSelect);
	switch (userSelect)
	{
	case 0:
		system("cls");
		mainMenu();
		break;
	case 1:
		printf("\n查找学生成绩单\n");
		findStudentGradeInformByStudent();
		break;
	case 2:
		printf("\n查找课程成绩单\n");
		findStudentGradeInformByCourse();
		break;
	default:
		system("cls");
		printf("输入错误，请重新输入\n");
		mode5SubMenu();
		break;
	}
}

/************************************************
 * @Function: mode6SubMenu
 * @Description: 模式六子菜单
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void mode6SubMenu(void)
{
	short userSelect;
	system("cls");
	printf("请选择你的操作：\n");
	printf("1. 添加成绩信息\n");
	printf("2. 修改成绩信息\n");
	printf("3. 删除成绩信息\n");
	printf("0. 返回主菜单\n");
	printf("请输入你的选择(0~3): ");
	scanf("%hd", &userSelect);
	switch (userSelect)
	{
	case 0:
		system("cls");
		mainMenu();
		break;
	case 1:
		printf("\n添加学生信息\n");
		addStudentGradeInformToFile();
		break;
	case 2:
		printf("\n修改学生信息\n");
		changeStudentGradeInform();
		break;
	case 3:
		printf("\n删除学生信息\n");
		deleteStudentGradeInform();
		break;
	default:
		system("cls");
		printf("输入错误，请重新输入\n");
		mode6SubMenu();
		break;
	}
}

/************************************************
 * @Function: mode7SubMenu
 * @Description: 模式七子菜单
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void mode7SubMenu(void)
{
	short userSelect;
	system("cls");
	printf("请选择你的操作：\n");
	printf("1. 导出学生成绩信息\n");
	printf("2. 导出课程成绩信息\n");
	printf("0. 返回主菜单\n");
	printf("请输入你的选择(0~2): ");
	fflush(stdin);
	scanf("%hd", &userSelect);
	switch (userSelect)
	{
	case 0:
		system("cls");
		mainMenu();
		break;
	case 1:
		printf("\n导出学生成绩信息\n");
		exportStudentData();
		break;
	case 2:
		printf("\n导出课程成绩信息\n");
		exportCourseData();
		break;
	default:
		system("cls");
		printf("输入错误，请重新输入\n");
		mode7SubMenu();
		break;
	}
}
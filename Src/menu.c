//
// Created by NianLee on 2023/5/3.
//

#include "../Inc/menu.h"

/************************************************
 * @Function: mainMenu
 * @Description: 显示主菜单
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void mainMenu(void)
{
	printf("欢迎使用学生成绩管理系统\n");
	printf("1. 查询学生信息\n");
	printf("2. 添加/修改/删除学生信息\n");
	printf("3. 查询课程信息\n");
	printf("4. 添加/修改/删除课程信息\n");
	printf("5. 查询成绩信息\n");
	printf("6. 添加/修改/删除成绩信息\n");
	printf("7. 导出数据\n");
	printf("0. 退出系统\n");
	printf("请输入你的选择(0~6): ");
	userSelectMainMenu();
}

/************************************************
 * @Function: userSelectMainMenu
 * @Description: 用户选择子菜单
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void userSelectMainMenu(void)
{
	char userSelect;
	fflush(stdin);
	scanf("%c", &userSelect);
	switch (userSelect)
	{
	case '\n':
		userSelect = '0';
	case '0':
		printf("\n感谢使用学生成绩管理系统\n\n");
		printf("按任意键退出系统...");
		fflush(stdin);
		getchar();
		exit(0);
	case '1':
		system("cls");
		printf("查询学生信息\n");
		findStudentBaseInform();
		mode1Continue();
		break;
	case '2':
		system("cls");
		printf("添加/修改/删除学生信息\n");
		mode2SubMenu();
		mode2Continue();
		break;
	case '3':
		system("cls");
		printf("查询课程信息\n");
		findCourseBaseInform();
		mode3Continue();
		break;
	case '4':
		printf("添加/修改/删除课程信息\n");
		mode4SubMenu();
		mode4Continue();
		break;
	case '5':
		printf("查询成绩信息\n");
		mode5SubMenu();
		mode5Continue();
		break;
	case '6':
		printf("添加/修改/删除成绩信息\n");
		mode6SubMenu();
		mode6Continue();
		break;
	case '7':
		printf("导出数据\n");
		mode7SubMenu();
		mode7Continue();
		break;
	default:
		system("cls");
		printf("输入错误，请重新输入\n");
		return;
	}
}







//
// Created by NianLee on 2023/5/17.
//

#include "../Inc/modeContinue.h"

/************************************************
 * @Function: mode1Continue
 * @Description: 模式一后续操作选择
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void mode1Continue(void)
{
	char userSelectContinue;
	printf("是否继续查询? (y/N): ");
	fflush(stdin);
	scanf("%c", &userSelectContinue);
	if (userSelectContinue == 'Y' ||
		userSelectContinue == 'y')
	{
		system("cls");
		findStudentBaseInform();
		mode1Continue();
	}
	else if (userSelectContinue == 'N' ||
			 userSelectContinue == 'n' ||
			 userSelectContinue == '\n')
	{
		system("cls");
		mainMenu();
	}
	else
	{
		printf("输入错误，请重新输入\n");
		mode1Continue();
	}
}

/************************************************
 * @Function: mode2Continue
 * @Description: 模式二后续操作选择
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void mode2Continue(void)
{
	char userSelectContinue;
	printf("\n操作成功!\n");
	printf("是否继续添加/修改/删除？(y/N): ");
	fflush(stdin);
	scanf("%c", &userSelectContinue);
	if (userSelectContinue == 'Y' ||
		userSelectContinue == 'y')
	{
		system("cls");
		mode2SubMenu();
	}
	else if (userSelectContinue == 'N' ||
			 userSelectContinue == 'n' ||
			 userSelectContinue == '\n')
	{
		system("cls");
		mainMenu();
	}
	else
	{
		printf("输入错误，请重新输入\n");
		mode2Continue();
	}
}

/************************************************
 * @Function: mode3Continue
 * @Description: 模式三后续操作选择
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void mode3Continue(void)
{
	char userSelectContinue;
	printf("是否继续查询?(y/N) ");
	fflush(stdin);
	scanf("%c", &userSelectContinue);
	if (userSelectContinue == 'Y' ||
		userSelectContinue == 'y')
	{
		system("cls");
		findCourseBaseInform();
		mode3Continue();
	}
	else if (userSelectContinue == 'N' ||
			 userSelectContinue == 'n' ||
			 userSelectContinue == '\n')
	{
		system("cls");
		mainMenu();
	}
	else
	{
		printf("输入错误，请重新输入\n");
		mode2Continue();
	}
}

/************************************************
 * @Function: mode4Continue
 * @Description: 模式四后续操作选择
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void mode4Continue(void)
{
	char userSelectContinue;
	printf("\n操作成功!\n");
	printf("是否继续添加/修改/删除？(y/N): ");
	fflush(stdin);
	scanf("%c", &userSelectContinue);
	if (userSelectContinue == 'Y' ||
		userSelectContinue == 'y')
	{
		system("cls");
		mode4SubMenu();
	}
	else if (userSelectContinue == 'N' ||
			 userSelectContinue == 'n' ||
			 userSelectContinue == '\n')
	{
		system("cls");
		mainMenu();
	}
	else
	{
		printf("输入错误，请重新输入\n");
		mode4Continue();
	}
}

/************************************************
 * @Function: mode5Continue
 * @Description: 模式五后续操作选择
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void mode5Continue(void)
{
	char userSelectContinue;
	printf("\n是否继续查询? (y/N): ");
	fflush(stdin);
	scanf("%c", &userSelectContinue);
	if (userSelectContinue == 'Y' ||
		userSelectContinue == 'y')
	{
		system("cls");
		mode5SubMenu();
		mode5Continue();
	}
	else if (userSelectContinue == 'N' ||
			 userSelectContinue == 'n' ||
			 userSelectContinue == '\n')
	{
		system("cls");
		mainMenu();
	}
	else
	{
		printf("输入错误，请重新输入\n");
		mode5Continue();
	}
}

/************************************************
 * @Function: mode6Continue
 * @Description: 模式六后续操作选择
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void mode6Continue(void)
{
	char userSelectContinue;
	printf("\n是否继续添加/修改/删除? (y/N): ");
	fflush(stdin);
	scanf("%c", &userSelectContinue);
	if (userSelectContinue == 'Y' ||
		userSelectContinue == 'y')
	{
		system("cls");
		mode6SubMenu();
		mode6Continue();
	}
	else if (userSelectContinue == 'N' ||
			 userSelectContinue == 'n' ||
			 userSelectContinue == '\n')
	{
		system("cls");
		mainMenu();
	}
	else
	{
		printf("输入错误，请重新输入\n");
		mode6Continue();
	}
}

/************************************************
 * @Function: mode7Continue
 * @Description: 模式七后续操作选择
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void mode7Continue(void)
{
	char userSelectContinue;
	printf("\n是否继续导出数据? (y/N): ");
	fflush(stdin);
	scanf("%c", &userSelectContinue);
	if (userSelectContinue == 'Y' ||
		userSelectContinue == 'y')
	{
		system("cls");
		mode7SubMenu();
		mode7Continue();
	}
	else if (userSelectContinue == 'N' ||
			 userSelectContinue == 'n' ||
			 userSelectContinue == '\n')
	{
		system("cls");
		mainMenu();
	}
	else
	{
		printf("输入错误，请重新输入\n");
		mode7Continue();
	}
}
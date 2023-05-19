//
// Created by NianLee on 2023/5/17.
//

#include "../Inc/modeContinue.h"

/************************************************
 * @Function: mode1Continue
 * @Description: ģʽһ��������ѡ��
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void mode1Continue(void)
{
	char userSelectContinue;
	printf("�Ƿ������ѯ? (y/N): ");
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
		printf("�����������������\n");
		mode1Continue();
	}
}

/************************************************
 * @Function: mode2Continue
 * @Description: ģʽ����������ѡ��
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void mode2Continue(void)
{
	char userSelectContinue;
	printf("\n�����ɹ�!\n");
	printf("�Ƿ�������/�޸�/ɾ����(y/N): ");
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
		printf("�����������������\n");
		mode2Continue();
	}
}

/************************************************
 * @Function: mode3Continue
 * @Description: ģʽ����������ѡ��
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void mode3Continue(void)
{
	char userSelectContinue;
	printf("�Ƿ������ѯ?(y/N) ");
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
		printf("�����������������\n");
		mode2Continue();
	}
}

/************************************************
 * @Function: mode4Continue
 * @Description: ģʽ�ĺ�������ѡ��
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void mode4Continue(void)
{
	char userSelectContinue;
	printf("\n�����ɹ�!\n");
	printf("�Ƿ�������/�޸�/ɾ����(y/N): ");
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
		printf("�����������������\n");
		mode4Continue();
	}
}

/************************************************
 * @Function: mode5Continue
 * @Description: ģʽ���������ѡ��
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void mode5Continue(void)
{
	char userSelectContinue;
	printf("\n�Ƿ������ѯ? (y/N): ");
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
		printf("�����������������\n");
		mode5Continue();
	}
}

/************************************************
 * @Function: mode6Continue
 * @Description: ģʽ����������ѡ��
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void mode6Continue(void)
{
	char userSelectContinue;
	printf("\n�Ƿ�������/�޸�/ɾ��? (y/N): ");
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
		printf("�����������������\n");
		mode6Continue();
	}
}

/************************************************
 * @Function: mode7Continue
 * @Description: ģʽ�ߺ�������ѡ��
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void mode7Continue(void)
{
	char userSelectContinue;
	printf("\n�Ƿ������������? (y/N): ");
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
		printf("�����������������\n");
		mode7Continue();
	}
}
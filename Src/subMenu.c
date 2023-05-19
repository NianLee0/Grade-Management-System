//
// Created by NianLee on 2023/5/17.
//

#include "../Inc/subMenu.h"

/************************************************
 * @Function: mode2SubMenu
 * @Description: ģʽ���Ӳ˵�
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void mode2SubMenu(void)
{
	short userSelect;
	system("cls");
	printf("��ѡ����Ĳ�����\n");
	printf("1. ���ѧ����Ϣ\n");
	printf("2. �޸�ѧ����Ϣ\n");
	printf("3. ɾ��ѧ����Ϣ\n");
	printf("0. �������˵�\n");
	printf("���������ѡ��(0~3): ");
	scanf("%hd", &userSelect);
	switch (userSelect)
	{
	case 0:
		system("cls");
		mainMenu();
		break;
	case 1:
		printf("\n���ѧ����Ϣ\n");
		addStudentBaseInformToFile();
		break;
	case 2:
		printf("\n�޸�ѧ����Ϣ\n");
		changeStudentBaseInform();
		break;
	case 3:
		printf("\nɾ��ѧ����Ϣ\n");
		deleteStudentBaseInform();
		break;
	default:
		system("cls");
		printf("�����������������\n");
		mode2SubMenu();
		break;
	}
}

/************************************************
 * @Function: mode4SubMenu
 * @Description: ģʽ���Ӳ˵�
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void mode4SubMenu(void)
{
	short userSelect;
	system("cls");
	printf("��ѡ����Ĳ�����\n");
	printf("1. ��ӿγ���Ϣ\n");
	printf("2. �޸Ŀγ���Ϣ\n");
	printf("3. ɾ���γ���Ϣ\n");
	printf("0. �������˵�\n");
	printf("���������ѡ��(0~3): ");
	scanf("%hd", &userSelect);
	switch (userSelect)
	{
	case 0:
		system("cls");
		mainMenu();
		break;
	case 1:
		printf("\n��ӿγ���Ϣ\n");
		addCourseBaseInformToFile();
		break;
	case 2:
		printf("\n�޸Ŀγ���Ϣ\n");
		changeCourseBaseInform();
		break;
	case 3:
		printf("\nɾ���γ���Ϣ\n");
		deleteCourseBaseInform();
		break;
	default:
		system("cls");
		printf("�����������������\n");
		mode4SubMenu();
		break;
	}
}

/************************************************
 * @Function: mode5SubMenu
 * @Description: ģʽ���Ӳ˵�
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void mode5SubMenu(void)
{
	short userSelect;
	system("cls");
	printf("��ѡ����Ĳ�����\n");
	printf("1. ����ѧ���ɼ���\n");
	printf("2. ���ҿγ̳ɼ���\n");
	printf("0. �������˵�\n");
	printf("���������ѡ��(0~2): ");
	fflush(stdin);
	scanf("%hd", &userSelect);
	switch (userSelect)
	{
	case 0:
		system("cls");
		mainMenu();
		break;
	case 1:
		printf("\n����ѧ���ɼ���\n");
		findStudentGradeInformByStudent();
		break;
	case 2:
		printf("\n���ҿγ̳ɼ���\n");
		findStudentGradeInformByCourse();
		break;
	default:
		system("cls");
		printf("�����������������\n");
		mode5SubMenu();
		break;
	}
}

/************************************************
 * @Function: mode6SubMenu
 * @Description: ģʽ���Ӳ˵�
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void mode6SubMenu(void)
{
	short userSelect;
	system("cls");
	printf("��ѡ����Ĳ�����\n");
	printf("1. ��ӳɼ���Ϣ\n");
	printf("2. �޸ĳɼ���Ϣ\n");
	printf("3. ɾ���ɼ���Ϣ\n");
	printf("0. �������˵�\n");
	printf("���������ѡ��(0~3): ");
	scanf("%hd", &userSelect);
	switch (userSelect)
	{
	case 0:
		system("cls");
		mainMenu();
		break;
	case 1:
		printf("\n���ѧ����Ϣ\n");
		addStudentGradeInformToFile();
		break;
	case 2:
		printf("\n�޸�ѧ����Ϣ\n");
		changeStudentGradeInform();
		break;
	case 3:
		printf("\nɾ��ѧ����Ϣ\n");
		deleteStudentGradeInform();
		break;
	default:
		system("cls");
		printf("�����������������\n");
		mode6SubMenu();
		break;
	}
}

/************************************************
 * @Function: mode7SubMenu
 * @Description: ģʽ���Ӳ˵�
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void mode7SubMenu(void)
{
	short userSelect;
	system("cls");
	printf("��ѡ����Ĳ�����\n");
	printf("1. ����ѧ���ɼ���Ϣ\n");
	printf("2. �����γ̳ɼ���Ϣ\n");
	printf("0. �������˵�\n");
	printf("���������ѡ��(0~2): ");
	fflush(stdin);
	scanf("%hd", &userSelect);
	switch (userSelect)
	{
	case 0:
		system("cls");
		mainMenu();
		break;
	case 1:
		printf("\n����ѧ���ɼ���Ϣ\n");
		exportStudentData();
		break;
	case 2:
		printf("\n�����γ̳ɼ���Ϣ\n");
		exportCourseData();
		break;
	default:
		system("cls");
		printf("�����������������\n");
		mode7SubMenu();
		break;
	}
}
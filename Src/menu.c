//
// Created by NianLee on 2023/5/3.
//

#include "../Inc/menu.h"

/************************************************
 * @Function: mainMenu
 * @Description: ��ʾ���˵�
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void mainMenu(void)
{
	printf("��ӭʹ��ѧ���ɼ�����ϵͳ\n");
	printf("1. ��ѯѧ����Ϣ\n");
	printf("2. ���/�޸�/ɾ��ѧ����Ϣ\n");
	printf("3. ��ѯ�γ���Ϣ\n");
	printf("4. ���/�޸�/ɾ���γ���Ϣ\n");
	printf("5. ��ѯ�ɼ���Ϣ\n");
	printf("6. ���/�޸�/ɾ���ɼ���Ϣ\n");
	printf("7. ��������\n");
	printf("0. �˳�ϵͳ\n");
	printf("���������ѡ��(0~6): ");
	userSelectMainMenu();
}

/************************************************
 * @Function: userSelectMainMenu
 * @Description: �û�ѡ���Ӳ˵�
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
		printf("\n��лʹ��ѧ���ɼ�����ϵͳ\n\n");
		printf("��������˳�ϵͳ...");
		fflush(stdin);
		getchar();
		exit(0);
	case '1':
		system("cls");
		printf("��ѯѧ����Ϣ\n");
		findStudentBaseInform();
		mode1Continue();
		break;
	case '2':
		system("cls");
		printf("���/�޸�/ɾ��ѧ����Ϣ\n");
		mode2SubMenu();
		mode2Continue();
		break;
	case '3':
		system("cls");
		printf("��ѯ�γ���Ϣ\n");
		findCourseBaseInform();
		mode3Continue();
		break;
	case '4':
		printf("���/�޸�/ɾ���γ���Ϣ\n");
		mode4SubMenu();
		mode4Continue();
		break;
	case '5':
		printf("��ѯ�ɼ���Ϣ\n");
		mode5SubMenu();
		mode5Continue();
		break;
	case '6':
		printf("���/�޸�/ɾ���ɼ���Ϣ\n");
		mode6SubMenu();
		mode6Continue();
		break;
	case '7':
		printf("��������\n");
		mode7SubMenu();
		mode7Continue();
		break;
	default:
		system("cls");
		printf("�����������������\n");
		return;
	}
}







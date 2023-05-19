//
// Created by NianLee on 2023/5/15.
//

#include "../Inc/deleteStudentBaseInform.h"

/************************************************
 * @Function: deleteStudentBaseInform
 * @Description: ����Աͨ������ɾ��ѧ����Ϣ,�����������Ա����䡢ѧ��
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void deleteStudentBaseInform(void)
{
	char target[20];
	int i;
	printf("������Ҫɾ����ѧ����������ѧ��: ");
	scanf("%s", target);
	for (i = 0; i < studentNum; i++)
	{
		if (strcmp(studentBaseInformation[i].name, target) == 0 ||
			strcmp(studentBaseInformation[i].number, target) == 0)
		{
			printf("\n���ҵ���ѧ��: \n");
			printf("����: %s\n", studentBaseInformation[i].name);
			printf("�Ա�: %s\n", studentBaseInformation[i].sex);
			printf("����: %s\n", studentBaseInformation[i].age);
			printf("ѧ��: %s\n", studentBaseInformation[i].number);
			break;
		}
	}
	if (i == studentNum)
	{
		printf("\nδ�ҵ���ѧ��!\n");
		printf("���������Ƿ���ȷ����������!\n");;
		deleteStudentBaseInform();
	}
	else
		deleteStudentBaseInformConfirm(i);
}

/************************************************
 * @Function: deleteStudentBaseInformConfirm
 * @Description: ȷ���Ƿ�ɾ����ѧ����Ϣ
 * @Input: targetStudentNum: Ҫɾ����ѧ���������е��±�
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void deleteStudentBaseInformConfirm(int targetStudentNum)
{
	char confirm;
	printf("\nȷ��ɾ����ѧ����Ϣ? (y/N): ");
	fflush(stdin);
	scanf("%s", &confirm);
	if (confirm == 'Y' || confirm == 'y')
		deleteStudentBaseInformFromStructure(targetStudentNum);
	else if (confirm == 'N' || confirm == 'n' || confirm == '\n')
	{
		system("cls");
		printf("\n��ȡ��ɾ��!\n");
		mode2SubMenu();
	}
	else
	{
		printf("\n�������!\n");
		printf("����������!\n");
		deleteStudentBaseInformConfirm(targetStudentNum);
	}
}

/************************************************
 * @Function: deleteStudentBaseInformFromStructure
 * @Description: �ӽṹ��������ɾ��ѧ����Ϣ
 * @Input: targetStudentNum: Ҫɾ����ѧ���������е��±�
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
 * @Description: ���޸ĺ��ѧ����Ϣ���浽�ļ���
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
	fputs("����,�Ա�,����,ѧ��\n", fp);
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
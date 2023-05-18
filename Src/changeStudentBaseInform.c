//
// Created by NianLee on 2023/5/15.
//

#include "../Inc/changeStudentBaseInform.h"

/************************************************
 * @Function: changeStudentBaseInform
 * @Description: ����Աͨ�������޸�ѧ����Ϣ,�����������Ա����䡢ѧ��
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void changeStudentBaseInform(void)
{
	char target[20];
	int i;
	printf("������Ҫ�޸ĵ�ѧ��������ѧ��: ");
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
		printf("���������Ƿ���ȷ����������!\n");
		changeStudentBaseInform();
	}
	else
	{
		printf("\n�������޸ĺ��ѧ����Ϣ:\n");
		printf("����: ");
		scanf("%s", studentBaseInformation[i].name);
		printf("�Ա�: ");
		scanf("%s", studentBaseInformation[i].sex);
		printf("����: ");
		scanf("%s", studentBaseInformation[i].age);
		printf("ѧ��: ");
		scanf("%s", studentBaseInformation[i].number);
		printf("�޸ĳɹ�!\n");
		saveStudentBaseInform();
	}
}

/************************************************
 * @Function: saveStudentBaseInform
 * @Description: ѯ�ʹ���Ա�Ƿ��޸ĺ��ѧ����Ϣ�������ļ�
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void saveStudentBaseInform(void)
{
	char choice;
	printf("\n�Ƿ���Ϣ�������ļ�? (Y/n): ");
	getchar();
	scanf("%c", &choice);
	if (choice == 'Y' || choice == 'y' || choice == '\n')
	{
		saveStudentBaseInformIntoFile_1();
		printf("����ɹ�!\n");
		printf("�����޸Ľ�������Ч!\n");
	}
	else if (choice == 'N' || choice == 'n')
	{
		printf("��ȡ������!\n");
		printf("�����޸Ľ���ǰ����ʱ��Ч!\n");
	}
	else
	{
		system("cls");
		printf("�������!\n");
		printf("����������!\n");
		saveStudentBaseInform();
	}
}

/************************************************
 * @Function: saveStudentBaseInformIntoFile_1
 * @Description: ���޸ĺ�Ŀγ���Ϣ�������ļ�
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void saveStudentBaseInformIntoFile_1(void)
{
	char inform[100];
	FILE* fp;
	fp = fopen(studentBaseInformFilePath, "r+");
	fseek(fp, 21, SEEK_SET);
	for (int i = 0; i < studentNum; i++)
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

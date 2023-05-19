//
// Created by NianLee on 2023/5/16.
//

#include "../Inc/changeCourseBaseInform.h"

/************************************************
 * @Function: changeCourseBaseInform
 * @Description: ����Աͨ�������޸Ŀγ���Ϣ,�����κ�,����,ѧ��
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void changeCourseBaseInform(void)
{
	char target[20];
	int i;
	printf("������Ҫ�޸ĵĿγ̵Ŀ�����κ�: ");
	scanf("%s", target);
	for (i = 0; i < courseNum; i++)
	{
		if (strcmp(courseBaseInformation[i].number, target) == 0 ||
			strcmp(courseBaseInformation[i].name, target) == 0)
		{
			printf("\n���ҵ��ÿγ�: \n");
			printf("�κ�: %s\n", courseBaseInformation[i].number);
			printf("����: %s\n", courseBaseInformation[i].name);
			printf("ѧ��: %s\n", courseBaseInformation[i].credit);
			break;
		}
	}
	if (i == courseNum)
	{
		printf("\nδ�ҵ���ѧ��!\n");
		printf("���������Ƿ���ȷ����������!\n");
		changeCourseBaseInform();
	}
	else
	{
		printf("\n�������޸ĺ�Ŀγ���Ϣ:\n");
		printf("�κ�: ");
		scanf("%s", courseBaseInformation[i].number);
		printf("����: ");
		scanf("%s", courseBaseInformation[i].name);
		printf("ѧ��: ");
		scanf("%s", courseBaseInformation[i].credit);
		printf("�޸ĳɹ�!\n");
		saveCourseBaseInform();
	}
}

/************************************************
 * @Function: saveCourseBaseInform
 * @Description: ѯ�ʹ���Ա�Ƿ��޸ĺ�Ŀγ���Ϣ�������ļ�
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void saveCourseBaseInform(void)
{
	char choice;
	printf("\n�Ƿ���Ϣ�������ļ�? (Y/n): ");
	fflush(stdin);
	scanf("%c", &choice);
	if (choice == 'Y' || choice == 'y' || choice == '\n')
	{
		saveCourseBaseInformIntoFile_1();
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
		saveCourseBaseInform();
	}
}

/************************************************
 * @Function: saveCourseBaseInformIntoFile_1
 * @Description: ���޸ĺ�Ŀγ���Ϣ�������ļ�
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void saveCourseBaseInformIntoFile_1(void)
{
	char inform[100];
	FILE* fp;
	fp = fopen(courseBaseInformFilePath, "r+");
	fseek(fp, 16, SEEK_SET);
	for (int i = 0; i < courseNum; i++)
	{
		sprintf(inform, "%s,%s,%s\n",
				courseBaseInformation[i].number,
				courseBaseInformation[i].name,
				courseBaseInformation[i].credit);
		fputs(inform, fp);
	}
	fclose(fp);
}

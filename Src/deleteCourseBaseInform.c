//
// Created by NianLee on 2023/5/16.
//

#include "../Inc/deleteCourseBaseInform.h"

/************************************************
 * @Function: deleteCourseBaseInform
 * @Description: ����Աͨ������ɾ���γ̻�����Ϣ,�����κ�,����,ѧ��
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void deleteCourseBaseInform(void)
{
	char target[20];
	int i;
	printf("������Ҫɾ���Ŀγ̵Ŀ�����κ�: ");
	scanf("%s", target);
	for (i = 0; i < courseNum; i++)
	{
		if (strcmp(courseBaseInformation[i].name, target) == 0 ||
			strcmp(courseBaseInformation[i].number, target) == 0)
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
		printf("\nδ�ҵ��ÿγ�!\n");
		printf("���������Ƿ���ȷ����������!\n");;
		deleteCourseBaseInform();
	}
	else
		deleteCourseBaseInformConfirm(i);
}

/************************************************
 * @Function: deleteCourseBaseInformConfirm
 * @Description: ȷ���Ƿ�ɾ���γ̻�����Ϣ
 * @Input: targetCourseNum: Ҫɾ����ѧ���������е��±�
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void deleteCourseBaseInformConfirm(int targetCourseNum)
{
	char confirm;
	printf("\nȷ��ɾ���ÿγ���Ϣ? (y/N): ");
	getchar();
	scanf("%c", &confirm);
	if (confirm == 'Y' || confirm == 'y')
		deleteCourseBaseInformFromStructure(targetCourseNum);
	else if (confirm == 'N' || confirm == 'n' || confirm == '\n')
	{
		system("cls");
		printf("\n��ȡ��ɾ������!\n");
		mode2SubMenu();
	}
	else
	{
		printf("\n�������!\n");
		printf("����������!\n");
		deleteStudentBaseInformConfirm(targetCourseNum);
	}
}

/************************************************
 * @Function: deleteCourseBaseInformFromStructure
 * @Description: �ӽṹ��������ɾ���γ̻�����Ϣ
 * @Input: targetCourseNum: Ҫɾ���Ŀγ��������е��±�
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void deleteCourseBaseInformFromStructure(int targetCourseNum)
{
	for (int i = targetCourseNum; i < courseNum - 1; i++)
		courseBaseInformation[i] = courseBaseInformation[i + 1];
	courseBaseInformation[courseNum].number[0] = '\0';
	courseBaseInformation[courseNum].name[0] = '\0';
	courseBaseInformation[courseNum].credit[0] = '\0';
	saveCourseBaseInformIntoFile_2();
	courseNum--;
}

/************************************************
 * @Function: saveCourseBaseInformIntoFile_2
 * @Description: ���޸ĺ�Ŀγ̻�����Ϣ���浽�ļ���
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void saveCourseBaseInformIntoFile_2(void)
{
	char inform[100];
	FILE* fp;
	fp = fopen(courseBaseInformFilePath, "w");
	fputs("�κ�,����,ѧ��\n", fp);
	fseek(fp, 16, SEEK_SET);
	for (int i = 0; i < courseNum - 1; i++)
	{
		sprintf(inform, "%s,%s,%s\n",
				courseBaseInformation[i].number,
				courseBaseInformation[i].name,
				courseBaseInformation[i].credit);
		fputs(inform, fp);
	}
	fclose(fp);
}
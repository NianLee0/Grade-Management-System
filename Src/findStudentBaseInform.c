//
// Created by NianLee on 2023/5/14.
//

#include "../Inc/findStudentBaseInform.h"

/************************************************
 * @Function: findStudentBaseInform
 * @Description: ����ѧ��������Ϣ,��������,�Ա�,����,ѧ��
 * @Input: None
 * @Output: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void findStudentBaseInform(void)
{
	char findInform[20];
	int i;
	printf("������Ҫ���ҵ�ѧ����������ѧ��: ");
	scanf("%s", findInform);
	for (i = 0; i < studentNum; i++)
	{
		if (strcmp(studentBaseInformation[i].name, findInform) == 0 ||
			strcmp(studentBaseInformation[i].number, findInform) == 0)
		{
			printf("\n����: %s\n", studentBaseInformation[i].name);
			printf("�Ա�: %s\n", studentBaseInformation[i].sex);
			printf("����: %s\n", studentBaseInformation[i].age);
			printf("ѧ��: %s\n\n", studentBaseInformation[i].number);
			break;
		}
	}
	if (i == studentNum)
		printf("\nδ�ҵ���ѧ��!\n\n");
}

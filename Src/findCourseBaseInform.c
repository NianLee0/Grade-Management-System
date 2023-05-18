//
// Created by NianLee on 2023/5/16.
//

#include "../Inc/findCourseBaseInform.h"

/************************************************
 * @Function: findCourseBaseInform
 * @Description: ���ҿγ̻�����Ϣ,�����κ�,����,ѧ��
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void findCourseBaseInform(void)
{
	char findInform[20];
	int i;
	printf("������Ҫ���ҵĿγ̵Ŀ�����κ�: ");
	scanf("%s", findInform);
	for (i = 0; i < courseNum; i++)
	{
		if (strcmp(courseBaseInformation[i].number, findInform) == 0 ||
			strcmp(courseBaseInformation[i].name, findInform) == 0)
		{
			printf("\n�κ�: %s\n", courseBaseInformation[i].number);
			printf("����: %s\n", courseBaseInformation[i].name);
			printf("ѧ��: %s\n\n", courseBaseInformation[i].credit);
			break;
		}
	}
	if (i == courseNum)
		printf("\nδ�ҵ��ÿγ�!\n\n");
}
//
// Created by NianLee on 2023/5/16.
//

#include "../Inc/findCourseBaseInform.h"

/************************************************
 * @Function: findCourseBaseInform
 * @Description: 查找课程基本信息,包括课号,课名,学分
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void findCourseBaseInform(void)
{
	char findInform[20];
	int i;
	printf("请输入要查找的课程的课名或课号: ");
	scanf("%s", findInform);
	for (i = 0; i < courseNum; i++)
	{
		if (strcmp(courseBaseInformation[i].number, findInform) == 0 ||
			strcmp(courseBaseInformation[i].name, findInform) == 0)
		{
			printf("\n课号: %s\n", courseBaseInformation[i].number);
			printf("课名: %s\n", courseBaseInformation[i].name);
			printf("学分: %s\n\n", courseBaseInformation[i].credit);
			break;
		}
	}
	if (i == courseNum)
		printf("\n未找到该课程!\n\n");
}
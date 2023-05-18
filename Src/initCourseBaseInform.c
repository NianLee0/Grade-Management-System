//
// Created by NianLee on 2023/5/16.
//

#include "../Inc/initCourseBaseInform.h"

/************************************************
 * @Function: loadCourseBaseInformFile
 * @Description: 打开需要的课程基本信息文件并进行数据初步处理
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void loadCourseBaseInformFile(void)
{
	char** temp;
	int dataNum = 0;
	int i = 0;
	int position;
	int ch;
	temp = (char**)malloc(sizeof(char*) * 100);
	FILE* fp = NULL;
	fp = fopen(courseBaseInformFilePath, "r+");
	fseek(fp, -1, SEEK_END);
	ch = fgetc(fp);
	fseek(fp, 0, SEEK_END);
	if (ch != '\r'&& ch != '\n')
		fputc('\n', fp);
	fseek(fp, 0, SEEK_END);
	int num = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	temp[0] = (char*)malloc(sizeof(char) * 100);
	for (int k = 0; k < num; k++)
	{
		fseek(fp, k, SEEK_SET);
		fread(&temp[dataNum][i++], sizeof(char), 1, fp);
		if (temp[dataNum][i - 1] == '\n')
		{
			position = ftell(fp);
			ch = fgetc(fp);
			fseek(fp, position, SEEK_SET);
			while (k + 1 < num && (ch == '\n' || ch == '\r'))
			{
				ch = fgetc(fp);
				k+=2;
			}
			temp[dataNum][i - 1] = '\0';
			i = 0;
			dataNum++;
			k++;
			temp[dataNum] = (char*)malloc(sizeof(char) * 100);
		}
	}
	initCourseBaseInform(temp, dataNum);
	free(temp);
	fclose(fp);
}

/************************************************
 * @Function: initCourseBaseInform
 * @Description: 初始化课程基本信息
 * @Input: token[]:数据块, num:数据块数量
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void initCourseBaseInform(char* temp[], int num)
{
	char* token[10];
	for (int i = 1; i < num; i++)
	{
		token[0] = strtok(temp[i], ",");
		for (int j = 0; j < 3; j++)
			token[j + 1] = strtok(NULL, ",");
		addCourseBaseInformFromFile(token);
	}
}

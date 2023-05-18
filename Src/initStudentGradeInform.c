//
// Created by NianLee on 2023/5/17.
//

#include "../Inc/initStudentGradeInform.h"

/************************************************
 * @Function: loadStudentGradeInformFile
 * @Description: ����Ҫ��ѧ���ɼ���Ϣ�ļ����������ݳ�������
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void loadStudentGradeInformFile(void)
{
	char** temp;
	int dataNum = 0;
	int i = 0;
	temp = (char**)malloc(sizeof(char*) * 100);
	FILE* fp = NULL;
	fp = fopen(studentGradeInformFilePath, "r");
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
			temp[dataNum][i - 1] = '\0';
			i = 0;
			dataNum++;
			k++;
			temp[dataNum] = (char*)malloc(sizeof(char) * 100);
		}
		//TODO: ��ȡ�ļ�ʱ������ļ����һ���ж�����з������������
	}
	initStudentGradeInform(temp, dataNum);
	free(temp);
	fclose(fp);
}

/************************************************
 * @Function: initStudentGradeInform
 * @Description: ��ʼ��ѧ���ɼ���Ϣ
 * @Input: token[]:���ݿ�, num:���ݿ�����
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void initStudentGradeInform(char* temp[], int num)
{
	char* token[10];
	for (int i = 1; i < num; i++)
	{
		token[0] = strtok(temp[i], ",");
		for (int j = 0; j < 4; j++)
			token[j + 1] = strtok(NULL, ",");
		addStudentGradeInformFromFile(token);
	}
}
//
// Created by NianLee on 2023/5/14.
//

#include "../Inc/init.h"

/************************************************
 * @Function: init
 * @Description: �����ʼ���������ļ�·�����ʹӸ����ļ��ж�ȡ��Ϣ��������ṹ����
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void init(void)
{
	pathTest();
	loadStudentBaseInformFile();
	loadCourseBaseInformFile();
	loadStudentGradeInformFile();
}

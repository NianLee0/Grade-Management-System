//
// Created by NianLee on 2023/5/14.
//

#include "../Inc/init.h"

/************************************************
 * @Function: init
 * @Description: 程序初始化，包括文件路径检测和从各个文件中读取信息并缓存入结构体中
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

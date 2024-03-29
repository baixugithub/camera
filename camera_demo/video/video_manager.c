
#include <config.h>
#include <video_manager.h>
#include <string.h>

static PT_VideoOpr g_ptVideoOprHead = NULL;

/**********************************************************************
 * 函数名称： RegisterVideoOpr
 * 功能描述： 注册"字体模块", 所谓字体模块就是取出字符位图的方法
 * 输入参数： ptVideoOpr - 一个结构体,内含"取出字符位图"的操作函数
 * 输出参数： 无
 * 返 回 值： 0 - 成功, 其他值 - 失败
 * 修改日期        版本号     	修改人	      					修改内容
 * ---------------------------------------------------------
 * 2019-8-4	   V1.0	  	Email：baixu1995@163.com	    创建
 ***********************************************************************/
int RegisterVideoOpr(PT_VideoOpr ptVideoOpr)
{
	PT_VideoOpr ptTmp;

	if (!g_ptVideoOprHead)
	{
		g_ptVideoOprHead   = ptVideoOpr;
		ptVideoOpr->ptNext = NULL;
	}
	else
	{
		ptTmp = g_ptVideoOprHead;
		while (ptTmp->ptNext)
		{
			ptTmp = ptTmp->ptNext;
		}
		ptTmp->ptNext     = ptVideoOpr;
		ptVideoOpr->ptNext = NULL;
	}

	return 0;
}


/**********************************************************************
 * 函数名称： ShowVideoOpr
 * 功能描述： 显示本程序能支持的"字体模块"
 * 输入参数： 无
 * 输出参数： 无
 * 返 回 值： 无
 * 修改日期        版本号     	修改人	      					修改内容
 * ---------------------------------------------------------
 * 2019-8-4	   V1.0	  	Email：baixu1995@163.com	    创建
 ***********************************************************************/
void ShowVideoOpr(void)
{
	int i = 0;
	PT_VideoOpr ptTmp = g_ptVideoOprHead;

	while (ptTmp)
	{
		printf("%02d %s\n", i++, ptTmp->name);
		ptTmp = ptTmp->ptNext;
	}
}

/**********************************************************************
 * 函数名称： GetVideoOpr
 * 功能描述： 根据名字取出指定的"字体模块"
 * 输入参数： pcName - 名字
 * 输出参数： 无
 * 返 回 值： NULL   - 失败,没有指定的模块, 
 *            非NULL - 字体模块的PT_VideoOpr结构体指针
 * 修改日期        版本号     	修改人	      					修改内容
 * ---------------------------------------------------------
 * 2019-8-4	   V1.0	  	Email：baixu1995@163.com	    创建
 ***********************************************************************/
PT_VideoOpr GetVideoOpr(char *pcName)
{
	PT_VideoOpr ptTmp = g_ptVideoOprHead;
	
	while (ptTmp)
	{
		if (strcmp(ptTmp->name, pcName) == 0)
		{
			return ptTmp;
		}
		ptTmp = ptTmp->ptNext;
	}
	return NULL;
}

int VideoDeviceInit(char *strDevName, PT_VideoDevice ptVideoDevice)
{
    int iError;
	PT_VideoOpr ptTmp = g_ptVideoOprHead;
	
	while (ptTmp)
	{
        iError = ptTmp->InitDevice(strDevName, ptVideoDevice);
        if (!iError)
        {
            return 0;
        }
		ptTmp = ptTmp->ptNext;
	}
    return -1;
}

/**********************************************************************
 * 函数名称： FontsInit
 * 功能描述： 调用各个字体模块的初始化函数
 * 输入参数： 无
 * 输出参数： 无
 * 返 回 值： 0 - 成功, 其他值 - 失败
 * 修改日期        版本号     	修改人	      					修改内容
 * ---------------------------------------------------------
 * 2019-8-4	   V1.0	  	Email：baixu1995@163.com	    创建
 ***********************************************************************/
int VideoInit(void)
{
	int iError;

    iError = V4l2Init();

	return iError;
}




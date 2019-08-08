
#ifndef _PIC_MANAGER_H
#define _PIC_MANAGER_H

#include <config.h>
#include <pic_operation.h>
#include <page_manager.h>
#include <file.h>

/**********************************************************************
 * �������ƣ� RegisterPicFileParser
 * ���������� ע��"ͼƬ�ļ�����ģ��", "ͼƬ�ļ�����ģ��"������ô��BMP/JPG��ͼƬ�ļ��н�������������
 * ��������� ptPicFileParser - һ���ṹ��,�ں�"ͼƬ�ļ�����ģ��"�Ĳ�������
 * ��������� ��
 * �� �� ֵ�� 0 - �ɹ�, ����ֵ - ʧ��
 * �޸�����        �汾��     	�޸���	      					�޸�����
 * ---------------------------------------------------------
 * 2019-8-4	   V1.0	  	Email��baixu1995@163.com	    ����
 ***********************************************************************/
int RegisterPicFileParser(PT_PicFileParser ptPicFileParser);

/**********************************************************************
 * �������ƣ� ShowPicFmts
 * ���������� ��ʾ��������֧�ֵ�"ͼƬ�ļ�����ģ��"
 * ��������� ��
 * ��������� ��
 * �� �� ֵ�� ��
 * �޸�����        �汾��     	�޸���	      					�޸�����
 * ---------------------------------------------------------
 * 2019-8-4	   V1.0	  	Email��baixu1995@163.com	    ����
 ***********************************************************************/
void ShowPicFmts(void);

/**********************************************************************
 * �������ƣ� PicFmtsInit
 * ���������� ���ø���"ͼƬ�ļ�����ģ��"�ĳ�ʼ������,����ע������
 * ��������� ��
 * ��������� ��
 * �� �� ֵ�� 0 - �ɹ�, ����ֵ - ʧ��
 * �޸�����        �汾��     	�޸���	      					�޸�����
 * ---------------------------------------------------------
 * 2019-8-4	   V1.0	  	Email��baixu1995@163.com	    ����
 ***********************************************************************/
int PicFmtsInit(void);

/**********************************************************************
 * �������ƣ� JPGParserInit
 * ���������� ע��"JPG�ļ�����ģ��"
 * ��������� ��
 * ��������� ��
 * �� �� ֵ�� 0 - �ɹ�, ����ֵ - ʧ��
 * �޸�����        �汾��     	�޸���	      					�޸�����
 * ---------------------------------------------------------
 * 2019-8-4	   V1.0	  	Email��baixu1995@163.com	    ����
 ***********************************************************************/
int JPGParserInit(void);

/**********************************************************************
 * �������ƣ� BMPParserInit
 * ���������� ע��"BMP�ļ�����ģ��"
 * ��������� ��
 * ��������� ��
 * �� �� ֵ�� 0 - �ɹ�, ����ֵ - ʧ��
 * �޸�����        �汾��     	�޸���	      					�޸�����
 * ---------------------------------------------------------
 * 2019-8-4	   V1.0	  	Email��baixu1995@163.com	    ����
 ***********************************************************************/
int BMPParserInit(void);

/**********************************************************************
 * �������ƣ� Parser
 * ���������� ��������ȡ��ָ����"ͼƬ�ļ�����ģ��"
 * ��������� pcName - ����
 * ��������� ��
 * �� �� ֵ�� NULL   - ʧ��,û��ָ����ģ��, 
 *            ��NULL - "ͼƬ�ļ�����ģ��"��PT_PicFileParser�ṹ��ָ��
 * �޸�����        �汾��     	�޸���	      					�޸�����
 * ---------------------------------------------------------
 * 2019-8-4	   V1.0	  	Email��baixu1995@163.com	    ����
 ***********************************************************************/
PT_PicFileParser Parser(char *pcName);

/**********************************************************************
 * �������ƣ� GetParser
 * ���������� �ҵ���֧��ָ���ļ���"ͼƬ�ļ�����ģ��"
 * ��������� ptFileMap - �ں��ļ���Ϣ
 * ��������� ��
 * �� �� ֵ�� NULL   - ʧ��,û��ָ����ģ��, 
 *            ��NULL - ֧�ָ��ļ���"ͼƬ�ļ�����ģ��"��PT_PicFileParser�ṹ��ָ��
 * �޸�����        �汾��     	�޸���	      					�޸�����
 * ---------------------------------------------------------
 * 2019-8-4	   V1.0	  	Email��baixu1995@163.com	    ����
 ***********************************************************************/
PT_PicFileParser GetParser(PT_FileMap ptFileMap);

#endif /* _PIC_MANAGER_H */

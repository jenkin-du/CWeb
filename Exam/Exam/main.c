#include"cgic.h"
#include<stdio.h>
#include<string.h>

int cgiMain(){
	char name[20]={0};
    char gender[5]={0};
    char ti1[256]={0};
    char ti2[256]={0};
    char ti3[256]={0};
    //MessageBoxA(0,"aa","aa",0);
    cgiHeaderContentType("text/html;charset=gbk");
    fprintf(cgiOut,"<html><head></head><body>");
 
    if(cgiFormString("name",name,sizeof(name))!=cgiFormSuccess)
    {
        fprintf(cgiOut,"����д������<br/>");
        return;
    }
    if(cgiFormString("gender",gender,sizeof(gender))!=cgiFormSuccess)
    {
        fprintf(cgiOut,"����д�Ա�<br/>");
        return;
    }
 
    if(cgiFormString("ti1",ti1,sizeof(ti1))!=cgiFormSuccess)
    {
        fprintf(cgiOut,"����д��һ��Ĵ𰸣�<br/>");
        return;
    }
 
    //�κ��о�����cgiFormStringMultiple����á���ѡ����
    if(cgiFormString("ti2",ti2,sizeof(ti2))!=cgiFormSuccess)
    {
        fprintf(cgiOut,"����д��2��Ĵ𰸣�<br/>");
        return;
    }
    if(cgiFormString("ti3",ti3,sizeof(ti3))!=cgiFormSuccess)
    {
        fprintf(cgiOut,"����д��3��Ĵ𰸣�<br/>");
        return;
    }
    if(strcmp(ti1,"a")==0)
    {
        fprintf(cgiOut,"��һ����ˣ����ǡ����ܷ롯<br/>");
    }
    else
    {
        fprintf(cgiOut,"��һ�����Ӧ���ǡ����ܷ롯<br/>");
    }
    if(strcmp(ti2,"d")==0)
    {
        fprintf(cgiOut,"��2����ˣ����Ǵ���רҵ��������<br/>");
    }
    else
    {
        fprintf(cgiOut,"��2�����Ӧ�������<br/>");
    }
    fprintf(cgiOut,strcmp(gender,"nan")==0?"˧��":"��Ů");
    fprintf(cgiOut,"��ã����������ǣ�%s",name);
    fprintf(cgiOut,"</body></html>");
	return 0;
}
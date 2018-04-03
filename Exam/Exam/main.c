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
        fprintf(cgiOut,"请填写姓名！<br/>");
        return;
    }
    if(cgiFormString("gender",gender,sizeof(gender))!=cgiFormSuccess)
    {
        fprintf(cgiOut,"请填写性别！<br/>");
        return;
    }
 
    if(cgiFormString("ti1",ti1,sizeof(ti1))!=cgiFormSuccess)
    {
        fprintf(cgiOut,"请填写第一题的答案！<br/>");
        return;
    }
 
    //课后研究：用cgiFormStringMultiple来获得“多选”。
    if(cgiFormString("ti2",ti2,sizeof(ti2))!=cgiFormSuccess)
    {
        fprintf(cgiOut,"请填写第2题的答案！<br/>");
        return;
    }
    if(cgiFormString("ti3",ti3,sizeof(ti3))!=cgiFormSuccess)
    {
        fprintf(cgiOut,"请填写第3题的答案！<br/>");
        return;
    }
    if(strcmp(ti1,"a")==0)
    {
        fprintf(cgiOut,"第一题对了：就是‘峰绍冯’<br/>");
    }
    else
    {
        fprintf(cgiOut,"第一题错误：应该是‘峰绍冯’<br/>");
    }
    if(strcmp(ti2,"d")==0)
    {
        fprintf(cgiOut,"第2题对了：就是代言专业户：刘翔<br/>");
    }
    else
    {
        fprintf(cgiOut,"第2题错误：应该是翔哥<br/>");
    }
    fprintf(cgiOut,strcmp(gender,"nan")==0?"帅哥":"美女");
    fprintf(cgiOut,"你好，您的姓名是：%s",name);
    fprintf(cgiOut,"</body></html>");
	return 0;
}
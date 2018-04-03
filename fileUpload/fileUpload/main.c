#include "cgic.h"
#include "ctemplate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void showWeb(TMPL_varlist *varlist){
	cgiHeaderContentType("text/html;charset=gbk");
	TMPL_write("upload.html",0,0,varlist,cgiOut,cgiOut);
}  

TMPL_varlist* addVar(TMPL_varlist* varlist,char *name,char *values){
	varlist=TMPL_add_var(varlist,name,values,0);
	return varlist;
}

int cgiMain(){
	TMPL_varlist *varlist=0;
	char uploadFileName[256]={0};
	char fileExt[10]={0};
	int fileSize=0;


	
	if (cgiFormSubmitClicked("sub")==cgiFormSuccess)
	{
		if(cgiFormFileName("upload",uploadFileName,sizeof(uploadFileName))
			!=cgiFormSuccess)
		{
			varlist=addVar(varlist,"msg","请选择一个文件");
			showWeb(varlist);
			return 0;
		}
		_splitpath(uploadFileName,NULL,NULL,NULL,fileExt);
		if (stricmp(fileExt,".png")!=0&&stricmp(fileExt,".zip")!=0
			&&stricmp(fileExt,".jpg")!=0&&stricmp(fileExt,".txt")!=0
			&&stricmp(fileExt,".doc")!=0&&stricmp(fileExt,".gif")!=0
			&&stricmp(fileExt,".MP3")!=0&&stricmp(fileExt,".MP4")!=0
			&&stricmp(fileExt,".docx")!=0)
		{
			varlist=addVar(varlist,"msg","上传文件类型错误！");
			showWeb(varlist);
			return 0;
		}
		/*cgiFormFileSize("upload",&fileSize);
		if (fileSize>1024*1024)
		{
			varlist=addVar(varlist,"msg","文件过大!");
			showWeb(varlist);
			return 0;

		}*/
		{
			cgiFilePtr upload;
			FILE *fileLocal=fopen(uploadFileName,"wb");
			char buffer[1024]={0};
			int length;
			cgiFormFileOpen("upload",&upload);
			while (cgiFormFileRead(upload,buffer,sizeof(buffer),&length)
				==cgiFormSuccess)
			{
				fwrite(buffer,length,1,fileLocal);
			}
			fclose(fileLocal);
			cgiFormFileClose(upload);
			varlist=addVar(varlist,"msg","上传成功！");
			showWeb(varlist);
		}
	}else
	{
		varlist=addVar(varlist,"msg","");
		showWeb(varlist);
		return 0;
	}
	return 0;
}


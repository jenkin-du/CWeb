#include <stdio.h>
#include <stdlib.h>
#include "cgic.h"
#include "ctemplate.h"


void showWeb(TMPL_varlist *varlist,char *filename){
	cgiHeaderContentType("text/html;charset=gbk");
	TMPL_write(filename,0,0,varlist,cgiOut,cgiOut);
}  

TMPL_varlist* addVar(TMPL_varlist* varlist,char *name,char *values){
	varlist=TMPL_add_var(varlist,name,values,0);
	return varlist;
}
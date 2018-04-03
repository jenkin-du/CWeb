#include <stdio.h>
#include <stdlib.h>
#include "cgic.h"
#include "ctemplate.h"

TMPL_varlist* cgiWriteStrToVar(TMPL_varlist * varlist,char *name,char *values){
	varlist = TMPL_add_var(varlist,name,values,0);
	return varlist;
}
#include "cgic.h"
#include "ctemplate.h"
#ifndef _CGI_H_
#define _CGI_H_

extern TMPL_varlist* addVar(TMPL_varlist* varlist,char *name,char *values);
extern void showWeb(TMPL_varlist *varlist,char *filename);

#endif

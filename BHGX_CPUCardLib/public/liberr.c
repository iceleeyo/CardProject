#include <stdio.h>
#include "liberr.h"
//#include "stdafx.h"


char *_err(int errcode)
{
	if(errcode < 0)
		errcode = -errcode;

	return errString[errcode];
}
/*
 ============================================================================
 Name        : decode.c
 Author      : Chaf0uin
 Version     :
 Copyright   : Your copyright notice
 Description : decode in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libdecode.h"
typedef enum { false = 0, true = 1 } bool;


int main(int argc, char *argv[])  {

	char * pcPosIn;
	char * pcPosOut;
	char acDeCode[255];
	int iIndex=0;
	int i;
	char acCode[255];

	bzero(acCode,255);
	printf("[2-9][p-z][a-h][2-9]keyword[p-z][2-9][p-z][2-9][p-z]\n");

	for(pcPosOut=acCode,iIndex=0;iIndex<argc-1;iIndex++)
	{
		iGet(argv[iIndex+1],&pcPosOut);
		iAddPad(&pcPosOut);
	}

	vAlpha2Num(acCode,acDeCode,strlen(acCode));


	printf("%s\n", acDeCode);
	return EXIT_SUCCESS;
}



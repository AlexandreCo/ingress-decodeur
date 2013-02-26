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
	char acCode[255];

	bzero(acCode,255);
	printf("[2-9][p-z][a-h][2-9]keyword[p-z][2-9][p-z][2-9][p-z]\n");
	printf("114 38 121 33 113 65 109 69 116 32 103 77 53\n");
	for(pcPosOut=acCode,iIndex=0;iIndex<argc-1;iIndex++)
	{
		iGet(argv[iIndex+1],&pcPosOut);
		iAddPad(&pcPosOut);
	}
	printf("%s\n", acCode);
	for(pcPosIn=acCode,pcPosOut=acDeCode,iIndex=0;pcPosIn;iIndex++)
	{
		if(!(iIndex%2))
		{
			iDecHex(pcPosIn,&pcPosOut);
		}
		else
		{
			iGet(pcPosIn,&pcPosOut);
		}
		iAddPad(&pcPosOut);
		iGetNewPos(&pcPosIn);
	}

	printf("%s\n", acDeCode);
	strcpy(acCode,acDeCode);
	bzero(acDeCode,255);

	for(pcPosIn=acCode,pcPosOut=acDeCode,iIndex=0;pcPosIn;iIndex++)
	{
		iHexAscii(pcPosIn,&pcPosOut);
		iAddPad(&pcPosOut);
		iGetNewPos(&pcPosIn);
	}

	printf("%s\n", acDeCode);
	return EXIT_SUCCESS;
}



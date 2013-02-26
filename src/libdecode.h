/*
 * libdecode.h
 *
 *  Created on: 26 févr. 2013
 *      Author: Chaf0uin
 */

#ifndef LIBDECODE_H_
#define LIBDECODE_H_

//#define PAD '\t'
#define PAD ' '
int iDecHex(char * acIn,char ** pacOut);
int iDecAscii(char * acIn,char ** pacOut);
int iHexAscii(char * acIn,char ** pacOut);
int iGet(char * acIn,char ** pacOut);
int iAddPad(char ** pacOut);
int iGetNewPos(char ** ppcPosIn);
#endif /* LIBDECODE_H_ */

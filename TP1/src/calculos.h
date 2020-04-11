/*
 * calculos.h
 *
 *  Created on: 11 abr. 2020
 *      Author: aleja
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

int getCalculos(int num1, int num2, int check, int* pResSuma, int* pResResta, int* pResMulti, float* pResDiv, int* chkDiv, double* pResFactA,double* pResFactB, int* chkFact);
int imprimeResultados(int num1,int num2,int check, int resSuma, int resResta, int resMulti, float resDiv, int chkResDiv, double resFactor1, double resFactor2,int chkResFact);
int menu(int ingresoA, int ingresoB, int check);


#endif /* CALCULOS_H_ */

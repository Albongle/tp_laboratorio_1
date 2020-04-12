/*
 * calculos.h
 *
 *  Created on: 11 abr. 2020
 *      Author: aleja
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

int getCalculos(float num1, float num2, int check, float* pResSuma, float* pResResta, float* pResMulti, float* pResDiv, int* chkDiv, double* pResFactA,double* pResFactB, int* chkFact);
int imprimeResultados(float num1,float num2,int check, float resSuma, float resResta, float resMulti, float resDiv, int chkResDiv, double resFactor1, double resFactor2,int chkResFact);
int menu(float ingresoA, float ingresoB, int check);


#endif /* CALCULOS_H_ */

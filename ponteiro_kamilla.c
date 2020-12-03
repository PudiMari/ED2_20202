/*
 * ponteiro_kamilla.c
 * 
 * Copyright 2020 Kamilla <kamilla@kamilla-Inspiron-5480>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int number = 10;
	int *np = &number;
		printf("Valor da variável number: %d\n",number);
		printf("Endereço da variável number: %p\n",&number);
		printf("Valor da variável np: %p\n",np);
		printf("Valor apontado por np: %d\n\n",*np);
		
		printf("Mudando o valor de number de forma indireta\n\n");
		*np = 15;
		printf("Valor da variável number: %d\n",number);
		
		np++;
		printf("Valor da variável np: %p\n", np);
		printf("Valor no endereço apontado: %d\n", *np);
		
		float *pi = (float *) malloc(sizeof(float));
		
		printf("Valor da variável pi: %p\n", pi);
		*pi=3.1415;
		printf("Valor no endereço apontado: %f\n", *pi);
		
		free(pi);
		printf("Valor da variável pi: %p\n", pi);
		printf("Valor no endereço apontado: %f\n", *pi);
		
		//Para não deixar rastro na memória
		pi = 0; 
		pi = NULL;
		
		
		int *numbers = (int *) malloc(sizeof(int) * 3);
		
		/*
		*  *(numbers+0) = 1;
		*  *(numbers+1) = 2;
		*  *(numbers+2) = 3;
		*/
		
		numbers[0] =1;
		numbers[1] =2;
		numbers[2] =3;
		
		for (int i = 0; i < 3; i++)
		 printf("numbers[%d] = %d\n",i,numbers[i]);
		 
		 
		for (int i = 0; i < 3; i++)
		printf("*(numbers+%d) = %d\n",i,*(numbers+i));
		
		int *aux = numbers;
		
		for (int i = 0; i < 3; i++) {
			printf("aux = %d\n",*aux);
			aux++;
		}
		
	return 0;
}


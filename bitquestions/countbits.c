/*
 * vim:expandtab:shiftwidth=8:tabstop=8:
 *
 * Copyright 2011
 * contributeur : Raghvendra Kumar Yadav (raghavmnnit@gmail.com) 
 *
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 * 
 * ---------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
//method 1 count set bits using loop for bit integer
void  countSetBitsLoop( number )
{
	int count = 0 ,loop ;
	for( loop = 0 ;loop < sizeof(int) * 8 ; loop++){
		if(number & 1)
			count++;
		number = number >> 1;
	}
       printf("number of set bits is %d \n",count);   
}
    //method 2 count set bits without using loop
void  countSetBitsWithoutLoop(number )
{
	number = ((number & 0xAAAAAAAA) >>1)  + (number & 0x55555555);
	number = ((number & 0xCCCCCCCC) >>2)  + (number & 0x33333333);
	number = ((number & 0xF0F0F0F0) >>4)  + (number & 0x0F0F0F0F);
	number = ((number & 0xFF00FF00) >>8)  + (number & 0x00FF00FF);
	printf("number of set bits is %d \n",number);

}

int main(int argc , char *argv[])
{
	unsigned int number;
	if( argc != 2 ){
		fprintf(stderr,"Usage:programe number");
		exit(1);
	}
	number = atoi(argv[1]);
	if(number < 0){
		fprintf(stderr,"enter a positive integer");
		exit(1);
	}
	//method 1 count set bits using loop
	countSetBitsLoop( number );
	//method 2 count set bits without using loop
	countSetBitsWithoutLoop(number );
	return 0;
}

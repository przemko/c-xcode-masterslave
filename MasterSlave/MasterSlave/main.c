//
//  main.c
//  MasterSlave
//
//  Created by Przemyslaw Kobylanski on 26.11.2013.
//  Copyright (c) 2013 Przemyslaw Kobylanski. All rights reserved.
//

#include <stdio.h>

#include "init.h"

int main()
{
    int n;
	
	do
	{
		printf("Ile utworzyć procesów Slave (od %d do %d): ",
               MINNUMOFSLAVES, MAXNUMOFSLAVES);
		scanf("%d", &n);
	} while(n < MINNUMOFSLAVES || n > MAXNUMOFSLAVES);
    
	Init(n);
	return 0;
}

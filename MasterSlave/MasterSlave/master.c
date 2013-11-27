//
//  master.c
//  MasterSlave
//
//  Created by Przemyslaw Kobylanski on 26.11.2013.
//  Copyright (c) 2013 Przemyslaw Kobylanski. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "master.h"
#include "init.h"
#include "semaphore.h"
#include "logger.h"

void Master(int n, char* shared_memory, int semaphore_id)
{
	print_log(MASTERLOGID, "rozpoczynam pracę");
	
	print_log(MASTERLOGID, "idę spać na 10 sekund");
	sleep(10); // kiedy proces śpi to nie upływa jego czas!
	
    print_log(MASTERLOGID, "czekam na semafor");
    binary_semaphore_wait(semaphore_id);
    print_log(MASTERLOGID, "zablokowałem semafor");
    
	print_log(MASTERLOGID, "piszę do wspólnej pamięci polecenie HALT");
	sprintf(shared_memory, "HALT");
	
    print_log(MASTERLOGID, "otwieram semafor");
    binary_semaphore_post(semaphore_id); // UWAGA: gdy Master kończy pracę i tak zostałby otwarty
    
	print_log(MASTERLOGID, "kończę pracę");
	exit(0);
}

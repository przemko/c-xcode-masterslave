//
//  slave.c
//  MasterSlave
//
//  Created by Przemyslaw Kobylanski on 26.11.2013.
//  Copyright (c) 2013 Przemyslaw Kobylanski. All rights reserved.
//

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "slave.h"
#include "init.h"
#include "semaphore.h"
#include "logger.h"

void Slave(int id, char* shared_memory, int semaphore_id)
{
    int ok;
    
	print_log(id, "rozpoczynam pracę");
	
    do {
        print_log(id, "idę spać na 1 sekundę");
        sleep(1);
        
        print_log(id, "czekam na semafor");
        binary_semaphore_wait(semaphore_id);
        print_log(id, "zablokowałem semafor");
        
        print_log(id, "czy we współdzielonej pamięci jest polecenie HALT?");
        ok = strcmp(shared_memory, "HALT") == 0;
        
        print_log(id, "otwieram semafor");
        binary_semaphore_post(semaphore_id);
    } while (!ok);
	
	print_log(id, "odczytałem ze wspólnej pamięci polecenie HALT");
	
	print_log(id, "kończę pracę");
	exit(0);
}

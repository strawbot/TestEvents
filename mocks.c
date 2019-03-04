#include "machines.h"
#include <stdio.h>

Long time = 0;
Long getTime(void) { return time; }
void addTime(Long n) { n /= ta_msecs(1); time+= n; }

void next (vector machine) { printf("\nnext: "); machine(); }
void later (vector machine) { printf("\nlater: "); machine(); }
char * getMachineName(Cell x) { (void)x; return "Bob"; }
void runMachines(void) { }

Long result = 0;
Long ret() { return result; }

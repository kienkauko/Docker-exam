/* localtime example */
#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
void INThandler(int);
int main (void)
{
signal(SIGINT, INThandler);
time_t rawtime;
struct tm * timeinfo;
while(1){
time ( &rawtime );
timeinfo = localtime ( &rawtime );
printf ( "Current local time and date: %s", asctime (timeinfo) );
sleep(1);
}
return 0;
}
void INThandler(int sig)
{
char c;
signal(sig, SIG_IGN);
printf("Do you want to quit? [y/n] ");
c = getchar();
if (c == 'y' || c == 'Y')
exit(0);
else
signal(SIGINT, INThandler);
getchar();
}
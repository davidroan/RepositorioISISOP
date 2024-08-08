#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
  char *p;
  char *q=NULL;
  printf("Address o p =%s\n",p);
  strcpy(p,"Hello,im the best in opeating system!!");
  printf("%s\n",p);
  printf("about to copy \"Goodbye"\"to q\n");
  strcpy(q,"goodbye");
  printf("String copied\n");
  printf("%s\n",q);
  return 0;
}
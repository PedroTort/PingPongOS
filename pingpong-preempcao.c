// PingPongOS - PingPong Operating System
// Prof. Carlos A. Maziero, DINF UFPR
// Versão 1.1 -- Julho de 2016

// Teste da preempção por tempo

#include <stdio.h>
#include <stdlib.h>
#include "ppos.h"

#define WORKLOAD 20000

task_t Pang, Peng, Ping, Pong, Pung ;

// simula um processamento pesado
int hardwork (int n)
{
   int i, j, soma ;

   soma = 0 ;
   for (i=0; i<n; i++)
      for (j=0; j<n; j++)
         soma += j ;
   return (soma) ;
}

// corpo das threads
void Body (void * arg)
{
   int i ;

   printf ("%s: inicio\n", (char *) arg) ;
   for (i=0; i<10; i++)
   {
      printf ("%s: %d\n", (char *) arg, i) ;
      hardwork (WORKLOAD) ;
   }
   printf ("%s: fim\n", (char *) arg) ;
   task_exit (0) ;
}

int main (int argc, char *argv[])
{
   printf ("main: inicio\n");

   ppos_init () ;
   
   task_create (&Pang, Body, "    Pang") ;
   task_set_eet(&Pang, 15);

   task_create (&Peng, Body, "        Peng") ;
   task_set_eet(&Peng, 15);
   task_create (&Ping, Body, "            Ping") ;
   task_set_eet(&Ping, 1);

   task_create (&Pong, Body, "                Pong") ;
   task_set_eet(&Pong, 15);
   
   task_create (&Pung, Body, "                    Pung") ;
   
   task_set_eet(&Pung, 15);
   hardwork(WORKLOAD);

   //task_yield();
   //task_join(&Pang);
   //task_join(&Peng);
   //task_join(&Ping);
   //task_join(&Pong);
   //task_join(&Pung);

   printf ("main: fim\n");
   exit (0);
}

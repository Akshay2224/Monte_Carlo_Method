#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#define SEED 35791246
void *fun1();
void *fun2();
int count=0;
int s=0;
pthread_mutex_t l;
int n;
int main()
{
 pthread_t t1,t2,t3,t4;
 pthread_mutex_init(&l,NULL);
 printf("-------------------------------------------------------------WELCOME-------------------------------------------------------------------------------------\n\n\n\n");
 printf("                                                                                                                                                 Made By- AKSHAY KHAN");
 printf("Enter the Iterations You want to check your values check:");
 scanf("%d",&n);
 pthread_create(&t1,NULL,&fun1,NULL);
 pthread_create(&t4,NULL,&fun1,NULL);
 pthread_create(&t3,NULL,&fun1,NULL);
 pthread_create(&t2,NULL,&fun2,NULL);
 pthread_join(t1,NULL);
 pthread_join(t4,NULL);
 pthread_join(t3,NULL);
 pthread_join(t2,NULL);
}
void *fun1()
{
  int i,k,sq=0;
  double x,y,z;
  pthread_mutex_lock(&l);
   count=0;
   s=0;
  srand(time(NULL));
  for(i=0;i<n;i++)
  {
   x=(double)(rand() % (n+1))/n;
   y=(double)(rand()%(n+1))/n;
   z=x*x+y*y;
   sleep(1);
   printf("The Random Number Generated are ::\n\n");
   printf("%g   %g  \n\n\n\n",x,y);
   if(z<=1)
   {
    count++;
   }
   s++;
  }
 pthread_mutex_unlock(&l);
}
void *fun2()
{
 pthread_mutex_lock(&l);
  double pi;
  pi=(double)(4*count)/s;
  printf("We got an estimated value of pi as %g \n",pi);
  printf("-------------------------------------------");
 pthread_mutex_unlock(&l);
}

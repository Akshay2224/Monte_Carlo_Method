#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#define SEED 35791246
void *fun1();
void *fun2();
int count=0;
pthread_mutex_t l;
int n;
int main()
{
 pthread_t t1,t2;
 pthread_mutex_init(&l,NULL);
 pthread_create(&t1,NULL,&fun1,NULL);
 pthread_create(&t2,NULL,&fun2,NULL);
 pthread_join(t1,NULL);
 pthread_join(t2,NULL);
 printf("The Number of the values are %d:",count);
}
void *fun1()
{
  int i,k;
  double x,y,z;
  pthread_mutex_lock(&l);
  printf("Enter the values you want to enter :");
  scanf("%d",&n);
  srand(SEED);
  for(i=0;i<n;i++)
  {
   x=(double)rand()/RAND_MAX;
   y=(double)rand()/RAND_MAX;
   z=x*x+y*y;
   if(z<=1)
   {
    count++;
   }
  }
 pthread_mutex_unlock(&l);
}
void *fun2()
{
 pthread_mutex_lock(&l);
  double pi;
  pi=(double)count/n*4;
  printf("# of trials= %d , estimate of pi is %g \n",n,pi);
 pthread_mutex_unlock(&l);
}
/*   double z;
   double pi;

   printf("Enter the number of iterations used to estimate pi: ");
   scanf("%d",&niter);

   /* initialize random numbers 
   srand(SEED);
   count=0;
   for ( i=0; i<niter; i++) {
      x = (double)rand()/RAND_MAX;
      y = (double)rand()/RAND_MAX;
      z = x*x+y*y;
      if (z<=1){ count++;}
      }
    printf("%d",count);
   pi=(double)count/niter*4;
   printf("# of trials= %d , estimate of pi is %g \n",niter,pi);*/

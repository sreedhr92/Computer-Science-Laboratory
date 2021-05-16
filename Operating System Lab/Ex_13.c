#include<pthread.h>
#include<stdio.h>
int average_,minimum_,maximum_,n;
void *average(void **param);
void *minimum(void **param);
void *maximum(void **param);
int main(int argc,char *argv[])
{
	pthread_t tid,tid1,tid2;
	pthread_attr_t attr,attr1,attr2;
	if(argc < 3)
	{
		fprintf(stderr,"usage:a.out<integer value>\n");
		return -1;
	}
	n=argc;
	/*get the default attributes*/
	pthread_attr_init(&attr);
	pthread_attr_init(&attr1);
	pthread_attr_init(&attr2);
	/*create the thread*/
	pthread_create(&tid,&attr,&average,argv);
	pthread_create(&tid1,&attr1,&minimum,argv);
	pthread_create(&tid2,&attr2,&maximum,argv);

	/*wait for the thread to exit*/
	pthread_join(tid,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);

	printf("Average=%d\n",average_);
	printf("Minimum=%d\n",minimum_);
	printf("Maximum=%d\n",maximum_);
}
void *average(void **param)
{
	int i;
	int sum=0;
	for(i=1;i<=n;i++)
	{
		sum+=atoi(param[i]);
	}
	average_=sum/(n-1);
	pthread_exit(0);
}
void *minimum(void **param)
{
	int i;
	minimum_=atoi(param[1]);
	for(i=1;i<=n;i++)
	{
		if(atoi(param[i]) < minimum_)
			minimum_=atoi(param[i]);
	}
	pthread_exit(0);
}
void *maximum(void **param)
{
	int i;
	maximum_=0;
	for(i=1;i<=n;i++)
	{
		if(atoi(param[i])>maximum_)
			maximum_=atoi(param[i]);
	}
	pthread_exit(0);
}
/*Output:
PS F:\Study\SSN\4thSem\OS> gcc threads.c -pthread -o a                        threads.c: In function 'main':
threads.c:22:28: warning: passing argument 3 of 'pthread_create' from incompatible pointer type [-Wincompatible-pointer-types]
  pthread_create(&tid,&attr,&average,argv);
                            ^
In file included from threads.c:1:0:
C:/TDM-GCC-64/x86_64-w64-mingw32/include/pthread.h:314:26: note: expected 'void * (*)(void *)' but argument is of type 'void * (*)(void **)'
 int       WINPTHREAD_API pthread_create(pthread_t *th, const pthread_attr_t *attr, void *(* func)(void *), void *arg);
                          ^
threads.c:23:30: warning: passing argument 3 of 'pthread_create' from incompatible pointer type [-Wincompatible-pointer-types]
  pthread_create(&tid1,&attr1,&minimum,argv);
                              ^
In file included from threads.c:1:0:
C:/TDM-GCC-64/x86_64-w64-mingw32/include/pthread.h:314:26: note: expected 'void * (*)(void *)' but argument is of type 'void * (*)(void **)'
 int       WINPTHREAD_API pthread_create(pthread_t *th, const pthread_attr_t *attr, void *(* func)(void *), void *arg);
                          ^
threads.c:24:30: warning: passing argument 3 of 'pthread_create' from incompatible pointer type [-Wincompatible-pointer-types]
  pthread_create(&tid2,&attr2,&maximum,argv);
                              ^
In file included from threads.c:1:0:
C:/TDM-GCC-64/x86_64-w64-mingw32/include/pthread.h:314:26: note: expected 'void * (*)(void *)' but argument is of type 'void * (*)(void **)'
 int       WINPTHREAD_API pthread_create(pthread_t *th, const pthread_attr_t *attr, void *(* func)(void *), void *arg);
                          ^
threads.c: In function 'average':
threads.c:41:8: warning: implicit declaration of function 'atoi' [-Wimplicit-function-declaration]
   sum+=atoi(param[i]);
        ^

//It shows some warning but displays the crt answers as well
PS F:\Study\SSN\4thSem\OS> ./a 90 81 78 95 79 72 85   
Average=82
Minimum=72
Maximum=95
PS F:\Study\SSN\4thSem\OS>*/
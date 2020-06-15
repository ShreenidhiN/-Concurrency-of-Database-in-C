#include <stdio.h>
#include <pthread.h>
#include "concurrent.h"
void *Thread2 (void *arg)
{
	int stock = 100, updated_stock = 0;	int num_products;
	char *product_name= "product1";
	printf ("%s\n", (char *)arg);
	concurrent_get_num_products(&num_products);
	concurrent_create_product(product_name);
	printf("\nproduct created T2 %s",product_name);
	concurrent_increment_stock(product_name, stock, &updated_stock);
	printf("\nT2 Stock inc stock:%d  updated stock %d",stock,updated_stock);
	concurrent_increment_stock(product_name, stock, &updated_stock);
	printf("\nT2 Stock inc stock:%d  updated stock %d",stock,updated_stock);
	concurrent_decrement_stock(product_name, stock, &updated_stock);
	printf("\nT2 Stock dec stock:%d  updated stock %d",stock,updated_stock);
	concurrent_get_stock(product_name, &stock);
	printf("\nT2 Stock inc stock:%d  updated stock %d",stock,updated_stock);
	pthread_exit (NULL);
}

void *Thread1 (void *arg)
{
	int stock = 100, updated_stock = 0;
	char *product_name= "product1";
	int num_products;

	printf ("%s\n", (char *)arg);
	concurrent_get_num_products(&num_products);
	concurrent_create_product(product_name);
	printf("\nproduct created T1 %s",product_name);
	concurrent_increment_stock(product_name, stock, &updated_stock);
	printf("\nT1 Stock inc stock:%d  updated stock %d",stock,updated_stock);
	concurrent_decrement_stock(product_name, stock, &updated_stock);
	printf("\nT1 Stock dec stock:%d  updated stock %d",stock,updated_stock);
	pthread_exit (NULL);
}

/*
#define MAX 3
int main()
{
	pthread_t th2;
	void *st1;

	concurrent_init();

	pthread_t th1;
	pthread_create (&th1, NULL, Thread1, "Thread 1");
	pthread_create (&th2, NULL, Thread2, "Thread 2");
	pthread_join (th1, NULL);
    pthread_join (th2, NULL);

    printf ("Thread return: %d\n", (int)((long)st1));
	concurrent_destroy();

    return 0;
}



/*	for (i=0;i<MAX;i++)
		pthread_create (&th1[i], NULL, Thread1, "Thread 1");
		pthread_create (&th2, NULL, Thread2, "Thread 2");
	for (i=0;i<MAX;i++)
		pthread_join (th1[i], (void **) &st1);
		pthread_join (th2, (void **) &st1);

*/




/*----------------------------
void *threadFuc(void *arg)
{
    int opt = 1;
    char *pname;
    int stock;


    while(opt!=0)
    {
        printf("ENTER :\n 1 TO ENTER PRODUCT\n 2 TO DELETE PRODUCT\n 3 TO GET STOCK\n 4 TO INCREMENT STOCK\n 5 TO DECREMENT STOCK\n 0 TO EXIT");
        scanf("%d",&opt);

        if(opt==1)
        {
            printf("Enter product name : ");
            scanf("%s",&pname);
            concurrent_create_product(pname);
            continue;
        }
        else if(opt==2)
        {
            printf("Enter product name : ");
            scanf("%s",&pname);
            concurrent_delete_product(pname);
            continue;
        }
        else if(opt==3)
        {
            int no_of_prod;
            printf("Enter product name : ");
            scanf("%s",&pname);
            concurrent_get_num_products(&no_of_prod);
            printf("/n The no. of products = %d",no_of_prod);
            continue;
        }
        else if(opt==4)
        {
            printf("Enter product name : ");
            scanf("%s",&pname);
            concurrent_increment_stock(pname,10,&stock);
            printf("The updated stock for %s = %d",&pname,stock);
            continue;
        }
        else if(opt==5)
        {
            printf("Enter product name : ");
            scanf("%s",&pname);
            concurrent_decrement_stock(pname,1,&stock);
            printf("The updated stock for %s = %d",&pname,stock);
            continue;
        }
        else if(opt==0)
        {
            exit(1);
        }

    }
    pthread_exit(NULL);
}

int main()
{
    printf("CONCURRENCY");

    concurrent_init();

    pthread_t th1;
    pthread_t th2;

    pthread_create(&th1,NULL,threadFuc,"Thread1");
    pthread_create(&th2,NULL,threadFuc,"Thread2");

    pthread_join(th1,NULL);
    pthread_join(th2,NULL);

    //concurrent_destroy();
    return 0;
}
*/

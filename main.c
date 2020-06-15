#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "concurrent.h"

/*int main()
{
    printf("CONCURRENCY");

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
    return 0;
}
*/

#include <stdio.h>
#include <pthread.h>
#include "sequential.h"


void example (void) {
	int stock = 100, updated_stock = 0;
	char *product_name= "product1";

	printf ("Executing sequential example \n");

	printf ("Creating product %s. \n", product_name);
	sequential_create_product(product_name);
	printf ("Created product %s. \n",product_name);

	printf ("Incrementing stock in %d units in product %s. \n",stock,product_name);
	sequential_increment_stock(product_name, stock, &updated_stock);
	printf ("Stock incremented in product %s, new stock: %d units. \n",product_name,updated_stock);

	printf ("Incrementing stock in %d units in product %s. \n",stock,product_name);
	sequential_increment_stock(product_name, stock, &updated_stock);
	printf ("Stock incremented in product %s, new stock: %d units. \n",product_name,updated_stock);

	printf ("Incrementing stock in %d units in product %s. \n",stock,product_name);
	sequential_increment_stock(product_name, stock, &updated_stock);
	printf ("Stock incremented in product %s, new stock: %d units. \n",product_name,updated_stock);

	printf ("Incrementing stock in %d units in product %s. \n",stock,product_name);
	sequential_increment_stock(product_name, stock, &updated_stock);
	printf ("Stock incremented in product %s, new stock: %d units. \n",product_name,updated_stock);

	printf ("Decrementing stock in %d units in product %s. \n",stock,product_name);
	sequential_decrement_stock(product_name, stock, &updated_stock);
	printf ("Decremented stock in product %s, new stock: %d units. \n",product_name,updated_stock);

	printf ("Obtaining stock from product %s. \n",product_name);
	sequential_get_stock(product_name, &stock);
	printf ("Stock obtained. The product %s has an stock of %d units. \n",product_name,stock);

	printf("Deleting product %s. \n", product_name);
	sequential_delete_product(product_name);
	printf("Deleted %s deleted. \n",product_name);

}
/*
int main(){

	sequential_init();

	example();

	sequential_destroy();

	return 0;
}
*/

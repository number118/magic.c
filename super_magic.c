/*...Магия квадратов.*/
	
#include <stdio.h>
#include <conio.h>
#define n 5
#include <stdlib.h>
#include <time.h>

int main (void) {
	
	int arr[n][n], i, j, sum_main = 0, sum;
	srand(time(NULL));
	
	//.Случайно заполняет первую строку

	while (1) {

	for ( i = 0, j = 0 ; j < n ; j++ ) {
		
			arr[i][j] = rand()%10; 
			sum_main += arr[i][j];
	}

	
	do {	//... Специальное заполнение строк от 2 до последней ...

	for ( i = 1 ; i < n ; i++ ) {
	
		sum = 0;
		for ( j = 0 ; j < n ; j++ ) {
			arr[i][j] = rand()%10;
			sum += arr[i][j];
		}
		
		if ( sum != sum_main ) break; 
	
	}
	
	} while ( sum != sum_main );	//...в идеале goto заполнение предыдущей строки, но...
		
	
	//.Проверяет столбцы

	for ( i = 0 ; i < n ; i++ ) {
	
		sum = 0;
		for ( j = 0 ; j < n ; j++ )		sum += arr[j][i];
		if ( sum != sum_main )	break;
		
	}
		
	if ( sum != sum_main )	continue;	//...goto заполнение первой строки матрицы...
	
	//.Проверяет главные диагонали

	sum = 0;
	
	for ( i = 0, j = 0 ; i < n ; i++, j++ )		sum += arr[i][j];
	
	if ( sum != sum_main ) continue;	//...goto заполнение первой строки матрицы...
	
	
	sum = 0;
	for ( i = 0, j = n - 1 ; i > -1 ; --i, --j )		sum += arr[i][j];
	
	if ( sum != sum_main )		continue;	//...goto заполнение первой строки матрицы...
	else break;
	
	}
	
	//.Вывод магии.
	
	for ( i = 0 ; i < n ; i++ ) {
		for ( j = 0 ; j < n ; j++ ) printf("%d ", arr[i][j]);
	printf("\n");
	//putchar('\n');
	}
	
	getch();
	return 0;
	
}



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int f1(long n){
	int k = 0;//0(1)
	for (int i = 0; i < n; i++){//0(n)
		for (int j = 0; j < n; j++){//0(n)
			k++;//0(1)
		}
	}
	return k;//0(n)
}

void f2(long n){
	int k = 0;//0(1)
	for (int i = 0; i < n; i++){//0(n)
		for (int j = 0; j < i; j++){//0(n)
			k++;//0(1)
		}
		for (int t = 0; t < 10000; t++){//0(1)
			k++;//0(1)
		}
	}
}//0(n^2)

void f3(long n){
	if (n > 0){
		f3(n / 2);
		f3(n / 2);
	}
}//o( n)

void f4(long n){
	if (n > 0){//o()
		f4(n / 2);//o(2)
		f4(n / 2);//o(2)
		f2(n);//o(n^2)
	}
}//o(n^log2^2)//o(n^2)

void f5(long n){
	int k = 0;//o(1)
	for (int i = 0; i < 10; i++){//o(n)
		int j = n;//o(1)
		while (j > 0){
			k++;//o(1)
			j = j / 2;//o(1)
		}
	}
}//o(log2 n)

void f6(long n){
	f2(n);//o(n^2)
	f3(n);//o( n )
	f5(n);//o(log2 n)
}//o(n^2)

void f7(long n){
	int k = 0;//o(1)
	for (int i = 0; i < f1(n); i++){//o(n^2)
		k++;//o(1)
	}
	for (int j = 0; j < n; j++){//o(n)
		k++;//o(1)
	}
}//o(n^3)

void main()
{
	int option;
	do
	 {
		long in = 0; //input for functions

		printf_s("enter a function number (1-7, 0 to quit): ");
		scanf_s("%d", &option);

		printf("Enter a value for n\n");
		scanf_s("%d", &in);
		clock_t start = clock();

		switch (option) {

			case 0:
				option = 0;
				break;
			case 1:
				f1(in);

				break;
			case 2:
				f2(in);
				break;
			case 3:
				f3(in);
				break;
			case 4:
				f4(in);
				break;
			case 5:
				f5(in);
				break;
			case 6:
				f6(in);
				break;
			case 7:
				f7(in);
				break;
		}
		clock_t diff = clock() - start;
		long msec = diff * 1000 / CLOCKS_PER_SEC;
		printf("Operation took %d milliseconds\n\n", msec);

	} while (option != 0);
}
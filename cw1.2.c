#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int transform_to_binary(int input, char* output);
int transform_to_hexadicimal(int input, char* output);
char digits(int num);
int main() {
	int input;/*store input*/
	char output_binary[32];/*store binary output*/
	char output_hexadecimal[32];/*store hexadecimal output*/
	int bnum,hnum; /*store the number of binary and hexadecimal output*/
	int binary, hexadecimal;/*store input seperately for calculate */
	scanf("%d", &input);
	binary = input;
	hexadecimal = input;
	/*store input*/
	bnum = transform_to_binary(binary, output_binary);
	printf("The decimal value %d is ", input);
	if (bnum != 0) {
		for (bnum = bnum - 1; bnum >= 0; bnum--) {/*reverse output the array*/
			printf("%c", output_binary[bnum]);
		}
	}
	else printf("0");
	printf(" in binary\n");
	/*output binary*/
	printf("The decimal value %d is ", input);
	hnum = transform_to_hexadicimal(hexadecimal, output_hexadecimal);
	if (hnum != 0) {
		for (hnum = hnum- 1; hnum >= 0; hnum--) {/*reverse output the array*/
			printf("%c", output_hexadecimal[hnum]);
		}
	}
	else printf("0");
	printf(" in hexadecimal");
	/*output hexadecimal*/
	return 0;
}

int transform_to_binary(int input,char* output) {
	int i=0;/*number of the output*/
	if (input >= 0) {
		while (input != 0) {
			*output = input % 2+48;
			input = input / 2;
			output++;
			i++;

		}
	}
	else {/*when input less than 0*/
		input = -1 * input;
		while (input != 0) {
			*output = input % 2+48;
			input = input / 2;
			output++;
			i++;

		}
		*output = '-';
		i++;

	}
	return i;
	
}//变量、方法的命名规范

int transform_to_hexadicimal(int input, char* output) {
	int i = 0;/*number of the output*/
	if (input >= 0) {
		while (input > 0) {
			*output = digits(input % 16);
			input = input / 16;
			output++;
			i++;
		}
		return i;
	}
	else {/*when input less than 0*/
		input = -1 * input;
		while (input > 0) {
			*output = digits(input % 16);
			input = input / 16;
			output++;
			i++;
		}
		*output = '-';
		i++;
		return i;
	}
}

char digits(int num) {/*a support function for ensuring the hexadecimal number */
	int i; int x=0;
	if (num < 10)
		return num+48;
	else {
		for (i = 10; ; i++) {
			if (i == num) {
				return 'A' + x;
			}
			else
				x++;
		}
	}
}
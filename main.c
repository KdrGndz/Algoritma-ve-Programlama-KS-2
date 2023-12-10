#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	FILE *input;  
	
	input = fopen("C:\\Users\\kdrgn\\OneDrive\\Masaüstü\\Algoritma Ödevi-2\\input.txt","r");
	
	FILE *encrypted;
	
	encrypted = fopen("C:\\Users\\kdrgn\\OneDrive\\Masaüstü\\Algoritma Ödevi-2\\encrypted.txt","a");
	
	int float_key;
		
	start_point:
	printf("Lutfen anahtar kaydirma degerini giriniz: ");
	if(scanf("%d",&float_key) != 1){
	printf("Sayi girmelisiniz!\n");
	fflush(stdin);
	goto start_point;
}
	
	char characters[50];
	int i = 0;		
	char character;

	while(character != EOF){
	
		character = getc(input);
		
		characters[i] = character;
		
		if (characters[i] == ' '){
			putc(' ',encrypted);	
			continue;
		}
		else if(characters[i] == '.'){
			putc('.',encrypted);
			continue;
		}
		
		//printf("%c",characters[i]);
		
		int ASCII_value = characters[i];
		
		if(ASCII_value == 10){
			putc('\n', encrypted);
			continue;
		}
		else if(ASCII_value > 65 && ASCII_value < 90){
			ASCII_value += float_key;
			if(ASCII_value > 97){
				ASCII_value -= 32;
				putc(ASCII_value, encrypted);
				i++;
				continue;
			}
		}
		
		ASCII_value += float_key; 
		
		if(ASCII_value > 122){
			ASCII_value -= 26;
		}
		else if(ASCII_value > 90 && ASCII_value < 97){
			ASCII_value  -= 26;
		}
		else if(ASCII_value < 65){
			continue;
		}
		//printf("%d\n",ASCII_value);
		
		putc(ASCII_value, encrypted);
		
		i++;
};

	
	
	
	
	
	return 0;
}

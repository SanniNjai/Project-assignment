

#include <stdio.h> 

void CeasarEncrypt(char* text, int key); //Fuction prototype for Ecryption
void CeasarDecrypt(char* text); // Fuction prototype for Decryption

int main()
{
 char text[100];//Defining characters array size for user input
 int key; //Assinging integer variable type for shifting
 int de; //Assinging interger variable type fro Encrypt or Decrypt option
 
 printf("Enter text: "); //Printing to ask user
 scanf("%s",text); //Getting user "string" input and storing at "text" variable
 
 printf("To Encrypt, enter '1' (or) To Decrypt, enter '2': ");//Asking option for En or De cryption
 scanf("%d", &de);
 
 while(de != 1 && de != 2){ // The loop if user's wrong input
 printf("\nInvalid input\nTo quit, enter '0' (or) To Encrypt, enter '1' (or) To decrypt, enter '2': ");
 scanf("%d", &de); 
 if (de == 0){ return 0;}
 }
 
 if (de == 1){
     printf("Enter shift: "); //Asking for shift
     scanf("%d", &key);
     CeasarEncrypt(text, key); //calling Encrypt function 
 }
 else if (de == 2){ 
     CeasarDecrypt(text); //calling Decrypt fuction
 }
    return 0;
}

// defining encrypt fuction
void CeasarEncrypt(char* text, int key){ 
int i;// counter
char c;// new character variable for equation
	for(i = 0; text[i] != '\0'; ++i){ // for loop as long as user do not put enter to end the string
		c = text[i]; //abbriviating
		
		if(c >= 'a' && c <= 'z'){ //setting condition for the string input between small letter a to z
		                      
			c =(( c - 97 + 26 ) - key ) %26 + 97 ;/* eg. input is 'a' and shift is 1: (97 - 97 + 26) = 26
			                                          26 - 1 = 25 ===> 25 % 26 = 25 ==> 25 + 97 = 122, which is z */                    
        
		}
		else if(c >= 'A' && c <= 'Z'){
		    c = (( c - 65 + 26) - key) % 26 + 65;
		
		}
		else if(c >= '0' && c <= '9'){
		    c = (( c - '0' + 10) - key ) %10 ;/* eg. 123 with 1 shift is ecrypted as ((1+10)-1)%10 = 0
		                                              ((2+10)-1)%10 = 1 and ((3+10)-1)%10 = 2*/
            text[i] = c + '0' ; 
		}	
		text[i] = c;	
	}
	printf("Encrypted message: %s", text);
}
	

void CeasarDecrypt(char* text){
int i, key;
int ask = 1;
char c;
 for (key = 1; ask != 0 && key < 26 ; key++){
	for(i = 0; text[i] != '\0'; ++i){
		c = text[i];
		
		if(c >= 'a' && c <= 'z'){         
			c = ((c + key)- 97) % 26 + 97;/*   a b c defghij k lmnopqrs t uvwxyz 
			                                   ^   ^         ^          ^
			                                -->z a b cdefghi j klmnopqr s tuvwxyz (1 shift decrypiton)*/
			
			
		}
		else if(c >= 'A' && c <= 'Z'){
		    c = ((c + key) - 65) % 26 + 65;
			
		}
		else if(c >= '0' && c <= '9'){
		    c = (c + key)% 10; /* 0123456789 if you put encrypted numbers 901 with 1 shift
		                          ^^^        it will be decrypted (9+1)%10 = 0, (0+1)%10 = 1, (1+1)%10 = 2
		                          9012345678  */      
		}	
		text[i] = c;	
	}
  printf("-%d shifted, decrypted message: %s",key, text);
  printf("\nTo Continue decrypting, enter 1 (or) To End, enter 0: ");
  scanf("%d", &ask);
 }	
}





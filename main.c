#include <stdio.h>
#include <string.h>

//Global char array
char upper_case[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char lower_case[26]="abcdefghijklmnopqrstuvwxyz";//lower case
char unique_key[26];//unique keys for encryption and decryption

void CeasarEncrypt(char* text, int key); //Fuction prototype for Ecryption
void CeasarDecrypt(char* text); // Fuction prototype for Decryption

void encryption(char* msg);// encrytion prototype
void decryption(char* msg);// decrytion prototype

int main() //main function
{
int key; //Assinging integer variable type for shifting
int de, opt; //Assinging interger variable type fro Encrypt or Decrypt option
char text[1000]; //Defining characters array size for user input or for the file

int opt1,
    opt2, //assinging option 1
    options; // assigning option 2
char msg[1000]; //defining array input size or file 
FILE *input1, *input2;// assinging file pointer

printf("Roational Cipher, Enter '1' (or) Substitution, Enter '2': ");
scanf("%d", &opt1);

while(opt1 != 1 && opt1 != 2){ // if user put other than 1 or 2 in the first attemp, the loop will start
 printf("\nInvalid input\nTo quit, enter '0' (or) Rotation Cipher, enter '1' (or) Substitution Cipher, enter '2': ");
 scanf("%d", &opt1); 
 if (opt1 == 0){ return 0;}// loop will end if input is '0'
 }
 
switch(opt1){
    case 1:printf("To Manually input '1' (or) to Read from the file '2': ");//Option for input
scanf("%d", &opt);

while(opt != 1  && opt != 2){ // if user put other than 1 or 2 in the first attemp, the loop will start
 printf("\nInvalid input\nTo quit, enter '0' (or) To Manually input, enter '1' (or) To Read from the file, enter '2': ");
 scanf("%d", &opt); 
 if (opt == 0){ return 0;}// loop will end if input is '0'
 }
 
 if (opt == 2){ //file will read if input is 2
     input1 = fopen("rotational.txt", "r"); //("file name", "read")
     if(input1 == NULL) { //if there is no file accessible, user's friendly error will show up and value returns to '0'
     perror("fopen()");
     return 0;
     }
     while(!feof(input1)){ //making sure system reads till the end of file
     fgets(text, 1000, input1);//getting("char variable", array size, file pointer)
     }
     fclose(input1);
 }
 else if (opt == 1){ 
 printf("Enter text: "); //Printing to ask user
 scanf("%s",text); //Getting user "string" input and storing at "text" variable
 }

 printf("To Encrypt, enter '1' (or) To Decrypt, enter '2': ");//Asking option for En or De cryption
 scanf("%d", &de);
 
 while(de != 1 && de != 2){ // The loop will start if user put other than 1 or 2
 printf("\nInvalid input\nTo quit, enter '0' (or) To Encrypt, enter '1' (or) To decrypt, enter '2': ");
 scanf("%d", &de); 
 if (de == 0){ return 0;}
 }
 
 if (de == 1){//if user put 1, encryption process will start
     printf("Enter shift: "); //Asking for shift
     scanf("%d", &key);
     CeasarEncrypt(text,key); //calling Encrypt function 
 }
 else if (de == 2){ // if user put 2,decryption process will start 
     CeasarDecrypt(text); //calling Decrypt fuction
 }
    break;
    case 2:printf("To Manually input '1' (or) to Read from the file '2': ");//Option for input
scanf("%d", &opt2); //getting option value

while(opt2 != 1 && opt2 != 2){ // if user put other than 1 or 2 in the first attemp, the loop will start
 printf("\nInvalid input\nTo quit, enter '0' (or) To Manually input, enter '1' (or) To Read from the file, enter '2': ");
 scanf("%d", &opt2); 
 if (opt2 == 0){ return 0;}// loop will end if input is '0'
 }
 if (opt2 == 1){ 
 printf("Enter text: "); //Printing to ask user
 scanf("%s",msg); //Getting user "string" input and storing at "text" variable
 }
 else if (opt2 == 2){ //file will read if input is 2
     input2 = fopen("sub.txt", "r"); //("file name", "read")
     if(input2 == NULL) { //if there is no file accessible, user's friendly error will show up and value returns to '0'
     perror("fopen()");
     return 0;
     }
     while(!feof(input2)){ //making sure system reads till the end of file
     fgets(msg, 1000, input2);//getting("char variable", array size, file pointer)
     }
     fclose(input2); // this make sure file closes after using
 }
 
printf("To Encrypt, enter '1' (or) To Decrypt, enter '2': ");//Asking option for En or De cryption
scanf("%d", &options);
 
while(options != 1 && options != 2){ // The loop if user's wrong input
  printf("\nInvalid input\nTo quit, enter '0' (or) To Encrypt, enter '1' (or) To decrypt, enter '2': ");
  scanf("%d", &options); 
    if (options == 0){ return 0;} //for input 0 to end the program
 }
 
switch(options){
    case 1:encryption(msg);//for input 1, it will call encrytion fucntion
           break;
    case 2:decryption(msg);// for input 2, it will call decryption function
           break;
}
    break;
}


    return 0; //ending the program
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
		else if(c >= 'A' && c <= 'Z'){// for upper case letter
		    c = (( c - 65 + 26) - key) % 26 + 65;
		
		}
		else if(c >= '0' && c <= '9'){//for numbers input
		    c = (( c - '0' + 10) - key ) %10 ;/* eg. 123 with 1 shift is ecrypted as ((1+10)-1)%10 = 0
		                                              ((2+10)-1)%10 = 1 and ((3+10)-1)%10 = 2*/
            text[i] = c + '0' ; 
		}	
		text[i] = c;//final value return to text variable	
	}
	printf("Encrypted message: %s", text);
}

	
//defining Decryption function
void CeasarDecrypt(char* text){
int i, key;   //counter
int ask = 1;  //variable for option to continue decrypting
char c;
 for (key = 0; ask != 0 && key < 26 ; key++){// for loop as long as user not put '0' or counter reaches 25
	for(i = 0; text[i] != '\0'; ++i){ //for loop until input reaches the end of file
		c = text[i]; // shorter form 
		
		if(c >= 'a' && c <= 'z'){ // lower_case letter decrypting   
			c = ((c + key)- 97) % 26 + 97;/*   a b c defghij k lmnopqrs t uvwxyz 
			                                   ^   ^         ^          ^
			                                -->z a b cdefghi j klmnopqr s tuvwxyz (1 shift decrypiton)*/
			
		}
		else if(c >= 'A' && c <= 'Z'){ //Upper_case letter decrypting
		    c = ((c + key) - 65) % 26 + 65;
			
		}
		else if(c >= '0' && c <= '9'){ //numbers decrypting
		    c = (c + key)% 10; /* 0123456789 if you put encrypted numbers 901 with 1 shift
		                          ^^^        it will be decrypted (9+1)%10 = 0, (0+1)%10 = 1, (1+1)%10 = 2
		                          9012345678  */      
		}	
		text[i] = c; //final value return to text variable	
	}
  printf("-%d shifted, decrypted message: %s",key, text); 
  printf("\nTo Continue decrypting, enter 1 (or) To End, enter 0: ");//user can determine how far decrypting will go
  scanf("%d", &ask);
 }	
}


//defining encrytion function
void encryption(char* msg){
int i, j; //counters
printf("Enter 26 unique key of character for encryption: ");
scanf("%s", unique_key); //getting unique keys for input

//This show the chart
printf("\nKey replaced as below\nABCDEFGHIJKLMNOPQRSTUVWXYZ\nabcdefghijklmnopqrstuvwxyz");
printf("\n||||||||||||||||||||||||||\n");
printf("%s\n",unique_key);


for(i = 0; i< strlen (msg); i++){// loop will run until the end of text input
    for(j = 0; j<26; j++){//loop will find the positions of unique key for plain text dring 26 counts
        if (lower_case[j] == msg[i]){ 
           msg[i] = unique_key[j]; // the value in the position of unique key will replace the value of input positon.
           break;//every time position of input text matches normal plain text postion, the count will start again
        }
        else if(upper_case[j] == msg[i]){//for upper case input letter detected
           msg[i] = unique_key[j];
           break;
        }
     }
  }
 printf("Encryted text is: %s", msg);// after getting the final value and print
}


//defining decryption function
void decryption(char* msg){
int i, j;//counters
printf("Enter 26 unique key of characters for decryption\naccording to upper or lower case of input text: ");
scanf("%s", unique_key);//getting unique:

  for (i = 0; i<strlen(msg);i++){// loop until end of input text
      for(j = 0; j<26; j++){// loop until positon of input matches position of unique keys
          if( unique_key[j] == msg[i]){// if condition matches,the position of unique key will pass to plain text position
              msg[i]=lower_case[j]; // then, value in the position of plain text will replace value in the position of output 
              break; // once the condition met counting will start agian
            }
        }
    }
printf("Decrypted text is: %s",msg); // the value of msg is printed
}







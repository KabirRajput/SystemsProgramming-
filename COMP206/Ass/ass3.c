#include <stdio.h>

int main()
{

        char msg[100];
        int key;

//user input
        printf("Enter message: \n");
        fgets(msg, 100, stdin);


//is key valid
do{
   printf("Enter key: ");
   scanf("%d", &key);
   if(key < 1 || key > 25){
         printf("Please enter key 1-25");
   }}while(key < 1 || key > 25);


        printf("Sentence: %s\n",msg);
        printf("Key: %d\n",key);
        printf("Original message: %s\n", msg);

//Encrypting
        int i=0;
        int letterNumber;
//LetterNumber- A/a=0 B/b=1.....converts to number

//if left shift is negative then right shift by (26-key)
        while(msg[i] !='\0') {
		letterNumber = -1;	
                if(msg[i] >=65 && msg[i] <=90)
                letterNumber= msg[i] - 'A';
                else if (msg[i] >=97 && msg[i] <= 122)
                letterNumber = msg[i] - 'a';
		if (letterNumber != -1){
                if (letterNumber - key < 0)
                msg[i] += (26 -key);
                else msg[i] -= key;
                }
                i++;
	}
        printf("Encrypted message: %s\n", msg);

//Decrypting
      int j=0;

 	while(msg[j] != '\0') {
		if(msg[j] >=65 && msg[j] <=90)
               msg[j] = ((msg[j] -'A' + key) % 26)+'A';
		else if (msg[j] >=97 && msg[j] <= 122)
		msg[j] = ((msg[j] -'a' + key) % 26)+'a';

               j++;
        }
	 printf("Decrypted message: %s\n", msg);
	
return 0;
}











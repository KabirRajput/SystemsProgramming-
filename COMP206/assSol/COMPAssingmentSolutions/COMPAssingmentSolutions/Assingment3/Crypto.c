#include <stdio.h>
#include <string.h>

#define INPUT_SIZE 100
#define NULL_CHAR '\0'
#define UPPER_A 'A'
#define UPPER_Z 'Z'
#define LOWER_a 'a'
#define LOWER_z 'z'

int main() {
  char input[INPUT_SIZE] = {NULL_CHAR};
  int key = 0;

  printf("Sentence: ");
  scanf("%[^\n]%*c", input);
  //fgets (input, sizeof(input), stdin);

  size_t length = strlen(input);
  char enc_letter[length + 1];
  char dec_letter[length + 1];

  printf("Key: ");
  scanf("%d", &key);
	while (key < 1 || key > 25) {
    printf("Please enter a key between 1 & 25: ");
		scanf("%d", &key);
	}

  for (size_t i = 0; i < length; i++) {
    if (input[i] >= UPPER_A && input[i] <= UPPER_Z) {
      /* it's an uppercase letter */
      enc_letter[i] = (((input[i] - UPPER_A) + (26 - key)) % 26) + UPPER_A;
      dec_letter[i] = (((enc_letter[i] - UPPER_A) + key) % 26) + UPPER_A;

    } else if (input[i] >= LOWER_a && input[i] <= LOWER_z) {
      enc_letter[i] = (((input[i] - LOWER_a) + (26 - key)) % 26) + LOWER_a;
      dec_letter[i] = (((enc_letter[i] - LOWER_a) + key) % 26) + LOWER_a;

    } else {
      printf("%d\n", input[i]);
	    enc_letter[i] = input[i];
      dec_letter[i] = input[i];
    }
  }
  enc_letter[length] = NULL_CHAR;
  dec_letter[length] = NULL_CHAR;

  printf("Original message: %s\n", input);
  printf("Encrypted message: %s\n", enc_letter);
  printf("Decrypted message: %s\n", dec_letter);
  return 0;
}

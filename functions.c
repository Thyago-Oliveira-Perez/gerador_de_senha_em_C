#include "functions.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define GENERATE_PASSWORD 1
#define PASSWORD_TYPE_SIMPLE 1
#define PASSWORD_TYPE_COMPLEX 2

char *generateSimplePassword(int password_length)
{
  char password[password_length];
  char caracteres[63] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                         'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'X', 'W', 'Y', 'Z',
                         '#', '@', '!', '$', '%', '&', '^', '?', '~', '+', '=',
                         'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                         'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'x', 'w', 'y', 'z'};

  for (int i = 0; i < password_length; i++)
  {
    password[i] = caracteres[rand() % 63];
  }

  printf("%s\n", password);
}

char *generateComplexPassword(int password_length, int word_length)
{
  char password[password_length + word_length];
  char caracteres[63] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                         'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'X', 'W', 'Y', 'Z',
                         '#', '@', '!', '$', '%', '&', '^', '?', '~', '+', '=',
                         'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                         'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'x', 'w', 'y', 'z'};

  for (int i = 0; i < password_length; i++)
  {
    password[i] = caracteres[rand() % 63];
  }

  printf("%s\n", password);

  printf("");
}

void newPassword()
{

  int password_length;
  int password_type;

  printf("Type the size of the password: ");
  scanf("%d", &password_length);

  printf("Wich kind of password do you want?\n");
  printf("1. Simple\n");
  printf("2. Complex\n");
  scanf("%d", &password_type);

  switch (password_type)
  {
  case PASSWORD_TYPE_SIMPLE:
    generateSimplePassword(password_length);
    break;

  case PASSWORD_TYPE_COMPLEX:

    int word_length;
    char *word;
    printf("Type a world to be used in the password: ");
    scanf("%s", &word);

    generateComplexPassword(password_length, strlen(word));
    break;
  default:
    break;
  }
}

void menu()
{
  int option_id;

  printf("Options:\n");
  printf("1. Generate password\n");
  printf("0. exit\n");

  scanf("%d", &option_id);

  if (option_id == GENERATE_PASSWORD)
  {
    newPassword();
  }

  getch();
}
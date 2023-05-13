#include "functions.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define GENERATE_PASSWORD 1

char *generatePassword(int password_length)
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

void newPassword()
{

  int password_length;

  printf("Type the size of the password: ");
  scanf("%d", &password_length);

  generatePassword(password_length);
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
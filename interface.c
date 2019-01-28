#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <windows.h>
#include <dos.h>
#include <time.h>
int main() {
FILE *us,*pw,*ques,*ans;
char name[20],passw[20],name1[20],passw1[20],name2[20],passw2[20],answ1[100],ques1[100],answ2[100];
int option,count=0;
printf(" \t\t\t#      #  ######  #       ######  ######  ###  ###  ######\n");
printf(" \t\t\t#      #  #       #       #       #    #  #  ##  #  #\n");
printf(" \t\t\t#      #  ######  #       #       #    #  #      #  ######\n");
printf(" \t\t\t#  ##  #  #       #       #       #    #  #      #  #\n");
printf(" \t\t\t##    ##  ######  ######  ######  ######  #      #  ######\n");

Sleep(500);

printf("\nEnter \n1.\tTo sign up\n2.\tTo sign in\n\n");
scanf("%d",&option );

Sleep(500);
if(option==1)
  {
    printf("\n|--------------------------------------------------------|\n");

    printf("|  SIGN UP                                               |\n");
    printf("|--------------------------------------------------------|\n");
    Sleep(500);
   us=fopen("username.txt","a");
    printf("\tEnter your username:\t");
    scanf("%s",name);

    fprintf(us, "%s\n", name);
    fclose(us);

    pw=fopen("password.txt","a");
    printf("\tEnter your password:\t" );
    scanf("%s",passw);
    fprintf(pw, "%s\n",passw );
    fclose(pw);
    Sleep(500);
    printf("|--------------------------------------------------------|\n");
    printf("| Signed up successfully  :)                             |\n" );
    printf("|--------------------------------------------------------|\n\n");
}

Sleep(2000);

    printf("\n\n|--------------------------------------------------------|\n");
    printf("| SIGN IN                                                |\n");
    printf("|--------------------------------------------------------|\n");
    Sleep(500);
printf("\tEnter username:\t");
scanf("%s",name1);
printf("\tEnter password:\t");
scanf("%s",passw1);
us=fopen("username.txt","r");
pw=fopen("password.txt","r");
while(!feof(us)&&!feof(pw))
{
fscanf(us,"%s",name2);
fscanf(pw,"%s",passw2);

if((strcmp(name1,name2)==0)&&(strcmp(passw1,passw2)==0))
{Sleep(500);
  printf("|--------------------------------------------------------|\n");
  printf("| Signed in successfully  :)                             |\n");
  printf("|--------------------------------------------------------|\n\n\n");
  goto label;
}
}
Sleep(500);
Beep(1000, 500);
printf("|--------------------------------------------------------|\n");
printf("| Incorrect username or password :(                      |\n");
printf("|--------------------------------------------------------|\n");

return 0;
exit(0);
label:  fclose(us);
        fclose(pw);
        Sleep(1000);
printf("\n\n|--------------------------------------------------------|\n");
printf("| Exam begins......!!!!!                                 |\n");
printf("| All the best ......!!!!!                               |\n");
printf("|--------------------------------------------------------|\n\n\n");
Sleep(1000);
ques=fopen("questions.txt","r");
ans=fopen("answers.txt","r");

while(!feof(ques) && !feof(ans))
{
  fscanf(ques,"%s",ques1);
  printf("\n%s\n",ques1 );
  fscanf(ques,"%s",ques1);
  printf("%s\n",ques1 );
  fscanf(ques,"%s",ques1);
  printf("%s\n",ques1 );

  printf("\nyour answer:\t");
  scanf("%s",answ1);
  fscanf(ans,"%s",answ2);
  if(strcmp(answ1,answ2)==0)
  {
    printf("your answer is right :)\n\n");
    count++;
  }
  else
  {
    Beep(1000, 500);
    printf("Your answer is wrong :( \n\n");

  }
}
  Sleep(2000);
printf(" ############################################################\n");
printf(" #                                                          #\n");
printf(" #                                                          #\n");
printf(" #\t YOUR SCORE IS %d                                    #\n",count);
printf(" #                                                          #\n");
printf(" #                                                          #\n");
printf(" ############################################################\n");

return 0;
}

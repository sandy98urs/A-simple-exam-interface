#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <windows.h>
#include <dos.h>
int main() {
FILE *us,*pw,*ques,*ans;
char name[20],passw[20],name1[20],passw1[20],name2[20],passw2[20],answ1[100],ques1[100],answ2[100];
int option,count=0;
printf("***********Welcome to online test***********\n\n ");
printf("Enter your option \n1.\tTosign up\n2.\tTosign in\n\n");
scanf("%d",&option );
Beep(750, 100);
if(option==1)
  {
    us=fopen("username.txt","a");
    printf("\nEnter your username\n");
    scanf("%s",name);
    fprintf(us, "%s\n", name);
    fclose(us);

    pw=fopen("password.txt","a");
    printf("Enter your password\n" );
    scanf("%s",passw);
    fprintf(pw, "%s\n",passw );
    fclose(pw);

    printf("Sign up successfull\n\n" );
  }

printf("\n\nSIGN IN\n");
printf("Enter username\n");
scanf("%s",name1);
printf("Enter password\n");
scanf("%s",passw1);

us=fopen("username.txt","r");
pw=fopen("password.txt","r");
while(!feof(us)&&!feof(pw))
{
fscanf(us,"%s",name2);
fscanf(pw,"%s",passw2);
if((strcmp(name1,name2)==0)&&(strcmp(passw1,passw2)==0))
{
  printf("\n\nSign in successfull\n");
  goto label;
}
}
printf("\n\nSign in un successfull\n");
return 0;
exit(0);
label:  fclose(us);
        fclose(pw);

printf("Exam begins\nAll the best\n\n");

ques=fopen("questions.txt","r");
ans=fopen("answers.txt","r");

while(!feof(ques) && !feof(ans))
{
  fscanf(ques,"%s",ques1);
  printf("%s\n",ques1 );
  printf("your answer:\n");
  scanf("%s",answ1);
  fscanf(ans,"%s",answ2);
  if(strcmp(answ1,answ2)==0)
  {
    printf("your answer is right\n\n");
    count++;
  }
  else
  {
    printf("Your answer is wrong\n\n");
  }
}
        fclose(us);
        fclose(pw);
return 0;
}

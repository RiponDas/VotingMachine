#include<stdio.h> //Including printf(),scanf()
#include<windows.h> //including Sleep()
#include<string.h>  //Including strcmp etc
#define MAX 20

void Password(void);
 void input(void);
 int user(void);
 void viewdata(void);
 void result(int n);
 void mainmenu(void);
 int t(void);
 void view(void);
 void del(void);
 void close(void);
 void help(void);

 struct candidate
 {
     char name[15];
     int vote;
 }
 can[MAX];

 FILE *f1;
 FILE *fp;


 int can_num;
 int id_range;
 int i,j;
 //int k;
 char ename[20];

 int main(void)
 {
     system("color 5a");
     Password();
     return 0;
 }


 void Password(void)
{

   system("cls");

   printf("             \xDB\xDB\xDB ELECTRONIC VOTING MACHINE \xDB\xDB\xDB\n\n");
   char d[25]="Password Protected";
   char ch,pass[10];
   char c,password[10]="csebu";
   int i=0,j;
    for(j=0;j<20;j++)
    {
    printf("*");
    Sleep(50);
    }
    for(j=0;j<20;j++)
   {
        Sleep(50);
   printf("%c",d[j]);
   }
   for(j=0;j<20;j++)
   {
        Sleep(50);
   printf("*");
   }
   printf("\nEnter Password:");
  while(ch!=13)
   {
    ch=getch();
    if(ch!=13 && ch!=8){
    putch('*');
    pass[i] = ch;
    i++;
    }
   }
   pass[i] = '\0';
   if(strcmp(password,pass)==0)
   {
       system("cls");
    printf("\n\nLOADING.....\n");
    for(j=0;j<60;j++)
   {
        Sleep(10);
   printf("\xB2");
   }
   system("cls");
   printf("\nPassword match");
    printf("\nPress any key to continue......");
    getch();
    mainmenu();
   }
   else
   {
     printf("\n\n\aWarning!! Incorrect Password");
     /*for(k=0;k<10;k++){
        printf("%c",pass[k]);
     }*/
     getch();
     Password();
   }
}


void mainmenu(void)
{
    system("cls");
    int n;
    char c;


    ///printf("\nPress any key to continue...");
    ///getch();
    printf("\n\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU");
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2 1. Input data");
    printf("\n\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2 2. User Window");
    printf("\n\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2 3. View result");
    printf("\n\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2 4. Delete data");
    printf("\n\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2 5. Edit Candidate's Record");
    printf("\n\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2 6. HELP");
    printf("\n\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2 7. View Election Info");
    printf("\n\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2 8. Close Application");
    printf("\n\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2 0. Quick Exit");
    printf("\n------------------------------------------\n");
    t();
    printf("Enter your choice:");
    scanf("%d",&n);
    c=getchar();

    if(isalpha(c))
    {
    printf("\n\nYou have pressed a alphabet\nPress any key to continue... \n");
    getch();

       mainmenu();
    }
    while(n!=0)
    {
    switch(n)
        {
    case 1:
      input();                  //Inputing info
        break;

    case 2:
    for(j=1;j<=id_range;j++){
       user();
       }
       system("cls");
       printf("\nEnter 1 for Main Menu:");
       scanf("%d",&c);
       if(c==1)
        Password();
       else
        user();
        break;
    case 3:
        view();              //Reading info from file
        break;
    case 4:
        del();                 //Delete the data file
        break;
    case 5:
        input();
        break;
    case 6:
        help();
        break;
    case 7:
        viewdata();
        break;
    case 8:
        close();
        break;

    default:

        printf("\n You have pressed wrong number. Please press ");
    break;

        }
        system("cls");
        printf("\n\nEnter 1 for Main Menu:");
        printf("\nEnter any key to Exit:");
    }
}


void input(void)
{
    int c;
    system("cls");
        printf("\nBefore using please visit HELP option.\n");
    printf("\nEnter 1 for HELP Option or press any to continue.....");
    if(getchar()=='1')
        help();
    else
        getch();
        system("cls");
        fp=fopen("input_file.txt","a");
        fprintf(fp,"............Election Record.............\n");
   printf("\n\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME ELECTION COMMISSION WINDOW");
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\nEnter the name of the election:");
    gets(ename);
   //gets(ename);
   fprintf(fp,"Name of the election: %s\n",ename);
   printf("\nNumber of Candidate:");
   scanf("%d",&can_num);
   fprintf(fp,"Number of Candidate: %d\t",can_num);
   printf("Number of Voter:");
   scanf("%d",&id_range);
   fprintf(fp,"Number of Voter: %d\n",id_range);

   printf("\nPress any key to continue...");
   getch();
   system("cls");
   printf("..........Welcome to %s",ename);
   printf("\n\nPlease input %d name or symbol of the candidate:\n",can_num);

   for(i=1;i<=can_num;i++){
    printf("\nName %d:",i);
    gets(can[i].name);
    gets(can[i].name);
   }
   fprintf(fp,"Candidate name or symbol:\n");
   for(i=1;i<=can_num;i++){
         fprintf(fp,"%d. %s\n",i,can[i].name);
         }
   printf("\nPress any key to Continue....");
   getch();
   system("cls");
   printf("\n\nEnter 1 for user's Window:\n");
   printf("Enter 2 for main menu:");
   scanf("%d",&c);
   if(c==2)
   {
       mainmenu();
   }
   else if(c==1)
   {
       for(j=1;j<=id_range;j++){
       user();
       }
       system("cls");
       printf("\nEnter 1 for Main Menu:");
       scanf("%d",&c);
       if(c==1)
        Password();
       else
        user();
   }
}


int user(void)
 {
     system("cls");
     int id,m;
     char c;
     static check;

     printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\n");
     printf("Welcome to %s",ename);
     printf("\n\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\n");
     t();
     printf("Voter: 0%d\n\n",j);

     printf("Input ID:\n");
        scanf("%d",&id);

        if(id>0 && id<=id_range)
        {
            if(id==check){
                   printf("Blocked");
                   getch();
                   user();
            }
        else{

     printf("\nApply your voting right....");
         for(i=1;i<=can_num;i++){

         printf("\nEnter %d for %s",i,can[i].name);
         }
         scanf("%d",&m);
         c=getchar();
    if(isalpha(c))
    {
    printf("\n\nYou have pressed a alphabet\nPlease chose your option again.... \n");
        return;
    }
        }
         check=id;
        }


    result(m);
}




void result(int n)
{
     FILE *f1;
     time_t t;
    for(i=1;i<=can_num;i++)
    {
        if(n==i){
            can[i].vote=can[i].vote+1;
        }
    }
    f1=fopen("Record.txt","a");
    fprintf(f1,"\n\n");
    fprintf(f1,"\t\tLast Update of %s is:\n",ename);
    time(&t);
    fprintf(f1,"\tTime:%s\n",ctime(&t));
    for(i=1;i<=can_num;i++)
    {


        fprintf(f1,"\tVote of %s is: %d",can[i].name,can[i].vote);

    }
    fclose(f1);

}

void view(void)
{
    int m;
    char c;
    system("cls");

    f1=fopen("Record.txt","r");

    if((c=getc(f1))==EOF)
    {
        printf("\n\nNo data found.Please enter a record first\n\n");
        getch();
    }
    while((c=getc(f1))!=EOF)
        printf("%c",c);
    fclose(f1);

    printf("\n\nEnter any key to continue....");
    getch();

    system("cls");
    printf("\nEnter 1 for main menu:");
    printf("\nEnter any Number to Exit:");

    scanf("%d",&m);
       if(m==1)
        mainmenu();
       else
        close();

   }

void del(void)
{
    system("cls");
    int m;
    char opt;
    printf("Welcome to %s \n\n",ename);
    printf("\n\aDo You want to erase the file?...(Y/N)?");
    scanf(" %c",&opt);
    if(toupper(opt)=='Y')
     {
    if(remove("Record.txt"))
    {
    printf("\nCan not erase file.\n ");
    return 0;
        }
    printf("\nErase file successfully.\n");
    }
     else
        printf("\n\nErasing canceled\n\n");

        printf("press any to continue........");
        getch();
        system("cls");
        printf("\nEnter 1 for main menu:");
    printf("\nEnter any Number to Exit:");

    scanf("%d",&m);
       if(m==1)
        mainmenu();
       else
        close();

}

int t(void)
{
    time_t t;
    time(&t);
    printf("Time & Date is:%s",ctime(&t));
}


void help(void)
{
    system("cls");
    system("color f0");
    int m;
    FILE *f1;
    char ch;
    f1=fopen("file.HLP","r");
    while((ch=getc(f1))!=EOF)
        printf("%c",ch);
    fclose(f1);
    printf("\n\nPress any to continue........");
    getch();
    system("cls");
     printf("\nEnter 1 for main menu:");
    printf("\nEnter any Number to Exit:");

    scanf("%d",&m);
       if(m==1)
        mainmenu();
       else
        close();

}


void close(void)
{
    printf("\a\nWaiting....");
    Sleep(1000);
    exit(0);
}

void viewdata(void)
{
    int m;
    char c;
    system("cls");

    fp=fopen("input_file.txt","r");

    if((c=getc(fp))==EOF)
    {
        printf("\n\nNo data found.Please enter a record first\n\n");
        getch();
    }
    while((c=getc(fp))!=EOF)
        printf("%c",c);
    fclose(fp);

    printf("\n\nEnter any key to continue....");
    getch();

    system("cls");
    printf("\nEnter 1 for main menu:");
    printf("\nEnter any Number to Exit:");

    scanf("%d",&m);
       if(m==1)
        mainmenu();
       else
        close();

   }

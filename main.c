#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
#include"function.h"
#define MAX 3
#include"functions.c"
#include"menu.c"
#include"file.c"

struct userlist{
    char name[50];
    char password[50];
};
int ulistsize;
struct userlist* user;
FILE *ulistfp;

void iuserlist(){

    ulistsize=10;
    user= (struct userlist*) calloc ( sizeof( struct userlist) , ulistsize);
    if ( (  ulistfp = fopen("userlist.dat","r")) == NULL ){
        printf("Cannot open file");
        _getch();
        exit(1);
    }
    char *s= (char*) calloc( sizeof(char),100);
    int index=0;

    while( ( fgets(s,100,ulistfp)) != NULL){
             if ( index >= ulistsize){
                ulistsize= ulistsize*2;
                user= (struct userlist*) realloc(user,sizeof ( struct userlist) * ulistsize);
            }

            strcpy(  user[index].name,strtoken(s,':')  );
            strcpy( user[index].password,rot13(strtoken(NULL,':')) );
            index++;
  }
    ulistsize=index;
    if  ( (user = (struct userlist*) realloc( user, sizeof ( struct userlist) * ulistsize)) == NULL)
        printf("Cannot allocate more space than %d",ulistsize);



    fclose(ulistfp);
}

void existingUser(){
    int attempt=0,index;
    system("cls");
    char * name =(char*)calloc( sizeof(char),50);
    do{
        if ( attempt > 0 ){
            if (attempt > 3){
                printf("you exceeds limits");
                exit(1);

            }
            printf(" username not found attemp %d try again ",attempt);
            }
        printf("\nEnter Your username here: ");
        gets(name);
        attempt++;
    }while( ( index = exist(name)) == -1);

    // Check for password                              `

    attempt=0;
    free(name);
    char * password= ( char *) calloc( sizeof( char),50);
    do {
        if ( attempt > 0){
            if (attempt > 3){
                printf("\nyou exceeds limits");
                exit(1);
            }
            printf("\nInvalid Password try again!");
        }
        printf("\nEnter your password: ");
        scanpass(password);
        fflush(stdin);
        attempt++;
    }while( strcmp(user[index].password,password) != 0);
	strcat(strcpy(userfile,".\\userfiles\\"),user[index].name);
    printf("\nWelcome %s",user[index].name);
    free(password);
    _getch();
    mainmenu();
}

void newUser(){
    system("cls");
    int attempt = 0;
    int len;
    char * name=(char*) calloc( sizeof(char),50);
    do{
        if ( attempt > 0)
            printf("username already exist try another name");
        printf("\nEnter Username: ");
        while( ( len=strlen ( fgets(name,50,stdin) )) <= 1 );
        name[len-1]='\0';
        attempt++;
    }while( exist( name ) != -1 );
    // set password of new user
    attempt=0;

    char * password= (char*)calloc( sizeof(char), 50);
    message();
    do {
        if ( attempt > 0){
            printf("\nPassword is too weak please try again. ");
            message();
        }

        printf("\nEnter password here");
        scanpass(password);
        attempt++;
        fflush(stdin);
    }while( !validPassword(password) );
    user= ( struct userlist*) realloc ( user, (ulistsize + 1 ) * sizeof( struct userlist));
    strcpy(user[ulistsize].name,name);
    strcpy(user[ulistsize].password,password);
    ulistsize++;
    // update and store it in the memory
    update();
	strcat(strcpy(userfile,".\\userfile\\"),name);
    mainmenu();

}

void message(){
	printf("\nPassword must contain the following chacters at least once ");
	printf("\nA lowercase letter");
	printf("\nA Uppercase letter");
	printf("\nA Numeric character");
	printf("\nA Special character");
	printf("\n It should not contain any white spaces:");
	printf("\n And length of password should be greater than 8 characters");
}
int exist(char *s){
    int flag=-1;
    int index;
    for ( index =0; index < ulistsize; index++){
        if ( strcmpi(s,user[index].name) == 0){
            flag=index;
            break;
        }
    }
    return flag;
}



void update(){
    int i,j;
    struct userlist temp;
    for ( i=0; i< ulistsize; i++){
        for ( j=i+1; j< ulistsize; j++){
            if ( strcmpi(user[i].name,user[j].name) > 0){
                temp= user[i];
                user[i]=user[j];
                user[j]=temp;
            }
        }
    }




    // update it in the file
    if ( ( ulistfp = fopen("userlist.dat","w")) == NULL){
        printf("Cannot open file userlist.dat");
        exit(1);
    }
    char name[100];
    for ( i=0; i< ulistsize; i++){
            fputs( strcat( strcat( strcpy(name,user[i].name),":"),rot13(user[i].password)),ulistfp);
            fputs("\n",ulistfp);

    }
    fclose(ulistfp);

}


int main()
{
    iuserlist();
    userfile=(char*)calloc(sizeof(char),50);
    system("cls");
    int choice;
    printf("1. New User :");
    printf("\n2. Existing User");
    printf("\nPress any other key to exit");
    printf("\nEnter your choice");
    scanf("%d",&choice);
    fflush(stdin);
    switch( choice){
         case 1: newUser();
                break;
         case 2: existingUser();
                break;
         default: printf("taking exit");
         exit(1);
         }
    return 0;
}

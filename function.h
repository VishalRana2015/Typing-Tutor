#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
char * userfile;
char* lessonName;
void mainmenu();
char* scanpass(char*);
int submenu(int);
int chooseLevel();
int Test();
int dopractice(char*);
int taketest(char*);
int introduce(char*);
int report();
int validPassword(const char*);
char * strcatn( char * , int );
char * strnword( char *, char ,int);
char * strtoken( char * , char );
void iuserlist();
void existingUser();
void newUser();
void message();
int exist(char*);
void update();
#endif // FUNCTION_H_INCLUDED

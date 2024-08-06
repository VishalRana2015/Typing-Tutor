

void mainmenu(){
    printf("in main menu");
    int returnstat=0,choice;
    do{
        system("cls");
        printf("1. Choose Lesson\n");
        printf("2. Test\n");
	printf("3. View Report\n");
        printf(" Press any other key to take exit\n");
        char s[10];
        scanf("%s",s);
        if ( choice = atoi(s));
        else
            choice=-1;
        fflush(stdin);
        switch( choice){
            case 1: returnstat= chooseLevel();
                    break;
            case 2: returnstat=Test();
                    break;
            case 3: returnstat=report();
		    break;
            default: returnstat=0;
            }

    }while( returnstat);
    exit(1);
}

int chooseLevel(){
    int returnstat=0;

    int choice;
    do{
        system("cls");
        printf("1.THE HOME ROW\n");
        printf("2. KEYS E AND I\n");
        printf("3.KEYS R AND U\n");
        printf("4.KEYS T AND O\n");
        printf("5. CAPITAL LETTERS AND PERIOD\n");
        printf("6.KEY C AND COMMA\n");
        printf("7. KEYS G,H AND APOSTROPHE\n");
        printf("8.KEYS V, N AND QUESTION MARK\n");
        printf("9.KEYS W AND M\n");
        printf("10.KEYS Q AND P\n");
        printf("11.KEYS B AND Y\n");
        printf("12.KEYS Z AND X\n");
        printf("press any other key to go back\n");
        char s[10];
        scanf("%s",s);
        if ( choice=atoi(s));
        else
            choice=-1;


        fflush(stdin);
        if ( choice >= 1 && choice <= 12){
                returnstat=submenu(choice);
        }
        else
            returnstat=0;
    }while(returnstat);

        return 1;

}

int submenu(int i){
    lessonName=(char*)calloc(sizeof(char),20);
    switch(i){
        case 1: strcpy(lessonName,"HOME ROW KEY");
                break;
        case 2: strcpy(lessonName,"KEYS E AND I");
                break;
        case 3: strcpy(lessonName,"KEYS R AND U");
                break;
        case 4: strcpy(lessonName,"KEYS T AND O");
                break;
        case 5: strcpy(lessonName,"CAPITAL LETTER,.");
                break;
        case 6: strcpy(lessonName,"KEYS C AND ,");
                break;
        case 7: strcpy(lessonName,"KEYS G,H AND '");
                break;
        case 8: strcpy(lessonName,"KEYS V,N AND ?");
                break;
        case 9: strcpy(lessonName,"KEYS W AND M");
                break;
        case 10:strcpy(lessonName,"KEYS Q AND D");
                break;
        case 11:strcpy(lessonName,"KEYS B AND Y");
                break;
        case 12:strcpy(lessonName,"KEYS Z AND X");
                break;

    }
    char* intro= ( char*) calloc( sizeof(char),50);
    char* lesson=(char*)calloc( sizeof(char),50);
    char* test= ( char*) calloc(sizeof(char),50);
    int returnstat=0;
    int choice;

    strcat(strcatn(strcpy(intro,".\\files\\intro\\intro"),i),".txt");
    strcat(strcatn(strcpy(test,".\\files\\test\\test"),i),".txt");
    strcat(strcatn(strcpy(lesson,".\\files\\lessons\\practice"),i),".txt");
    do{
        system("cls");
        printf("1. Introduce\n");
        printf("2. Practice\n");
        printf("3. Test\n");
        printf("Press any other key to take exit");
        char s[10];
        scanf("%s",s);
        if ( ( choice = atoi(s)));
        else
            choice=-1;
        fflush(stdin);
        switch(choice){
            case 1: returnstat=introduce(intro);
                    break;
            case 2: returnstat=dopractice(lesson);
                    break;
            case 3: returnstat=taketest(test);
                    break;
            default: 
                        returnstat=0;
            }

    }while(returnstat);
    free(intro);
    free(lesson);
    free(test);
    free(lessonName);
    return 1; // successfully returning of the function
}

int Test(){
    char *test;
    lessonName=(char*)calloc(sizeof(char),25);
    test=(char*)calloc(sizeof(char),50);
    system("cls");
    printf("1. Abraham Lincoln\n");
    printf("2. Hubble Space Telescope\n");
    int choice;
    char s[10];
    scanf("%s",s);
    if ( choice=atoi(s));
    else
        choice=-1;
    fflush(stdin);
    switch(choice){
        case 1: strcpy(test,".\\files\\grandTest\\test1.txt");
                strcpy(lessonName,"ABRAHAM LINCOLN");
                taketest(test);
                break;
        case 2: strcpy(test,".\\files\\grandTest\\test2.txt");
                strcpy(lessonName,"HST");
                taketest(test);
                break;
        default: free(test);
        }
        free(lessonName);
    return 1;
}

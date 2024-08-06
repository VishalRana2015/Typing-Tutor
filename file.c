
int dopractice(char* lesson){
		FILE * lessonfp;
	if ( ( lessonfp = fopen(lesson,"r")) == NULL ){
		printf("Cannot open file");
		exit(1);
	}
	int pos=0,i,length;
	char ch;

	char *pointer;
	char s[100]={};

	while( fgets(s,100,lessonfp) != NULL){
		length = strlen(s);
		pointer = (char*) calloc(sizeof(char),length+1);
		pos=0;

		while( pos < length){
			system("cls");
			for ( i=0; i < length; i++){
				if( i == pos)
					pointer[i]=31;
				else
					pointer[i]=32;
			}

			printf("%s\n",pointer);
			printf("%s",s);
			ch=_getch();
			if ( s[pos] == 10 || s[pos] == 13){
				if ( ch == 13 || ch == 10)
					pos++;
				else
					printf("\a");
			}
			else if( ch == s[pos] )
				pos++;
			else
				printf("\a");
		}
	       free(pointer);
	}
	fclose(lessonfp);
	printf("\nWell DONE");
	return 0;

}

int taketest(char * test){
	FILE *testfp;
	time_t t1,t2;
	if ( ( testfp =fopen( test,"r") ) == NULL ){
		printf("Cannot open file");
		exit(1);
	}
	char *fs[MAX];
	char *us[MAX];
	int completed=0; // 0 means not completed
	char *csu;
	char *csf;
	int i,j,total=0,wrong=0,k,missed=0;
	printf("Press any key to start");
	_getch();
    time(&t1);
	while( !completed){
		system("cls");
		i=0;
		while( i < MAX ){
			fs[i]=(char*) calloc( sizeof(char),200);
			if ( fgets(fs[i],200,testfp) != NULL){}
			else{
				completed=1;
				break;
			}
			i++;
		}

		for ( j=0; j<i; j++)
			printf("%s", fs[j]);

		printf("\n\nEnter text here: \n");
		j=0;
		while( j<i){
			us[j]=(char*)calloc(sizeof(char),200);
			fgets(us[j],200,stdin);
			j++;
		}
		printf("Succesffuly entered");

		for ( j=0; j< i; j++){
			csf=strnword(fs[j],32,0);
			csu=strnword(us[j],32,0);
			k=0;
			while( csu != NULL || csf != NULL){
				k++;
				if ( csf != NULL && csu != NULL){
					total++;
					if ( strcmp(csf,csu))
						wrong++;
				}
				else{
					if ( csf != NULL){
						total++;
						missed++;
					}
					else{
						wrong++;
					}
				}
				free(csu);
				free(csf);
				csu=strnword(us[j],32,k);
				csf= strnword(fs[j],32,k);
			}
		}
	}
	time(&t2);
	int dur = t2-t1;
	float acc= (float)((total-missed-wrong)*100)/total;
	int grs= ( (total-missed)*60)/dur;
	int nes= ( (total -missed -wrong)*60)/dur;
	fclose(testfp);
	printf(" total = %d and wrong = %d and missed = %d " ,total ,wrong,missed);
	printf("\nAccuracy = %f \nGross Speed = %dwpm \nNet Speed= %dwpm",acc,grs,nes);
	// save it in the userfile
    
    FILE *userfp;
    if ( (userfp = fopen(userfile,"ab")) == NULL){
        printf("cannot open file");
        exit(1);
    }
   
  
    _getch();
    int l=strlen(lessonName);
    fwrite(&t1,sizeof(time_t),1,userfp);
    fwrite(&acc,sizeof(float),1,userfp);
    fwrite(&grs,sizeof(int),1,userfp);
    fwrite(&nes,sizeof(int),1,userfp);
    fwrite(&l,sizeof(int),1,userfp);
    fwrite(lessonName,(l+1)*sizeof(char),1,userfp);

    fclose(userfp);
	_getch();
	return 1;
}

int introduce(char * intro){
    char *s =(char*)calloc( sizeof(char),200);
    FILE * introfp;
    if ( ( introfp= fopen(intro,"r")) == NULL){
        printf("Cannot open file");
        exit(1);
    }
    while( fgets( s, 150, introfp) != NULL){
        printf("%s",s);
    }
    printf("\n Press any key to go back");
    _getch();
    free(s);
    return 1;
}

int report(){
	FILE *userfp;
	
	if ( ( userfp= fopen(userfile,"rb") ) == NULL){
		printf("You didn't appeared in any test\nNo Report to show.");
		_getch();
		return 1;
	}
	system("cls");
	time_t time;
	float acc;
	int grs,nes,l;
	struct tm *t;
	char lessonName[25];
	printf("%25s %10s%8s%8s%20s\n","Date","Accuracy","Gross","Net","Lesson Name");
	printf("%44s%8s\n\n","Speed","Speed");
	while( !feof(userfp)){
		fread(&time,sizeof(time_t),1,userfp);
		fread(&acc,sizeof(float),1,userfp);
		fread(&grs,sizeof(int),1,userfp);
		fread(&nes,sizeof(int),1,userfp);
		fread(&l,sizeof(int),1,userfp);
		fread(lessonName,(l+1)*sizeof(char),1,userfp);
		t=localtime(&time);
		char *s=asctime(t);
		s[strlen(s)-1]='\0';
		printf("%25s %7.2f%8d%8d%25s\n",s,acc,grs,nes,lessonName);
		
	}
	getch();
	fclose(userfp);
	return 1;
}

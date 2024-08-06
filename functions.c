int validPassword ( const char* s){
	int flag=0,i;

	int lc=0,uc=0,n=0,sp=0,length =0;

	for ( i=0; s[i]!='\0'; i++){
		if( (s[i] >= 65 && s[i] <= 90) || ( s[i] >=97 && s[i] <=122) || (s[i]>=48 && s[i]<=57)){
			if( s[i] >= 65 && s[i] <= 90)
				uc++;
			else if( s[i] >= 90 && s[i] <= 122)
				lc++;
			else
				n++;
		}
		else
			sp++;
		length++;
	}

	if( sp >0 && lc > 0 && n>0 && uc>0 && length>8)
		flag =1;
	else
		flag =0;
	return flag;
}


char *strcatn(char *s,int n){
    int length= strlen(s);
    int rev=0,rem=0;
    while( n != 0){
        rem = n%10;
        rev= rev *10 + rem;
        n= n/10;
    }

    while( rev != 0 ){
        rem = rev % 10;
        s[length++]= rem + 48;
        rev=rev/10;
    }
    s[length]='\0';
    return s;
}

char * strnword( char *s, char del, int n){ // gives nth word from the given string
	char *rstr;
        rstr=( char *) calloc ( sizeof(char) , 100);
	int precharflag=1;
	int index=0, i, wordcount=-1;

	for ( i=0; s[i] != '\0' && s[i] != '\n' ; i++){

		if ( s[i] == 32){
			precharflag=1;
		}
		else{
			if ( precharflag == 1){
				precharflag=0;
				wordcount++;
			}
			if ( wordcount == n){

				rstr[index++]=s[i];

			}
		}
	}
	rstr[index]='\0';


	int length = strlen( rstr);
	if ( length > 0)
		return rstr;
	else
		return NULL;
}

char * strtoken( char * s1, char del){
	static int pos =0;
	static char *str ;
	if ( s1 != NULL){
		str= s1;
		pos=0;
	}
	int index=0;
	char * rstr = (char *)calloc( sizeof(char ), 100);

	for(; str[pos] != '\0' && str[pos] != '\n' ;pos++){
		if ( (str[pos] == del) && (index == 0) )
			continue;

		if ( str[pos] == del){
			rstr[index]='\0';
			break;
		}
		rstr[index++]=str[pos];
	}
	rstr[index]='\0';
	if ( !strlen ( rstr)  )
		return NULL;
	else
		return rstr;

}

char * scanpass(char *s){
	int index=0;
	char ch;
	while( ( ch = _getch()) != 10 && ( ch != 13)){
		if ( ch == 8){
			if( index >0)
			     s[index--]='\0';
		}
		else
			s[index++]=ch;
	}
	s[index]='\0';
	return s;
}
char * rot13(char* s){

	int i=0;
	for(i=0; s[i] != '\0'; i++){
		if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')){
			if((s[i]>='A' && s[i]<='M') || (s[i]>='a' && s[i]<='m'))
				s[i]=s[i]+13;
			else
				s[i]=s[i]-13;
		}
	}
	return s;
}
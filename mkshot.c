
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>  //define getcwd
#include <time.h>
// #include "../lib/libtime.c"
// 




#include <time.h>
char *strtimenow()
{
      long t;
      struct tm *ltime;
      time(&t);
      ltime=localtime(&t);
      char charo[50];  int fooi ; 
      fooi = snprintf( charo, 50 , "%02d:%02d:%02d",
       ltime->tm_hour, ltime->tm_min, ltime->tm_sec 
	);

    size_t siz = sizeof charo ; 
    char *r = malloc( sizeof charo );
    return r ? memcpy(r, charo, siz ) : NULL;
}




///////////////////////////////
///////////////////////////////
///////////////////////////////
char *strtimestamp()
{
      long t;
      struct tm *ltime;
      time(&t);
      ltime=localtime(&t);
      char charo[50];  int fooi ; 
      fooi = snprintf( charo, 50 , "%04d%02d%02d%02d%02d%02d",
	1900 + ltime->tm_year, ltime->tm_mon +1 , ltime->tm_mday, 
	ltime->tm_hour, ltime->tm_min, ltime->tm_sec 
	);

    size_t siz = sizeof charo ; 
    char *r = malloc( sizeof charo );
    return r ? memcpy(r, charo, siz ) : NULL;
}
     /* fooi = snprintf( charo, 50 , "%04d%02d%02d-%02d%02d%02d",
	1900 + ltime->tm_year, ltime->tm_mon +1 , ltime->tm_mday, 
	ltime->tm_hour, ltime->tm_min, ltime->tm_sec 
	); */




///////////////////////////////
///////////////////////////////
///////////////////////////////
char *strdatetime()
{
      long t;
      struct tm *ltime;
      time(&t);
      ltime=localtime(&t);
      char charo[80];  int fooi ; 
      fooi = snprintf( charo, 80 , "%04d/%02d/%02d-%02d:%02d:%02d",
	1900 + ltime->tm_year, ltime->tm_mon +1 , ltime->tm_mday, 
	ltime->tm_hour, ltime->tm_min, ltime->tm_sec 
	);

      size_t siz = sizeof charo ; 
      char *r = malloc( sizeof charo );
      return r ? memcpy(r, charo, siz ) : NULL;
}








int main( int argc, char *argv[])
{
     printf( "\n" );
     printf("****************************\n");
     printf("** 2017, PC MKSHOT        **\n" );
     printf("****************************\n");
     printf( "\n" );

     char mytimestamp[PATH_MAX];
     char cwd[PATH_MAX];
     char cmdi[PATH_MAX];
     strncpy( mytimestamp,  strtimestamp() , PATH_MAX );

     char str[PATH_MAX];
     int i;

     char mytime[PATH_MAX];
     strncpy( mytime, mytimestamp, PATH_MAX );

     strncpy( cmdi, " scrot -s  " , PATH_MAX );
     strncat( cmdi , " \"" , PATH_MAX - strlen(cmdi) - 1);
     strncat( cmdi , mytime , PATH_MAX - strlen(cmdi) - 1);
     strncat( cmdi , "-" , PATH_MAX - strlen(cmdi) - 1);
     if ( argc >= 2 ) strncat( cmdi , argv[ 1 ] , PATH_MAX - strlen(cmdi) - 1);
     strncat( cmdi , "-shot.png"  , PATH_MAX - strlen(cmdi) - 1);
     strncat( cmdi , "\" "  , PATH_MAX - strlen(cmdi) - 1);

     printf( "<PATH: %s>\n" , getcwd( cwd, PATH_MAX ));
     printf( "<CMD: %s>\n" , cmdi );
     system( cmdi );

     FILE *fp;  
     chdir( getenv( "HOME" ));
     fp = fopen( ".clipboard", "ab+" );
       fputs( "!fig{", fp );
       fputs( mytime, fp );
       fputs( "-", fp );
       fputs( "-shot.png" , fp );
       fputs( "}" , fp );
       fputs( "\n" , fp );
     fclose( fp );

    return 0;
}




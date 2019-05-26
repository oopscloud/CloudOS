/* CloudOS clib.c */

#include "type.h"
#include "const.h"
#include "protect.h"
#include "proto.h"
#include "string.h"
#include "proc.h"
#include "global.h"


void itoa(int i, char *string)
{
        int power=0,j=0;
 
        j=i;
        for( power=1;j>10;j/=10)
                power*=10;
 
        for(;power>0;power/=10)
        {
                *string++='0'+i/power;
                i%=power;
        }
        *string='\0';
        
}





PUBLIC void disp_int(int input)
{
	char output[16];
	itoa(input, output);
	
	disp_str(output);
}

PUBLIC void delay(int time)
{
	int i, j, k;
	for(k=0;k<time;k++){
		for(i=0;i<10;i++){
			for(j=0;j<10000;j++){}
		}
	}
}

char *strcat(char *s1, char *s2)
 {
     //数组型
 /*    int i = 0;
      while(s1[i] != '\0') {
         i++;
     } 
     int j = 0;
     while(s2[j] != '\0') {
         s1[i] = s2[j];
         i++;
         j++;
     }
     s1[i] = '\0';
     
     return s1;   */
    //指针型
     char *p = s1;            //定义字符型指针p指向s1 
     while(*s1 != '\0') {     //让s1指向'\0' 
         s1++;
     } 
     while(*s2 != '\0') {     //让s2连在s1后 
         *s1 = *s2;
         s1++;
         s2++;
     }
     *s1 = '\0';              //让s1以'\0'结尾 
     
     return p;
     
 }
 
 int strcmp(char *s1, char *s2)
{
    //数组型
/*    int i = 0;
    while(s1[i] == s2[i] && s1[i] != '\0') {
        i++;
    } 
    
    return s1[i] - s2[i];  */
    //指针型
    while(*s1 == *s2 && *s1 != '\0') {
        s1++;
        s2++;
    } 
    
    return *s1 - *s2;
}



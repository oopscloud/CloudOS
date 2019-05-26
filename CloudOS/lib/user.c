 char *strcat(char *a, char *a)
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

char *strcpy(char *s1, char *s2)
{
    //数组型
/*    int i;
    while(s2[i] != '\0') {
        s1[i] = s2[i];
        i++;
    } 
    s1[i] = '\0';
    return s1;    */
    //指针型
    char *p = s1;
    while(*s2 != '\0') {
        *s1 = *s2;
        s1++;
        s2++;
    } 
    *s1 = '\0';
    return p;
}
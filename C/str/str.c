#include "str.h"
#include "utils.h"
int strcomp(char* str1,char* str2){
int index=0;
if (strlen(str1)==strlen(str2)){
 while(index<strlen(str1)){
     if((int) str1[index]==(int) str2[index]){
         index++;
     }
     else
     {
         return 0;
     }
     

 }
 return 1;
}
else
{
    return 0;
}
return 1;
}
int strbegw(char* suf,char* str){
if (strlen(suf)<=strlen(str)){
    int index=0;
    while (index<strlen(suf)){
        if ((int)suf[index]==(int)str[index]){
            index++;
        }
        else
        {
            return 0;
        }
        
    }
    return 1;
}
else
{
    return 0;
}

}

#include "utils.h"
extern print_new_line();
extern print_int(int);
extern sleep(int);
uint32 strlen(const char* str)
{
  uint32 length = 0;
  while(str[length])
    length++;
  return length;
}

uint32 digit_count(int num)
{
  uint32 count = 0;
  if(num == 0)
    return 1;
  while(num > 0){
    count++;
    num = num/10;
  }
  return count;
}
void append(char s[], char n) {
    int len = strlen(s);
    s[len] = n;
    s[len+1] = '\0';
}
void strcpystruct(char* structt, char* str){
 for (int i=0; i<strlen(str);i++)
 {

   print_int(strlen(structt));
   //sleep(900000000000);
   append(structt,str[i]);
 }
 
}
int str2int(char* number){
  int multiplyer=strlen(number);
  int premult=strlen(number)-1;
  int finalvalue=0;
  while (multiplyer>=0){
    //finalvalue+=((int)(number[multiplyer]-48))*exp1bydef(10,premult-multiplyer);
    if( (int)number[multiplyer]==(int)'1'){
      finalvalue+=(1)*exp1bydef(10,premult-multiplyer);
    }
    else if( (int)number[multiplyer]==(int)'2'){
      finalvalue+=(2)*exp1bydef(10,premult-multiplyer);
    }
    else if( (int)number[multiplyer]==(int)'3'){
      finalvalue+=(3)*exp1bydef(10,premult-multiplyer);
    }
    else if( (int)number[multiplyer]==(int)'4'){
      finalvalue+=(4)*exp1bydef(10,premult-multiplyer);
    }
    else if( (int)number[multiplyer]==(int)'5'){
      finalvalue+=(5)*exp1bydef(10,premult-multiplyer);
    }
    else if( (int)number[multiplyer]==(int)'6'){
      finalvalue+=(6)*exp1bydef(10,premult-multiplyer);
    }
    else if( (int)number[multiplyer]==(int)'7'){
      finalvalue+=(7)*exp1bydef(10,premult-multiplyer);
    }
    else if( (int)number[multiplyer]==(int)'8'){
      finalvalue+=(8)*exp1bydef(10,premult-multiplyer);
    }
    else if( (int)number[multiplyer]==(int)'9'){
      finalvalue+=(9)*exp1bydef(10,premult-multiplyer);
    }
    /*else
    {
      finalvalue+=((int)(number[multiplyer]-48))*exp1bydef(10,premult-multiplyer);
    }
*/    
    multiplyer--;
  }
  return finalvalue;

}
float modulus(float divised,float divisor){
  return (float)((int)divised%(int)divisor);
  
}
int exp1bydef(int value,int exp){
  int returnvalue=value;
  int expcount=1;
  while (expcount<exp){
    returnvalue*=value;
    expcount++;
  }
  if(exp<=0){
  return 1;
  }
  else
  {
    return returnvalue;
  }
  
}
int exp(int value,int exp){
  int returnvalue=value;
  int expcount=1;
  while (expcount<exp){
    returnvalue*=value;
    expcount++;
  }
  return returnvalue;
}
void itoa(int num, char *number)
{
  int dgcount = digit_count(num);
  int index = dgcount - 1;
  char x;
  if(num == 0 && dgcount == 1){
    number[0] = '0';
    number[1] = '\0';
  }else{
    while(num != 0){
      x = num % 10;
      number[index] = x + '0';
      index--;
      num = num / 10;
    }
    number[dgcount] = '\0';
  }
}





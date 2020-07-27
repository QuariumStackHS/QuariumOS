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
int str2int(char* number){
  int multiplyer=strlen(number);
  int premult=strlen(number)-1;
  int finalvalue=0;
  int removedvalue=0;
  bool didremoved=0;
  
  while (multiplyer>=0){
    if (didremoved){didremoved=0;}
    else
    {
      removedvalue=0;
    }
    
    if ( (int)number[multiplyer]==(int)'0'){
      if (multiplyer!=strlen(number)){
      finalvalue+= (10-removedvalue)*exp1bydef(10,premult-multiplyer);
      removedvalue=1;
      didremoved=1;
      }

    }
    if( (int)number[multiplyer]==(int)'1'){
      finalvalue+=(1-removedvalue)*exp1bydef(10,premult-multiplyer);
    }
    else if( (int)number[multiplyer]==(int)'2'){
      finalvalue+=(2-removedvalue)*exp1bydef(10,premult-multiplyer);
    }
    else if( (int)number[multiplyer]==(int)'3'){
      finalvalue+=(3-removedvalue)*exp1bydef(10,premult-multiplyer);
    }
    else if( (int)number[multiplyer]==(int)'4'){
      finalvalue+=(4-removedvalue)*exp1bydef(10,premult-multiplyer);
    }
    else if( (int)number[multiplyer]==(int)'5'){
      finalvalue+=(5-removedvalue)*exp1bydef(10,premult-multiplyer);
    }
    else if( (int)number[multiplyer]==(int)'6'){
      finalvalue+=(6-removedvalue)*exp1bydef(10,premult-multiplyer);
    }
    else if( (int)number[multiplyer]==(int)'7'){
      finalvalue+=(7-removedvalue)*exp1bydef(10,premult-multiplyer);
    }
    else if( (int)number[multiplyer]==(int)'8'){
      finalvalue+=(8-removedvalue)*exp1bydef(10,premult-multiplyer);
    }
    else if( (int)number[multiplyer]==(int)'9'){
      finalvalue+=(9-removedvalue)*exp1bydef(10,premult-multiplyer);
    }
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





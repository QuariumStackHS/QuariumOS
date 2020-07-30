#include "structapp.h"
#include "utils.h"
#include "str.h"
#include "calc.h"
struct appstruct apps;
void addfunct(void (*functions),char* name,int id ){
    apps.functions[id]=functions;
    for(int i=0; i<strlen(name);i++){
    apps.functions_name[id][i]=name[i];
    }

}
void execute_func(char* name,char* args){
    for (int i=0;i<256;i++){
        if (strbegw(name,apps.functions_name[i])){
            apps.functions[i]();

        }
    }

}
void test(){
    extern print_string(char*);
    print_string("test common executed sexecflu");
}
void add_allcommandes(){
    addfunct(calculus,"calculus",0);
    addfunct(test,"t",1);

}
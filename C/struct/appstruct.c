#include "structapp.h"
#include "utils.h"
#include "str.h"
#include "calc.h"
struct appstruct apps;
void addfunct(void (*functions),char* name ){
    apps.functions[strlen(apps.functions)+1]=functions;
    for(int i=0; i<strlen(name);i++){
    apps.functions_name[strlen(apps.functions_name)+1][i]=name[i];
    }

}
void execute_func(char* name,char* args){
    for (int i=0;i<256;i++){
        if (strbegw(name,apps.functions_name[i])){
            apps.functions[i](args);

        }
    }

}
void test(){
    extern print_string(char*);
    print_string("test common executed sexecflu");
}
void add_allcommandes(){
    addfunct(calculus,"calculus");
    addfunct(test,"t");

}
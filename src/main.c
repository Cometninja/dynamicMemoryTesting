#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct button{
    char *name;
    int port;
    int pin;
    struct button* next;
} button_t;

button_t *Buttons;

button_t * get_last_index(void){
    button_t * dp = Buttons;
    
    if(dp == NULL){
        return NULL;
    }
    
    while(dp->next != NULL){
        dp = dp->next;
    }
    return dp;
}

bool add_button(char *name,int port,int pin){
    bool ret;
    button_t *dp;

    dp = get_last_index(); //Buttons;

    if(dp == NULL){
        puts("NULL");
        Buttons = (button_t*)malloc(sizeof(button_t));
        printf("Buttons = 0x%x\n",Buttons);
        dp = get_last_index();
    }else{
        puts("NOT_NULL");
        dp->next = (button_t*)malloc(sizeof(button_t));
        dp = dp->next;
    }
    
    printf("dp = \t0x%x\n",dp);
    
    strcpy(dp->name,name);
    dp->port = port;
    dp->pin = pin;
   
    printf("dp->port = %d\n",dp->port); 
}

int get_buttons_size(void){
    int i = 0;
    button_t *dp = Buttons; 
    while(dp != NULL){
        dp = dp->next;
        i++;
    }
    return i;
}

void print_dtls(void){
    int size = get_buttons_size();
    button_t *last = get_last_index();
    printf("Current size = %d\nCurrent last = 0x%08x\n",size,last);
}

int main(int argc,char *args[]){
    print_dtls();
    add_button("1",2,3);
    printf("%d\n",Buttons->port);
    print_dtls();     
}

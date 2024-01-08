#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "freertos/queue.h"
#define DR_REG_RNG_BASE 0x3ff75144
#include "freertos/semaphr.h"
#include"freertoos/eventgroup.h"


void tacheone (void * paar){
    uint32_t delai;
    while (true)
    {
        delai==READ_PERI_REG(DR_REG_RNG_BASE)%1000;
        vTaskDelay(pdMS_To_Ticks(delai));
    
        Eventgroupsetbits(surveillance,1);
    }    
    
}
void tachetwo (void * paar){
    uint32_t delai;
    while (true)
    {
        delai==READ_PERI_REG(DR_REG_RNG_BASE)%1000;
        vTaskDelay(pdMS_To_Ticks(delai));
    
        Eventgroupsetbits(surveillance,2);
    }    
    
}
void tachesurvone (void * paar){
    uint32_t delai;
    while (true)
    {
        delai==READ_PERI_REG(DR_REG_RNG_BASE)%1000;
        vTaskDelay(pdMS_To_Ticks(delai));
    
        EventgroupWaitForBits(surveillance,1,pdfalse,pdflase,PortMax_Delay());
        printf("la tache une est executer ");
    }    
    
}
void tachesurvtwo (void * paar){
    uint32_t delai;
    while (true)
    {
        delai==READ_PERI_REG(DR_REG_RNG_BASE)%1000;
        vTaskDelay(pdMS_To_Ticks(delai));
    
        EventgroupWaitForBits(surveillance,2,pdfalse,pdflase,PortMax_Delay());
        printf("la tache deux est executer ");
    }    
    
}


void tachesurvsimul (void * paar){
    uint32_t delai;
    while (true)
    {
        delai==READ_PERI_REG(DR_REG_RNG_BASE)%1000;
        vTaskDelay(pdMS_To_Ticks(delai));
    
        EventgroupWaitForBits(surveillance,3,pTrue,pdTrue,PortMax_Delay(3000));
        printf("les deux tache sont  executer appiue");
    }    
    
}

void app main(){
    surveillance=xEventGroupCreat();
    xTaskCreate(tacheone,"tache1",1024,NULL,2,NULL);
    xTaskCreate(tachetwo,"tache2",1024,NULL,2,NULL);
    xTaskCreate(tachesurvone,"tache3",1024,NULL,2,NULL);
    xTaskCreate(tachesurvtwo,"tache4",1024,NULL,2,NULL);
    xTaskCreate(tachesurvsimul,"tache5",1024,NULL,2,NULL);
    

}

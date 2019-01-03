#include "magnic.h"

void magnic_init(void)//四路电磁采集初始化;
{
   adc_init(ADC1_SE4a) ;     //PTE0   最左电磁 
   adc_init(ADC1_SE5a) ;     //PTE1  左
   adc_init(ADC1_SE6a) ;     //PTE2  右
   adc_init(ADC1_SE7a) ;     //PTE3  最右电磁  
}

void dianci_debug_modle(void)
{   
    uint16 advale0=0;
    uint16 advale1=0;
    uint16 advale2=0;
    uint16 advale3=0;
    Site_t loc[8] = { {0,55},{0,70},{0,85},{0,100},{65,55},{65,70},{65,85},{65,100}};
    uint16  i = 0;     
    lcd_init(RED);            //初始化，配置背景为 RED 红色    
    magnic_init();
    ASSERT(enter_init());   //由于英文字库和汉字字库都在FWD里，因此需要判断是否加载了FWD固件
    for(i=0;i<3;i++)
    {
      advale0=adc_once(ADC1_SE4a,ADC_10bit);
      advale1=adc_once(ADC1_SE5a,ADC_10bit);
      advale2=adc_once(ADC1_SE6a,ADC_10bit);
      advale3=adc_once(ADC1_SE7a,ADC_10bit);
      advale0++;
      advale1++;
      advale2++;
      advale3++;
    }
    advale0=advale0/3;
    advale1=advale1/3;
    advale2=advale2/3;
    advale3=advale3/3;
    
    lcd_str(loc[0],"最左",BLUE,RED);
    lcd_num_c(loc[4],advale0,BLUE,RED);
    
    lcd_str(loc[1],"中左",BLUE,RED);
    lcd_num_c(loc[5],advale1,BLUE,RED);
    
    lcd_str(loc[2],"中右",BLUE,RED);
    lcd_num_c(loc[6],advale2,BLUE,RED);
    
    lcd_str(loc[3],"最右",BLUE,RED);
    lcd_num_c(loc[7],advale3,BLUE,RED);
    
}

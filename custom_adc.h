#define _XTAL_FREQ 16000000

void adc_init();
unsigned int adc_read(unsigned char);
void adc_init()
{
    ADCON1 = 0x00;
    ADCON2 = 0x8A;
}

unsigned int adc_read(unsigned char channel)
{
    if(channel>5)
        return 0;
    ADCON0 = 0x00;
    ADON = 1;
    ADCON0 |= (channel<<2);
    __delay_ms(2);
    ADCON0bits.GO = 1;
    while(ADCON0bits.DONE == 1);
    ADON = 0;
    return(ADRES);
}
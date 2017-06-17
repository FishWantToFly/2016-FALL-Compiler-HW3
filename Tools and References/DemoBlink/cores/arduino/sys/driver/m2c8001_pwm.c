#include "m2c8001_pwm.h"

void PWM_CLK_EN(u8 pin)
{
    if(pin ==4 || pin==5)
       CGU->PIPCLKSW |= (PIP_EN_PWM1_CLK|PIP_EN_PWM1_APBCLK);
    else //if(pin ==8 || pin==9)
       CGU->PIPCLKSW |= (PIP_EN_PWM0_CLK|PIP_EN_PWM0_APBCLK);
}

void MTF_PWM_ENA(u8 pin)
{
    if(pin == 4)    //MFP_PWM3_ENABLE();    //PWM1.1
        TOP->PADMUX1 = (TOP->PADMUX1 & ~PAD_I2C_SDA_MUX_MASK) | PAD_I2C_SDA_MUX_PWM3;
    else if(pin == 5)   //MFP_PWM2_ENABLE();    //PWM1.0
        TOP->PADMUX1 = (TOP->PADMUX1 & ~PAD_I2C_CLK_MUX_MASK) | PAD_I2C_CLK_MUX_PWM2;
    else if(pin == 8)   //MFP_PWM0_ENABLE();    //PWM0.0
        TOP->PADMUX0 = (TOP->PADMUX0 & ~PAD_GPIO1_MUX_MASK) | PAD_GPIO1_MUX_PWM0;
    else if(pin == 9)   //MFP_PWM1_ENABLE();    //PWM0.1
        TOP->PADMUX0 = (TOP->PADMUX0 & ~PAD_GPIO2_MUX_MASK) | PAD_GPIO2_MUX_PWM1;
}

void PWM_Set_Clk_Src(u8 pin)
{
    if(pin ==4 || pin==5)
        CGU->DIPCLKSEL = (CGU->DIPCLKSEL &~DIP_CLK_SEL_PWM1_MASK) | DIP_CLK_SEL_PWM1_32K | DIP_CLK_SEL_RTC_XO;
    else //if(pin ==8 || pin==9)
        CGU->DIPCLKSEL = (CGU->DIPCLKSEL &~DIP_CLK_SEL_PWM0_MASK) | DIP_CLK_SEL_PWM0_32K | DIP_CLK_SEL_RTC_XO;
}

void PWM_Config_Setting(u8 pin, u16 Duty,u16 Period,u8 Div)
{
    u8 ch = 0;
    PWM_TypeDef* ptr= (PWM_TypeDef*)PWM1_BASE;;

    if(pin <=5)
    {
        if(pin==5)
            ch = 0;
        else if(pin==4)
            ch = 1;
        ptr = (PWM_TypeDef*)PWM1_BASE;
    }
    else if(pin<=9)
    {
        if(pin==9)
            ch = 1;
        else if(pin==8)
            ch = 0;
        ptr = (PWM_TypeDef*)PWM0_BASE;
    }

    if(ch == 0)
    {
        /*Set clock*/
        ptr->PWM0CR = Div & PWM_CTRL_PRESCALE ;
        /*Duty*/
        ptr->PWM0DUTY = Duty & PWM_DUTY_DCYCLE;
        /*Period*/
        ptr->PWM0PER =  Period & PWM_PER_PERVAL ;
    }
    else
    {
        /*Set clock*/
        ptr->PWM1CR = Div & PWM_CTRL_PRESCALE ;
        /*Duty*/
        ptr->PWM1DUTY = Duty & PWM_DUTY_DCYCLE;
        /*Period*/
        ptr->PWM1PER =  Period & PWM_PER_PERVAL ;
    }
}

void PWM_ENA(u8 pin)
{
    u8 ch = 0;

    PWM_TypeDef* ptr= (PWM_TypeDef*)PWM1_BASE;;

    if(pin <=5)
    {
        if(pin==5)
            ch = 0;
        else if(pin==4)
            ch = 1;
        ptr = (PWM_TypeDef*)PWM1_BASE;
    }
    else if(pin<=9)
    {
        if(pin==9)
            ch = 1;
        else if(pin==8)
            ch = 0;
        ptr = (PWM_TypeDef*)PWM0_BASE;
    }

    if(ch == 0)
        ptr->PWM0CR2 |=PWM_CTRL2_EN;
    else
        ptr->PWM1CR2 |=PWM_CTRL2_EN;

}

void PWM_Disable(u8 pin)
{
    u8 ch = 0;

    PWM_TypeDef* ptr= (PWM_TypeDef*)PWM1_BASE;;

    if(pin <=5)
    {
        if(pin==5)
            ch = 0;
        else if(pin==4)
            ch = 1;
        ptr = (PWM_TypeDef*)PWM1_BASE;
    }
    else if(pin<=9)
    {
        if(pin==9)
            ch = 1;
        else if(pin==8)
            ch = 0;
        ptr = (PWM_TypeDef*)PWM0_BASE;
    }

    if(ch == 0)
        ptr->PWM0CR2 &= ~PWM_CTRL2_EN;
    else
        ptr->PWM1CR2 &= ~PWM_CTRL2_EN;
}

void PWM_CLK_DIS(u8 pin)
{
    if(pin ==4 || pin==5)
        CGU->PIPCLKSW &= ~(PIP_EN_PWM1_CLK|PIP_EN_PWM1_APBCLK);
    else //if(pin ==8 || pin==9)
        CGU->PIPCLKSW &= ~(PIP_EN_PWM0_CLK|PIP_EN_PWM0_APBCLK);
}

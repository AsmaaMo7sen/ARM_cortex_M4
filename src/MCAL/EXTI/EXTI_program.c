#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/STD_LIB.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

void EXTI_voidEnableInt(u8 Copy_u8IntId , void(*Copy_ptrToFunc)(void))
{
	SET_BIT(EXTI->IMR , Copy_u8IntId);
}

void EXTI_voidDisableInt(u8 Copy_u8IntId)
{
	CLR_BIT(EXTI->IMR , Copy_u8IntId);
}

void EXTI_voidSetSenseSignal(u8 Copy_u8SenseSignal , u8 Copy_u8IntId)
{
	switch(Copy_u8SenseSignal)
	{
	case RISING_EDGE :
		CLR_BIT(EXTI->FTSR , Copy_u8IntId);
		SET_BIT(EXTI->RTSR , Copy_u8IntId);
		break ;

	case FALLING_EDGE :
		CLR_BIT(EXTI->RTSR , Copy_u8IntId);
		SET_BIT(EXTI->FTSR , Copy_u8IntId);
		break ;

	case ON_CHANGE :
		SET_BIT(EXTI->RTSR , Copy_u8IntId);
		SET_BIT(EXTI->FTSR , Copy_u8IntId);
		break ;

	}
}

void EXTI_voidSetLinePort(u8 Copy_u8IntId , u8 Copy_u8PortId)
{

}

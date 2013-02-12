#include <avr/io.h>

#include "twi_master/twi_master.h"
#include "../include/PowerCommander.h"
#include "i2c_com.h"

t_outputdata outputdata;

void sync_stat_cache()
{
	if (TWIM_Start(TWI_ADDRESS + TW_READ))
	{
		outputdata.ports = TWIM_ReadAck();
		outputdata.ports += TWIM_ReadAck() << 8;
		uint8_t i;
		for (i = 0; i < PWM_CHAN - 1; i++)
			outputdata.pwmval[i] = TWIM_ReadAck();
		outputdata.pwmval[i] = TWIM_ReadNack();
	}
	TWIM_Stop();
}


void twi_send()
{
	if (TWIM_Start(TWI_ADDRESS + TW_WRITE))
	{
		TWIM_Write(outputdata.ports);
		TWIM_Write(outputdata.ports >> 8);
		uint8_t i;
		for (i = 0; i < PWM_CHAN; i++)
			TWIM_Write(outputdata.pwmval[i]);
	}
	TWIM_Stop();
	// XXX send as can
}

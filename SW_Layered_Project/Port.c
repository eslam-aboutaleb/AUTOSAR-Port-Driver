/******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for Port Module.
 *
 * Author: Eslam Aboutaleb
 ******************************************************************************/

#include "Port.h"
#include "Port_Cfg.h"
#include "Dio_Regs.h"

/* AUTOSAR Version checking between Det and Port Modules */
#if ((DET_AR_MAJOR_VERSION != Port_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != Port_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != Port_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

/* port status */
static uint8 Port_Status = PORT_NOT_INITIALIZED;
/* pointer to Port_Config structure */
static Port_Config * Port_PortChannels = NULL_PTR;


void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction )
{
	Port_PinType * DDR_Ptr = NULL_PTR;
		//Dio_PortLevelType * Port_Ptr = NULL_PTR;
		boolean error = FALSE;
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (PORT_NOT_INITIALIZED == Port_Status)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_SetPinDirection_SID,
		     PORT_E_UNINIT);
		error = TRUE;
	}
	if (Pin >= PORT_CONFIGURED_CHANNLES)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_SetPinDirection_SID,
		     PORT_E_PARAM_PIN);
	}
	else
	{
		/* No Action Required */
	}

#endif


if(FALSE == error)
{
	    Port_Status=PORT_INITIALIZED;

		switch(Port_PortChannels[Pin].port)
				{
					case 0:	DDR_Ptr = &DDRA_REG;;//&DDRA_REG;
				        break;
					case 1:	DDR_Ptr = &DDRB_REG;;//&DDRB_REG;
				        break;
					case 2:	DDR_Ptr = &DDRC_REG;;//&DDRC_REG;
				        break;
					case 3:	DDR_Ptr = &DDRD_REG;
				        break;
				}


	if( Direction == PORT_PIN_OUT)
	{

		SET_BIT(*DDR_Ptr,Port_PortChannels[Pin].pin_num); // set the corresponding bit in the DDR register to configure it as output pin
	}
	else if( Direction == PORT_PIN_IN)
	{
		CLEAR_BIT(*DDR_Ptr,Port_PortChannels[Pin].pin_num); // clear the corresponding bit in the DDR register to configure it as input pin
	}
	else
	{
		/*Do Nothing */

	}

}


else
{
	/*Do Nothing */
}

}

/************************************************************************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Description: Function to Initialize the Port module.
************************************************************************************/
void Port_Init( const Port_ConfigType* ConfigPtr )
{
	Port_PinType *DDR_Ptr, *Port_Ptr;

	 #if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (NULL_PTR == ConfigPtr)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_Init_SID,
		     PORT_E_PARAM_CONFIG);
	}
	else
#endif

{
	/*
		 * Set the module state to initialized and point to the PB configuration structure using a global pointer.
		 * This global pointer is global to be used by other functions to read the PB configuration structures
		 */

		 /* address of the first of Channels structure --> Channels[0] */
		Port_PortChannels = ConfigPtr->Channels;
		/* iteration to check all channels */
        for(int i=0;i<PORT_CONFIGURED_CHANNLES;i++){
		switch(Port_PortChannels[i].port)
				{
					case 0:	DDR_Ptr = &DDRA_REG;
					       Port_Ptr = &PORTA_REG;
				        break;
					case 1:	DDR_Ptr  = &DDRB_REG;
					        Port_Ptr = &PORTB_REG;
				        break;
					case 2:	DDR_Ptr  = &DDRC_REG;
					        Port_Ptr = &PORTC_REG;
				        break;
					case 3:	DDR_Ptr  = &DDRD_REG;
					        Port_Ptr = &PORTD_REG;
				        break;
				}
		if(PORT_PIN_IN==Port_PortChannels[i].direction)
		{
					CLEAR_BIT(*DDR_Ptr,Port_PortChannels[i].pin_num);
					if (STD_LOW== Port_PortChannels[i].Level)
					{
						CLEAR_BIT(*Port_Ptr, Port_PortChannels[i].pin_num);
					}

					else if(STD_HIGH== Port_PortChannels[i].Level)
					{
						SET_BIT(*Port_Ptr, Port_PortChannels[i].pin_num);
					}

					else
					{

					}

		} /* end of INPUT condition */

		else if(PORT_PIN_OUT==Port_PortChannels[i].direction)
					{

					/* Make this pin as output */
						SET_BIT(*DDR_Ptr,Port_PortChannels[i].pin_num);

						/*Check whether is it Output High OR Low */
						if (STD_LOW==Port_PortChannels[i].Level)
						{
							CLEAR_BIT(*Port_Ptr,Port_PortChannels[i].pin_num);

						}
						else if (STD_HIGH==Port_PortChannels[i].Level)
						{
							SET_BIT(*Port_Ptr,Port_PortChannels[i].pin_num);
						}
						else
						{

						}
					} /* end of OUTPUT condition */
}
        /* Initialize the port */
       	Port_Status = PORT_INITIALIZED;
}



#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if input pointer is not Null pointer */
	if(NULL_PTR == versioninfo)
	{
		/* Report to DET  */

	   Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_GetVersionInfo_SID,
		     PORT_E_PARAM_POINTER);
	}
	else
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
	{
		/* Copy the vendor Id */
		versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
		/* Copy the module Id */
		versioninfo->moduleID = (uint16)PORT_MODULE_ID;
		/* Copy Software Major Version */
		versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
		/* Copy Software Minor Version */
		versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
		/* Copy Software Patch Version */
		versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
	}
}
#endif

void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode )
{
	    Port_PinType *DDR_Ptr = NULL_PTR;
	    Port_PinType *Port_Ptr = NULL_PTR;
		//Dio_PortLevelType * Port_Ptr = NULL_PTR;
		boolean error = FALSE;
#if (DIO_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (DIO_NOT_INITIALIZED == Dio_Status)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_SetPinDirection_SID,
		     PORT_E_UNINIT);
		error = TRUE;
	}
	if (Pin >= PORT_CONFIGURED_CHANNLES)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_SetPinDirection_SID,
		     PORT_E_PARAM_PIN);
	}
	else
	{
		/* No Action Required */
	}

#endif

	if(FALSE == error)
	{
		/* Can't setup mode for AVR */
	}

    }
}


/* Port_RefreshPortDirection API */
void Port_RefreshPortDirection(void)
{

}

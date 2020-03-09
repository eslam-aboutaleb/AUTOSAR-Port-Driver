 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for Port Module.
 *
 *
 *      Author: Eslam Aboutaleb
 *

 ******************************************************************************/

#ifndef PORT_H
#define PORT_H

#include "Micro_Config.h"

/* Id for the company in the AUTOSAR*/
#define PORT_VENDOR_ID    (1000U)


#define PORT_MODULE_ID    (120U)


#define PORT_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)


#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)

/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Port Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* Dio Pre-Compile Configuration Header file */
#include "Port_Cfg.h"

/* AUTOSAR Version checking between port_Cfg.h and Dio.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Dio_Cfg.h and Dio.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of Port_Cfg.h does not match the expected version"
#endif

/* Non AUTOSAR files */
#include "Common_Macros.h"

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
#define Port_Init_SID                            (uint8)0x00

#define Port_SetPinDirection_SID                 (uint8)0x01

#define Port_RefreshPortDirection_SID            (uint8)0x02

#define Port_GetVersionInfo_SID                  (uint8)0x03

#define Port_SetPinMode_SID                      (uint8)0x04



/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/* DET code to report Invalid Channel */
#define PORT_E_PARAM_PIN                          (uint8)0x0A

#define PORT_E_DIRECTION_UNCHANGEABLE             (uint8)0x0B

/* DET code to report Invalid Port */
#define PORT_E_PARAM_CONFIG                       (uint8)0x0C

/* DET code to report Invalid Channel Group */
#define PORT_E_PARAM_INVALID_MODE                 (uint8)0x0D

#define PORT_E_MODE_UNCHANGEABLE                  (uint8)0x0E

/*
 * API service used without module initialization is reported using following
 * error code (Not exist in AUTOSAR 4.0.3 DIO SWS Document.
 */
#define PORT_E_UNINIT                             (uint8)0x0F
#define PORT_E_PARAM_POINTER                      (uint8)0x10
/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

typedef uint8 Port_PinType;

typedef uint8 Port_PinModeType;


typedef uint8 Port_ChannelType;


typedef enum
{
    PORT_PIN_INPUT , PORT_PIN_OUTPUT
} Port_PinDirectionType;

typedef struct
{
	/* Member contains the ID of the Port that this channel belongs to */
	Port_PinType port;
	/* Member contains the ID of the Channel*/
	Port_ChannelType pin_num;
	Port_PinDirectionType direction;
	Port_PinType Level;
}Port_Config;

typedef struct
{
	Port_Config Channels[PORT_CONFIGURED_CHANNLES];
} Port_ConfigType;



/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

void Port_Init( const Port_ConfigType* ConfigPtr );

void Port_RefreshPortDirection( void );


#if ( PORT_SET_PIN_DIRECTION_API == STD_ON )
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction );
#endif

void Port_RefreshPortDirection( void );

#if (PORT_SET_PIN_MODE_API == STD_ON)

void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode );
#endif

#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo );
#endif

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/
extern const Port_ConfigType Port_Configuration;
/* Extern PB structures to be used by port and other modules */

/*********************************************************************************
 * 						PIN Definitions 														 *
 * *******************************************************************************/

#define PORTA_ID					(0U)
#define PORTB_ID					(1U)
#define PORTC_ID					(2U)
#define PORTD_ID					(3U)

#define PORT_PIN0 							(Port_PinType)0
#define PORT_PIN1 							(Port_PinType)1
#define PORT_PIN2 							(Port_PinType)2
#define PORT_PIN3 							(Port_PinType)3
#define PORT_PIN4 							(Port_PinType)4
#define PORT_PIN5 							(Port_PinType)5
#define PORT_PIN6 							(Port_PinType)6
#define PORT_PIN7 							(Port_PinType)7

#define PINS_PER_PORT					(8U)
#define NUMBER_OF_PORTS					(4U)


#endif /* PORT_H */

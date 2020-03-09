#ifndef PORT_CFG_H
#define PORT_CFG_H

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (3U)

/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                (STD_ON)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API                (STD_OFF)



#define PORT_SET_PIN_MODE_API                (STD_OFF)

#define PORT_SET_PIN_DIRECTION_API           (STD_ON)

#define	PORT_PIN_DIRECTION_CHANGEABLE		(STD_OFF)

/* Number of the configured Dio Channels */
#define PORT_CONFIGURED_CHANNLES             (32U)





/*Configure PORT direction status*/
#define PORTA_PIN0_DDR          						(PORT_PIN_IN)
#define PORTA_PIN1_DDR          						(PORT_PIN_IN)
#define PORTA_PIN2_DDR          						(PORT_PIN_IN)
#define PORTA_PIN3_DDR          						(PORT_PIN_IN)
#define PORTA_PIN4_DDR          						(PORT_PIN_IN)
#define PORTA_PIN5_DDR          						(PORT_PIN_IN)
#define PORTA_PIN6_DDR          						(PORT_PIN_IN)
#define PORTA_PIN7_DDR          						(PORT_PIN_IN)

#define PORTB_PIN0_DDR          						(PORT_PIN_IN)
#define PORTB_PIN1_DDR          						(PORT_PIN_IN)
#define PORTB_PIN2_DDR          						(PORT_PIN_IN)
#define PORTB_PIN3_DDR          						(PORT_PIN_IN)
#define PORTB_PIN4_DDR          						(PORT_PIN_IN)
#define PORTB_PIN5_DDR          						(PORT_PIN_IN)
#define PORTB_PIN6_DDR          						(PORT_PIN_IN)
#define PORTB_PIN7_DDR          						(PORT_PIN_IN)

#define PORTC_PIN0_DDR          						(PORT_PIN_IN)
#define PORTC_PIN1_DDR          						(PORT_PIN_IN)
#define PORTC_PIN2_DDR          						(PORT_PIN_IN)
#define PORTC_PIN3_DDR          						(PORT_PIN_IN)
#define PORTC_PIN4_DDR          						(PORT_PIN_IN)
#define PORTC_PIN5_DDR          						(PORT_PIN_OUT)	//LED DDR
#define PORTC_PIN6_DDR          						(PORT_PIN_IN)
#define PORTC_PIN7_DDR          						(PORT_PIN_IN)

#define PORTD_PIN0_DDR          						(PORT_PIN_IN)
#define PORTD_PIN1_DDR          						(PORT_PIN_IN)
#define PORTD_PIN2_DDR          						(PORT_PIN_IN)	//BUTTON DDR
#define PORTD_PIN3_DDR          						(PORT_PIN_IN)
#define PORTD_PIN4_DDR          						(PORT_PIN_IN)
#define PORTD_PIN5_DDR          						(PORT_PIN_IN)
#define PORTD_PIN6_DDR          						(PORT_PIN_IN)
#define PORTD_PIN7_DDR          						(PORT_PIN_IN)

/*************************/
/*Configure PORT control status*/
#define PORTA_PIN0_CR   								(STD_LOW)
#define PORTA_PIN1_CR   								(STD_LOW)
#define PORTA_PIN2_CR   								(STD_LOW)
#define PORTA_PIN3_CR   								(STD_LOW)
#define PORTA_PIN4_CR   								(STD_LOW)
#define PORTA_PIN5_CR   								(STD_LOW)
#define PORTA_PIN6_CR   								(STD_LOW)
#define PORTA_PIN7_CR   								(STD_LOW)

#define PORTB_PIN0_CR   								(STD_LOW)
#define PORTB_PIN1_CR   								(STD_LOW)
#define PORTB_PIN2_CR   								(STD_LOW)
#define PORTB_PIN3_CR   								(STD_LOW)
#define PORTB_PIN4_CR   								(STD_LOW)
#define PORTB_PIN5_CR   								(STD_LOW)
#define PORTB_PIN6_CR   								(STD_LOW)
#define PORTB_PIN7_CR   								(STD_LOW)

#define PORTC_PIN0_CR   								(STD_LOW)
#define PORTC_PIN1_CR   								(STD_LOW)
#define PORTC_PIN2_CR   								(STD_LOW)
#define PORTC_PIN3_CR   								(STD_LOW)
#define PORTC_PIN4_CR   								(STD_LOW)
#define PORTC_PIN5_CR   								(STD_LOW)	//LED PORT
#define PORTC_PIN6_CR   								(STD_LOW)
#define PORTC_PIN7_CR   								(STD_LOW)

#define PORTD_PIN0_CR   								(STD_LOW)
#define PORTD_PIN1_CR   								(STD_LOW)
#define PORTD_PIN2_CR   								(STD_LOW)	//BUTTON PORT
#define PORTD_PIN3_CR   								(STD_LOW)
#define PORTD_PIN4_CR   								(STD_LOW)
#define PORTD_PIN5_CR   								(STD_LOW)
#define PORTD_PIN6_CR   								(STD_LOW)
#define PORTD_PIN7_CR   								(STD_LOW)


#endif

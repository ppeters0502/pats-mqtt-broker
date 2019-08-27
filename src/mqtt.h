#ifndef MQTT_H
#define MQTT_H

#include <stdio.h>

#define MQTT_HEADER_LEN 2
#define MQTT_ACK_LEN 4

/*Message Types*/
enum message_opcode {
	CONNECT		= 0x10,
	CONNACK		= 0x20,
	PUBLISH		= 0x30,
	PUBACK		= 0x40,
	PUBREC		= 0x50,
	PUBREL		= 0x60,
	PUBCOMP		= 0x70,
	SUBSCRIBE	= 0x80,
	SUBACK		= 0x90,
	UNSUBSCRIBE	= 0xA0,
	UNSUBACK	= 0xB0,
	PINGREQ		= 0xC0,
	PINGRESP	= 0xD0,
	DISCONNECT	= 0xE0
};

enum message_type {
	CONNECT_TYPE 	= 1,
	CONNACK_TYPE	= 2,
	PUBLISH_TYPE	= 3,
	PUBACK_TYPE		= 4,
	PUBREC_TYPE		= 5,
	PUBREL_TYPE		= 6,
	PUBCOMP_TYPE	= 7,
	SUBSCRIBE_TYPE	= 8,
	SUBACK_TYPE		= 9,
	UNSUBSCRIBE_TYPE = 10,
	UNSUBACK_TYPE	= 11,
	PINGREQ_TYPE	= 12,
	PINGRESP_TYPE 	= 13,
	DISCONNECT_TYPE	= 14
};

enum qos_level {AT_MOST_ONCE, AT_LEAST_ONCE, EXACTLY_ONCE };

union mqtt_header {
	unsigned char byte;

	struct {
		unsigned retain : 1;
		unsigned qos : 2;
		unsigned dup : 1;
		unsigned type : 4
	} bits;
};
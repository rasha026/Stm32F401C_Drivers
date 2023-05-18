


#include "../../LIB/Stdtypes.h"
#include "../../LIB/BIT_MATH.h"


#define NVIC_ISER_BASE_ADDRESS 				0xE000E100
#define NVIC_ICER_BASE_ADDRESS 				0XE000E180
#define NVIC_ISPR_BASE_ADDRESS 				0XE000E200
#define NVIC_ICPR_BASE_ADDRESS 				0XE000E280
#define NVIC_IABR_BASE_ADDRESS 				0xE000E300
#define NVIC_IPR_BASE_ADDRESS 				0xE000E400
#define NVIC_STIR_BASE_ADDRESS				0xE000EF00







#define NVIC_ISER							(( u32*)(NVIC_ISER_BASE_ADDRESS	))
#define NVIC_ICER							(( u32*)(NVIC_ICER_BASE_ADDRESS	))
#define NVIC_ISPR							(( u32*)(NVIC_ISPR_BASE_ADDRESS	))
#define NVIC_ICPR							(( u32*)(NVIC_ICPR_BASE_ADDRESS	))
#define NVIC_IABR							(( u32*)(NVIC_IABR_BASE_ADDRESS	))
#define NVIC_IPR							(( u32*)(NVIC_IPR_BASE_ADDRESS	))




typedef struct{
	u8 NVIC_IPR0;
	u8 NVIC_IPR1;
	u8 NVIC_IPR2;
	u8 NVIC_IPR3;
	u8 NVIC_IPR4;
	u8 NVIC_IPR5;
	u8 NVIC_IPR6;
	u8 NVIC_IPR7;
	u8 NVIC_IPR8;
	u8 NVIC_IPR9;
	u8 NVIC_IPR10;
	u8 NVIC_IPR11;
	u8 NVIC_IPR12;
	u8 NVIC_IPR13;
	u8 NVIC_IPR14;
	u8 NVIC_IPR15;
	u8 NVIC_IPR16;
	u8 NVIC_IPR17;
	u8 NVIC_IPR18;
	u8 NVIC_IPR19;
	u8 NVIC_IPR20;
	u8 NVIC_IPR21;
	u8 NVIC_IPR22;
	u8 NVIC_IPR23;
	u8 NVIC_IPR24;
	u8 NVIC_IPR25;
	u8 NVIC_IPR26;
	u8 NVIC_IPR27;
	u8 NVIC_IPR28;
	u8 NVIC_IPR29;
	u8 NVIC_IPR30;
	u8 NVIC_IPR31;
	u8 NVIC_IPR32;
	u8 NVIC_IPR33;
	u8 NVIC_IPR34;
	u8 NVIC_IPR35;
	u8 NVIC_IPR36;
	u8 NVIC_IPR37;
	u8 NVIC_IPR38;
	u8 NVIC_IPR39;
	u8 NVIC_IPR40;
	u8 NVIC_IPR41;
	u8 NVIC_IPR42;
	u8 NVIC_IPR43;
	u8 NVIC_IPR44;
	u8 NVIC_IPR45;
	u8 NVIC_IPR46;
	u8 NVIC_IPR47;
	u8 NVIC_IPR48;
	u8 NVIC_IPR49;
	u8 NVIC_IPR50;
	u8 NVIC_IPR51;
	u8 NVIC_IPR52;
	u8 NVIC_IPR53;
	u8 NVIC_IPR54;
	u8 NVIC_IPR55;
	u8 NVIC_IPR56;
	u8 NVIC_IPR57;
	u8 NVIC_IPR58;
	u8 NVIC_IPR59;

}NVIC_Strut_IPR;




typedef enum{
	NVIC_enuPeripheral_0=0,
	NVIC_enuPeripheral_1,
	NVIC_enuPeripheral_2,
	NVIC_enuPeripheral_3,
	NVIC_enuPeripheral_4,
	NVIC_enuPeripheral_5,
	NVIC_enuPeripheral_6,
	NVIC_enuPeripheral_7,
	NVIC_enuPeripheral_8,
	NVIC_enuPeripheral_9,
	NVIC_enuPeripheral_10,
	NVIC_enuPeripheral_11,
	NVIC_enuPeripheral_12,
	NVIC_enuPeripheral_13,
	NVIC_enuPeripheral_14,
	NVIC_enuPeripheral_15,
	NVIC_enuPeripheral_16,
	NVIC_enuPeripheral_17,
	NVIC_enuPeripheral_18,
	NVIC_enuPeripheral_19,
	NVIC_enuPeripheral_20,
	NVIC_enuPeripheral_21,
	NVIC_enuPeripheral_22,
	NVIC_enuPeripheral_23,
	NVIC_enuPeripheral_24,
	NVIC_enuPeripheral_25,
	NVIC_enuPeripheral_26,
	NVIC_enuPeripheral_27,
	NVIC_enuPeripheral_28,
	NVIC_enuPeripheral_29,
	NVIC_enuPeripheral_30,
	NVIC_enuPeripheral_31,
	NVIC_enuPeripheral_32,
	NVIC_enuPeripheral_33,
	NVIC_enuPeripheral_34,
	NVIC_enuPeripheral_35,
	NVIC_enuPeripheral_36,
	NVIC_enuPeripheral_37,
	NVIC_enuPeripheral_38,
	NVIC_enuPeripheral_39,
	NVIC_enuPeripheral_40,
	NVIC_enuPeripheral_41,
	NVIC_enuPeripheral_42,
	NVIC_enuPeripheral_43,
	NVIC_enuPeripheral_44,
	NVIC_enuPeripheral_45,
	NVIC_enuPeripheral_46,
	NVIC_enuPeripheral_47,
	NVIC_enuPeripheral_48,
	NVIC_enuPeripheral_49,
	NVIC_enuPeripheral_50,
	NVIC_enuPeripheral_51,
	NVIC_enuPeripheral_52,
	NVIC_enuPeripheral_53,
	NVIC_enuPeripheral_54,
	NVIC_enuPeripheral_55,
	NVIC_enuPeripheral_56,
	NVIC_enuPeripheral_57,
	NVIC_enuPeripheral_58,
	NVIC_enuPeripheral_59,
	NVIC_enuPeripheral_60,
	NVIC_enuPeripheral_61,
	NVIC_enuPeripheral_62,
	NVIC_enuPeripheral_63,
	NVIC_enuPeripheral_64,
	NVIC_enuPeripheral_65,
	NVIC_enuPeripheral_66,
	NVIC_enuPeripheral_67,
	NVIC_enuPeripheral_68,
	NVIC_enuPeripheral_69,
	NVIC_enuPeripheral_70,
	NVIC_enuPeripheral_71,
	NVIC_enuPeripheral_72,
	NVIC_enuPeripheral_73,
	NVIC_enuPeripheral_74,
	NVIC_enuPeripheral_75,
	NVIC_enuPeripheral_76,
	NVIC_enuPeripheral_77,
	NVIC_enuPeripheral_78,
	NVIC_enuPeripheral_79,
	NVIC_enuPeripheral_80,
	NVIC_enuPeripheral_81,
	NVIC_enuPeripheral_82,
	NVIC_enuPeripheral_83,
	NVIC_enuPeripheral_84,
	NVIC_enuPeripheral_85,
	NVIC_enuPeripheral_86,
	NVIC_enuPeripheral_87,
	NVIC_enuPeripheral_88,
	NVIC_enuPeripheral_89,
	NVIC_enuPeripheral_90,
	NVIC_enuPeripheral_91,
	NVIC_enuPeripheral_92,
	NVIC_enuPeripheral_93,
	NVIC_enuPeripheral_94,
	NVIC_enuPeripheral_95,
	NVIC_enuPeripheral_96,
	NVIC_enuPeripheral_97,
	NVIC_enuPeripheral_98,
	NVIC_enuPeripheral_99,
	NVIC_enuPeripheral_100,
	NVIC_enuPeripheral_101,
	NVIC_enuPeripheral_102,
	NVIC_enuPeripheral_103,
	NVIC_enuPeripheral_104,
	NVIC_enuPeripheral_105,
	NVIC_enuPeripheral_106,
	NVIC_enuPeripheral_107,
	NVIC_enuPeripheral_108,
	NVIC_enuPeripheral_109,
	NVIC_enuPeripheral_110,
	NVIC_enuPeripheral_111,
	NVIC_enuPeripheral_112,
	NVIC_enuPeripheral_113,
	NVIC_enuPeripheral_114,
	NVIC_enuPeripheral_115,
	NVIC_enuPeripheral_116,
	NVIC_enuPeripheral_117,
	NVIC_enuPeripheral_118,
	NVIC_enuPeripheral_119,
	NVIC_enuPeripheral_120,
	NVIC_enuPeripheral_121,
	NVIC_enuPeripheral_122,
	NVIC_enuPeripheral_123,
	NVIC_enuPeripheral_124,
	NVIC_enuPeripheral_125,
	NVIC_enuPeripheral_126,
	NVIC_enuPeripheral_127,
	NVIC_enuPeripheral_128,
	NVIC_enuPeripheral_129,
	NVIC_enuPeripheral_130,
	NVIC_enuPeripheral_131,
	NVIC_enuPeripheral_132,
	NVIC_enuPeripheral_133,
	NVIC_enuPeripheral_134,
	NVIC_enuPeripheral_135,
	NVIC_enuPeripheral_136,
	NVIC_enuPeripheral_137,
	NVIC_enuPeripheral_138,
	NVIC_enuPeripheral_139,
	NVIC_enuPeripheral_140,
	NVIC_enuPeripheral_141,
	NVIC_enuPeripheral_142,
	NVIC_enuPeripheral_143,
	NVIC_enuPeripheral_144,
	NVIC_enuPeripheral_145,
	NVIC_enuPeripheral_146,
	NVIC_enuPeripheral_147,
	NVIC_enuPeripheral_148,
	NVIC_enuPeripheral_149,
	NVIC_enuPeripheral_150,
	NVIC_enuPeripheral_151,
	NVIC_enuPeripheral_152,
	NVIC_enuPeripheral_153,
	NVIC_enuPeripheral_154,
	NVIC_enuPeripheral_155,
	NVIC_enuPeripheral_156,
	NVIC_enuPeripheral_157,
	NVIC_enuPeripheral_158,
	NVIC_enuPeripheral_159,
	NVIC_enuPeripheral_160,
	NVIC_enuPeripheral_161,
	NVIC_enuPeripheral_162,
	NVIC_enuPeripheral_163,
	NVIC_enuPeripheral_164,
	NVIC_enuPeripheral_165,
	NVIC_enuPeripheral_166,
	NVIC_enuPeripheral_167,
	NVIC_enuPeripheral_168,
	NVIC_enuPeripheral_169,
	NVIC_enuPeripheral_170,
	NVIC_enuPeripheral_171,
	NVIC_enuPeripheral_172,
	NVIC_enuPeripheral_173,
	NVIC_enuPeripheral_174,
	NVIC_enuPeripheral_175,
	NVIC_enuPeripheral_176,
	NVIC_enuPeripheral_177,
	NVIC_enuPeripheral_178,
	NVIC_enuPeripheral_179,
	NVIC_enuPeripheral_180,
	NVIC_enuPeripheral_181,
	NVIC_enuPeripheral_182,
	NVIC_enuPeripheral_183,
	NVIC_enuPeripheral_184,
	NVIC_enuPeripheral_185,
	NVIC_enuPeripheral_186,
	NVIC_enuPeripheral_187,
	NVIC_enuPeripheral_188,
	NVIC_enuPeripheral_189,
	NVIC_enuPeripheral_190,
	NVIC_enuPeripheral_191,
	NVIC_enuPeripheral_192,
	NVIC_enuPeripheral_193,
	NVIC_enuPeripheral_194,
	NVIC_enuPeripheral_195,
	NVIC_enuPeripheral_196,
	NVIC_enuPeripheral_197,
	NVIC_enuPeripheral_198,
	NVIC_enuPeripheral_199,
	NVIC_enuPeripheral_200,
	NVIC_enuPeripheral_201,
	NVIC_enuPeripheral_202,
	NVIC_enuPeripheral_203,
	NVIC_enuPeripheral_204,
	NVIC_enuPeripheral_205,
	NVIC_enuPeripheral_206,
	NVIC_enuPeripheral_207,
	NVIC_enuPeripheral_208,
	NVIC_enuPeripheral_209,
	NVIC_enuPeripheral_210,
	NVIC_enuPeripheral_211,
	NVIC_enuPeripheral_212,
	NVIC_enuPeripheral_213,
	NVIC_enuPeripheral_214,
	NVIC_enuPeripheral_215,
	NVIC_enuPeripheral_216,
	NVIC_enuPeripheral_217,
	NVIC_enuPeripheral_218,
	NVIC_enuPeripheral_219,
	NVIC_enuPeripheral_220,
	NVIC_enuPeripheral_221,
	NVIC_enuPeripheral_222,
	NVIC_enuPeripheral_223,
	NVIC_enuPeripheral_224,
	NVIC_enuPeripheral_225,
	NVIC_enuPeripheral_226,
	NVIC_enuPeripheral_227,
	NVIC_enuPeripheral_228,
	NVIC_enuPeripheral_229,
	NVIC_enuPeripheral_230,
	NVIC_enuPeripheral_231,
	NVIC_enuPeripheral_232,
	NVIC_enuPeripheral_233,
	NVIC_enuPeripheral_234,
	NVIC_enuPeripheral_235,
	NVIC_enuPeripheral_236,
	NVIC_enuPeripheral_237,
	NVIC_enuPeripheral_238,
	NVIC_enuPeripheral_239,
	NVIC_enuPeripheral_Conunt,


}NVIC_tenuPeripheral;




typedef enum{
	NVIC_enuStateOK= 0,
	NVIC_enuStateNOTOK,
	NVIC_enuStateNullPTR,
}NVIC_enuErrorStatus_t;

/*

typedef enum{
	NVIC_Disable_Interrupt=0,
	NVIC_Enable_Interrupt,



}NVIC_enuEnableInterrupt;

typedef enum{
	NVIC_Clear_Pending=0,
	NVIC_SET_Pending,
}NVIC_enuSetPending;
*/



NVIC_enuErrorStatus_t NVIC_EnableInterrupt(NVIC_tenuPeripheral cpy_PeripheralNum );


NVIC_enuErrorStatus_t NVIC_DisableInterrupt(NVIC_tenuPeripheral cpy_PeripheralNum );

NVIC_enuErrorStatus_t NVIC_SetPending(NVIC_tenuPeripheral cpy_PeripheralNum);

NVIC_enuErrorStatus_t NVIC_CLEARPending(NVIC_tenuPeripheral cpy_PeripheralNum);
NVIC_enuErrorStatus_t NVIC_GetActionStatus(NVIC_tenuPeripheral cpy_PeripheralNum,u8 *Adreess_ActiveValu);


NVIC_enuErrorStatus_t NVIC_SetPriority(NVIC_tenuPeripheral cpy_PeripheralNum);


NVIC_enuErrorStatus_t NVIC_SetSubGroupLevel(NVIC_tenuPeripheral cpy_PeripheralNum);



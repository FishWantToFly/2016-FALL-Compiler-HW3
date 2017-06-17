# build options
## platform: M2C8001
PLAT ?= M2C8001
## mode: XIP
MODE ?= XIP
## EX9: YES, NO
EX9 ?= NO

$(info platform: $(PLAT), mode:$(MODE), EX9:$(EX9))

ifneq ($(filter $(PLAT), M2C8001),$(PLAT))
 $(error Unknown PLAT "$(PLAT)" is not supported!)
endif

# tool-chain
CROSS_COMPILE ?= nds32le-elf-

CC = $(CROSS_COMPILE)gcc
CXX = $(CROSS_COMPILE)g++
OBJCOPY = $(CROSS_COMPILE)objcopy
OBJDUMP = $(CROSS_COMPILE)objdump
NM = $(CROSS_COMPILE)nm
READELF = $(CROSS_COMPILE)readelf

# You can use gpio, spi, printf, bt as APP. Default is printf
APP ?= Blink

COMMON_PATH		:= 	./cores/arduino
COMMON_LIB_PATH		:=	./libraries
SPI_PATH		:=	${COMMON_LIB_PATH}/SPI
WIRE_PATH		:=	${COMMON_LIB_PATH}/Wire
TARGET_NDS32_PATH	:=	${COMMON_PATH}/sys/m2c-arch
TARGET_M2C8001_PATH 	:=	${COMMON_PATH}/sys/inc
TARGET_DRI_PATH		:=	${COMMON_PATH}/sys/driver
TARGET_BUILD_PATH	:=	./Demo_${APP}

INCLUDE_PATH := \
		-I${TARGET_M2C8001_PATH} \
		-I${COMMON_PATH} \
		-I${TARGET_NDS32_PATH} \
		-I${WIRE_PATH} \
		-I${SPI_PATH}

LDSCRIPT = ${COMMON_PATH}/sys/board/M2C8001.ld
COMMON_CPP_SRC		:=	${COMMON_PATH}/main.cpp \
				${COMMON_PATH}/WMath.cpp \
				${COMMON_PATH}/Tone.cpp \
				${COMMON_PATH}/Print.cpp \
				${COMMON_PATH}/Stream.cpp \
				${COMMON_PATH}/WString.cpp \
				${COMMON_PATH}/HardwareSerial.cpp \
				${SPI_PATH}/SPI.cpp \
				${WIRE_PATH}/Wire.cpp
COMMON_C_SRC		:= \
				${TARGET_NDS32_PATH}/interrupt.c \
				${COMMON_PATH}/avr/dtostrf.c \
				${COMMON_PATH}/wiring_digital.c \
				${COMMON_PATH}/wiring.c \
				${COMMON_PATH}/wiring_analog.c \
				${COMMON_PATH}/wiring_pulse.c \
				${COMMON_PATH}/wiring_shift.c \
				${COMMON_PATH}/itoa.c \
				${COMMON_PATH}/WInterrupts.c

DEPS := ${TARGET_M2C8001_PATH}/*.h
NDS32_SRC		:=	${TARGET_NDS32_PATH}/init-default.c
CRTBEGIN_SRC	:=	${TARGET_NDS32_PATH}/crtbegin.c
CRTEND_SRC		:=	${TARGET_NDS32_PATH}/crtend.c
BOOT_SRC		:=	${TARGET_NDS32_PATH}/crt0.S
SYS_SRC			:=	${TARGET_NDS32_PATH}/init-soc.c
DRIVER_SRC 	:=	${COMMON_PATH}/sys/board/m2c8001_board.c \
				${TARGET_DRI_PATH}/m2c8001_sys.c \
				${TARGET_DRI_PATH}/m2c8001_gpio.c \
				${TARGET_DRI_PATH}/m2c8001_int.c \
				${TARGET_DRI_PATH}/m2c8001_timer.c \
				${TARGET_DRI_PATH}/m2c8001_uart.c \
				${TARGET_DRI_PATH}/m2c8001_pwm.c \
				${TARGET_DRI_PATH}/m2c8001_spi.c \
				${TARGET_DRI_PATH}/m2c8001_i2c.c \
				${TARGET_DRI_PATH}/m2c8001_adc.c
SRCS := \
	${NDS32_SRC} \
	${SYS_SRC} \
	${DRIVER_SRC} \
	${COMMON_C_SRC}

CPP_SRCS := \
	${COMMON_CPP_SRC}

APP_${APP}_SRC		:=	${TARGET_BUILD_PATH}/${APP}.cpp
CPP_SRCS		+=      ${APP_$(APP)_SRC}

${APP}_SRCS	:= ${SRCS}
${APP}_AS_SRCS	+= ${BOOT_SRC}
${APP}_CPP_SRCS := ${CPP_SRCS}

# % can match to all the strings
${APP}_OBJS := $(patsubst %.S,%.o,$(patsubst %.c,%.o,${${APP}_SRCS}))
${APP}_CPP_OBJS := $(patsubst %.cpp,%.o,${${APP}_CPP_SRCS})
${APP}_AS_OBJS := $(patsubst %.S,%.o,${${APP}_AS_SRCS})

CRTBEGIN_OBJ := $(patsubst %.c,%.o,${CRTBEGIN_SRC})
CRTEND_OBJ := $(patsubst %.c,%.o,${CRTEND_SRC})

# Please make sure the first object file is crtbegin.o and the last one is crtend.o
OBJS = ${CRTBEGIN_OBJ} ${${APP}_OBJS} ${${APP}_AS_OBJS} ${${APP}_CPP_OBJS} ${CRTEND_OBJ}

AFLAGS =
#CFLAGS = -g3 -Os -c -Wall $(INCLUDE_PATH) -mcmodel=large -D__Andino_M1__ # Comment by Mark.
#CFLAGS = -Os -c -Wall $(INCLUDE_PATH) -mcmodel=large -D__Andino_M1__ # Comment by Mark.
CFLAGS = -O0 -mno-16-bit -c -Wall $(INCLUDE_PATH) -mcmodel=large -D__Andino_M1__
LDFLAGS = -Os -Wl,--start-group -lgloss -lgcc -lc -lstdc++ -lm -nostdlib -nostartfiles -static -T $(LDSCRIPT)
OBJCOPYFLAGS = -O binary -R .note -R .comment -S
NMFLAGS = -B -n
TARGET = $(TARGET_BUILD_PATH)/arduino-$(APP)

# EX9 feature check
ifeq ($(shell echo | $(CC) -E -dM - | grep '\<__NDS32_EXT_EX9__\>' > /dev/null && echo "EX9"), EX9)
 ifeq (NO,$(EX9))
  CEXTLDFLAGS += -Wl,--mno-ex9
  CFLAGS += -DCONFIG_NO_NDS32_EXT_EX9
 endif
else
 CFLAGS += -DCONFIG_NO_NDS32_EXT_EX9
endif


all: $(TARGET).elf

.cpp.o : $(DEPS)
	$(CXX) -c $(CFLAGS) $< -o $@
	$(CXX) -S $(CFLAGS) $< -o $@.s
# Add by Mark.

.c.o : $(DEPS)
	$(CC)  -c $(CFLAGS) $< -o $@

#.S.o : # Comment by Mark. When using .s file.
#.s.o : # Comment by Mark. When using .cpp file.
.S.o :
	$(CC)  -c $(CFLAGS) $(AFLAGS) $< -o $@
	
.s.o :
	$(CC)  -c $(CFLAGS) $(AFLAGS) $< -o $@
# .s.o and .S.o should exist at the same time when we use .s file.

$(TARGET).elf: $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) $(CEXTLDFLAGS) -o $(TARGET).elf
	$(OBJDUMP) -D $(TARGET).elf > $(TARGET).s
	$(OBJDUMP) -s $(TARGET).elf > $(TARGET).dat
	$(OBJCOPY) $(OBJCOPYFLAGS) $(TARGET).elf $(TARGET).bin
	$(NM) $(NMFLAGS) $(TARGET).elf > $(TARGET).map
	$(READELF) -a $(TARGET).elf > $(TARGET).txt

.PHONY: clean
clean:
	echo $(OBJS)
	rm -rf $(TARGET).* $(OBJS)

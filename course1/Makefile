#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <This is a Make file to support to two build platforms>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.o - Builds a <FILE>.o object file
#      <FILE>.i - Builds a <FILE>.i preprocessed file
#      <FILE>.asm - Dumps <FILE>.asm assembly file
#      <FILE>.d - Builds <FILE>.d dependency file
#      compile-all - Compiles all source files in project
#      build - Builds all object files in project (links as well)
#      clean - Removes all generated files
#
#
# Platform Overrides:
#      HOST - Default platform
#      MSP342 - Target cross-compiled platform
#
#------------------------------------------------------------------------------
include sources.mk

#Platform Overrides
# Platform Overrides
PLATFORM = HOST
CPU=cortex-m4
BASENAME=c1m2
TARGET=$(BASENAME).out
LDFLAGS = -Wl
DEPENDFLAG =-MMD\
			-MD\
			-MF\
			 
			
# Compiler Flags and Defines
CFLAGS = -Wall\
		-Werror\
		-g\
		-O0\
		-std=c99		
ifeq ($(PLATFORM),HOST)
  #Host specific flags
  CC = gcc
  CPPFLAGS =$(INCLUDES) -DHOST
  SIZETOOL=size
  LD= 
else ifeq($(PLATFORM),MSP432)
  #msp specific flags
  SIZETOOL=arm-none-eabi-size
  SOURCES:=$(SOURCES)\
		   startup_msp432p401r_gcc.c\
		   system_msp432p401r.c\
		   interrupts_msp432p401r_gcc.c
  LD = -T 		   
  LINKER_FILE = ../msp432p401r.lds
  SPECS = nosys.specs
  CC = arm-none-eabi-gcc
  CPPFLAGS = $(MSP_INCLUDES) -DMSP432
  ARCH = -mcpu=$(CPU)\
		 -mthumb\
		 -march=armv7e-m\
		 --specs=$(SPECS)\
		 -mfloat-abi=hard\
		 -mfpu=fpv4-sp-d16
else
	
endif

OBJS:=$(SOURCES:.c=.o) 

#compile all object files and link into final executable
.PHONY: build
build: $(TARGET)
$(TARGET):$(SOURCES)
	@echo "Building TARGET "$(TARGET)" with the following pre requisites "$(SOURCES)
# generate the target executable
	$(CC) $(DEPENDFLAG) $*.d $(CFLAGS) $(ARCH) $(CPPFLAGS) $(LD) $(LINKER_FILE) -o $@ $^ -Wl,-Map=$*.map
	$(SIZETOOL) $(TARGET)
	
.PHONY: compile-all
compile-all: $(OBJS)
$(OBJS):$(SOURCES)
	$(CC) $(CFLAGS) $(ARCH) $(CPPFLAGS) -c $^
	
%.o:%.c
	@echo "Compiling into objects"
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $^ 

%.i:%.c
	@echo "Generating preproccesor file for "$(PLATFORM)
	$(CC) $(CPPFLAGS) -E -o $@ $^

# use an implicit chain rule to generate the .o file
%.asm:%.o
	@echo "Dumping assembley"
	objdump -S $^ > $@
	
#remove all compiled objs, prepocessor outputs, asm outputs, exe files, build output files
.PHONY: clean
clean:
	rm -f $(TARGET) *.map *.i *.o *.out *.asm *.d
#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin_4.x-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/database/database.o \
	${OBJECTDIR}/database/index.o \
	${OBJECTDIR}/database/record.o \
	${OBJECTDIR}/database/table.o \
	${OBJECTDIR}/esecuele.o \
	${OBJECTDIR}/operation/condition/condition.o \
	${OBJECTDIR}/operation/condition/condition_and.o \
	${OBJECTDIR}/operation/condition/condition_coleqcol.o \
	${OBJECTDIR}/operation/condition/condition_coleqcte.o \
	${OBJECTDIR}/operation/condition/condition_not.o \
	${OBJECTDIR}/operation/condition/condition_or.o \
	${OBJECTDIR}/operation/condition/condition_true.o \
	${OBJECTDIR}/operation/operation.o \
	${OBJECTDIR}/operation/operation_count.o \
	${OBJECTDIR}/operation/operation_index.o \
	${OBJECTDIR}/operation/operation_limit.o \
	${OBJECTDIR}/operation/operation_offset.o \
	${OBJECTDIR}/operation/operation_product.o \
	${OBJECTDIR}/operation/operation_project.o \
	${OBJECTDIR}/operation/operation_select.o \
	${OBJECTDIR}/operation/operation_sequential.o \
	${OBJECTDIR}/operation/operation_union.o \
	${OBJECTDIR}/operation/projection/projection.o \
	${OBJECTDIR}/operation/projection/projection_col.o \
	${OBJECTDIR}/operation/projection/projection_sum.o \
	${OBJECTDIR}/parser/parser.o \
	${OBJECTDIR}/parser/stack/stack.o \
	${OBJECTDIR}/type/type.o


# C Compiler Flags
CFLAGS=-Wall -pedantic -ansi

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/esecuele.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/esecuele.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/esecuele ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/database/database.o: database/database.c 
	${MKDIR} -p ${OBJECTDIR}/database
	${RM} $@.d
	$(COMPILE.c) -O2 -Werror -Wall -pedantic -ansi -MMD -MP -MF $@.d -o ${OBJECTDIR}/database/database.o database/database.c

${OBJECTDIR}/database/index.o: database/index.c 
	${MKDIR} -p ${OBJECTDIR}/database
	${RM} $@.d
	$(COMPILE.c) -O2 -Werror -Wall -pedantic -ansi -MMD -MP -MF $@.d -o ${OBJECTDIR}/database/index.o database/index.c

${OBJECTDIR}/database/record.o: database/record.c 
	${MKDIR} -p ${OBJECTDIR}/database
	${RM} $@.d
	$(COMPILE.c) -O2 -Werror -Wall -pedantic -ansi -MMD -MP -MF $@.d -o ${OBJECTDIR}/database/record.o database/record.c

${OBJECTDIR}/database/table.o: database/table.c 
	${MKDIR} -p ${OBJECTDIR}/database
	${RM} $@.d
	$(COMPILE.c) -O2 -Werror -Wall -pedantic -ansi -MMD -MP -MF $@.d -o ${OBJECTDIR}/database/table.o database/table.c

${OBJECTDIR}/esecuele.o: esecuele.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -O2 -Werror -Wall -pedantic -ansi -MMD -MP -MF $@.d -o ${OBJECTDIR}/esecuele.o esecuele.c

${OBJECTDIR}/operation/condition/condition.o: operation/condition/condition.c 
	${MKDIR} -p ${OBJECTDIR}/operation/condition
	${RM} $@.d
	$(COMPILE.c) -O2 -Werror -Wall -pedantic -ansi -MMD -MP -MF $@.d -o ${OBJECTDIR}/operation/condition/condition.o operation/condition/condition.c

${OBJECTDIR}/operation/condition/condition_and.o: operation/condition/condition_and.c 
	${MKDIR} -p ${OBJECTDIR}/operation/condition
	${RM} $@.d
	$(COMPILE.c) -O2 -Werror -Wall -pedantic -ansi -MMD -MP -MF $@.d -o ${OBJECTDIR}/operation/condition/condition_and.o operation/condition/condition_and.c

${OBJECTDIR}/operation/condition/condition_coleqcol.o: operation/condition/condition_coleqcol.c 
	${MKDIR} -p ${OBJECTDIR}/operation/condition
	${RM} $@.d
	$(COMPILE.c) -O2 -Werror -Wall -pedantic -ansi -MMD -MP -MF $@.d -o ${OBJECTDIR}/operation/condition/condition_coleqcol.o operation/condition/condition_coleqcol.c

${OBJECTDIR}/operation/condition/condition_coleqcte.o: operation/condition/condition_coleqcte.c 
	${MKDIR} -p ${OBJECTDIR}/operation/condition
	${RM} $@.d
	$(COMPILE.c) -O2 -Werror -Wall -pedantic -ansi -MMD -MP -MF $@.d -o ${OBJECTDIR}/operation/condition/condition_coleqcte.o operation/condition/condition_coleqcte.c

${OBJECTDIR}/operation/condition/condition_not.o: operation/condition/condition_not.c 
	${MKDIR} -p ${OBJECTDIR}/operation/condition
	${RM} $@.d
	$(COMPILE.c) -O2 -Werror -Wall -pedantic -ansi -MMD -MP -MF $@.d -o ${OBJECTDIR}/operation/condition/condition_not.o operation/condition/condition_not.c

${OBJECTDIR}/operation/condition/condition_or.o: operation/condition/condition_or.c 
	${MKDIR} -p ${OBJECTDIR}/operation/condition
	${RM} $@.d
	$(COMPILE.c) -O2 -Werror -Wall -pedantic -ansi -MMD -MP -MF $@.d -o ${OBJECTDIR}/operation/condition/condition_or.o operation/condition/condition_or.c

${OBJECTDIR}/operation/condition/condition_true.o: operation/condition/condition_true.c 
	${MKDIR} -p ${OBJECTDIR}/operation/condition
	${RM} $@.d
	$(COMPILE.c) -O2 -Werror -Wall -pedantic -ansi -MMD -MP -MF $@.d -o ${OBJECTDIR}/operation/condition/condition_true.o operation/condition/condition_true.c

${OBJECTDIR}/operation/operation.o: operation/operation.c 
	${MKDIR} -p ${OBJECTDIR}/operation
	${RM} $@.d
	$(COMPILE.c) -O2 -Werror -Wall -pedantic -ansi -MMD -MP -MF $@.d -o ${OBJECTDIR}/operation/operation.o operation/operation.c

${OBJECTDIR}/operation/operation_count.o: operation/operation_count.c 
	${MKDIR} -p ${OBJECTDIR}/operation
	${RM} $@.d
	$(COMPILE.c) -O2 -Werror -Wall -pedantic -ansi -MMD -MP -MF $@.d -o ${OBJECTDIR}/operation/operation_count.o operation/operation_count.c

${OBJECTDIR}/operation/operation_index.o: operation/operation_index.c 
	${MKDIR} -p ${OBJECTDIR}/operation
	${RM} $@.d
	$(COMPILE.c) -O2 -Werror -Wall -pedantic -ansi -MMD -MP -MF $@.d -o ${OBJECTDIR}/operation/operation_index.o operation/operation_index.c

${OBJECTDIR}/operation/operation_limit.o: operation/operation_limit.c 
	${MKDIR} -p ${OBJECTDIR}/operation
	${RM} $@.d
	$(COMPILE.c) -O2 -Werror -Wall -pedantic -ansi -MMD -MP -MF $@.d -o ${OBJECTDIR}/operation/operation_limit.o operation/operation_limit.c

${OBJECTDIR}/operation/operation_offset.o: operation/operation_offset.c 
	${MKDIR} -p ${OBJECTDIR}/operation
	${RM} $@.d
	$(COMPILE.c) -O2 -Werror -Wall -pedantic -ansi -MMD -MP -MF $@.d -o ${OBJECTDIR}/operation/operation_offset.o operation/operation_offset.c

${OBJECTDIR}/operation/operation_product.o: operation/operation_product.c 
	${MKDIR} -p ${OBJECTDIR}/operation
	${RM} $@.d
	$(COMPILE.c) -O2 -Werror -Wall -pedantic -ansi -MMD -MP -MF $@.d -o ${OBJECTDIR}/operation/operation_product.o operation/operation_product.c

${OBJECTDIR}/operation/operation_project.o: operation/operation_project.c 
	${MKDIR} -p ${OBJECTDIR}/operation
	${RM} $@.d
	$(COMPILE.c) -O2 -Werror -Wall -pedantic -ansi -MMD -MP -MF $@.d -o ${OBJECTDIR}/operation/operation_project.o operation/operation_project.c

${OBJECTDIR}/operation/operation_select.o: operation/operation_select.c 
	${MKDIR} -p ${OBJECTDIR}/operation
	${RM} $@.d
	$(COMPILE.c) -O2 -Werror -Wall -pedantic -ansi -MMD -MP -MF $@.d -o ${OBJECTDIR}/operation/operation_select.o operation/operation_select.c

${OBJECTDIR}/operation/operation_sequential.o: operation/operation_sequential.c 
	${MKDIR} -p ${OBJECTDIR}/operation
	${RM} $@.d
	$(COMPILE.c) -O2 -Werror -Wall -pedantic -ansi -MMD -MP -MF $@.d -o ${OBJECTDIR}/operation/operation_sequential.o operation/operation_sequential.c

${OBJECTDIR}/operation/operation_union.o: operation/operation_union.c 
	${MKDIR} -p ${OBJECTDIR}/operation
	${RM} $@.d
	$(COMPILE.c) -O2 -Werror -Wall -pedantic -ansi -MMD -MP -MF $@.d -o ${OBJECTDIR}/operation/operation_union.o operation/operation_union.c

${OBJECTDIR}/operation/projection/projection.o: operation/projection/projection.c 
	${MKDIR} -p ${OBJECTDIR}/operation/projection
	${RM} $@.d
	$(COMPILE.c) -O2 -Werror -Wall -pedantic -ansi -MMD -MP -MF $@.d -o ${OBJECTDIR}/operation/projection/projection.o operation/projection/projection.c

${OBJECTDIR}/operation/projection/projection_col.o: operation/projection/projection_col.c 
	${MKDIR} -p ${OBJECTDIR}/operation/projection
	${RM} $@.d
	$(COMPILE.c) -O2 -Werror -Wall -pedantic -ansi -MMD -MP -MF $@.d -o ${OBJECTDIR}/operation/projection/projection_col.o operation/projection/projection_col.c

${OBJECTDIR}/operation/projection/projection_sum.o: operation/projection/projection_sum.c 
	${MKDIR} -p ${OBJECTDIR}/operation/projection
	${RM} $@.d
	$(COMPILE.c) -O2 -Werror -Wall -pedantic -ansi -MMD -MP -MF $@.d -o ${OBJECTDIR}/operation/projection/projection_sum.o operation/projection/projection_sum.c

${OBJECTDIR}/parser/parser.o: parser/parser.c 
	${MKDIR} -p ${OBJECTDIR}/parser
	${RM} $@.d
	$(COMPILE.c) -O2 -Werror -Wall -pedantic -ansi -MMD -MP -MF $@.d -o ${OBJECTDIR}/parser/parser.o parser/parser.c

${OBJECTDIR}/parser/stack/stack.o: parser/stack/stack.c 
	${MKDIR} -p ${OBJECTDIR}/parser/stack
	${RM} $@.d
	$(COMPILE.c) -O2 -Werror -Wall -pedantic -ansi -MMD -MP -MF $@.d -o ${OBJECTDIR}/parser/stack/stack.o parser/stack/stack.c

${OBJECTDIR}/type/type.o: type/type.c 
	${MKDIR} -p ${OBJECTDIR}/type
	${RM} $@.d
	$(COMPILE.c) -O2 -Werror -Wall -pedantic -ansi -MMD -MP -MF $@.d -o ${OBJECTDIR}/type/type.o type/type.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/esecuele.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

# ------------------- Required for MSVC nmake ---------------------------------
# This file should be included at the top of a MAKEFILE as follows:


CPU = AMD64

MODEL  = App_v0p2
TARGET = cgxe
MODULE_SRCS 	= m_q5pXm8srdYxK0T8n4wsZmB.c m_N7dQiE8dzxoZ3zD5HN1j4.c m_Vcc8ISteIOqGP7Pz5Cs32B.c m_vBzYk5rxBuuk3tHfKRBn4B.c m_WqYNctr5az53WvPBtSKqtE.c m_unN3reohie2VbRJ8Gdn4vD.c m_Pe1gyJNSvQtAxyP0HVs3QE.c m_TmhUzaTizl4mODx5ncv8iC.c m_1G2T82xNlaygne7cNWxD7.c m_QH2ipmi4AEsKLe0nOk4ysG.c m_yZHQAeALt4OuuN5DI39hDH.c
MODEL_SRC	= App_v0p2_cgxe.c
MODEL_REG = App_v0p2_cgxe_registry.c
MAKEFILE    = App_v0p2_cgxe.mak
MATLAB_ROOT	= C:\Program Files\MATLAB\R2018b
BUILDARGS   =

#--------------------------- Tool Specifications ------------------------------
#
#
MSVC_ROOT1 = $(MSDEVDIR:SharedIDE=vc)
MSVC_ROOT2 = $(MSVC_ROOT1:SHAREDIDE=vc)
MSVC_ROOT  = $(MSVC_ROOT2:sharedide=vc)

# Compiler tool locations, CC, LD, LIBCMD:
CC     = cl.exe
LD     = link.exe
LIBCMD = lib.exe
#------------------------------ Include/Lib Path ------------------------------


USER_INCLUDES   =  /I "E:\farm\android" /I "E:\farm\android\slprj\_cprj"

MLSL_INCLUDES     = \
    /I "C:\Program Files\MATLAB\R2018b\extern\include" \
    /I "C:\Program Files\MATLAB\R2018b\simulink\include" \
    /I "C:\Program Files\MATLAB\R2018b\rtw\c\src"
COMPILER_INCLUDES = /I "$(MSVC_ROOT)\include"

THIRD_PARTY_INCLUDES   =  /I "E:\farm\android\slprj\_cgxe\App_v0p2\src"
INCLUDE_PATH = $(MLSL_INCLUDES) $(USER_INCLUDES) $(THIRD_PARTY_INCLUDES)
LIB_PATH     = "$(MSVC_ROOT)\lib"
CFLAGS = /c /Zp8 /GR /W3 /EHs /D_CRT_SECURE_NO_DEPRECATE /D_SCL_SECURE_NO_DEPRECATE /D_SECURE_SCL=0 /DMX_COMPAT_64 /DMATLAB_DEFAULT_RELEASE=R2017b /DMATLAB_MEX_FILE /nologo /MD   
LDFLAGS = /nologo /dll /MANIFEST /OPT:NOREF /export:mexFunction /export:mexfilerequiredapiversion  
#----------------------------- Source Files -----------------------------------

USER_ABS_OBJS =

AUX_SRCS = C:\PROGRA~1\MATLAB\R2018b\extern\version\c_mexapi_version.c  

REQ_SRCS  = $(MODEL_SRC) $(MODEL_REG) $(MODULE_SRCS) $(AUX_SRCS)
REQ_OBJS = $(REQ_SRCS:.cpp=.obj)
REQ_OBJS2 = $(REQ_OBJS:.c=.obj)
OBJS = $(REQ_OBJS2) $(USER_ABS_OBJS) $(AUX_ABS_OBJS)
OBJLIST_FILE = App_v0p2_cgxe.mol
TMWLIB = "C:\Program Files\MATLAB\R2018b\extern\lib\win64\microsoft\libmx.lib" "C:\Program Files\MATLAB\R2018b\extern\lib\win64\microsoft\libmex.lib" "C:\Program Files\MATLAB\R2018b\extern\lib\win64\microsoft\libmat.lib" "C:\Program Files\MATLAB\R2018b\extern\lib\win64\microsoft\libfixedpoint.lib" "C:\Program Files\MATLAB\R2018b\extern\lib\win64\microsoft\libut.lib" "C:\Program Files\MATLAB\R2018b\extern\lib\win64\microsoft\libmwmathutil.lib" "C:\Program Files\MATLAB\R2018b\extern\lib\win64\microsoft\libemlrt.lib" "C:\Program Files\MATLAB\R2018b\extern\lib\win64\microsoft\libmwcgxert.lib" "C:\Program Files\MATLAB\R2018b\extern\lib\win64\microsoft\libmwslexec_simbridge.lib" "C:\Program Files\MATLAB\R2018b\lib\win64\libmwipp.lib" "C:\Program Files\MATLAB\R2018b\extern\lib\win64\microsoft\libcovrt.lib" "C:\Program Files\MATLAB\R2018b\extern\lib\win64\microsoft\libmwsl_sfcn_cov_bridge.lib" 
THIRD_PARTY_LIBS = 

#--------------------------------- Rules --------------------------------------

MEX_FILE_NAME_WO_EXT = $(MODEL)_$(TARGET)
MEX_FILE_NAME = $(MEX_FILE_NAME_WO_EXT).mexw64
all : $(MEX_FILE_NAME) 


$(MEX_FILE_NAME) : $(MAKEFILE) $(OBJS)
	@echo ### Linking ...
	$(LD) $(LDFLAGS) /OUT:$(MEX_FILE_NAME) /map:"$(MEX_FILE_NAME_WO_EXT).map" $(TMWLIB) $(THIRD_PARTY_LIBS) @$(OBJLIST_FILE)
     mt -outputresource:"$(MEX_FILE_NAME);2" -manifest "$(MEX_FILE_NAME).manifest"
	@echo ### Created $@

.c.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

.cpp.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"


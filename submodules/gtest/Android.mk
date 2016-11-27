# Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
# Apache 2.0 License


# Init the building section for project.
PROJECT_PATH	:= $(call my-dir)/../googletest/googletest
LOCAL_PATH		:= $(PROJECT_PATH)
include $(CLEAR_VARS)

LOCAL_MODULE			:= gtest
LOCAL_EXPORT_C_INCLUDES	:= $(PROJECT_PATH)/include
LOCAL_C_INCLUDES		:= $(LOCAL_EXPORT_C_INCLUDES)

LOCAL_SRC_FILES			:=	\
	src/gtest.cc			\
	src/gtest-death-test.cc	\
	src/gtest-filepath.cc	\
	src/gtest-port.cc		\
	src/gtest-printers.cc	\
	src/gtest-test-part.cc	\
	src/gtest-typed-test.cc	\

LOCAL_CPP_FEATURES		:= rtti exceptions
LOCAL_EXPORT_LDLIBS		:= -latomic -llog
LOCAL_CPPFLAGS			:= -std=c++11

# Build rules for Android native applications.
include $(BUILD_STATIC_LIBRARY)

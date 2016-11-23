# Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp)
# Apache 2.0 License


# Looks for a files in requested tree of folders.
define lookup-files
    $(wildcard $(1)) $(foreach e, $(wildcard $(1)/*), $(call lookup-files, $(e)))
endef


LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

$(call import-add-path, $(LOCAL_PATH)/../../../submodules)


LOCAL_PATH				:= $(call my-dir)/source
LOCAL_MODULE			:= jnipp-test
LOCAL_C_INCLUDES		:= $(LOCAL_PATH)
LOCAL_SRC_FILES			:= $(patsubst $(LOCAL_PATH)/%, %, $(filter %.cpp, $(call lookup-files, $(LOCAL_PATH))))
LOCAL_STATIC_LIBRARIES	:= jnipp


# Build rules for Android native applications.
include $(BUILD_SHARED_LIBRARY)


# Include rules for building BitLight libraries.
$(call import-module, jnipp)

# Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp)
# Apache 2.0 License

NDK_TOOLCHAIN_VERSION	:= clang
APP_PLATFORM			:= android-19
APP_ABI					:= armeabi-v7a
APP_STL					:= c++_static
APP_CPPFLAGS			:= -std=c++11
APP_LDFLAGS				:= -latomic -llog

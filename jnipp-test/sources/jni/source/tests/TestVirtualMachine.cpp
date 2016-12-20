// Copyright since 2016 : Evgenii Shatunov (github.com/FrankStain/jnipp-test)
// Apache 2.0 License
#include <main.h>
#include <gtest/gtest.h>


TEST( TestVirtualMachine, IsValid )
{
	EXPECT_EQ( true, Jni::VirtualMachine::IsValid() );
};

TEST( TestVirtualMachine, GetJvm )
{
	EXPECT_NE( nullptr, Jni::VirtualMachine::GetJvm() );
};

TEST( TestVirtualMachine, GetLocalEnvironment )
{
	EXPECT_NE( nullptr, Jni::VirtualMachine::GetLocalEnvironment() );
};

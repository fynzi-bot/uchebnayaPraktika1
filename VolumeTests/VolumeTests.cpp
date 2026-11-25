#include "pch.h"
#include "CppUnitTest.h"
#define UNIT_TESTING
#include "..\VolumeFormulas\VolumeFormulas.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VolumeTests
{
    TEST_CLASS(VolumeTests)
    {
    public:
        TEST_METHOD(TestCubeVolume_ValidSide_ReturnsCorrectVolume)
        {
            Assert::AreEqual(27.0, VolumeFormulas::cubeVolume(3), 0.0001);
        }

        TEST_METHOD(TestCylinderVolume_ValidData_ReturnsCorrectVolume)
        {
            Assert::AreEqual(62.8319, VolumeFormulas::cylinderVolume(2, 5), 0.0001);
        }

        TEST_METHOD(TestSphereVolume_NegativeRadius_ThrowsException)
        {
            Assert::ExpectException<std::invalid_argument>([]() { VolumeFormulas::sphereVolume(-1); });
        }

        TEST_METHOD(TestConeVolume_ZeroHeight_ThrowsException)
        {
            Assert::ExpectException<std::invalid_argument>([]() { VolumeFormulas::coneVolume(3, 0); });
        }
    };
}

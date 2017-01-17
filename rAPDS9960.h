#pragma once
#include "B4RDefines.h"
#include "SparkFun_APDS9960.h"
//~version: 1.00
namespace B4R {
	//~shortname: APDS9960
	//~Event: Gesture (Gesture As Int)
	class B4RAPDS9960 {
		private:
			typedef void (*SubVoidInt)(Int Gesture) ;
			SparkFun_APDS9960 apd;
			PollerNode pnode;
			static void looper(void* b);
			SubVoidInt GestureSub;
		public:
			#define /*Int DIR_LEFT;*/ B4RAPDS9960_DIR_LEFT DIR_LEFT
			#define /*Int DIR_RIGHT;*/ B4RAPDS9960_DIR_RIGHT DIR_RIGHT
			#define /*Int DIR_UP;*/ B4RAPDS9960_DIR_UP DIR_UP
			#define /*Int DIR_DOWN;*/ B4RAPDS9960_DIR_DOWN DIR_DOWN
			#define /*Int DIR_NEAR;*/ B4RAPDS9960_DIR_NEAR DIR_NEAR
			#define /*Int DIR_FAR;*/ B4RAPDS9960_DIR_FAR DIR_FAR
			#define /*Int DIR_ALL;*/ B4RAPDS9960_DIR_ALL DIR_ALL
			//Initializes the module. Returns true if it was initialized successfully.
			bool Initialize(SubVoidInt GestureSub);
			//Enables the gesture sensor. Returns true if successful.
			bool EnableGestureSensor();
			//Disables the gesture sensor.
			void DisableGestureSensor();
			//Enables the proximity sensor. Returns true if successful.
			bool EnableProximitySensor();
			//Disables the proximity sensor.
			void DisableProximitySensor();
			//Returns the proximity value (0 far - 255 near).
			//Returns -1 if it failed to read the proximity.
			//Make sure to first call EnableProximitySensor.
			Int ReadProximity() ;
			//Enables the light sensor.
			bool EnableLightSensor();
			void DisableLightSensor();
			Long ReadRedLight();
			Long ReadGreenLight();
			Long ReadBlueLight();
	};
}
#include "B4RDefines.h"

namespace B4R {
	bool B4RAPDS9960::Initialize(SubVoidInt GestureSub) {
		this->GestureSub = GestureSub;
		FunctionUnion fu;
		fu.PollerFunction = looper;
		pnode.functionUnion = fu;
		pnode.tag = this;
		return apd.init();
	}
	bool B4RAPDS9960::EnableGestureSensor() {
		if (apd.enableGestureSensor(false)) {
			if (pnode.next == NULL) {
				pollers.add(&pnode);
			}
			return true;
		}
		return false;
	}
	//static
	void B4RAPDS9960::looper(void* b) {
		B4RAPDS9960* me = (B4RAPDS9960*) b;
		if (me->apd.isGestureAvailable()) {
			Int g = me->apd.readGesture();
			if (g > 0) {
				me->GestureSub(g);
			}
		}
	}
	void B4RAPDS9960::DisableGestureSensor() {
		apd.disableGestureSensor();
		if (pnode.next != NULL)
			pollers.remove(&pnode);
	}
	bool B4RAPDS9960::EnableProximitySensor() {
		return apd.enableProximitySensor();
	}
	void B4RAPDS9960::DisableProximitySensor() {
		apd.disableProximitySensor();
	}
	Int B4RAPDS9960::ReadProximity() {
		uint8_t b;
		if (apd.readProximity(b))
			return b;
		else
			return -1;
	}
	bool B4RAPDS9960::EnableLightSensor() {
		return apd.enableLightSensor();
	}
	void B4RAPDS9960::DisableLightSensor() {
		apd.disableLightSensor();
	}
	Long B4RAPDS9960::ReadRedLight() {
		uint16_t u;
		if (apd.readRedLight(u))
			return u;
		return -1;
	}
	Long B4RAPDS9960::ReadGreenLight() {
				uint16_t u;
		if (apd.readGreenLight(u))
			return u;
		return -1;
	}
	Long B4RAPDS9960:: ReadBlueLight() {
				uint16_t u;
		if (apd.readBlueLight(u))
			return u;
		return -1;
	}
}
#include <node.h>
#include <node_object_wrap.h>
#include "kdmapper.hpp"

namespace kdmapperNS {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::NewStringType;
using v8::Object;
using v8::String;
using v8::Number;
using v8::Value;
using v8::Exception;

void mapDriver(const FunctionCallbackInfo<Value>& args) {
	Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate,"Wrong number of arguments",NewStringType::kNormal).ToLocalChecked()));
		args.GetReturnValue().Set(Number::New(isolate, 0));
		return;
	}
	v8::String::Utf8Value path(args[0]->ToString());   
    std::string driverPath = std::string(*path);
	
	KernelDriverMapper kdmapper;
	if (!kdmapper.Initialize()){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate,"[-] Failed to initalize kdmapper",NewStringType::kNormal).ToLocalChecked()));
		args.GetReturnValue().Set(Number::New(isolate, 0));
		return;
	}
	const uint64_t mapped_driver_code = kdmapper.MapDriver(driverPath);
	args.GetReturnValue().Set(Number::New(isolate, (double)mapped_driver_code));
}

void Initialize(Local<Object> exports) {
  NODE_SET_METHOD(exports, "mapDriver", mapDriver);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

}
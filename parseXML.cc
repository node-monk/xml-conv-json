#include <nan.h>
#include <string>
#include <iostream> 
#include "./libs/xml2json/include/xml2json.hpp"

void parseXML(const Nan::FunctionCallbackInfo<v8::Value>& info) {

  if (info.Length() < 1) {
    Nan::ThrowTypeError("Wrong number of arguments");
    return;
  }

  if (!info[0]->IsString()) {
    Nan::ThrowTypeError("Argument 1 must be an XML String");
    return;
  }


    v8::String::Utf8Value s1(info[0]);
    std::string ss1 = std::string(*s1);
    const char* xmlString=ss1.c_str();


  std::string js1=xml2json(xmlString);
  v8::Local<v8::String> hTextJS = v8::String::NewFromUtf8(v8::Isolate::GetCurrent(), js1.c_str());

  info.GetReturnValue().Set(hTextJS);
}

void Init(v8::Local<v8::Object> exports) {
  exports->Set(Nan::New("parseXML").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(parseXML)->GetFunction());
}

NODE_MODULE(addon, Init)

#ifndef __BINDING_H
#define __BINDING_H


#define ADD_PROTOTYPE_METHOD(class, name, method) \
class ## _ ## name ## _symbol = NODE_PSYMBOL(#name); \
NODE_SET_PROTOTYPE_METHOD(constructor_template, #name, method);

#define REQ_EXT_ARG(I, VAR) \
if (args.Length() <= (I) || !args[I]->IsExternal()) \
return ThrowException(Exception::TypeError( \
String::New("Argument " #I " invalid"))); \
Local<External> VAR = Local<External>::Cast(args[I]);

#define REQ_FUN_ARG(I, VAR) \
if (args.Length() <= (I) || !args[I]->IsFunction()) \
return ThrowException(Exception::TypeError( \
String::New("Argument " #I " must be a function"))); \
Local<Function> VAR = Local<Function>::Cast(args[I]);


#define REQ_STR_ARG(I, VAR) \
if (args.Length() <= (I) || !args[I]->IsString()) \
return ThrowException(Exception::TypeError( \
String::New("Argument " #I " must be a string"))); \
String::Utf8Value VAR(args[I]->ToString());


#define V8STR(str) String::New(str)
#define V8STR2(str, len) String::New(str, len)

#include <string>
#include <gphoto2/gphoto2-camera.h>

// Useful functions taken from library examples, with slight modifications
int open_camera (Camera ** camera, std::string model, std::string port);
int  autodetect (CameraList *list, GPContext *context, GPPortInfoList **portinfolist, CameraAbilitiesList	**abilities);
int  set_config_value_string (Camera *camera, const char *key, const char *val, GPContext *context);
int  get_config_value_string (Camera *camera, const char *key, char **str, GPContext *context);



#endif
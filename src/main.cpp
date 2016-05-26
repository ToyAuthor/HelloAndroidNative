#include <android_native_app_glue.h>
#include <android/log.h>


void android_main(struct android_app* state)
{
	// 用來阻止編譯器將 glue 忽略掉
	app_dummy();

	// 使用這指令來擷取此訊息 adb logcat MyTag:I *:S
	__android_log_print(ANDROID_LOG_INFO, "MyTag", "Hello World!");

	// 關閉我們唯一使用的 Activity
	ANativeActivity_finish(state->activity);
}

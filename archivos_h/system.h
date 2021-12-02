#ifndef SYSTEM_H_
#define SYSTEM_H_

#ifdef __linux__
#define CLR_SCREEN "clear"
#endif // __linux__

#ifdef __MINGW32__
#define CLR_SCREEN "CLS"
#endif // __MINGW32__

#ifdef __APPLE__
#define CLR_SCREEN "clear"
#endif // __APPLE__

#endif //_SYSTEM_H_
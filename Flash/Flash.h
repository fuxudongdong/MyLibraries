#ifndef _Flash__
#define _Flash__

#include "Arduino.h"

class Flash {
  private:
    String fileName = "";
  public:
    Flash(String file);
    ~Flash();
    void add(String str, String name);
    void remove();
    void save();
    String getContent(String str);
    bool exists();
};
#endif
